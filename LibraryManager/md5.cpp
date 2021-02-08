#include "md5.h"
#include <QCryptographicHash>

QString MD5::Encrypt(const QString &text)
{
    QByteArray ba = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5);
    QString ret = ba.toHex().mid(8, 16).toUpper();
    return ret;
}

