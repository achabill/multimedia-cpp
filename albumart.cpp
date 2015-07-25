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
