/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionPreview;
    QAction *actionPause;
    QAction *actionSave;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *menuTitle;
    QFrame *line;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QLabel *label_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *colorResolutionBox;
    QPushButton *showColorStreamButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QComboBox *depthResolutionBox;
    QLabel *label_3;
    QComboBox *captureModeBox_2;
    QPushButton *showDepthStreamButton;
    QPushButton *previewButton;
    QFrame *line_2;
    QPushButton *pauseButton;
    QFrame *line_3;
    QPushButton *savePointCloudButton;
    QPushButton *saveColorImageButton;
    QPushButton *saveDepthImageButton;
    QPushButton *saveAllButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QOpenGLWidget *openGLWidget;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1357, 778);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QStringLiteral("actionPreview"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        menuTitle = new QLabel(centralWidget);
        menuTitle->setObjectName(QStringLiteral("menuTitle"));
        menuTitle->setAutoFillBackground(false);
        menuTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(menuTitle);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(999999999);
        spinBox->setValue(500);

        horizontalLayout_2->addWidget(spinBox);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        colorResolutionBox = new QComboBox(groupBox);
        colorResolutionBox->setObjectName(QStringLiteral("colorResolutionBox"));
        colorResolutionBox->setEnabled(false);

        verticalLayout->addWidget(colorResolutionBox);

        showColorStreamButton = new QPushButton(groupBox);
        showColorStreamButton->setObjectName(QStringLiteral("showColorStreamButton"));

        verticalLayout->addWidget(showColorStreamButton);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        depthResolutionBox = new QComboBox(groupBox_2);
        depthResolutionBox->setObjectName(QStringLiteral("depthResolutionBox"));
        depthResolutionBox->setEnabled(false);

        verticalLayout_4->addWidget(depthResolutionBox);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        captureModeBox_2 = new QComboBox(groupBox_2);
        captureModeBox_2->setObjectName(QStringLiteral("captureModeBox_2"));
        captureModeBox_2->setEnabled(false);

        verticalLayout_4->addWidget(captureModeBox_2);

        showDepthStreamButton = new QPushButton(groupBox_2);
        showDepthStreamButton->setObjectName(QStringLiteral("showDepthStreamButton"));

        verticalLayout_4->addWidget(showDepthStreamButton);


        verticalLayout_2->addWidget(groupBox_2);

        previewButton = new QPushButton(centralWidget);
        previewButton->setObjectName(QStringLiteral("previewButton"));

        verticalLayout_2->addWidget(previewButton);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        verticalLayout_2->addWidget(pauseButton);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        savePointCloudButton = new QPushButton(centralWidget);
        savePointCloudButton->setObjectName(QStringLiteral("savePointCloudButton"));
        savePointCloudButton->setEnabled(false);

        verticalLayout_2->addWidget(savePointCloudButton);

        saveColorImageButton = new QPushButton(centralWidget);
        saveColorImageButton->setObjectName(QStringLiteral("saveColorImageButton"));
        saveColorImageButton->setEnabled(false);

        verticalLayout_2->addWidget(saveColorImageButton);

        saveDepthImageButton = new QPushButton(centralWidget);
        saveDepthImageButton->setObjectName(QStringLiteral("saveDepthImageButton"));
        saveDepthImageButton->setEnabled(false);

        verticalLayout_2->addWidget(saveDepthImageButton);

        saveAllButton = new QPushButton(centralWidget);
        saveAllButton->setObjectName(QStringLiteral("saveAllButton"));
        saveAllButton->setEnabled(false);

        verticalLayout_2->addWidget(saveAllButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        verticalLayout_3->addWidget(openGLWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1357, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionPreview);
        menuFile->addAction(actionPause);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionAbout);
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Point Cloud Registration Using Distance Geometry", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionPreview->setText(QApplication::translate("MainWindow", "Preview", 0));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        menuTitle->setText(QApplication::translate("MainWindow", "Menu", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Screen", 0));
        label_4->setText(QApplication::translate("MainWindow", "Refresh Rate", 0));
        label_5->setText(QApplication::translate("MainWindow", "ms", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Color Stream", 0));
        label->setText(QApplication::translate("MainWindow", "Reaolution", 0));
        colorResolutionBox->clear();
        colorResolutionBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "320x240", 0)
         << QApplication::translate("MainWindow", "640x480", 0)
         << QApplication::translate("MainWindow", "1280x720", 0)
         << QApplication::translate("MainWindow", "1920x1080", 0)
        );
        showColorStreamButton->setText(QApplication::translate("MainWindow", "Show Color Stream", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Depth Stream", 0));
        label_2->setText(QApplication::translate("MainWindow", "Resolution", 0));
        depthResolutionBox->clear();
        depthResolutionBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "320x240", 0)
         << QApplication::translate("MainWindow", "480x360", 0)
         << QApplication::translate("MainWindow", "628x468", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Capture Mode", 0));
        captureModeBox_2->clear();
        captureModeBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Auto", 0)
         << QApplication::translate("MainWindow", "Indoor", 0)
         << QApplication::translate("MainWindow", "Outdoor", 0)
        );
        showDepthStreamButton->setText(QApplication::translate("MainWindow", "Show Depth Stream", 0));
        previewButton->setText(QApplication::translate("MainWindow", "Preview", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        savePointCloudButton->setText(QApplication::translate("MainWindow", "Save Point Cloud", 0));
        saveColorImageButton->setText(QApplication::translate("MainWindow", "Save Color Image", 0));
        saveDepthImageButton->setText(QApplication::translate("MainWindow", "Save Depth Image", 0));
        saveAllButton->setText(QApplication::translate("MainWindow", "Save All", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
