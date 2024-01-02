#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define BUFFER_SIZE 10

/* 打印函数 */
void printArray(int *array, int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}


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


/* 1 表示存在， 0 表示不存在*/
int binarySearchIsExist(int *array, int length, int val)
{
    if (array == NULL)
    {
        return 0;
    }

    int begin = 0;
    int end = length - 1;
    int mid = (begin + end) >> 1;

    while(begin <= end)
    {
        if(val < array[mid])
        {   
            end = mid - 1;
            mid = (begin + end) / 2;
        }
        else if(val > array[mid])
        {
            begin = mid + 1;
            mid = (begin + end) / 2;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int buffer[BUFFER_SIZE] = {0};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }

    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);

    quickSort02(buffer, 0, length - 1);
    printArray(buffer, length);

    int is_Exist =  binarySearchIsExist(buffer, length, 36);
    printf("%d\n", is_Exist);

    return 0;
}