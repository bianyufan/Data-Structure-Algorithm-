#include <iostream>
using namespace std;

// 交换数组中两个元素的位置
void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

// 将数组划分为两部分，返回划分后基准元素的位置
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];  // 选取最后一个元素作为基准元素
    int i = low - 1;  // i 指向小于基准元素的位置

    for (int j = low; j < high; j++) 
    {
        // 如果当前元素小于基准元素，将其交换到前面
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // 将基准元素放置到正确的位置上
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序算法
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);  // 划分数组
        quickSort(arr, low, pivotIndex - 1);  // 对划分后的左子数组进行快速排序
        quickSort(arr, pivotIndex + 1, high);  // 对划分后的右子数组进行快速排序
    }
}

int main() {
    int arr[] = { 9, 5, 2, 7, 1, 8, 6, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
