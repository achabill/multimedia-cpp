/* Copyright (C) 2015, multimediaApp
 * Written by shadow-code <achbill12@gmail.com>
 *
 *
 *
 * ========LICENCE========
 * This file is part of the library LinBox.
 *
 * multimediaApp is free software: you can redistribute it and/or modify
 * it under the terms of the  GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  "Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 * ========LICENCE========
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListView>
#include <QTime>
#include <QDebug>
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //add paths to favorites
    favorites.append("C:/Users/Bill/Music");
    favorites.append("C:/Users/Bill/Downloads");

    itemChanged = false;
    setIcons(); //set window icons
    loadComputerTreeWidget();   //load direcotries in computerTreeWidget

    //initialize player controls
    muted = false;
    ui->playButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->previousButton->setEnabled(false);
    ui->slider->setEnabled(false);
    ui->itemsLabel->setText("0 items");
    ui->fullScreenButton->setEnabled(false);

    //initials
    videoOn = false;
    artOn = true;

    //create player and playlist
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;

    //set player playlist
    player->setPlaylist(playlist);

    //create videowidget at specified location
    videoWidget = new QVideoWidget(this);
    videoWidget->setGeometry(890,120,221,180);

    //create album art label at same position as video widget
    //with default album art
    defaultAlbumArt = "C:/Users/Bill/Desktop/default.jpg";
    albumArtLabel = new QLabel(this);
    albumArtLabel->setGeometry(890,120,221,180);

    //add album art widget the layout
    layout()->addWidget(albumArtLabel);

    //set the video ouput of the player
    player->setVideoOutput(videoWidget);

    //initialize chat dialog
    chatDialog = new ChatDialog();
    chatDialog->setModal(false);

    //instantiate pixmap with default album art
    QPixmap pixmap(defaultAlbumArt);
    //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    pixmap = pixmap.scaledToHeight(albumArtLabel->height());
    pixmap = pixmap.scaledToWidth(albumArtLabel->width());
    albumArtLabel->setPixmap(pixmap);

    //connections
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(on_value_changed(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(on_duration_changed(qint64)));
    connect(playlist,SIGNAL(currentIndexChanged(int)),this,SLOT(marquee(int)));
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(setState(QMediaPlayer::State)));
    connect(player,SIGNAL(metaDataChanged()),this,SLOT(on_metadataChanged()));
    connect(playlist,SIGNAL(currentIndexChanged(int)),this,SLOT(setItemCount(int)));
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(on_mediaStatusChanged(QMediaPlayer::MediaStatus)));
    connect(player,SIGNAL(videoAvailableChanged(bool)),this,SLOT(on_videoAvailableChanged(bool)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

//add child node to computer tree widget
void MainWindow::addChild(QTreeWidgetItem *item)
{
    //use QDir to manage directories and subdirectories
    QDir subDir(item->text(0));

    //file info of files in directory
    QFileInfoList list = subDir.entryInfoList();

    //check for non-empty directories
    if(list.size() > 0)
    {
        list.removeFirst(); //remove .
        list.removeFirst(); //remove ..
    }

    //add parent directories
    foreach(QFileInfo info, list)
    {
        //ensure file is a directory
        if(info.isDir())
        {
            //create child item with parent item
            QTreeWidgetItem *child = new QTreeWidgetItem(item);
            child->setText(0,info.absoluteFilePath());

            //add subdirectory
            item->addChild(child);
        }
    }
    //add sub-sub-directories recursively
    for(int i = 0; i < item->childCount(); i++)
        addChild(item->child(i));
}

//After adding directories to the computer tree widget,
//nodes have "absolute files names" as text
//replace these texts with the directory names.
void MainWindow::showFileNames(QTreeWidgetItem *item)
{
    QDir x = item->text(0);
    item->setText(0,x.dirName());

    //write directory names for this node and child nodes
    for(int i = 0; i < item->childCount(); i++)
        showFileNames(item->child(i));
}

//clicking an item on the computer tree widget will
//display the files in the clicked directory in the detials tree widget
void MainWindow::on_computerTreeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    //clear the widget first
    ui->detailsTreeWidget->clear();

    //instantiate empty treewidget item
    QTreeWidgetItem *parent = NULL;

    //initialize path with the text on the treewidget item clicked
    path = item->text(0);

    //get parent item of item clicked
    parent = item->parent();

    //recursively loop back through each node of the computer tree widget to
    //get absolute file path.
    //Rememer "showFilenName" overrode their aboslute paths
    while(parent)
    {
        path = parent->text(0) + "/" + path;
        parent = parent->parent();
    }
    std::string s = path.toStdString();
    s.erase(s.begin(),s.begin()+s.find_first_of('/')+1);
    path = QString::fromStdString(s);

    //find real path by cheching with favorites
    foreach(QString dir,favorites)
    {
        QString p = dir+"/"+path;
        if(QFile(p).exists())
        {
            path = p;
            break;
        }
    }
    QDir d(path);

    //list all files in directory
    foreach(QFileInfo info, d.entryInfoList())
    {
        //supported media format
        if(info.isFile() && (info.suffix() == "mp3" || info.suffix() == "wav" || info.suffix() == "flac" ||
                             info.suffix() == "MP3" || info.suffix() == "wma" || info.suffix() == "m4a"))
        {
            QTreeWidgetItem *x = new QTreeWidgetItem(ui->detailsTreeWidget);

            //use taglib to get file tags
            TagLib::FileName fn(info.absoluteFilePath().toStdWString().c_str());
            TagLib::FileRef ref(fn,true,TagLib::AudioProperties::Accurate);

            //file tags
            QString artist = ref.tag()->artist().toCString();
            QString album = ref.tag()->artist().toCString();
            QString title = ref.tag()->title().toCString();
            QString track = QString::number(ref.tag()->track());
            QString duration = "0:0";


            int length = ref.audioProperties()->length();
            if(length > 0)
                duration = QString::number(length/60) + QString(":") + QString::number(length%60);
            x->setText(0,track);
            x->setText(2,duration);
            x->setText(1,title);
            x->setText(3,artist);
            x->setText(4,album);

            //add item to tree widget
            ui->detailsTreeWidget->insertTopLevelItem(ui->detailsTreeWidget->topLevelItemCount(),x);

        }
        //Taglib failed to provide metadata for video files.
        //Until a better lib is used,
        //show filenames on the details tree widget
        if(info.isFile() && (info.suffix() == "mp4" || info.suffix() == "MP4" ))
        {
            QTreeWidgetItem *x = new QTreeWidgetItem(ui->detailsTreeWidget);
            x->setText(1,info.fileName());
            ui->detailsTreeWidget->insertTopLevelItem(ui->detailsTreeWidget->topLevelItemCount(),x);
        }

    }
}

//clicking an item here should append the song to the playlist
//and start playing the song
//if the item is already in the playlist, dont add it again
//restart the song
void MainWindow::on_detailsTreeWidget_itemDoubleClicked(QTreeWidgetItem *item,int column)
{
    bool inPlayList = false; //whether item is already in playlist widget

    QDir d(path);
    foreach(QFileInfo info , d.entryInfoList())
    {


        //Question: why is this necessary?
        //Answer: check the algorithm. Remeber that computer tree widget does not show absolute path
        if(info.isFile() && (info.suffix() == "mp3" || info.suffix() == "wav" || info.suffix() == "flac" ||
                             info.suffix() == "wma" || info.suffix() == "m4a"))
        {

            TagLib::FileName fn(info.absoluteFilePath().toStdWString().c_str());
            TagLib::FileRef ref(fn,true,TagLib::AudioProperties::Accurate);

            QString artist = ref.tag()->artist().toCString();
            QString title = ref.tag()->title().toCString();

            //is this really the file?
            if((artist == item->text(3)) && (title == item->text(1))
                    || item->text(1) == info.fileName())
            {

                    for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
                    {
                        if(item->text(1) == ui->playListTreeWidget->topLevelItem(i)->text(0))
                        {
                            player->stop();
                            playlist->setCurrentIndex(i);
                            player->play();
                            ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(i));
                            inPlayList = true;
                            break;
                        }
                    }
                    if(inPlayList)
                        break;

                    playlist->addMedia(QMediaContent(QUrl::fromLocalFile(info.absoluteFilePath())));

                    QTreeWidgetItem *x = new QTreeWidgetItem(ui->playListTreeWidget);
                    x->setText(0,item->text(1));
                    x->setFlags(x->flags() & Qt::ItemIsDropEnabled);
                    ui->playListTreeWidget->insertTopLevelItem(ui->playListTreeWidget->topLevelItemCount(),x);

                    ui->playListTreeWidget->setCurrentItem(x);
                    break;
            }
        }
    }
    //Remember video files are displayed on the details tree widget with file names
    foreach(QFileInfo info , d.entryInfoList())
    {
        //supported media
        if(info.isFile() && (info.suffix() == "mp4" || info.suffix() == "MP4" ))
        {
            if(info.fileName() == item->text(1))
            {

                for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
                {
                    if(item->text(1) == ui->playListTreeWidget->topLevelItem(i)->text(0))
                    {
                        player->stop();
                        playlist->setCurrentIndex(i);
                        player->play();
                        ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(i));
                        inPlayList = true;
                        break;
                    }
                }
                if(inPlayList)
                    break;

                playlist->addMedia(QMediaContent(QUrl::fromLocalFile(info.absoluteFilePath())));

                QTreeWidgetItem *x = new QTreeWidgetItem(ui->playListTreeWidget);
                x->setText(0,item->text(1));
                x->setFlags(x->flags() & Qt::ItemIsDropEnabled);
                ui->playListTreeWidget->insertTopLevelItem(ui->playListTreeWidget->topLevelItemCount(),x);

                break;
            }
        }
    }
    if(!inPlayList)
    {
        //move playlist to newly added media
        playlist->setCurrentIndex(ui->playListTreeWidget->topLevelItemCount()-1);
        player->play();
    }
}

//load computer tree widget from paths in favorites
void MainWindow::loadComputerTreeWidget()
{
    int j = 0;
    for(int i = 0; i < favorites.size(); i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->computerTreeWidget);
        item->setText(0,favorites.at(i));
        ui->computerTreeWidget->insertTopLevelItem(j++,item);
    }
    //add sub directories
    for(int i = 0; i < ui->computerTreeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *item = ui->computerTreeWidget->topLevelItem(i);
        addChild(item);
    }
    //change absolute paths to file names
    for(int i = 0; i < ui->computerTreeWidget->topLevelItemCount(); i++)
        showFileNames(ui->computerTreeWidget->topLevelItem(i));
}
//set common player icons
void MainWindow::setIcons()
{
    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->stopButton->setEnabled(false);
    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
}
void MainWindow::on_loopOneRadioButton_clicked(bool checked)
{
   playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::CurrentItemInLoop);
}

void MainWindow::on_loopAllRadioButton_clicked(bool checked)
{
    playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
}

void MainWindow::on_loopNoeRadioButton_clicked(bool checked)
{
    playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Sequential);
}

void MainWindow::on_computerTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    return;
}

//move to next item
//if current item is last, move to first
void MainWindow::on_nextButton_clicked()
{
    if(playlist->currentIndex() == ui->playListTreeWidget->topLevelItemCount()-1)
    {
        player->stop();
        playlist->setCurrentIndex(0);
        ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(0));
        player->play();
        return;
    }
    playlist->next();
    for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
    {
        if(ui->playListTreeWidget->topLevelItem(i)->text(0) == ui->playListTreeWidget->currentItem()->text(0))
        {
            ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(i));
            break;
        }
    }
}
//move to previous item
//if current item is fisrt, move to last item
void MainWindow::on_previousButton_clicked()
{
    if(playlist->currentIndex() == 0)
    {
        player->stop();
        playlist->setCurrentIndex(ui->playListTreeWidget->topLevelItemCount()-1);
        ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(ui->playListTreeWidget->topLevelItemCount() - 1));
        player->play();
        return;
    }
    playlist->previous();
    for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
    {
        if(ui->playListTreeWidget->topLevelItem(i)->text(0) == ui->playListTreeWidget->currentItem()->text(0))
        {
            ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(i-1));
            break;
        }
    }
}
//stop player
void MainWindow::on_stopButton_clicked()
{
    player->stop();
}

//time of current playing media
void MainWindow::on_value_changed(qint64 value)
{
    ui->slider->setValue(value);
    QTime currentTime((value/36000000)%24,(value/60000)%60,(value/1000)%60);
    QTime totalTime((duration/36000000)%24,(duration/60000)%60,(duration/1000)%60);
    QString format = "mm:ss";
    if (duration > 3600)
        format = "hh:mm:ss";
    ui->startTimeLabel->setText(currentTime.toString(format));
    ui->endTimeLabel->setText(totalTime.toString(format));
}
//move slider position
void MainWindow::on_duration_changed(qint64 value)
{
    ui->slider->setMaximum(value);
    duration = value;

    if(artOn)
    {
        QString s = playlist->currentMedia().canonicalUrl().toLocalFile();
        if(QFileInfo(s).suffix() == "mp3")
        {
            TagLib::MPEG::File mp3File(s.toStdString().c_str());
            TagLib::ID3v2::Tag* mp3Tag;
            TagLib::ID3v2::AttachedPictureFrame *picFrame;
            TagLib::ID3v2::FrameList list;
            mp3Tag = mp3File.ID3v2Tag();

            if(mp3Tag)
            {

                list = mp3Tag->frameListMap()["APIC"];
                if(!list.isEmpty())
                {
                    picFrame = static_cast<TagLib::ID3v2::AttachedPictureFrame *>(list.front());

                    QImage image;
                    image.loadFromData((const uchar*)picFrame->picture().data(),picFrame->picture().size());
                    QPixmap pixmap(QPixmap::fromImage(image));
                    //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                    pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                    pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                    albumArtLabel->setPixmap(pixmap);
                }
                else
                {
                    QPixmap pixmap(defaultAlbumArt);
                    //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                    pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                    pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                    albumArtLabel->setPixmap(pixmap);
                }
            }
            else
            {
                QPixmap pixmap(defaultAlbumArt);
                //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                albumArtLabel->setPixmap(pixmap);
            }
        }
        if(QFileInfo(s).suffix() == "m4a")
        {
            TagLib::MP4::File f(s.toStdString().c_str());
            TagLib::MP4::Tag* tag = f.tag();

            if(tag)
            {
                TagLib::MP4::ItemListMap itemsListMap = tag->itemListMap();

                if(itemsListMap.isEmpty())
                {
                    QPixmap pixmap(defaultAlbumArt);
                    //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                    pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                    pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                    albumArtLabel->setPixmap(pixmap);
                }
                else
                {
                    TagLib::MP4::Item coverItem = itemsListMap["covr"];
                    TagLib::MP4::CoverArtList coverArtList = coverItem.toCoverArtList();
                    TagLib::MP4::CoverArt coverArt = coverArtList.front();
                    QImage image;
                    image.loadFromData((const uchar *) coverArt.data().data(),coverArt.data().size());
                    QPixmap pixmap(QPixmap::fromImage(image));
                    //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                    pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                    pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                    albumArtLabel->setPixmap(pixmap);
                }
            }
            else
            {
                QPixmap pixmap(defaultAlbumArt);
                //pixmap.scaled(albumArtLabel->height(),albumArtLabel->width(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
                pixmap = pixmap.scaledToHeight(albumArtLabel->height(),Qt::FastTransformation);
                pixmap = pixmap.scaledToWidth(albumArtLabel->width(),Qt::FastTransformation);
                albumArtLabel->setPixmap(pixmap);
            }
        }
    }
}
//slider moved
void MainWindow::on_slider_valueChanged(int value)
{
    player->setPosition(value);
}

void MainWindow::on_muteButton_clicked()
{
    ui->muteButton->setIcon(style()->standardIcon(!muted ? QStyle::SP_MediaVolumeMuted: QStyle::SP_MediaVolume));
    player->setMuted(!muted);
    muted = !muted;
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
    ui->volumeLabel->setText(QString::fromStdString(std::to_string(value))+"%");
}

//clicking an item on the playlist plays the item clicked
void MainWindow::on_playListTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    //get current index of item clicked in playlist
    for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
    {
        if(ui->playListTreeWidget->topLevelItem(i)->text(0) == item->text(0))
        {
            player->stop();
            playlist->setCurrentIndex(i);
            player->play();
            break;
        }
    }
}
//display name of current playing medai on top screen
void MainWindow::marquee(int index)
{
    ui->currentSongLabel->setText(ui->playListTreeWidget->topLevelItem(index)->text(0));
    ui->playListTreeWidget->setCurrentItem(ui->playListTreeWidget->topLevelItem(index));
    setWindowTitle(ui->playListTreeWidget->topLevelItem(index)->text(0));
}
void MainWindow::setState(QMediaPlayer::State state)
{
    switch (state)
    {
    case QMediaPlayer::StoppedState:
        ui->stopButton->setEnabled(false);
        ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        ui->nextButton->setEnabled(false);
        ui->previousButton->setEnabled(false);
        break;
    case QMediaPlayer::PlayingState:
        ui->slider->setEnabled(true);
        ui->stopButton->setEnabled(true);
        ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        ui->playButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->previousButton->setEnabled(true);
        break;
    case QMediaPlayer::PausedState:
        ui->stopButton->setEnabled(true);
        ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}
//play|pause button clicked
void MainWindow::on_playButton_clicked()
{
    switch(player->state())
    {
    case QMediaPlayer::PlayingState:
        player->pause();
        break;
    case QMediaPlayer::PausedState:
         player->play();
         break;
    case QMediaPlayer::StoppedState:
        for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
        {
            if(ui->playListTreeWidget->topLevelItem(i)->text(0) == ui->playListTreeWidget->currentItem()->text(0))
            {
                playlist->setCurrentIndex(i);
                player->play();
                break;
            }
        }
        break;
    }
}
//shuffle checked
void MainWindow::on_shuffleCheckBox_toggled(bool checked)
{
    if(checked)
        playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);
    else
        playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Sequential);
}

void MainWindow::on_actionOpen_File_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this,
                                                          "select one or more files to open",
                                                          favorites.at(0),
                                                          "media (*.mp3,*.mp4,*.wma,*.m4a,*.wav,*.flac");
    if(fileNames.size() == 0)
        return;
    for(int i = 0; i < fileNames.size(); i++)
    {
        QFileInfo info(fileNames.at(i));
        if(info.isFile() && (info.suffix() == "mp3" || info.suffix() == "wav" || info.suffix() == "flac" ||
                             info.suffix() == "MP3" || info.suffix() == "wma" || info.suffix() == "m4a"))
        {
            TagLib::FileName fn(info.absoluteFilePath().toStdWString().c_str());
            TagLib::FileRef ref(fn,true,TagLib::AudioProperties::Accurate);


            QString title = ref.tag()->title().toCString();

            QTreeWidgetItem *item = new QTreeWidgetItem(ui->playListTreeWidget);
            item->setText(0,title.isEmpty()
                          ?info.fileName()
                         :title);
            item->setFlags(item->flags() & Qt::ItemIsDropEnabled);
            ui->playListTreeWidget->insertTopLevelItem(i+ui->playListTreeWidget->topLevelItemCount(),item);
            playlist->addMedia(QMediaContent(QUrl::fromLocalFile(info.absoluteFilePath())));

        }
        else
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->playListTreeWidget);
            item->setFlags(item->flags() & Qt::ItemIsDropEnabled);
            ui->playListTreeWidget->insertTopLevelItem(i+ui->playListTreeWidget->topLevelItemCount(),item);
            playlist->addMedia(QMediaContent(QUrl::fromLocalFile(info.absoluteFilePath())));
        }
    }

    player->stop();
    playlist->setCurrentIndex(playlist->mediaCount()-fileNames.size());
    player->play();
}
void MainWindow::setItemCount(int count)
{
    ui->itemsLabel->setText(QString::number(ui->playListTreeWidget->topLevelItemCount()) + " items");
}
void MainWindow::on_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
   if(status == QMediaPlayer::MediaStatus::EndOfMedia)
    { 
        if(playlist->mediaCount() == playlist->currentIndex())
        {
            player->stop();
            ui->slider->setValue(0);
            setWindowTitle("default");
            ui->currentSongLabel->setText("");
        }
    }
}

//helper function. checks whether string s1 is contained in string s2
bool MainWindow::contains(QString s1, QString s2)
{
    for (int i = 0; i < s1.length() - s2.length(); i++)
    {
        if (QString::fromStdString(s1.toStdString().substr(i, s2.length())) == s2)
            return true;
    }
    return false;
}
void MainWindow::on_videoAvailableChanged(bool available)
{
    if(available)
    {
        ui->fullScreenButton->setEnabled(true);
        if(!videoOn)
        {
            if(artOn)
            {
                layout()->removeWidget(albumArtLabel);
                delete albumArtLabel;
                albumArtLabel = new QLabel(this);
                albumArtLabel->setGeometry(890,120,221,180);
            }
            layout()->addWidget(videoWidget);
            ui->fullScreenButton->setEnabled(true);

            connect(ui->fullScreenButton, SIGNAL(clicked(bool)),videoWidget, SLOT(setFullScreen(bool)));
            connect(videoWidget, SIGNAL(fullScreenChanged(bool)),ui->fullScreenButton, SLOT(setChecked(bool)));

            if (ui->fullScreenButton->isChecked())
                videoWidget->setFullScreen(true);
            else
                videoWidget->setFullScreen(false);

            videoOn = true;
            artOn = false;
        }
    }
    else
    {
        if(!artOn)
        {
            if(videoOn)
            {
                layout()->removeWidget(videoWidget);
            }
            layout()->addWidget(albumArtLabel);
            ui->fullScreenButton->setEnabled(false);

            disconnect(ui->fullScreenButton, SIGNAL(clicked(bool)),videoWidget, SLOT(setFullScreen(bool)));
            disconnect(videoWidget, SIGNAL(fullScreenChanged(bool)),ui->fullScreenButton, SLOT(setChecked(bool)));
            videoWidget->setFullScreen(false);
            videoOn = false;
            artOn = true;
        }
    }
}

void MainWindow::on_playAllButton_clicked()
{

    player->stop(); //stop player

    ui->playListTreeWidget->clear();      //clear playlist widget
    playlist->clear();                    //clear playlist

    QTreeWidgetItem *parent = NULL;
    path = ui->computerTreeWidget->currentItem()->text(0);
    parent = ui->computerTreeWidget->currentItem()->parent();

    //recursively loop back through each node of the computer tree widget to
    //get absolute file path.
    //Rememer "showFilenName" overrode their aboslute paths
    while(parent)
    {
       path = parent->text(0) + "/" + path;
       parent = parent->parent();
    }
    std::string s = path.toStdString();
    s.erase(s.begin(),s.begin()+s.find_first_of('/')+1);
    path = QString::fromStdString(s);

    foreach(QString dir,favorites)
    {
        QString p = dir+"/"+path;
        if(QDir(p).exists())
        {
            path = p;
            break;
        }
    }

    QDir d(path);
    //list all files in directory
    foreach(QFileInfo info, d.entryInfoList())
    {
        //supported media are shown below
        //audio
        if(info.isFile() && (info.suffix() == "mp3" || info.suffix() == "wav" || info.suffix() == "flac" ||
                             info.suffix() == "MP3" || info.suffix() == "wma" || info.suffix() == "m4a"))
        {
            TagLib::FileName fn(info.absoluteFilePath().toStdWString().c_str());
            TagLib::FileRef ref(fn,true,TagLib::AudioProperties::Accurate);


            QString title = ref.tag()->title().toCString();

            QTreeWidgetItem *x = new QTreeWidgetItem(ui->playListTreeWidget);
            title.isEmpty() ? x->setText(0,info.fileName()) : x->setText(0,title);

            x->setFlags(x->flags() & Qt::ItemIsDropEnabled);
            ui->playListTreeWidget->insertTopLevelItem(ui->playListTreeWidget->topLevelItemCount(),x);
            playlist->addMedia(QUrl::fromLocalFile(info.absoluteFilePath()));

        }
        //Taglib failed to provide metadata for video files.
        //until a better lib is used,
        //show filenames on the details tree widget
        if(info.isFile() && (info.suffix() == "mp4" || info.suffix() == "MP4" ))
        {
            QTreeWidgetItem *x = new QTreeWidgetItem(ui->playListTreeWidget);
            x->setText(0,info.fileName());
            x->setFlags(x->flags() & Qt::ItemIsDropEnabled);
            ui->playListTreeWidget->insertTopLevelItem(ui->playListTreeWidget->topLevelItemCount(),x);
            playlist->addMedia(QUrl::fromLocalFile(info.absoluteFilePath()));
        }

    }
    playlist->setCurrentIndex(0);
    player->play();
}

void MainWindow::on_chatButton_clicked()
{
    QMessageBox::information(this, tr("Chat"),
                             tr("Launch several instances of this "
                                "program on your local network and "
                                "start chatting!"));
    chatDialog->show();
}

void MainWindow::on_recordButton_clicked()
{
    recorder = new AudioRecorder();
    recorder->show();
}

void MainWindow::on_rateComboBox_currentIndexChanged(int index)
{
    std::string s_rate = ui->rateComboBox->itemText(index).toStdString();
    std::string ss_rate;
    for(int i = 0; i < s_rate.length(); i++)
        ss_rate+=s_rate.at(i);
    player->setPlaybackRate(QString::fromStdString(ss_rate).toDouble());
}

void MainWindow::on_clearListButton_clicked()
{
    playlist->clear();
    player->stop();
    ui->playListTreeWidget->clear();
    ui->slider->setValue(0);
    ui->currentSongLabel->setText("");
    ui->startTimeLabel->setText("");
    ui->endTimeLabel->setText("");
}
void MainWindow::on_playListTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    int c,p;
    for(int i = 0; i < ui->playListTreeWidget->topLevelItemCount(); i++)
    {
        if(ui->playListTreeWidget->topLevelItem(i)->text(0) == current->text(0))
            c = i;
        if(ui->playListTreeWidget->topLevelItem(i)->text(0) == previous->text(0))
            p = i;
    }
    QMediaContent media = playlist->media(p);
    playlist->removeMedia(p);
    playlist->insertMedia(c,media);
}
