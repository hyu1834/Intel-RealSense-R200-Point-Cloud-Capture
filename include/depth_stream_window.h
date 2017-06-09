#ifndef DEPTHSTREAM_H
#define DEPTHSTREAM_H
/*
 *  Standard Libraries
*/


/*
 *  3rd Party Libraries
*/
//QT
#include <QWidget>
#include <QImage>

//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/*
 *  Local Libraries
*/


/*
	ENUM
*/


/*
	MACRO
*/


namespace Ui {
class depthStream;
}

class depthStream : public QWidget
{
    Q_OBJECT

public:
    explicit depthStream(QWidget *parent = 0);
    ~depthStream();

    void setImage(cv::Mat img);

private:
    Ui::depthStream *ui;
};

#endif // COLORSTREAM_H
