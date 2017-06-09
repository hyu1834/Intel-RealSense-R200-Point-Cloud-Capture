/********************************************************************************
** Form generated from reading UI file 'depthstream.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPTHSTREAM_H
#define UI_DEPTHSTREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_depthStream
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *depthImage;

    void setupUi(QWidget *depthStream)
    {
        if (depthStream->objectName().isEmpty())
            depthStream->setObjectName(QStringLiteral("depthStream"));
        depthStream->resize(400, 300);
        verticalLayout = new QVBoxLayout(depthStream);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        depthImage = new QLabel(depthStream);
        depthImage->setObjectName(QStringLiteral("depthImage"));

        verticalLayout->addWidget(depthImage);


        retranslateUi(depthStream);

        QMetaObject::connectSlotsByName(depthStream);
    } // setupUi

    void retranslateUi(QWidget *depthStream)
    {
        depthStream->setWindowTitle(QApplication::translate("depthStream", "Form", 0));
        depthImage->setText(QApplication::translate("depthStream", "Depth Image", 0));
    } // retranslateUi

};

namespace Ui {
    class depthStream: public Ui_depthStream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPTHSTREAM_H
