/*
 *鸡兔同笼问题的穷举算法举例
*/

#include <stdio.h>
#define CHICKEN_FOOT    2
#define RABBIT_FOOT     4

int qiongju(int head, int foot, int *chicken ,int *rabbit)
{
    int i = 0; //chicken
    int j = 0; // rabbit
    int ret = 0;
    for (i = 0; i < head; i++)
    {
        j = head -i;//rabbit = total heads - chichek
        if ((i * CHICKEN_FOOT + j * RABBIT_FOOT) == foot)
        {
            printf("found a result\n");
            ret = 1;
            *chicken = i;
            *rabbit = j;
        }
    }

    return ret;
}

int main(int argc, char **argv)
{
    int chicken, rabbit, head, foot;
    int ret;
    printf("穷举法求解鸡兔同笼的问题：\n");
    printf("输入头数：\n");
    scanf("%d", &head);
    printf("输入脚数：\n");
    scanf("%d", &foot);
    
    ret = qiongju(head, foot, &chicken, &rabbit);
    if (1 == ret)
    {
        printf("鸡有：%d , 兔有:%d \n", chicken, rabbit);
    }
    else
    {
        printf("此问题无解\n");
    }

    return 0;
}
