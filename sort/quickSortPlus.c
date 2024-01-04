#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define array_nums 100000
#define true 1
#define false 0


int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;

    return ret;
}

int bubberSortPuls(int *arr, int start, int end)
{
    int ret = 0;
    if(!arr || start >= end)
    {
        return false;
    }
    /* 从小到大排序 */
    if(arr[start] > arr[end])
    {
        swap(&arr[start], &arr[end]);
    }

    /* 定义三个索引   : left, right, mid */
    /* 以及两个基准值 : pivot1, pivot2 */
    int left = start, right = end, mid =left + 1;
    int pivot1 = arr[start], pivot2 = arr[end];

    while (mid < right)
    {
        if (arr[mid] < pivot1)
        {
            swap(&arr[++left], &arr[mid++]);
        }
        else if (arr[mid] <= pivot2)
        {
            mid++;
        }
        else
        { 
#if 0
            while (arr[--right] > pivot2 && right > mid)
            {
                if(mid >= right)
                {
                    break;
                }
                swap(&arr[mid], &arr[right]);
            }
#else
            while (arr[--right] > pivot2 && right > mid);
            if(mid >= right)
            {
                break;
            }
            swap(&arr[mid], &arr[right]);
#endif
        }
    }

    swap(&arr[start], &arr[left]);
    swap(&arr[end], &arr[right]);

    bubberSortPuls(arr, start, left - 1);
    bubberSortPuls(arr, left + 1, right - 1);
    bubberSortPuls(arr, right + 1, end);
    return ret;
}

int printArray(int *arr, int begin, int end)
{
    for(int idx = begin; idx <= end; idx++)
    {
        printf("%d\t", arr[idx]);
    }
    printf("\n");
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


    bubberSortPuls(array, 0, array_nums - 1);

    printArray(array, 0, array_nums -1);
    printf("\n");

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("代码执行的时间为 %f秒\n", elapsed_time);
    return 0;
}