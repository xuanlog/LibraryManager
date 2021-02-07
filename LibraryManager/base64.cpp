#include "base64.h"

QString Base64::Encrypt(const QString &text)
{
    QString ret = text.toUtf8().toBase64().toHex();
    return ret;
}

QString Base64::Decrypt(const QString &text)
{
    QString ret = QByteArray::fromHex(text.toUtf8());
    ret = QByteArray::fromBase64(text.toUtf8());
    return ret;
}

