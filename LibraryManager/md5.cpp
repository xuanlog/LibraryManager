#include "md5.h"
#include <QCryptographicHash>

QString MD5::Encrypt(const QString &text)
{
    // 16 位大写 MD5 加密
    QByteArray ba = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5);
    QString ret = ba.toHex().mid(8, 16).toUpper();
    return ret;
}

