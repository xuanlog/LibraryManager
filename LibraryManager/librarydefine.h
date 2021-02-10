#ifndef LIBRARYDEFINE_H
#define LIBRARYDEFINE_H

#include <QString>
#include <QMessageBox>
#include <QDebug>

#define MAX_BORROW 5
#define MD5_LENGTH 16
#define MIN_LENGTH 6

const QString kVersion = "1.0.3";
const QString kManagerAccount = "admin";

enum WIDGET_PAGE
{
    PAGE_LOGIN = 0,
    PAGE_RESET,
    PAGE_REGISTERED,
    PAGE_PERSONAL,
    PAGE_STACK_ROOM,
    PAGE_MANAGER,
    PAGE_READER
};

enum STACK_ROOM_HEADER
{
    STACK_NUM = 0,
    STACK_NAME,
    STACK_PUBLISH,
    STACK_AUTHOR,
    STACK_INVENTORY
};

enum PERSONAL_CENTER_HEADER
{
    PERSONAL_LTIME = 0,
    PERSONAL_RTIME,
    PERSONAL_NUM,
    PERSONAL_NAME,
    PERSONAL_PUBLISH,
    PERSONAL_INVENTORY
};

enum USER_INFO_HEADER
{
    USER_ACCOUNT = 0,
    USER_PASSWORD,
    USER_BORROWED,
    USER_TOTAL
};

enum STATUS
{
    STATUS_NORMAL = 0,
    STATUS_REBORROW,
    STATUS_OVERDUE
};

enum SELECT_FLAG
{
    SELECT_OK = 0,
    SELECT_CANCEL
};

#endif // LIBRARYDEFINE_H
