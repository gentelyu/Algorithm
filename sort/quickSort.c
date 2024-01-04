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

#if 0
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
#if 0
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