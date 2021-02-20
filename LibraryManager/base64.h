#ifndef BASE64_H
#define BASE64_H

#include <QString>

/**
* @brief base64 加解密类
* 加解密文本
*/
class Base64
{
public:
    /**
    * @brief 加密函数
    *
    * @param text 需要加密的字符串
    * @return 加密后的结果
    */
    static QString Encrypt(const QString &text);

    /**
    * @brief 解密函数
    *
    * @param text 需要解密的字符串
    * @return 解密后的结果
    */
    static QString Decrypt(const QString &text);
};

#endif // BASE64_H
