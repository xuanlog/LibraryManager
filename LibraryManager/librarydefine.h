#ifndef LIBRARYDEFINE_H
#define LIBRARYDEFINE_H

#include <QString>
#include <QMessageBox>
#include <QDebug>

#define MAX_COLUMN 4

const QString kManagerAccount = "admin";

enum WIDGET_PAGE
{
    PAGE_LOGIN = 0,
    PAGE_REGISTERED,
    PAGE_PERSONAL,
    PAGE_STACK_ROOM,
    PAGE_MANAGER,
    PAGE_READER
};

enum STACK_ROOM_HEADER
{
    HEADER_NUM = 0,
    HEADER_NAME,
    HEADER_PUBLISH,
    HEADER_AUTHOR,
    HEADER_INVENTORY
};

#endif // LIBRARYDEFINE_H
