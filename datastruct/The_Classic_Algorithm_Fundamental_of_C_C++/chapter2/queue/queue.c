#include <stdio.h>
#include <stdlib.h>

#define QUEUE_LEN	15
#define NAME_LEN	10
#define TRUE		1
#define FALSE		0

typedef struct
{
	char name[NAME_LEN];
	int age;
}DATA;

typedef struct
{
	DATA data[QUEUE_LEN];
	int head;
	int tail;
}SQType;

SQType *InitQueue()
{
	SQType *q = (SQType *)malloc(sizeof(SQType));
	if (NULL != q)
	{
		q->head = 0;
		q->tail = 0;
		return q;
	}
	else
	{
		return NULL;
	}
}

int IsQueueEmpty(SQType *queue)
{
	if (queue->head == queue->tail)
	{
		return TRUE;
	}
	
	return FALSE;
}

int IsQueueFull(SQType *queue)
{
	if (queue->tail == QUEUE_LEN)
	{
		return TRUE;
	}
	
	return FALSE;
}

void UninitQueue(SQType *queue)
{
    printf("UninitQueue\n");
	if (NULL != queue)
	{
		free(queue);
		queue = NULL;
	}
	
	return;
}

void PrintQueue(SQType *queue)
{
	int i = 0;
	for (i = queue->head; i < queue->tail; i++)
	{
		printf("name %s,  age %d\n", queue->data[i].name, queue->data[i].age);
	}
}

int EnQueue(SQType *queue, DATA data)
{
	if (TRUE == IsQueueFull(queue))
	{
		printf("queue is full\n");
		return FALSE;
	}
	
	queue->data[queue->tail++] = data;
	
	return TRUE;
}

DATA DeQueue(SQType *queue)
{
	if (TRUE == IsQueueEmpty(queue))
	{
		printf("queue is empty, exit\n");
		exit(0);
	}
	
	return queue->data[queue->head++];
}

int GetQueueLen(SQType *queue)
{
	return queue->tail - queue->head;
}

int main(int argc, char **argv)
{
	SQType *queue = NULL;
	DATA data;
	DATA data1;
	
	queue = InitQueue();
	if (NULL == queue)
	{
		printf("InitQueue error\n");
		exit(0);
	}
	
	printf("入队操作\n");
	printf("输入姓名　年龄");
	do
	{
		scanf("%s%d", data.name, &(data.age));
		if (data.age == 0)
		{
			printf("Input end\n");
			break;
		}
		
		EnQueue(queue, data);
	}
	while(FALSE == IsQueueFull(queue));
	
	PrintQueue(queue);
	
	do
	{
		printf("出队操作，按任意键出队");
		getchar();
		data1 = DeQueue(queue);
		printf("出队数据是%s  %d\n", data1.name, data1.age);
	}
	while(FALSE == IsQueueEmpty(queue));
		
	UninitQueue(queue);
	
	return 0;
}
