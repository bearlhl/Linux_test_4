#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <sort.h>

#define SIZE 100
int CCBubble=0;                   //CC:关键字比较计数
int SCBubble=0;                   //SC:关键字移动计数
int CCInsert=0;
int SCInsert=0;
int CCSelect=0;
int SCSelect=0;
int CCQuick=0;
int SCQuick=0;
int CCShell=0;
int SCShell=0;
int CCHeap=0;
int SCHeap=0;

int main()
{
    int i,number[SIZE],test[SIZE];
    unsigned int seed=time(NULL);
    srand(seed);
    for(i=0;i<SIZE;i++)
        number[i]=rand();
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    for(i=0;i<SIZE;i++)
        printf("%-8d",number[i]);
    putchar(10);
    BubbleSort(test,SIZE);
    printf("bubble_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("bubble_sort:比较:%d,移动:%d\n",CCBubble,SCBubble);
    putchar(10);
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    InsertSort(test,SIZE);
    printf("insert_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("insert_sort:比较:%d,移动:%d\n",CCInsert,SCInsert);
    putchar(10);
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    SelectSort(test,SIZE);
    printf("select_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("select_sort:比较:%d,移动:%d\n",CCSelect,SCSelect);
    putchar(10);
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    QuickSort(test,0,SIZE-1);
    printf("quick_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("quick_sort:比较:%d,移动:%d\n",CCQuick,SCQuick);
    putchar(10);
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    shellSort(test,SIZE,(int)(log(SIZE+1)/log(2)));
    printf("shell_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("shell_sort:比较:%d,移动:%d\n",CCShell,SCShell);
    putchar(10);
    for(i=0;i<SIZE;i++)
        test[i]=number[i];
    HeapSort(test,SIZE);
    printf("heap_sort:\n");
    for(i=0;i<SIZE;i++)
        printf("%-8d",test[i]);
    printf("heap_sort:比较:%d,移动:%d",CCHeap,SCHeap);
    return 0;
}
