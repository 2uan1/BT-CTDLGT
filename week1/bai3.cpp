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
