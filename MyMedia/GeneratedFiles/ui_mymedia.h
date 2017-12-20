/********************************************************************************
** Form generated from reading UI file 'mymedia.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMEDIA_H
#define UI_MYMEDIA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMediaClass
{
public:
    QAction *action_open;
    QAction *action_chose;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *phBtn_stop;
    QPushButton *phBtn_play;
    QPushButton *phBtn_Next;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *phBtn_Vlm;
    QSlider *horizontalSlider_Voluem;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMediaClass)
    {
        if (MyMediaClass->objectName().isEmpty())
            MyMediaClass->setObjectName(QString::fromUtf8("MyMediaClass"));
        MyMediaClass->resize(651, 621);
        MyMediaClass->setStyleSheet(QString::fromUtf8("QSlider{\n"
"border-color: #bcbcbc;\n"
"}\n"
"QSlider::groove:horizontal {                                \n"
"     border: 1px solid #999999;                             \n"
"     height: 1px;                                           \n"
"    margin: 0px 0;                                         \n"
"     left: 5px; right: 5px; \n"
" }\n"
" /*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256 */\n"
"QSlider::handle:horizontal {                               \n"
"     border: 0px ;                           \n"
"     border-image:  url(:/MyMedia/img/bullet_blue.png);\n"
"     width: 15px;                                           \n"
"     margin: -7px -7px -7px -7px;                  \n"
"} \n"
"/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346\226\271*/\n"
"QSlider::add-page:horizontal{\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop"
                        ":0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
"\n"
"}\n"
"/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/\n"
"QSlider::sub-page:horizontal{                               \n"
" background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);                     \n"
"}\n"
"\n"
"QPushButton#phBtn_play{\n"
"	border-image: url(:/MyMedia/img/playnormal.png);\n"
"}\n"
"QPushButton#phBtn_play:pressed{\n"
"    border: 0px ; \n"
"	border-image: url(:/MyMedia/img/playpressed.png);\n"
"}\n"
"QPushButton#phBtn_stop{\n"
"	border-image: url(:/MyMedia/img/stop1normalblue.png);\n"
"}\n"
"QPushButton#phBtn_stop:pressed{\n"
"    border: 0px ; \n"
"	border-image: url(:/MyMedia/img/stop1pressedblue.png);\n"
"}\n"
"QPushButton#phBtn_Next{\n"
"	border-image: url(:/MyMedia/img/stepforwardnormalblue.png);\n"
"}\n"
"QPushButton#phBtn_Next:pressed{\n"
"    border: 0px ; \n"
"	border-image: url(:/MyMedia/img/s"
                        "tepforwardpressedblue.png);\n"
"}\n"
"QMainWindow{\n"
"	border:0px;\n"
"	margin:0px;\n"
"}\n"
"\n"
"QPushButton#phBtn_Vlm{\n"
"	border-image: url(:/MyMedia/img/volumenormalblue.png);\n"
"}\n"
"QPushButton#phBtn_Vlm:pressed{\n"
"    border: 0px ; \n"
"	border-image: url(:/MyMedia/img/volumepressedblue.png);\n"
"}"));
        action_open = new QAction(MyMediaClass);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_chose = new QAction(MyMediaClass);
        action_chose->setObjectName(QString::fromUtf8("action_chose"));
        centralWidget = new QWidget(MyMediaClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout_2->addWidget(widget);

        verticalSpacer_2 = new QSpacerItem(236, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        phBtn_stop = new QPushButton(centralWidget);
        phBtn_stop->setObjectName(QString::fromUtf8("phBtn_stop"));
        phBtn_stop->setMinimumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(phBtn_stop);

        phBtn_play = new QPushButton(centralWidget);
        phBtn_play->setObjectName(QString::fromUtf8("phBtn_play"));
        phBtn_play->setMinimumSize(QSize(30, 30));
        phBtn_play->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(phBtn_play);

        phBtn_Next = new QPushButton(centralWidget);
        phBtn_Next->setObjectName(QString::fromUtf8("phBtn_Next"));
        phBtn_Next->setMinimumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(phBtn_Next);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        phBtn_Vlm = new QPushButton(centralWidget);
        phBtn_Vlm->setObjectName(QString::fromUtf8("phBtn_Vlm"));
        phBtn_Vlm->setMinimumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(phBtn_Vlm);

        horizontalSlider_Voluem = new QSlider(centralWidget);
        horizontalSlider_Voluem->setObjectName(QString::fromUtf8("horizontalSlider_Voluem"));
        horizontalSlider_Voluem->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_Voluem);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_6->setStretch(0, 4);

        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        horizontalLayout_3->addWidget(listView);

        horizontalLayout_3->setStretch(0, 6);
        horizontalLayout_3->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        MyMediaClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyMediaClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 651, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MyMediaClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MyMediaClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyMediaClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_open);
        menu->addAction(action_chose);

        retranslateUi(MyMediaClass);

        QMetaObject::connectSlotsByName(MyMediaClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyMediaClass)
    {
        MyMediaClass->setWindowTitle(QApplication::translate("MyMediaClass", "MyMedia", 0, QApplication::UnicodeUTF8));
        action_open->setText(QApplication::translate("MyMediaClass", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        action_chose->setText(QApplication::translate("MyMediaClass", "\351\200\211\346\213\251\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyMediaClass", "00:00:00/00:00:00", 0, QApplication::UnicodeUTF8));
        phBtn_stop->setText(QString());
        phBtn_play->setText(QString());
        phBtn_Next->setText(QString());
        phBtn_Vlm->setText(QString());
        menu->setTitle(QApplication::translate("MyMediaClass", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyMediaClass: public Ui_MyMediaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMEDIA_H
