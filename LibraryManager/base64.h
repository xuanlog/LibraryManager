#ifndef BASE64_H
#define BASE64_H

#include <QString>

class Base64
{
public:
    static QString Encrypt(const QString &text);
    static QString Decrypt(const QString &text);
};

#endif // BASE64_H
