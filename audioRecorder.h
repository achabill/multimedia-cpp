#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMediaRecorder>
#include <QUrl>
class QAudioRecorder;
class QAudioProbe;
class QAudioBuffer;

class QAudioLevel;


namespace Ui {
class AudioRecorder;
}

class AudioRecorder : public QMainWindow
{
    Q_OBJECT

public:
    AudioRecorder(QWidget *parent = 0);
    ~AudioRecorder();

public slots:
    void processBuffer(const QAudioBuffer&);

private slots:
    void setOutputLocation();
    void togglePause();
    void toggleRecord();

    void updateStatus(QMediaRecorder::Status);
    void onStateChanged(QMediaRecorder::State);
    void updateProgress(qint64 pos);
    void displayErrorMessage();

private:
    void clearAudioLevels();

    Ui::AudioRecorder *ui;

    QAudioRecorder *audioRecorder;
    QAudioProbe *probe;
    QList<QAudioLevel*> audioLevels;
    bool outputLocationSet;

};

#endif // AUDIORECORDER_H
