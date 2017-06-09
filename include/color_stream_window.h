#ifndef COLORSTREAM_H
#define COLORSTREAM_H
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
class colorStream;
}

class colorStream : public QWidget
{
    Q_OBJECT

public:
    explicit colorStream(QWidget *parent = 0);
    ~colorStream();

    void setImage(cv::Mat img);

private:
    Ui::colorStream *ui;
};

#endif // COLORSTREAM_H
