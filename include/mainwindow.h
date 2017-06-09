#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 *  Standard Libraries
*/
#include <iostream>

/*
 *  3rd Party Libraries
*/
//QT
#include <QTime>
#include <QtGui>
#include <QFile>
#include <QImage>

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QCoreApplication>


//PCL
#include <pcl/common/common_headers.h>

/*
 *  Local Libraries
*/
#include "str_utils.h"
#include "realsense_wrapper.h"
#include "point_cloud_utils.h"
#include "color_stream_window.h"
#include "depth_stream_window.h"

/*
	ENUM
*/


/*
	MACRO
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

	public:
	    explicit MainWindow(QWidget *parent = 0);
	    ~MainWindow();

    private slots:
		/*
			Clicked Signal Methods
		*/
		void on_previewButton_clicked();
		void on_pauseButton_clicked();
		void on_savePointCloudButton_clicked();
		void on_saveDepthImageButton_clicked();
		void on_saveColorImageButton_clicked();
		void on_saveAllButton_clicked();
		void on_showColorStreamButton_clicked();
		void on_showDepthStreamButton_clicked();

		/*
			Trigger Signal Methods
		*/
		void on_actionExit_triggered();
		void on_actionHelp_triggered();
		void on_actionAbout_triggered();
		void updatePointCloud();

	private:
	    Ui::MainWindow *ui;
	    QTimer *timer;
	    RealsenseWrapper* rs_wrapper;
	    cv::Mat depthImage;
	    cv::Mat colorImage;
	    colorStream *colorStreamWindow;
	    depthStream *depthStreamWindow;
	    int frameRate;

	    static bool paused;
	    static bool preview;

	    boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> > pointCloud3D;

	    /*
	    	Class Function
	    */
	    void initializeRealsense();
};

#endif // MAINWINDOW_H
