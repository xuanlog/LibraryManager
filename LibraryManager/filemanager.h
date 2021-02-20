#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>

/**
* @brief 文档管理类
* 读写配置文档
*/
class FileManager
{
public:
    /**
    * @brief 写函数
    * @detail 将信息写到配置文档
    *
    * @param key 信息的名称，如姓名
    * @param value 信息的内容，如张三
    */
    static void write(const QString &key, const QString &value);

    /**
    * @brief 读函数
    * @detail 从配置文档读取信息
    *
    * @param key 信息的名称
    * @return 信息的内容
    */
    static QString read(const QString &key);

    /**
    * @brief 删除函数
    * @detail 删除不需要的信息
    *
    * @param key 需要删除的信息名称
    */
    static void remove(const QString &key);
};

#endif // FILEMANAGER_H
