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

/**********************************************************************/

int partition(int a[],const int start,const int end)
{
    const int pivot = a[end-1];
    int i = start-1,j;
    for(j = start;j < end-1;j++)
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    swap(a[i+1],a[end-1]);
    return i+1;
}
void quick_sort(int a[],const int start,const int end)
{
    if (start < end-1)
    {
        const int pos = partition(a,start,end);
        quick_sort(a,start,pos);
        quick_sort(a,pos+1,end);
    }
}
int rand_partition(int a[],const int start,const int end)
{
    int i = random(start,end);  //[start,end)
    swap(a[i],a[end-1]);
    return partition(a,start,end);
}
/*******************************************************************/
int partition(int a[],const int start,const int end)
{
    int i = start,j = end - 1;
    const int pivot = a[i];
    while(i < j)
    {
        while(i < j && a[j] >= pivot)
            j--;
        a[i] = a[j];
        while(i < j && a[i] <= pivot)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
void quick_sort(int a[],const int start,const int end)
{
    if(start < end - 1)
    {
        const int pos = partition(a,start,end);
        quick_sort(a,start,pos);
        quick_sort(a,pos+1,end);
    }
}
/*******************************************************************/
int median3(int a[],int left,int right)
{
    int mid = left + (right-left>>1);
    if(a[left] > a[mid])
        swap(a[left],a[mid]);
    if(a[left] > a[right])
        swap(a[left],a[right]);
    if(a[mid] > a[right])
        swap(a[mid],a[right]);
    swap(a[mid],a[right-1]);  //hide pivot
    return a[right-1];
}
void insertion_sort(int a[],const int n)
{
    int tmp;
    int i,j;
    for(i = 1; i < n; i++)
    {
        tmp = a[i];
        for(j = i - 1; j >= 0 && tmp < a[j]; j--)
            a[j+1] = a[j];
        a[j+1] = tmp;
    }
}
//[left,right]
#define Cutoff (3)
void quick_sort(int a[],const int left,const int right)
{
    int i,j;
    int pivot;
    if(left + Cutoff <= right)
    {
        pivot = median3(a,left,right);
        i = left,j = right - 1;
        for(; ;)
        {
            while(a[++i] < pivot){}
            while(a[--j] > pivot){}
            if(i < j)
                swap(a[i],a[j]);
            else
                break;
        }
        swap(a[i],a[right-1]);    //restore pivot
        quick_sort(a,left,i-1);
        quick_sort(a,i+1,right);
    }
    else
        insertion_sort(a+left,right-left+1);
}

/*******************************************************************/

















































