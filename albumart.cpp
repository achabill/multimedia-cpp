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

#include "albumart.h"
#include <QFileInfo>
AlbumArt::AlbumArt()
{

}

AlbumArt::~AlbumArt()
{

}
QPixmap* AlbumArt::albumArt(QString file)
{
    if(QFileInfo(file).suffix() == "mp3")
    {
        TagLib::MPEG::File mp3File(file.toStdString().c_str());
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
              //  ui->label->setPixmap(QPixmap::fromImage(QImage(picFrame->picture().data())));
                QImage image;
                image.loadFromData((const uchar*)picFrame->picture().data(),picFrame->picture().size());
                art = new QPixmap(QPixmap::fromImage(image));

            }
        }
    }
    if(QFileInfo(file).suffix() == "m4a")
    {
        TagLib::MP4::File f(file.toStdString().c_str());
        TagLib::MP4::Tag* tag = f.tag();
        TagLib::MP4::ItemListMap itemsListMap = tag->itemListMap();
        TagLib::MP4::Item coverItem = itemsListMap["covr"];
        TagLib::MP4::CoverArtList coverArtList = coverItem.toCoverArtList();
        TagLib::MP4::CoverArt coverArt = coverArtList.front();
        QImage image;
        image.loadFromData((const uchar *) coverArt.data().data(),coverArt.data().size());
        art = new QPixmap(QPixmap::fromImage(image));
    }
    return art;
}
