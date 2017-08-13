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

typedef struct Node
{
    DATA ListData;
    struct Node *ListNext;
}LLType;


LLType *AddEnd(LLType *head, DATA data)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	
	Node *node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		LogE("malloc fail");
		return NULL:
	}
	
	node->ListData = data;
	node->ListNext = NULL;
	
	Node *htemp = head;
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
	
	Node *node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		LogE("malloc fail");
		return NULL:
	}
	
	node->ListData = data;
	node->ListNext = head;
	head = noed;
	return head;
}

LLType *FindNode(LLType *head, char *name)
{
	if (NULL == head)
	{
		LogE("head is NULL");
		return NULL;
	}
	Node *node = NULL;
	Node *htemp = head;
	
	while (htemp->ListNext != NULL)
	{
		if (0 == strcmp(htemp->ListData.name, name)
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
	
	Node *node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		LogE("malloc erroe");
		return NULL;
	}
	
	node->ListData = data;
	node->ListNext = NULL;
	
	Node *ntemp = NULL;
	
	Node *htemp = head;
	
	while (htemp->ListNext != NULL)
	{
		if (strcmp(htem->ListData.name, name) == 0)
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
	
	
	Node *htemp = head;
	Node *node = head;
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
