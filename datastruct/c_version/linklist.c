/*
 *链表的实现
 */

#include <stdio.h>

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define OVERFLOW    -2
#define LIST_INIT_SIZE  20
#define LISTINCREMENT   20

typedef int Status;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *LinkList;


typedef struct
{
    Link head, tail;
    int length;
}LinkList;


void CreateList(LinkList *L)

int main(int argc, char **argv)
{
	return 0;
}
