/********************************************************************************
** Form generated from reading UI file 'colorstream.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSTREAM_H
#define UI_COLORSTREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_colorStream
{
public:
    QGridLayout *gridLayout;
    QLabel *colorImage;

    void setupUi(QWidget *colorStream)
    {
        if (colorStream->objectName().isEmpty())
            colorStream->setObjectName(QStringLiteral("colorStream"));
        colorStream->resize(400, 300);
        gridLayout = new QGridLayout(colorStream);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        colorImage = new QLabel(colorStream);
        colorImage->setObjectName(QStringLiteral("colorImage"));

        gridLayout->addWidget(colorImage, 0, 0, 1, 1);


        retranslateUi(colorStream);

        QMetaObject::connectSlotsByName(colorStream);
    } // setupUi

    void retranslateUi(QWidget *colorStream)
    {
        colorStream->setWindowTitle(QApplication::translate("colorStream", "Form", 0));
        colorImage->setText(QApplication::translate("colorStream", "ColorImage", 0));
    } // retranslateUi

};

namespace Ui {
    class colorStream: public Ui_colorStream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSTREAM_H
