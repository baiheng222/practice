#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct Node
{
    DATA ListData;
    struct Node *ListNext;
}LLType;


LLType *AddEnd(LLType *head, DATA data)
{
    /*
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
    */
	
    LLType *node = (LLType*)malloc(sizeof(LLType));
	if (NULL == node)
	{
		LogE("malloc fail");
        return NULL;
	}
	
	node->ListData = data;
	node->ListNext = NULL;

    if (NULL == head)
    {
        head = node;
        return head;
    }
	
    LLType *htemp = head;
	while (htemp->ListNext != NULL)
	{
		htemp = htemp->ListNext;
	}
	
	htemp->ListNext = node;
	
	return head;
}

LLType *AddFirst(LLType *head, DATA data)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	
    LLType *node = (LLType*)malloc(sizeof(LLType));
	if (NULL == node)
	{
		LogE("malloc fail");
        return NULL;
	}
	
	node->ListData = data;
	node->ListNext = head;
    head = node;
	return head;
}

LLType *FindNode(LLType *head, char *name)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	LLType *node = NULL;
	LLType *htemp = head;
	
	while (htemp->ListNext != NULL)
	{
		if (0 == strcmp(htemp->ListData.name, name))
		{
			LogD("find node");
			node = htemp;
			break;
		}
		else
		{
			htemp = htemp->ListNext;
		}
	}
	
	return node;
}

LLType *InsertNode(LLType *head, char *name, DATA data)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	
	LLType *node = (LLType*)malloc(sizeof(LLType));
	if (NULL == node)
	{
		LogE("malloc erroe");
		return NULL;
	}
	
	node->ListData = data;
	node->ListNext = NULL;
	
	LLType *ntemp = NULL;
	
	LLType *htemp = head;
	
	while (htemp->ListNext != NULL)
	{
        if (strcmp(htemp->ListData.name, name) == 0)
		{
			ntemp = htemp;
			break;
		}
		else
		{
			htemp = htemp->ListNext;
		}
	}
	
	if (NULL != ntemp)
	{
		node->ListNext = ntemp->ListNext;
		ntemp->ListNext = node;
	}
	else
	{
		LogD("no name found");
		free(node);
		node = NULL;
	}
	
	return head;
}

LLType *DeleteNode(LLType *head, char *name)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	
	if (NULL == name)
	{
		LogE("name is NULL");
		return NULL;
	}
	
	
	LLType *htemp = head;
	LLType *node = head;
	//这里有个问题，如果heda就是要被删除的，会不会出错，需要测试一下
	while (htemp->ListNext != NULL)
	{
		if (0 == strcmp(htemp->ListData.name, name))
		{
			node->ListNext = htemp->ListNext;
			free(htemp);
			break;
		}
		else
		{
			node = htemp;
			htemp = htemp->ListNext;
			
		}
	}
	
	return head;
}

int ListLength(LLType* head)
{
    if (NULL == head)
    {
        LogE("head is NULL");
        return 0;
    }

    int len = 0;
    LLType * htemp = head;
    while (htemp->ListNext != NULL)
    {
        len++;
        htemp = htemp->ListNext;
    }

    return len;
}

void PrintAllNodes(LLType * head)
{
    if (NULL == head)
    {
        LogE("head is NULL");
        return;
    }

    LogI("Total nodes: %d", ListLength(head));

    LLType *htemp = head;
    while (htemp->ListNext != NULL)
    {
        LogI("name: %s,  age: %d", htemp->ListData.name, htemp->ListData.age);
        htemp = htemp->ListNext;
    }

    return;
}

int main(int argc, char **argv)
{
    init_mylogger();
    LLType *head = NULL, *node;
    DATA data;
    char name[10];
    int age;

    printf("输入数据（名字， 年龄）\n");
    do
    {
        scanf("%s%d", name, &age);
        if (age == 0)
        {
            LogI("输入数据非法，结束输入");
            break;
        }
        strcpy(data.name, name);
        data.age = age;

        head = AddEnd(head, data);
    }
    while (1);

    PrintAllNodes(head);

    return 0;
}
