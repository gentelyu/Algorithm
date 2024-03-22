#include <iostream>
#include <random>

using namespace std;

int Swap(int *data1, int *data2)
{
    int ret = 0;
    if (data1 == nullptr || data2 == nullptr)
        return -1;
    
    int temp = 0;
    temp = *data1;
    *data1 = *data2;
    *data2 = temp;

    return ret;
}

int GetSrandNum(int begin, int end)
{
    /* 使用mt19937 随机数生成器 */
    mt19937 rng(random_device{}());

    /* 使随机数生成的分布范围为begin到end */
    uniform_int_distribution<int> dist(begin, end);

    /* 生成随机数 */
    int random_number = dist(rng);

    return random_number;
}

int Partition(int data[], int length, int begin, int end)
{
    if (data == nullptr || length <= 0 || begin < 0 || end >= length)
        throw ("Partition invalid input");
    
    /* 取随机索引 */
    int index = GetSrandNum(begin, end);
    Swap(&data[index], &data[end]);

    /* 已经排好的小于索引值的位置索引 */
    int small = begin -1;
    for (int idx = begin; idx < end; idx++)
    {
        if (data[idx] < data[end])
        {
            small++;
            if (idx != small)
                Swap(&data[small], &data[idx]);
        }
    }

    small++;
    Swap(&data[small], &data[end]);

    return small;
}

int FastSort(int data[], int length, int begin, int end)
{
    int ret = 0;
    if (data == nullptr || length <= 0 || begin < 0 || end >= length)
        throw ("FastSort invalid input");
    

    int index = Partition(data, length, begin, end);
    if (index > begin)
        FastSort(data, length, begin, index - 1);
    if (index < end)
        FastSort(data, length, index + 1, end);
    
    return ret;
}

int main()
{
    int array[1000];

    for (int idx = 0; idx < 1000; idx++)
    {
        array[idx] = GetSrandNum(0, 1000);
    }

    int length = 0;
    length = sizeof(array) / sizeof(array[0]);

    try
    {
        FastSort(array, length, 0, 999);
        
        FastSort(array, length, 0,1000);// 为什么会先抛出异常？？？？
    } 
    catch (const char *msg)
    {
        cerr << "excepect caugth:" << msg << endl;
    }
    
    for (int idx = 0; idx < 1000; idx++)
    {
        printf("%d\t", array[idx]);
    }
    

    return 0;
}