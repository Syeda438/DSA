#include<iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting:\n";
    display(arr, n);
    selectionSort(arr, n);
    cout << "After sorting:\n";
    display(arr, n);
    return 0;
}
