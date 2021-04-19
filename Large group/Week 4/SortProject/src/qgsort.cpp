#include<iostream>
#include<cmath>
#include"qgsort.h"
using namespace std;

void insertSort(int* a, int n)//插入排序算法
{
    int i, j, k;
    for (i = 1;i <= n;i++)
    {
        for (j = i;j > 0;j--)
        {
            if (a[j] >= a[j - 1])
            {
                break;
            }
            else
            {
                k = a[j];
                a[j] = a[j - 1];
                a[j - 1] = k;
            }

        }
    }
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)//归并排序（合并数组）
{
    int i = 0, j = 1, k = 0;
    int n1 = mid - begin;
    int n2 = end - mid;

    while (i <= n1 && j <= n2)
    {
        if (a[begin + i] <= a[mid + j])
        {
            temp[k] = a[begin + i];
            i++;
        }

        else
        {
            temp[k] = a[mid + j];
            j++;
        }

        k++;
    }

    while (i <= n1)
    {
        temp[k] = a[begin + i];
        i++;
        k++;
    }

    while (j <= n2)
    {
        temp[k] = a[mid + j];
        j++;
        k++;
    }

    for (int n = 0; n <= end - begin; n++)
    {
        a[begin + n] = temp[n];
    }
}

void MergeSort(int* a, int begin, int end, int* temp)//归并排序
{
    if (begin < end)
    {
        int m = begin + (end - begin) / 2;
        MergeSort(a, begin, m, temp);
        MergeSort(a, m + 1, end, temp);
        MergeArray(a, begin, m, end, temp);
    }
}

void QuickSort_Recursion(int* a, int begin, int end)//快速排序（递归版）
{
    if (begin < end)
    {
        int p = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, p - 1);//对左半段排序
        QuickSort_Recursion(a, p + 1, end);//对右半段排序
    }
}

void QuickSort(int* a, int size)//快速排序（非递归版）
{

}

int Partition(int* a, int begin, int end)//快速排序（枢轴存放）
{
    int i = begin + 1, j = end, m, n = a[begin];
    while (i < j)
    {
        while (a[i] <= a[begin] && a[j] >= a[begin] && i < j)
        {
            i++;
            j--;
        }
        if (i >= j)
        {
            break;
        }
        else if (a[i] >= a[begin] && a[j] <= a[begin])
        {
            m = a[i];
            a[i] = a[j];
            a[j] = m;
        }
        else if (a[i] <= a[begin])
        {
            do
            {
                i++;
            } while (a[i] <= a[begin] && i < j);

            if (i == j)
            {
                break;
            }
            else
            {
                m = a[i];
                a[i] = a[j];
                a[j] = m;
            }
        }
        else if (a[j] >= a[begin])
        {
            do
            {
                j--;
            } while (a[j] >= a[begin] && i < j);

            if (i == j)
            {
                break;
            }
            else
            {
                int m = a[i];
                a[i] = a[j];
                a[j] = m;
            }
        }
    }
    //int key = a[begin];  //第一个值作为基准值
    //int i = begin, j = end;
    //// 将< x的元素交换到左边区域
    //// 将> x的元素交换到右边区域
    //while (i < j)
    //{
    //    while (i < j && a[i] <= key)
    //    {
    //        i++;
    //    }
    //    while (a[j] > key)
    //    {
    //        j--;
    //    }
    //    if (i <= j)
    //    {
    //        int m = a[i];
    //        a[i] = a[j];
    //        a[j] = m;
    //    }
    //}
    if (a[begin] >= a[i])
    {
        m = a[begin];
        a[begin] = a[i];
        a[i] = m;
    }
    else
    {
        m = a[begin];
        a[begin] = a[i - 1];
        a[i - 1] = m;
    }
    return i;
}

void CountSort(int* a, int size, int max)//计数排序
{
    for (int i = 0;i <= size;i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int* b = new int[max];
    for (int i = 0; i <= max; i++)
    {
        b[i] = 0;
    }
    for (int j = 0;j <= size;j++)
    {
        b[a[j]]++;
    }
    for (int i = 0, j = 0;i <= max || j <= size;i++)
    {
        while (b[i] > 0)
        {
            a[j] = i;
            j++;
            b[i]--;
        }
    }
}

void RadixCountSort(int* a, int size)//基数计数排序
{
    int* c1 = new int[10], * b1 = new int[size+1], n, m = 0, max = 0;
    for (int i = 0;i <= size;i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    while (max != 0)
    {
        m++;
        max /= 10;
    }

    for (int d = 0; d <= m-1;d++)
    {
        for (int j = 0; j < 10; j++)
        {
            c1[j] = 0;
        }
    
        for (int j = 0; j <= size; j++)
        {
            n = a[j] / (int (pow (10,d))) % 10 ;
            c1[n]++;
        }
        for (int j = 1; j < 10; j++)
        {
            c1[j] += c1[j - 1];
        }
        for (int j = size; j >= 0; j--)
        {
            n = a[j] / (int(pow(10, d))) % 10;
            int num = c1[n] - 1;
            b1[num] = a[j];
            c1[n]--;
        }
        for (int j = 0; j < size; j++)
        {
            a[j] = b1[j];
        }
    }
}

void ColorSort(int* a, int size)//颜色排序
{

}
