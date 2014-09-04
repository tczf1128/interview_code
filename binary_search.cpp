/************************* binary search *****************************/

int binary_search(int A[],int n,int target)
{
    int low = 0,high = n-1;     // another way: high = n
    while(low <= high)          // another way: low < high
    {
        int mid = low + (high-low >> 1);
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;     // another way: high = mid
    }
    return -1;
}

int binary_search(int a[],int low,int high,int target){
    if (low > high)
        return -1;
    int mid = low + (high-low>>1);
    if (target < a[mid])
        return binary_search(a,low,mid-1,target);
    else if (target > a[mid])
        return binary_search(a,mid+1,high,target);
    else
        return mid;
}

/**********************************************************************/

int find_lower_bound(int A[],int n,int target)
{
    int low = 0,high = n-1;
    while (low <= high)
    {
        int mid = low + (high-low>>1);
        if (A[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (A[low] == target)
        return low;
    return -1;
}

int find_upper_bound(int A[],int n,int target)
{
    int low = 0,high = n-1;
    while (low <= high)
    {
        int mid = low + (high-low>>1);
        if(A[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (A[high] == target)
        return high;
    return -1;
}

/**********************************************************************/



