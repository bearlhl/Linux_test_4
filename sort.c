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

void BubbleSort(int a[],int n)      //冒泡排序
{
    int i,j,temp;
    for(j=0;j<n-1;j++)
        for(i=0;i<n-1-j;i++)
        {
            CCBubble++;
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                SCBubble+=3;
            }
        }
}

void InsertSort(int a[],int n)      //插入排序
{
    int i,j,temp;
    for(i=1;i<SIZE;i++)
    {
        CCInsert++;
        if(a[i]<a[i-1])
        {
            temp=a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--)
            {
                CCInsert++;
                a[j+1]=a[j];
                SCInsert++;
            }
            a[j+1]=temp;
            SCInsert+=3;
        }
    }
}

void SelectSort(int a[],int n)      //选择排序
{
    int i,j,k,temp;
    for(i=0;i<SIZE;i++)
    {
        temp=i;
        for(j=i+1;j<SIZE;j++)
        {
            CCSelect++;
            if(a[temp]>a[j])
                temp=j;
        }
        k=a[temp];
        a[temp]=a[i];
        a[i]=k;
        SCSelect+=3;
    }
}

void QuickSort(int a[],int left,int right)  //快速排序
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int key=a[left];
    while(i<j)
    {
        CCQuick++;
        while(i<j&&key<=a[j])
        {
            CCQuick++;
            j--;
        }
        a[i]=a[j];
        while(i<j&&key>=a[i])
        {
            //CCQuick++;
            i++;
        }
        a[j]=a[i];
        SCQuick+=3;
    }
    a[i]=key;
    QuickSort(a,left,i-1);
    QuickSort(a,i+1,right);
}

void shellInsert(int array[],int n,int dk)  //希尔排序
{
    int i,j,temp;
    for(i=dk;i<n;i++)
    {
        temp=array[i];
        for(j=i-dk;(j>=i%dk)&&array[j]>temp;j-=dk)
        {
            CCShell++;
            array[j+dk]=array[j];
            SCShell++;
        }
        if(j!=i-dk)
        {
            array[j+dk]=temp;
            SCShell+=3;
        }
    }
}
int dkHibbard(int t,int k)
{
    return (int)(pow(2,t-k+1)-1);
}
void shellSort(int array[],int n,int t)
{
    void shellInsert(int array[],int n,int dk);
    int i;
    for(i=1;i<=t;i++)
        shellInsert(array,n,dkHibbard(t,i));
}

void HeapAdjust(int array[],int i,int nLength)      //堆排序
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        //子结点的位置=2*（父结点位置）+1
        nChild=2*i+1;
        //得到子结点中较大的结点
        CCHeap++;
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])
            ++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp;
            SCHeap+=3;
        }
        else
            break; //否则退出循环
    }
}
//堆排序算法
void HeapSort(int array[],int length)
{
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i=length/2-1;i>=0;--i)
        HeapAdjust(array,i,length);
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i=length-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        SCHeap+=3;
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array,0,i);
    }
}
