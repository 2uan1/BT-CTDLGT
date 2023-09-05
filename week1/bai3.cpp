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