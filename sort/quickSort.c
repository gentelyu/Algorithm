#include <stdio.h>
#include <time.h>
#define array_nums 100000

/* 数组做函数参数会自动弱化成指针 */
int printArray(int *array, int length)
{   
    int ret = 0;
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\t", idx, array[idx]);
    }
    return ret;
}

#if 1
int quickSort01(int *array, int start, int end)
{
    int ret = 0;
    if (start >= end)
    {
        return ret;
    }
    
    int temp = array[start];
    int idx = start;
    int jdx = end;
    while (start < end)
    {
        while (start < end)
        {
            if (temp <= array[end])
            {
                end--;
            }
            else
            {
                array[start++] = array[end];
                break;
            }
        }

        while (start < end)
        {
            if (temp >= array[start])
            {
                start++;
            }
            else
            {
                array[end--] = array[start]; 
                break;
            }   
        }
    }   // 退出循环的条件是: start >= end. 
    array[start] = temp;
    quickSort01(array, idx, start - 1);
    quickSort01(array, start + 1, jdx);

    return ret;
}
#endif 



/* 找到基准值的位置 */
static int findBaseValPos(int *array, int start, int end)
{
    int ret = 0;
    end--;
    /* 基准值 */
    int baseValPos = array[start];
    while (start < end)
    {
        while (start < end)
        {
            if (array[end] < baseValPos)
            {
                array[start++] = array[end];
                break;
            }
            else
            {
                end--;
            }
        }

        while (start < end)
        {
            if (array[start] > baseValPos)
            {
                array[end--] = array[start];
                break;
            }
            else
            {
                start++;
            }
        }    
    }   // 退出条件是：start = end.
    array[start] = baseValPos;
    return start;   
}   

/* 快速排序 */
int quickSort02(int *array, int start, int end)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    /* 如果start == end 说明数组只有一个元素. 直接返回. */
    if (start >= end)
    {
        return ret;
    }
    int baseValPos = findBaseValPos(array, start, end);

    /* 对基准值左侧排序 */
    quickSort02(array, start, baseValPos);
    /* 对基准值右侧排序 */
    quickSort02(array, baseValPos + 1, end);

    return ret;
}

#if 0
/* 剑指offer排序算法C++版 */
/* Partition函数用于在数组中取一个随即索引，并将小于索引对应的值放到他前面 */
int Partition(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        return -1;
    
    /* 获得随机索引index，并与最后一个元素进行交换，RandomInRange自己实现：获得一个随机值 */
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    /* small 记录当前小于分区点元素的最后位置 */
    int small = -1;
    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            /* 更新small位置 */
            ++small;
            if (small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++small;
    Swap(&data[small], &data[end]);

    return small;
}

int QuickSort3(int data[], int length, int start, int end)
{
    int ret = 0;
    if (start == end)
        return -1;
    
    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort3(data, length, start, index - 1);
    if (index < end)
        QuickSort3(data, length, index + 1, end);
}
#endif

int main()
{
    clock_t start_time, end_time;
    double elapsed_time;

    start_time = clock();

    int array[array_nums];
    for(int idx = 0; idx < array_nums; idx++)
    {
        array[idx] = array_nums - idx; 
    }


    int length = sizeof(array) / sizeof(array[0]);
#if 1
    quickSort01(array, 0, length - 1);
#else
    /* 快速排序 */
    quickSort02(array, 0, length);
#endif
    printArray(array, length);

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("代码执行时间为 %f 秒\n", elapsed_time);
    return 0;
}