#include <stdio.h>
#include <string.h>

#include "../lib/mylogger.h"

#define MAXLEN 100
#define OK                   0
#define ERROR               -1
#define INVALIDPOS          -2
#define LISTFULL            -3
typedef struct 
{
    char name[10];
    int age;
}DATA;

typedef struct
{
    DATA ListData[MAXLEN + 1];
    int ListLen;
}SLType;

void initList(SLType *list)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return;
    }

    list->ListLen = 0;
    return;
}

int listLen(SLType *list)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }

    return list->ListLen;
}

int listInsert(SLType *list, int n, DATA data)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }

    if (list->ListLen >= MAXLEN)
    {
        LogW("List is full!!!");
        return LISTFULL;
    }

    if ((n < 1) || (n > list->ListLen -1))
    {
        LogE("invalid insert position");
        return INVALIDPOS;
    }
    
    int i;
    for (i = list->ListLen; i >= n; i--)
    {
        list->ListData[i+1] = list->ListData[i];
        //list->ListData[i+1].age = list->ListData[i].age;
        //strcpy(list->ListData[i+1].name, list->ListData[i].name);
    }

    //list->ListData[n].age = data.age;
    //strcpy(list->ListData[n].name, data.name);
    list->ListData[n] = data;

    list->ListLen = list->ListLen +1;

    return OK;
}

int listAdd(SLType *list, DATA data)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }

    if (list->ListLen >= MAXLEN)
    {
        LogW("List is full!!!");
        return LISTFULL;
    }

    list->ListLen++;
    list->ListData[list->ListLen] = data;

    return OK;

}

int listDel(SLType *list, int n)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }
 
    if (n < 1 || n > list->ListLen)
    {
        LogW("Invalid del postion");
        return INVALIDPOS;
    }
    int i;
    for (i = n; i < list->ListLen; i++)
    {
        list->ListData[i] = list->ListData[i+1];
    } 
    
    list->ListLen--;

    return OK;

}

DATA *listGetByNum(SLType *list, int n)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return NULL;
    }

    if (n < 1 || n > list->ListLen)
    {
        LogW("Invalid del postion");
        return NULL;
    }

    return &(list->ListData[n]);

}

int listGetByName(SLType *list , char *name)
{
    int ret = INVALIDPOS;

    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }

    if (NULL == name)
    {
        LogE("name is NULL");
        return ERROR;
    }
    int i;
    for (i = 1 ; i <= list->ListLen; i++)
    {
        if (strcmp(name, list->ListData[i].name) == 0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int listPrintAll(SLType *list)
{
    if (NULL == list)
    {
        LogE("list is NULL");
        return ERROR;
    }
    
    int i; 
    for (i = 1; i <= list->ListLen; i++)
    {
        LogI("itme[%d] -- name: %s  age: %d  \n", i, list->ListData[i].name, list->ListData[i].age);
    }

    return OK;

}

int main(int argc, char **argv)
{
    init_mylogger();

    int i;  
    int age;
    SLType list;
    DATA data;
    DATA *pdata = NULL;
    char name[10];

    printf("顺序表演示程序!\n");
    
    initList(&list);
    LogI("init finished!!!!i\n");

    do
    {
        printf("输入添加的结点（名字 年龄）：\n");
        fflush(stdin);
        scanf("%s%d", name, &age);
        data.age = age;
        strcpy(data.name, name);
        if (0 != data.age)
        {
            if (OK != listAdd(&list, data))
            {
                LogD("break from lisAdd");
                break;
            }
        }
        else
        {
            LogD("break cause age is 0");
            break;
        }
    }
    while(1);

    printf("\n 顺序表中的结点为: \n");
    listPrintAll(&list);
    
    printf("\n 要取出的结点的序号: ");
    scanf("%d", &i);

    pdata = listGetByNum(&list, i);

    if (NULL != pdata)
    {
        printf("第 %d个结点为： %s , %d\n", i, pdata->name, pdata->age);
    }

    pdata = NULL;
    i = INVALIDPOS;

    printf("\n 要查找的名字：");
    scanf("%s", name);
    i = listGetByName(&list, name);
    pdata = listGetByNum(&list, i);
    if (NULL != pdata)
    {
        printf("第 %d个结点为： %s , %d\n", i, pdata->name, pdata->age);
    }

    printf("\n 要删除的结点序号：");
    scanf("%d", &i);
    
    int ret = listDel(&list, i);
    if (ret == OK)
    {
        printf("结点已经删除\n");
    }

    printf("剩余结点为\n");
    listPrintAll(&list);


    printf("\n 插入结点(名字 年龄 位置");
    scanf("%s%d%d", name, &age, &i);
    strcpy(data.name, name);
    data.age = age;
    listInsert(&list, i, data); 

    printf("\n 插入后的结点");
    listPrintAll(&list);

    getchar();

    return 0;
}
