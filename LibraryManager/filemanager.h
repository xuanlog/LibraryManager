#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>

class FileManager
{
public:
    static void write(const QString &key, const QString &value);
    static QString read(const QString &key);
    static void remove(const QString &key);
};

#endif // FILEMANAGER_H
