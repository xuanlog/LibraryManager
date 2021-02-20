#ifndef MD5_H
#define MD5_H

#include <QString>

/**
* @brief MD5 加密类
* 不可逆的加密文本
*/
class MD5
{
public:
    /**
    * @brief 加密函数
    *
    * @param text 需要加密的字符串
    * @return 加密后的结果
    */
    static QString Encrypt(const QString &text);
};

#endif // MD5_H
