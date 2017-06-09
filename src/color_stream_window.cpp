#include "color_stream_window.h"
#include "ui_colorstream.h"

colorStream::colorStream(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::colorStream)
{
    ui->setupUi(this);
}

colorStream::~colorStream()
{
    delete ui;
}


void colorStream::setImage(cv::Mat img)	{
	ui->colorImage->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));	
}