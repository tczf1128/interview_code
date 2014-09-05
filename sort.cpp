/*********************** sort algorithms *************************/

void insertion_sort(int A[],const int start,const int end)
{
    int i,j,tmp;

    for(i = start+1;i < end;i++)
    {
        tmp = A[i];
        for(j = i-1;j >= start && tmp < A[j];j--)
            A[j+1] = A[j];
        A[j+1] = tmp;
    }
}
/**********************************************************************/

void binary_insertion_sort(int A[],const int start,const int end)
{
    int i,j;

    for(i = start+1;i < end;i++)
    {
        int tmp = A[i];
        int left = start;
        int right = i-1;
        while (left <= right)
        {
            int mid = left + (right-left>>1);
            if (tmp < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for(j = i-1;j >= left;j--)
            A[j+1] = A[j];
        A[left] = tmp;
    }
}
/**********************************************************************/

void shell_sort(int A[],const int start,const int end)
{
    int i,j,gap,tmp;

    for(gap = (end-start>>1);gap > 0;gap >>= 1)
        for(i = start+gap;i < end;i++)
        {
            tmp = A[i];
            for(j = i-gap;j >= start && tmp < A[j];j -= gap)
                A[j+gap] = A[j];
            A[j+gap] = tmp;
        }
}















