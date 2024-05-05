#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10000;

void generateArray(int arr[], int size) 
{
    srand(time(0));
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 1000;
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size, int& comparisons, int& swaps) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        //boolean flag = false;
        for (int j = 0; j < size - i - 1; j++) 
        {
            comparisons++;
            if (arr[j] > arr[j+1]) 
            {
                //flag = true
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size, int& comparisons, int& swaps) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int minIndex = i;
        for (int j = i+1; j < size; j++) 
        {
            comparisons++;
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swaps++;
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size, int& comparisons, int& swaps) 
{
    for (int i = 1; i < size; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            comparisons++;
            swaps++;
            arr[j+1] = arr[j];
            j--;
        }
        swaps++;
        arr[j+1] = key;
    }
}

void exchangeSort(int arr[], int size, int& comparisons, int& swaps) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i+1; j < size; j++) 
        {
            comparisons++;
            if (arr[i] > arr[j]) 
            {
                swaps++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void mergeSort(int arr[], int left, int right, int& comparisons, int& swaps) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++) 
        {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) 
        {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) 
        {
            comparisons++;
            if (L[i] <= R[j]) 
            {
                swaps++;
                arr[k] = L[i];
                i++;
            }
            else 
            {
                swaps++;
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) 
        {
            swaps++;
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) 
        {
            swaps++;
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

int partition(int arr[], int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quicksort(int arr[], int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quicksort(arr, low, pi - 1, comparisons, swaps);
        quicksort(arr, pi + 1, high, comparisons, swaps);
    }
}

int main()
{
    int arr[ARRAY_SIZE];
    int size = ARRAY_SIZE;

    int num;
    int comp = 0; 
    int swap = 0;

    generateArray(arr, size);
    cout << "Initial array:" << endl;
    printArray(arr, size);

    cout << "1.Bubble sort" << endl;
    cout << "2.Selection Sort" << endl;
    cout << "3.Insertion Sort" << endl;
    cout << "4.Exchange Sort" << endl;
    cout << "5.Merge Sort" << endl;
    cout << "6.Quick Sort" << endl;
    cout << ">";
    cin >> num;

    switch(num)
    {
        case 1:
            bubbleSort(arr, size, comp, swap);
            cout << "bubbleSort:" << endl;
            printArray(arr, size);
            cout << "Bubble sort Comparisons: " << comp << endl;
            cout << "Bubble sort Swaps: " << swap << endl;
        break;

        case 2:
            selectionSort(arr, size, comp, swap);
            cout << "selectionSort:" << endl;
            printArray(arr, size);
            cout << "Selection Sort Comparisons: " << comp << endl;
            cout << "Selection Sort Swaps: " << swap << endl;
        break;

        case 3:
            insertionSort(arr, size, comp, swap);
            cout << "insertionSort:" << endl;
            printArray(arr, size);
            cout << "Insertion Sort Comparisons: " << comp << endl;
            cout << "Insertion Sort Swaps: " << swap << endl;
        break;

        case 4:
            exchangeSort(arr, size, comp, swap);
            cout << "exchangeSort:" << endl;
            printArray(arr, size);
            cout << "Exchange Sort Comparisons: " << comp << endl;
            cout << "Exchange Sort Swaps: " << swap << endl;
        break;

        case 5:
            mergeSort(arr, 0, 9999, comp, swap);
            cout << "mergeSort:" << endl;
            printArray(arr, size);
            cout << "Merge Sort Comparisons: " << comp << endl;
            cout << "Merge Sort Swaps: " << swap << endl;
        break;

        case 6:
            quicksort(arr, 0, 9999, comp, swap);
            cout << "quicksort:" << endl;
            printArray(arr, size);
            cout << "Quick Sort Comparisons: " << comp << endl;
            cout << "Quick Sort Swaps: " << swap << endl;
    }

    string x;
    cin >> x;

    return 0;
}