#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTreeWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QWidget>
#include <QStringList>
#include <QVideoWidget>
#include <QFileDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <taglib/id3v2tag.h>
#include <taglib/flacfile.h>
#include <taglib/id3v2frame.h>
#include <taglib/mp4file.h>
#include <taglib/mpegfile.h>
#include <taglib/fileref.h>
#include <taglib/attachedpictureframe.h>
#include "chatdialog.h"
#include "audiorecorder.h"
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addChild(QTreeWidgetItem *);
    void showFileNames(QTreeWidgetItem *);
    void loadComputerTreeWidget();
    void setIcons();
    bool contains(QString s1, QString s2);

    bool itemChanged;
private slots:
    void on_computerTreeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_detailsTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_loopOneRadioButton_clicked(bool checked);

    void on_loopAllRadioButton_clicked(bool checked);

    void on_loopNoeRadioButton_clicked(bool checked);

    void on_computerTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_nextButton_clicked();

    void on_previousButton_clicked();

    void on_stopButton_clicked();

    void on_value_changed(qint64 value);

    void on_duration_changed(qint64 value);

    void on_slider_valueChanged(int value);

    void on_muteButton_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_playListTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void marquee(int);

    void setState(QMediaPlayer::State state);

    void on_playButton_clicked();

    void on_shuffleCheckBox_toggled(bool checked);

    void on_actionOpen_File_triggered();

    void setItemCount(int);

    void on_mediaStatusChanged(QMediaPlayer::MediaStatus);

    void on_videoAvailableChanged(bool available);


    void on_playAllButton_clicked();

    void on_chatButton_clicked();

    void on_recordButton_clicked();

    void on_rateComboBox_currentIndexChanged(int index);

    void on_clearListButton_clicked();


    void on_playListTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    Ui::MainWindow *ui;
    QStringList favorites;
    QString path;
    qint64 duration;
    QString current;
    bool muted;
    QLabel *albumArtLabel;
    QVideoWidget *videoWidget;
    QString defaultAlbumArt;
    QHBoxLayout *videoLayout;
    QHBoxLayout *albumArtLayout;
    bool videoOn;
    bool artOn;
    ChatDialog *chatDialog;
    AudioRecorder *recorder;

};

#endif // MAINWINDOW_H
