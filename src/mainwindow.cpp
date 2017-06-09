#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::paused = false;
bool MainWindow::preview = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), colorStreamWindow(NULL),
										  depthStreamWindow(NULL), frameRate(500)	{
    ui->setupUi(this);
    // Open application in full screen mode
    QWidget::showMaximized();

    // Initialize Realsense
    initializeRealsense();
    pointCloud3D = boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> >(new pcl::PointCloud<pcl::PointXYZRGB>); 

    //Timer trigger to capture point cloud every 0.5 seconds
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updatePointCloud()));
	timer->start(frameRate); //time specified in ms
}

MainWindow::~MainWindow()	{
    delete ui;
}

/*
	Class Function
*/
void MainWindow::initializeRealsense()	{
	rs_wrapper = NULL;
	try	{
		//init rs_wrapper
		rs_wrapper = new RealsenseWrapper();
	}
	catch(int e)	{
		exit(REALSENSE_ERROR);
	}

	// init color and depth stream
	rs_wrapper->init(rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH);
	//init sensing mode
	rs_wrapper->setSensingMode(rs_wrapper::SENSINGMODE::INDOOR);
}

/*
	Clicked Signal Methods
*/
void MainWindow::on_previewButton_clicked()	{
	if(preview)	{
		preview = false;
		ui->previewButton->setText("Preview");
		ui->pauseButton->setEnabled(false);
	}
	else	{
		preview = true;
		ui->previewButton->setText("Stop");
		ui->pauseButton->setEnabled(true);
	}
}

void MainWindow::on_pauseButton_clicked()	{
	if(paused)	{
		paused = false;
		ui->pauseButton->setText("Pause");
		ui->savePointCloudButton->setEnabled(false);
		ui->saveDepthImageButton->setEnabled(false);
		ui->saveColorImageButton->setEnabled(false);
		ui->saveAllButton->setEnabled(false);
	}
	else	{
		paused = true;
		ui->pauseButton->setText("Resume");
		ui->savePointCloudButton->setEnabled(true);
		ui->saveDepthImageButton->setEnabled(true);
		ui->saveColorImageButton->setEnabled(true);
		ui->saveAllButton->setEnabled(true);
	}
}

void MainWindow::on_savePointCloudButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
	}
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Point Cloud File"), QString(),
														  tr("Text Files (*.txt);;All Files (*.*)"));
	// if a file is selected
	if(filePath != "")  {
		exportPointCloud<pcl::PointXYZRGB>(filePath.toUtf8().constData(), pointCloud3D, 0.0, 0.0, 0.0);
		QMessageBox::information(this, "Export Point Cloud", 
								 QString::fromStdString("Exported: " + formatNumber<int>(pointCloud3D->size()) + " points"));
	}
}

void MainWindow::on_saveDepthImageButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
	}
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Depth Image File"), QString(),
														  tr("Portable Network Graphics (*.png);;Joint Photographic Experts Group (*.JPEG)"));
	// if a file is selected
	if(filePath != "")  {
		cv::imwrite(filePath.toUtf8().constData(), depthImage);
	}
}

void MainWindow::on_saveColorImageButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
	}
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Color Image File"), QString(),
														  tr("Portable Network Graphics (*.png);;Joint Photographic Experts Group (*.JPEG)"));
	// if a file is selected
	if(filePath != "")  {
		cv::imwrite(filePath.toUtf8().constData(), colorImage);
	}
}

void MainWindow::on_saveAllButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
	}
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Point Cloud File"), QString(),
														  tr("All Files (*.*)"));
	// if a file is selected
	if(filePath != "")  {
		cv::imwrite(filePath.toUtf8().constData(), colorImage);
		cv::imwrite(filePath.toUtf8().constData(), depthImage);
		exportPointCloud<pcl::PointXYZRGB>(filePath.toUtf8().constData(), pointCloud3D, 0.0, 0.0, 0.0);
		QMessageBox::information(this, "Export Point Cloud", 
								 QString::fromStdString("Exported: " + formatNumber<int>(pointCloud3D->size()) + " points"));
	}
}

void MainWindow::on_showColorStreamButton_clicked()	{
	if(!colorStreamWindow)	{

		colorStreamWindow = new colorStream(); // Be sure to destroy your window somewhere
		colorStreamWindow->show();
		ui->showColorStreamButton->setText("Hide Color Stream");
	}
	else	{
		delete colorStreamWindow;
		colorStreamWindow = NULL;
		ui->showColorStreamButton->setText("Show Color Stream");
	}
	
}

void MainWindow::on_showDepthStreamButton_clicked()	{
	if(!depthStreamWindow)	{
		depthStreamWindow = new depthStream(); // Be sure to destroy your window somewhere
		depthStreamWindow->show();
		ui->showDepthStreamButton->setText("Hide Depth Stream");
	}
	else	{
		delete depthStreamWindow;
		depthStreamWindow = NULL;
		ui->showDepthStreamButton->setText("Show Depth Stream");
	}
}


/*
	Trigger Signal Methods
*/
void MainWindow::on_actionExit_triggered()	{
	QApplication::quit();
}


void MainWindow::on_actionHelp_triggered()	{
	QString helpStr = QString::fromStdString(std::string("Click \"Preview\" button to start camera stream\n") +
											 "Click \"Pause\" button to pause the camera stream\n" +
											 "Click \"Save Point Cloud\" button to save captured point cloud" 
											);
	QMessageBox::information(this, "Help", helpStr);
}

void MainWindow::on_actionAbout_triggered()	{
	QString aboutStr = QString::fromStdString(std::string("Program Title: Intel RealSense R200 Point Cloud Capture\n") + 
											  "Developer: Hiu Hong Yu\n" +
											  "Developer Email: hiuyu@ucdavis.edu\n" +
											  "Organization: Advanced Highway Maintenance and Construction Research Center (AHMCT), University of California, Davis\n" +
											  "Copy Right 2017"
											 );
	QMessageBox::information(this, "About", aboutStr);
}

void MainWindow::updatePointCloud()	{
	if(preview && !paused)	{
		rs_wrapper->getXYZRGBDepthColor(pointCloud3D, rs_wrapper::COORDMODE::RIGHTHANDED, depthImage, colorImage);
		if(colorStreamWindow != NULL)	{
			colorStreamWindow->setImage(colorImage);
		}

		if(depthStreamWindow != NULL)	{
			depthStreamWindow->setImage(depthImage);
		}
		// ui->depthImage->setPixmap(QPixmap::fromImage(QImage(depthImage.data, depthImage.cols, depthImage.rows, depthImage.step, QImage::Format_Grayscale8)));
		// ui->colorImage->setPixmap(QPixmap::fromImage(QImage(colorImage.data, colorImage.cols, colorImage.rows, colorImage.step, QImage::Format_RGB888)));	
	}
	
}