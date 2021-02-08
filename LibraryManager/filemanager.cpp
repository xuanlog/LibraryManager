#include "filemanager.h"
#include <QtCore>
#include "md5.h"

void FileManager::write(const QString &key, const QString &value)
{   
    QString path = MD5::Encrypt("UserData.ini");
    path = QCoreApplication::applicationDirPath() + QString("/Data/%1").arg(path);
    QSettings *setting = new QSettings(path, QSettings::IniFormat);
    setting->setValue(key, value);
    delete setting;
}

QString FileManager::read(const QString &key)
{
    QString path = MD5::Encrypt("UserData.ini");
    path = QCoreApplication::applicationDirPath() + QString("/Data/%1").arg(path);
    QSettings* setting = new QSettings(path, QSettings::IniFormat);
    QString ret = setting->value(key).toString();
    delete setting;
    return ret;
}

void FileManager::remove(const QString &key)
{
    QString path = MD5::Encrypt("UserData.ini");
    path = QCoreApplication::applicationDirPath() + QString("/Data/%1").arg(path);
    QSettings* setting= new QSettings(path, QSettings::IniFormat);
    setting->remove(key);
    delete setting;
}
