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

/**********************************************************************/

void bubble_sort(int A[],const int start,const int end)
{
    for(int i = start;i < end-1;i++)
    {
        bool exchange = false;
        for(int j = end-1;j > i;j--)
            if (A[j-1] > A[j])
            {
                int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                exchange = true;
            }
        if (!exchange)
            return ;
    }
}

/**********************************************************************/

void selection_sort(int A[],const int start,const int end)
{
    int i,j;

    for(i = start;i < end;i++)
    {
        int pos = i;
        for(j = i+1;j < end;j++)
            if (A[j] < A[pos])
                pos = j;
        if (pos != i)
        {
            int tmp = A[pos];
            A[pos] = A[i];
            A[i] = tmp;
        }
    }
}

/**********************************************************************/

void merge(int A[],int tmp[],const int start,const int mid,const int end)
{
    int i,j,k;

    for(i = start;i < end;i++)
        tmp[i] = A[i];
    i = start,j = mid,k = start;
    while (i < mid && j < end)
        if (tmp[i] < tmp[j])
            A[k++] = tmp[i++];
        else
            A[k++] = tmp[j++];
    while (i < mid)
        A[k++] = tmp[i++];
    while (j < end)
        A[k++] = tmp[j++];
}

void merge_sort(int A[],int tmp[],const int start,const int end)
{
    if (start < end-1)
    {
        int mid = start + (end-start>>1);
        merge_sort(A,tmp,start,mid);
        merge_sort(A,tmp,mid,end);
        merge(A,tmp,start,mid,end);
    }
}

/**********************************************************************/

#define LeftChild(i) (2*(i) + 1)

void percolate_down(int a[],int i,int n)
{
    int tmp,child;

    for(tmp = a[i];LeftChild(i) < n;i = child)
    {
        child = LeftChild(i);
        if (child != n-1 && a[child+1] > a[child])
            child++;
        if (tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}
void heap_sort(int a[],const int n)
{
    int i;

    for(i = n/2;i >= 0;i--) //build heap
        percolate_down(a,i,n);
    for(i = n-1;i > 0;i--)
    {
        swap(a[0],a[i]);    //delete max
        percolate_down(a,0,i);
    }
}




















































