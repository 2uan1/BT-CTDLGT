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