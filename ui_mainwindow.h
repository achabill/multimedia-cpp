/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionQuit_at_end_of_playlist;
    QAction *actionQuit;
    QAction *actionPlay_Pause;
    QAction *actionNext;
    QAction *actionNet;
    QAction *actionPrevious;
    QAction *actionSkip_to_time;
    QAction *actionVolume_up;
    QAction *actionVolume_down;
    QAction *actionMute;
    QAction *actionRecord;
    QAction *actionConvert_format;
    QAction *actionSwitch_mode;
    QAction *actionVisualizers;
    QAction *actionSettings;
    QAction *actionAbout;
    QWidget *centralwidget;
    QSlider *slider;
    QTreeWidget *detailsTreeWidget;
    QTreeWidget *computerTreeWidget;
    QPushButton *switchModeButton;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;
    QLabel *currentSongLabel;
    QPushButton *playAllButton;
    QTreeWidget *playListTreeWidget;
    QPushButton *muteButton;
    QSlider *volumeSlider;
    QGroupBox *groupBox;
    QPushButton *stopButton;
    QPushButton *playButton;
    QComboBox *rateComboBox;
    QCheckBox *shuffleCheckBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *loopOneRadioButton;
    QRadioButton *loopAllRadioButton;
    QRadioButton *loopNoeRadioButton;
    QGroupBox *groupBox_2;
    QPushButton *chatButton;
    QPushButton *recordButton;
    QPushButton *convertButton;
    QLabel *volumeLabel;
    QPushButton *fullScreenButton;
    QLabel *itemsLabel;
    QPushButton *clearListButton;
    QPushButton *openListButton;
    QPushButton *saveListButon;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAudio;
    QMenu *menuTools;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuHelp_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1126, 670);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(218, 218, 218, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(181, 181, 181, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(72, 72, 72, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(97, 97, 97, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(200, 200, 200, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionQuit_at_end_of_playlist = new QAction(MainWindow);
        actionQuit_at_end_of_playlist->setObjectName(QStringLiteral("actionQuit_at_end_of_playlist"));
        actionQuit_at_end_of_playlist->setCheckable(true);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPlay_Pause = new QAction(MainWindow);
        actionPlay_Pause->setObjectName(QStringLiteral("actionPlay_Pause"));
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        actionNet = new QAction(MainWindow);
        actionNet->setObjectName(QStringLiteral("actionNet"));
        actionPrevious = new QAction(MainWindow);
        actionPrevious->setObjectName(QStringLiteral("actionPrevious"));
        actionSkip_to_time = new QAction(MainWindow);
        actionSkip_to_time->setObjectName(QStringLiteral("actionSkip_to_time"));
        actionVolume_up = new QAction(MainWindow);
        actionVolume_up->setObjectName(QStringLiteral("actionVolume_up"));
        actionVolume_down = new QAction(MainWindow);
        actionVolume_down->setObjectName(QStringLiteral("actionVolume_down"));
        actionMute = new QAction(MainWindow);
        actionMute->setObjectName(QStringLiteral("actionMute"));
        actionRecord = new QAction(MainWindow);
        actionRecord->setObjectName(QStringLiteral("actionRecord"));
        actionConvert_format = new QAction(MainWindow);
        actionConvert_format->setObjectName(QStringLiteral("actionConvert_format"));
        actionSwitch_mode = new QAction(MainWindow);
        actionSwitch_mode->setObjectName(QStringLiteral("actionSwitch_mode"));
        actionVisualizers = new QAction(MainWindow);
        actionVisualizers->setObjectName(QStringLiteral("actionVisualizers"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        slider = new QSlider(centralwidget);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setGeometry(QRect(250, 40, 751, 22));
        slider->setOrientation(Qt::Horizontal);
        detailsTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("#"));
        detailsTreeWidget->setHeaderItem(__qtreewidgetitem);
        detailsTreeWidget->setObjectName(QStringLiteral("detailsTreeWidget"));
        detailsTreeWidget->setGeometry(QRect(240, 100, 641, 501));
        computerTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("Computer"));
        computerTreeWidget->setHeaderItem(__qtreewidgetitem1);
        computerTreeWidget->setObjectName(QStringLiteral("computerTreeWidget"));
        computerTreeWidget->setGeometry(QRect(10, 100, 221, 371));
        switchModeButton = new QPushButton(centralwidget);
        switchModeButton->setObjectName(QStringLiteral("switchModeButton"));
        switchModeButton->setGeometry(QRect(1070, 600, 41, 23));
        startTimeLabel = new QLabel(centralwidget);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));
        startTimeLabel->setGeometry(QRect(250, 10, 61, 31));
        QFont font;
        font.setPointSize(11);
        startTimeLabel->setFont(font);
        endTimeLabel = new QLabel(centralwidget);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setGeometry(QRect(940, 10, 61, 31));
        endTimeLabel->setFont(font);
        currentSongLabel = new QLabel(centralwidget);
        currentSongLabel->setObjectName(QStringLiteral("currentSongLabel"));
        currentSongLabel->setGeometry(QRect(390, 10, 361, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        currentSongLabel->setFont(font1);
        playAllButton = new QPushButton(centralwidget);
        playAllButton->setObjectName(QStringLiteral("playAllButton"));
        playAllButton->setGeometry(QRect(240, 80, 75, 23));
        playListTreeWidget = new QTreeWidget(centralwidget);
        playListTreeWidget->setObjectName(QStringLiteral("playListTreeWidget"));
        playListTreeWidget->setGeometry(QRect(890, 310, 221, 261));
        playListTreeWidget->setDragEnabled(true);
        playListTreeWidget->setDragDropOverwriteMode(true);
        playListTreeWidget->setDragDropMode(QAbstractItemView::DragDrop);
        playListTreeWidget->setDefaultDropAction(Qt::MoveAction);
        playListTreeWidget->setAnimated(false);
        muteButton = new QPushButton(centralwidget);
        muteButton->setObjectName(QStringLiteral("muteButton"));
        muteButton->setGeometry(QRect(1060, 70, 51, 23));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(1040, 40, 71, 22));
        volumeSlider->setValue(99);
        volumeSlider->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 81));
        stopButton = new QPushButton(groupBox);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(40, 20, 31, 41));
        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(0, 20, 41, 41));
        playButton->setStyleSheet(QStringLiteral(""));
        rateComboBox = new QComboBox(groupBox);
        rateComboBox->setObjectName(QStringLiteral("rateComboBox"));
        rateComboBox->setGeometry(QRect(160, 40, 51, 21));
        shuffleCheckBox = new QCheckBox(groupBox);
        shuffleCheckBox->setObjectName(QStringLiteral("shuffleCheckBox"));
        shuffleCheckBox->setGeometry(QRect(160, 10, 51, 20));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 10, 34, 54));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        verticalLayout->addWidget(nextButton);

        previousButton = new QPushButton(layoutWidget);
        previousButton->setObjectName(QStringLiteral("previousButton"));

        verticalLayout->addWidget(previousButton);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 10, 49, 65));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        loopOneRadioButton = new QRadioButton(layoutWidget1);
        loopOneRadioButton->setObjectName(QStringLiteral("loopOneRadioButton"));

        verticalLayout_2->addWidget(loopOneRadioButton);

        loopAllRadioButton = new QRadioButton(layoutWidget1);
        loopAllRadioButton->setObjectName(QStringLiteral("loopAllRadioButton"));

        verticalLayout_2->addWidget(loopAllRadioButton);

        loopNoeRadioButton = new QRadioButton(layoutWidget1);
        loopNoeRadioButton->setObjectName(QStringLiteral("loopNoeRadioButton"));

        verticalLayout_2->addWidget(loopNoeRadioButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 490, 221, 111));
        chatButton = new QPushButton(groupBox_2);
        chatButton->setObjectName(QStringLiteral("chatButton"));
        chatButton->setGeometry(QRect(10, 30, 51, 61));
        recordButton = new QPushButton(groupBox_2);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setGeometry(QRect(70, 30, 51, 61));
        convertButton = new QPushButton(groupBox_2);
        convertButton->setObjectName(QStringLiteral("convertButton"));
        convertButton->setGeometry(QRect(130, 30, 51, 61));
        volumeLabel = new QLabel(centralwidget);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        volumeLabel->setGeometry(QRect(1070, 10, 41, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        volumeLabel->setFont(font2);
        fullScreenButton = new QPushButton(centralwidget);
        fullScreenButton->setObjectName(QStringLiteral("fullScreenButton"));
        fullScreenButton->setGeometry(QRect(890, 280, 75, 23));
        fullScreenButton->setCheckable(true);
        itemsLabel = new QLabel(centralwidget);
        itemsLabel->setObjectName(QStringLiteral("itemsLabel"));
        itemsLabel->setGeometry(QRect(900, 600, 131, 16));
        clearListButton = new QPushButton(centralwidget);
        clearListButton->setObjectName(QStringLiteral("clearListButton"));
        clearListButton->setGeometry(QRect(891, 571, 69, 23));
        openListButton = new QPushButton(centralwidget);
        openListButton->setObjectName(QStringLiteral("openListButton"));
        openListButton->setGeometry(QRect(966, 571, 69, 23));
        saveListButon = new QPushButton(centralwidget);
        saveListButon->setObjectName(QStringLiteral("saveListButon"));
        saveListButon->setGeometry(QRect(1041, 571, 69, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1126, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAudio = new QMenu(menubar);
        menuAudio->setObjectName(QStringLiteral("menuAudio"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAudio->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionQuit_at_end_of_playlist);
        menuFile->addAction(actionQuit);
        menuAudio->addAction(actionVolume_up);
        menuAudio->addAction(actionVolume_down);
        menuAudio->addAction(actionMute);
        menuTools->addAction(actionRecord);
        menuTools->addAction(actionConvert_format);
        menuView->addAction(actionSwitch_mode);
        menuView->addAction(actionVisualizers);
        menuHelp->addAction(actionSettings);
        menuHelp_2->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File(s)", 0));
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionQuit_at_end_of_playlist->setText(QApplication::translate("MainWindow", "Quit at end of playlist", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionPlay_Pause->setText(QApplication::translate("MainWindow", "Play/Pause", 0));
        actionNext->setText(QApplication::translate("MainWindow", "Stop", 0));
        actionNet->setText(QApplication::translate("MainWindow", "Next", 0));
        actionPrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
        actionSkip_to_time->setText(QApplication::translate("MainWindow", "Skip to time", 0));
        actionVolume_up->setText(QApplication::translate("MainWindow", "Volume up", 0));
        actionVolume_down->setText(QApplication::translate("MainWindow", "Volume down", 0));
        actionMute->setText(QApplication::translate("MainWindow", "mute", 0));
        actionRecord->setText(QApplication::translate("MainWindow", "Record", 0));
        actionConvert_format->setText(QApplication::translate("MainWindow", "Convert format", 0));
        actionSwitch_mode->setText(QApplication::translate("MainWindow", "Switch mode", 0));
        actionVisualizers->setText(QApplication::translate("MainWindow", "visualizers", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        QTreeWidgetItem *___qtreewidgetitem = detailsTreeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Album", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Artists", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Length", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Title", 0));
        switchModeButton->setText(QApplication::translate("MainWindow", "...", 0));
        startTimeLabel->setText(QString());
        endTimeLabel->setText(QString());
        currentSongLabel->setText(QString());
        playAllButton->setText(QApplication::translate("MainWindow", "play all", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = playListTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Play list", 0));
        muteButton->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Controls", 0));
        stopButton->setText(QString());
        playButton->setText(QString());
        rateComboBox->clear();
        rateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1.0x", 0)
         << QApplication::translate("MainWindow", "2.0x", 0)
         << QApplication::translate("MainWindow", "0.5x", 0)
        );
        shuffleCheckBox->setText(QApplication::translate("MainWindow", "shuffle", 0));
        nextButton->setText(QString());
        previousButton->setText(QString());
        loopOneRadioButton->setText(QApplication::translate("MainWindow", "1", 0));
        loopAllRadioButton->setText(QApplication::translate("MainWindow", "All", 0));
        loopNoeRadioButton->setText(QApplication::translate("MainWindow", "none", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        chatButton->setText(QApplication::translate("MainWindow", "chat", 0));
        recordButton->setText(QApplication::translate("MainWindow", "record\n"
"audio", 0));
        convertButton->setText(QApplication::translate("MainWindow", "convert\n"
"media\n"
"format", 0));
        volumeLabel->setText(QApplication::translate("MainWindow", "99%", 0));
        fullScreenButton->setText(QApplication::translate("MainWindow", "full screen", 0));
        itemsLabel->setText(QString());
        clearListButton->setText(QApplication::translate("MainWindow", "clear", 0));
        openListButton->setText(QApplication::translate("MainWindow", "open", 0));
        saveListButon->setText(QApplication::translate("MainWindow", "save", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAudio->setTitle(QApplication::translate("MainWindow", "Audio", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuHelp_2->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
