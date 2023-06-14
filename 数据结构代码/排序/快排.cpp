#include <iostream>
using namespace std;

// ��������������Ԫ�ص�λ��
void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

// �����黮��Ϊ�����֣����ػ��ֺ��׼Ԫ�ص�λ��
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];  // ѡȡ���һ��Ԫ����Ϊ��׼Ԫ��
    int i = low - 1;  // i ָ��С�ڻ�׼Ԫ�ص�λ��

    for (int j = low; j < high; j++) 
    {
        // �����ǰԪ��С�ڻ�׼Ԫ�أ����佻����ǰ��
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // ����׼Ԫ�ط��õ���ȷ��λ����
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ���������㷨
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);  // ��������
        quickSort(arr, low, pivotIndex - 1);  // �Ի��ֺ������������п�������
        quickSort(arr, pivotIndex + 1, high);  // �Ի��ֺ������������п�������
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
