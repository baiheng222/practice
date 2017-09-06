#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 10
#define STACK_MAX_LEN 50

#define TRUE				1
#define	FALSE				0
#define OK			 		0
#define ERROR				-1
#define ERR_NULL_STACK		-2
#define ERR_OVERFLOW_STACK 	-3
#define ERR_EMPTY_STACK		-4


typedef struct
{
    char name[NAME_LEN];
    int age;
}Data;

typedef struct
{
    Data data[STACK_MAX_LEN + 1];
    int top;
}StackType;

StackType *InitStack()
{
	StackType *p = NULL;
	p = (StackType *) malloc(sizeof(StackType));
	
	if (NULL != p)
	{
		p->top = 0;
	}
	
	return p;
}

int IsEmptyStack(StackType *stack)
{
	if (NULL == stack)
	{
		return ERR_NULL_STACK;
	}
	
	if (stack->top == 0)
	{
		return TRUE;
	}
	
	return FALSE;
}

int IsFullStack(StackType *stack)
{
	if (NULL == stack)
	{
		return ERR_NULL_STACK;
	}
	
	if (stack->top == STACK_MAX_LEN)
	{
		return TRUE;
	}
	
	return FALSE;
}

void ClearStack(StackType *stack)
{
	if (NULL == stack)
	{
		return;
	}
	
	stack->top = 0;
	
	return;
}

void UnInitStack(StackType *stack)
{
	if (NULL == stack)
	{
		return;
	}
	
	free(stack);
	stack = NULL;
	
	return;
}

int PushStack(StackType *stack, Data data)
{
	if (NULL == stack)
	{
		return ERR_NULL_STACK;
	}
	
	if ((stack->top + 1) > STACK_MAX_LEN)
	{
		return ERR_OVERFLOW_STACK;
	}
	
	stack->top = stack->top + 1;
	stack->data[stack->top] = data;
	
	return OK;
	
}

void PrintStack(StackType *stack)
{
    if (NULL == stack)
    {
        return;
    }
    int i;
    for (i = stack->top; i > 0; i--)
    {
        printf("stack[%d] is %s  %d\n", i, stack->data[i].name, stack->data[i].age);
    }
}

Data PopStack(StackType *stack)
{
    Data tmpdat;
    strcpy(tmpdat.name, "end");
    tmpdat.age = -1;
    if (stack->top == 0)
    {
        printf("stack is empty\n");
        return tmpdat;
    }
	//stack->top = stack->top -1;
	
	return stack->data[stack->top--];
}


int main(int argc, char **argv)
{
	StackType *stack;
	Data data, data1;
	
	stack = InitStack();
	
	
	if (NULL == stack)
	{
		printf("init stack faile \n");
		return -1;
	}
	
	printf("入栈操作: \n");
	printf("\n输入姓名　年龄：");
	do
	{
		scanf("%s%d", data.name, &data.age);
		if (data.age == 0)
		{
			break;
		}
		else
        {
		    PushStack(stack, data);
        }   
	}
	while(1);
	
    printf("stack->top is %d\n", stack->top);
    PrintStack(stack);
	printf("出栈操作 \n");
	do
	{
		printf("\n按任意键进行出栈操作");
		getchar();
		data1 = PopStack(stack);
		printf("出栈数据是：　%s    %d\n", data1.name, data1.age);
	}
	while(IsEmptyStack(stack) == FALSE);
	
    UnInitStack(stack);

	return 0;
}

