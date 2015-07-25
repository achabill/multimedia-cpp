/********************************************************************************
** Form generated from reading UI file 'audiorecorder.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIORECORDER_H
#define UI_AUDIORECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioRecorder
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *audioDeviceBox;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QComboBox *containerBox;
    QComboBox *sampleRateBox;
    QComboBox *audioCodecBox;
    QLabel *label_5;
    QComboBox *channelsBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *constantQualityRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QSlider *qualitySlider;
    QRadioButton *constantBitrateRadioButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *bitrateBox;
    QPushButton *outputButton;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QLabel *levelLabel;
    QVBoxLayout *levelsLayout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AudioRecorder)
    {
        if (AudioRecorder->objectName().isEmpty())
            AudioRecorder->setObjectName(QStringLiteral("AudioRecorder"));
        AudioRecorder->resize(297, 374);
        centralwidget = new QWidget(AudioRecorder);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        audioDeviceBox = new QComboBox(centralwidget);
        audioDeviceBox->setObjectName(QStringLiteral("audioDeviceBox"));

        gridLayout_2->addWidget(audioDeviceBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        containerBox = new QComboBox(centralwidget);
        containerBox->setObjectName(QStringLiteral("containerBox"));

        gridLayout_2->addWidget(containerBox, 2, 1, 1, 1);

        sampleRateBox = new QComboBox(centralwidget);
        sampleRateBox->setObjectName(QStringLiteral("sampleRateBox"));

        gridLayout_2->addWidget(sampleRateBox, 3, 1, 1, 1);

        audioCodecBox = new QComboBox(centralwidget);
        audioCodecBox->setObjectName(QStringLiteral("audioCodecBox"));

        gridLayout_2->addWidget(audioCodecBox, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        channelsBox = new QComboBox(centralwidget);
        channelsBox->setObjectName(QStringLiteral("channelsBox"));

        gridLayout_2->addWidget(channelsBox, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        constantQualityRadioButton = new QRadioButton(groupBox);
        constantQualityRadioButton->setObjectName(QStringLiteral("constantQualityRadioButton"));
        constantQualityRadioButton->setChecked(true);

        gridLayout->addWidget(constantQualityRadioButton, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        qualitySlider = new QSlider(groupBox);
        qualitySlider->setObjectName(QStringLiteral("qualitySlider"));
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(qualitySlider, 1, 1, 1, 1);

        constantBitrateRadioButton = new QRadioButton(groupBox);
        constantBitrateRadioButton->setObjectName(QStringLiteral("constantBitrateRadioButton"));

        gridLayout->addWidget(constantBitrateRadioButton, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        bitrateBox = new QComboBox(groupBox);
        bitrateBox->setObjectName(QStringLiteral("bitrateBox"));
        bitrateBox->setEnabled(false);

        gridLayout->addWidget(bitrateBox, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 3);

        outputButton = new QPushButton(centralwidget);
        outputButton->setObjectName(QStringLiteral("outputButton"));

        gridLayout_3->addWidget(outputButton, 2, 0, 1, 1);

        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));

        gridLayout_3->addWidget(recordButton, 2, 1, 1, 1);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        gridLayout_3->addWidget(pauseButton, 2, 2, 1, 1);

        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));

        gridLayout_3->addWidget(levelLabel, 3, 0, 1, 1);

        levelsLayout = new QVBoxLayout();
        levelsLayout->setObjectName(QStringLiteral("levelsLayout"));

        gridLayout_3->addLayout(levelsLayout, 3, 1, 1, 2);

        AudioRecorder->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AudioRecorder);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AudioRecorder->setStatusBar(statusbar);

        retranslateUi(AudioRecorder);
        QObject::connect(constantQualityRadioButton, SIGNAL(toggled(bool)), qualitySlider, SLOT(setEnabled(bool)));
        QObject::connect(constantBitrateRadioButton, SIGNAL(toggled(bool)), bitrateBox, SLOT(setEnabled(bool)));
        QObject::connect(outputButton, SIGNAL(clicked()), AudioRecorder, SLOT(setOutputLocation()));
        QObject::connect(recordButton, SIGNAL(clicked()), AudioRecorder, SLOT(toggleRecord()));
        QObject::connect(pauseButton, SIGNAL(clicked()), AudioRecorder, SLOT(togglePause()));

        QMetaObject::connectSlotsByName(AudioRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *AudioRecorder)
    {
        AudioRecorder->setWindowTitle(QApplication::translate("AudioRecorder", "MainWindow", 0));
        label_4->setText(QApplication::translate("AudioRecorder", "Sample rate:", 0));
        label_2->setText(QApplication::translate("AudioRecorder", "Audio Codec:", 0));
        label->setText(QApplication::translate("AudioRecorder", "Input Device:", 0));
        label_3->setText(QApplication::translate("AudioRecorder", "File Container:", 0));
        label_5->setText(QApplication::translate("AudioRecorder", "Channels:", 0));
        groupBox->setTitle(QApplication::translate("AudioRecorder", "Encoding Mode:", 0));
        constantQualityRadioButton->setText(QApplication::translate("AudioRecorder", "Constant Quality:", 0));
        constantBitrateRadioButton->setText(QApplication::translate("AudioRecorder", "Constant Bitrate:", 0));
        outputButton->setText(QApplication::translate("AudioRecorder", "Output...", 0));
        recordButton->setText(QApplication::translate("AudioRecorder", "Record", 0));
        pauseButton->setText(QApplication::translate("AudioRecorder", "Pause", 0));
        levelLabel->setText(QApplication::translate("AudioRecorder", "Audio Level:", 0));
    } // retranslateUi

};

namespace Ui {
    class AudioRecorder: public Ui_AudioRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H
