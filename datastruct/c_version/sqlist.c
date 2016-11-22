/*
 *	顺序表的实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define OVERFLOW	-2
#define LIST_INIT_SIZE	20
#define	LISTINCREMENT	20

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

//生成num以内的随机数
int getRand(int num)
{
    srand((unsigned)time(NULL)); //用于保证是随机数
    return rand()%num;  //用rand产生随机数并设定范围
}

Status InitList_Sq(Sqlist *L)
{
	if (NULL == L)
	{
		return ERROR;
	}
	
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (NULL == L->elem)
	{
		printf("malloc error, %s\n", strerror(errno));
		return ERROR;
	}
	
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

void DestoryList(Sqlist *L)
{
	if (NULL == L)
	{
		return;
	}	
	
	if (L->elem != NULL)
	{
        printf("\tfree elem\n");
		free(L->elem);
		L->elem == NULL;
		L->length = 0;
		L->listsize = 0;
	}		
}

void ClearList(Sqlist *L)
{
	if (L->elem !=NULL)
	{
		int i = 0;
		for (i = 0; i < L->length; i++)
		{
			L->elem[i] = 0;
		}
		
		L->length = 0;
			
	}	
}


Status ListEmpty(Sqlist *L)
{
    if (NULL == L)
	{
        printf("\tNULL list!\n");
		return ERROR;
	}	
	
    if (L->length == 0)
	{
        return TRUE;
	}			
	else
	{
        return FALSE;
	}	
}

int ListLength(Sqlist *L)
{
	if (NULL == L)
	{
		return OVERFLOW;
	}	
	
	return L->length;
}

Status GetElem(Sqlist *L, int i, ElemType *e)
{
	if ((NULL == L) || (e == NULL))
	{
		return ERROR;
	}	
	
	if ((i > L->length) || (i < 1))
	{
		return ERROR;
	}	
	
	*e = L->elem[i -1];
	return OK;
}

int LocateElem(Sqlist *L, ElemType e)
{
	if (NULL == L)
	{
		return ERROR;
	}
	
	int len = ListLength(L);

	if (len == OVERFLOW)
	{
		return ERROR;
	}
	
	int i = 0;
	int ret = 0;
	for (i = 0; i < len; i++)
	{
		if (L->elem[i] == e)
		{
			ret = i;
			break;
		}
	}
	
	return ret;
}

Status PriorElem(Sqlist *L, ElemType cur_e, ElemType *e)
{
	if (NULL == L)
	{
		return ERROR;
	}

	int ret = ERROR;
	int i = 1;
	for (i = 1; i < L->length; i++)
	{
		if (L->elem[i] == cur_e)
		{
			*e = L->elem[i-1];
			ret = OK;
			break;
		}
	}

	return ret;
}

Status NextElem(Sqlist *L, ElemType cur_e, ElemType *e)
{
	if (NULL == L || e == NULL)
	{
		return ERROR;
	}

	int ret = ERROR;
	int i = 0;
	for (i = 0; i < (L->length -1); i++)
	{
		if (L->elem[i] == cur_e)
		{
			*e = L->elem[i+1];
			ret = OK;
			break;
		}
	}

	return ret;
}


Status ListInsert(Sqlist *L, int i, ElemType e)
{
	if (NULL == L)
	{
		return ERROR;
	}

	printf("\te is %d\n", e);

	if (i < 1 || i > L->length+1)
	{
        printf("\ti > length+1 \n");
		return ERROR;
	}

	if (L->length >= L->listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L->elem, sizeof(ElemType) * (L->listsize + LISTINCREMENT));
		if (NULL != newbase)
		{
			L->elem = newbase;
			L->listsize += LISTINCREMENT;
		}
		else
		{
			return ERROR;
		}
	}

	ElemType *q = &(L->elem[i-1]);
	ElemType *p;
    for (p = &(L->elem[L->length -1]); p >= q; --p)
	{
		*(p+1) = *p;
	}

	*q = e;
	
    ++(L->length);

	return OK;
	
}


Status ListDelete(Sqlist *L, int i, ElemType *e)
{
	if (NULL == L || e == NULL)
	{
		return ERROR;
	}

	if (i < 1 || i > L->length)
	{
		return ERROR;
	}

	ElemType * p = &(L->elem[i-1]);
	e = p;
	ElemType *q = L->elem + L->length-1;
	for (++p; p <= q; p++)
	{
		*(p -1) = *p;
	}
	
	L->length --;

	return OK;
}

Status ListTraverse(Sqlist *L)
{
	if (NULL == L)
	{
		return ERROR;
	}

    if (L->length == 0)
    {
        printf("Empty list\n");
        return ERROR;
    }
    int i = 1;
    for (i = 0; i < L->length; i++)
    {
        printf("\tlist[%d] is %d \n", i, L->elem[i]);
    }

    return OK;

}

void ListSort(Sqlist *L)
{
    if (NULL == L)
    {
        return;
    }

    int i, j, max, tmp;
    for (i = 0; i < L->length - 1; i++)
    {
        max = i;
        for (j = i; j < L->length; j++)
        {
            if (L->elem[max] < L->elem[j])
            {
                max = j;
            }
        }

        tmp = L->elem[i];
        L->elem[i] = L->elem[max];
        L->elem[max] = tmp;
    }
}

int main(int argc, char **argv)
{
    int i;
    ElemType e;
    Sqlist L;

    srand((int) time(0));

    Status ret = InitList_Sq(&L);
    if (ret == ERROR)
    {
        printf("\tInitList error\n");
        return -1;
    }
    else
    {
        printf("\tInitlist success\n");
    }


    /*判断该线性表是否为空*/
    printf("\n\t列表是否为空？\n");
    if(ListEmpty(&L) == TRUE)
    {
        printf("\t该线性表是为空！\n\n");
    }
    else
    {
        printf("\t该线性表不为空！\n\n");
    }


    /*该线性表的长度*/
    printf("\n\t该线性表的长度：%d\n\n", ListLength(&L));


    /*向线性表中插入元素*/
    printf("\n\t插入元素\n");
    for(i = 1; i <= 8; i++)
    {
        ListInsert(&L, i, rand()%100);
    }

    ListTraverse(&L);
    printf("\n\t该线性表的长度：%d\n\n", ListLength(&L));


    /*查找数的前驱*/
    printf("\n\t将要查找元素的前驱！\n");
    printf("\t输入要查找的值: ");
    scanf("%d", &i);
    if(PriorElem(&L, i, &e) == 1)
    {
        printf("\t存在前驱，且前驱为：%d\n\n", e);
    }
    else
    {
        printf("\t不存在前驱元素！\n\n");
    }

    /*查找数的后继*/
    printf("\n\t将要查找元素的后继！\n");
    printf("\t输入要查找的值: ");
    scanf("%d", &i);
    if(NextElem(&L, i, &e) == 1)
    {
        printf("\t存在后继，且后继为：%d\n\n", e);
    }
    else
    {
        printf("\t不存在后继元素！\n\n");
    }

    /*删除线性表中的第i个元素*/
    printf("\n\t删除元素！\n");
    printf("\n\t删除前：\n");
    ListTraverse(&L);
    printf("\t输入要删除的第几个元素：");
    scanf("%d", &i);
    ListDelete(&L, i, &e);
    printf("\n\t删除后：\n");
    ListTraverse(&L);


    /*元素排序*/
    printf("\n\t排序前：\n");
    ListTraverse(&L);
    printf("\n\t排序后：\n");
    ListSort(&L);
    ListTraverse(&L);


    DestoryList(&L);
	
	return ret;
}
