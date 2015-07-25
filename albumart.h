#ifndef ALBUMART_H
#define ALBUMART_H

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/flacfile.h>
#include <taglib/id3v2frame.h>
#include <taglib/mp4file.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>
#include <QPixmap>


class AlbumArt
{
public:
    AlbumArt();
    ~AlbumArt();
    QPixmap* albumArt(QString file);
private:
    QPixmap* art;
};

#endif // ALBUMART_H
