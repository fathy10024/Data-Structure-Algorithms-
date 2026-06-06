void max_heapify(int array[], int i, int n)
{
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int largest;
    if (left < n && array[left] > array[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(array[i], array[largest]);
        max_heapify(array, largest, n);
    }
}

void build_max_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, i, n);
    }
}

void heap_sort(int arr[], int n)
{
    build_max_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

void swap(int &a1, int &a2)
{
    int temp = 0;
    temp = a1;
    a1 = a2;
    a2 = temp;
}