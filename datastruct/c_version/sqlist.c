#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define OVERFLOW	-2
#define LIST_INIT_SIZE	10
#define	LISTINCREMENT	10

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

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
	if (NULL != L)
	{
		printf("NULL list!\n");
		return ERROR;
	}	
	
	if (L->length < 1)
	{
		return ERROR;
	}			
	else
	{
		return OK;
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

	if (i < 1 || i > L->length+1)
	{
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
	for (p = &(L->elem[L->length -1]); p >= q; p--)
	{
		*(p+1) = *p;
	}

	*q = e;
	
	(L->length)++;

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

int main(int argc, char **argv)
{
	Sqlist list;
	Status ret = InitList_Sq(&list);
	
	DestoryList(&list);
	
	return ret;
}
