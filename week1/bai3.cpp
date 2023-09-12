void selectionSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int curMin = i;
        for (int cur = i; cur < size; cur++)
        {
            if (a[curMin] > a[cur])
            {
                curMin = cur;
            }
        }
        int tmp = a[i];
        a[i] = a[curMin];
        a[curMin] = tmp;
    }
}

void insertionSort(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int j = i;
        if (j != 0)
        {
            while(j > 0 && a[j] < a[j-1])
            {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                j--;
            }
        }
    }
}

void bubbleSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void quickSort(int arr[], int left, int right){

    if (left < right){
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi- 1);
        quickSort(arr, pi + 1, right);
    }
}

int partition(int arr[], int left, int right){
    int i = left, j = left;
    int pivot = arr[right];
    while (j < right){
        while (arr[i] < pivot) i++;
        j = i;
        while (arr[j] > pivot) j++;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    return i;
}

void mergeSort(int a[], int start, int end)
{
    if (start >= end) return;
    int mid = start + (end - start) /2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a, start, end, mid);
}

void merge(int a[], int start, int end, int mid)
{
    int subArrayOne = mid - start + 1;
    int subArrayTwo = end - mid;

    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++) leftArray[i] = a[start+i];
    for (int i = 0; i < subArrayTwo; i++) rightArray[i] = a[i+mid+1];

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfArray = start;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (rightArray[indexOfSubArrayTwo] <= leftArray[indexOfSubArrayOne])
        {
            a[indexOfArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        else if (leftArray[indexOfSubArrayOne] < rightArray[indexOfSubArrayTwo])
        {
            a[indexOfArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        indexOfArray++;
    }
    if (indexOfSubArrayOne < subArrayOne)
    {
        while (indexOfSubArrayOne < subArrayOne)
        {
            a[indexOfArray] = leftArray[indexOfSubArrayOne];
            indexOfArray++;
            indexOfSubArrayOne++;
        }
    }
    else if (indexOfSubArrayTwo < subArrayTwo)
    {
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            a[indexOfArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfArray++;
        }
    }
    delete[] rightArray;
    delete[] leftArray;
}