#include "depth_stream_window.h"
#include "ui_depthstream.h"

depthStream::depthStream(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::depthStream)
{
    ui->setupUi(this);
}

depthStream::~depthStream()
{
    delete ui;
}


void depthStream::setImage(cv::Mat img)	{
	// Set pixel map
	ui->depthImage->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_Grayscale8)));	
}