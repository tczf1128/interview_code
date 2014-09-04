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

int searchInsert(int A[],int n,int target)
{
    if (A[n-1] < target)
        return n;
    int low = 0,high = n-1;
    while (low <= high)
    {
        int mid = low + (high-low>>1);
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

/**********************************************************************/

int search_rotate(int A[],int n,int target)
{
    // no duplicates
    int low = 0,high = n;
    while (low != high)
    {
        int mid = low + (high-low>>1);
        if (A[mid] == target)
            return mid;
        if (A[mid] >= A[low])   //left order
        {
            if (target < A[mid] && target >= A[low])
                high = mid;
            else
                low = mid + 1;
        }
        else                    //right order
        {
            if (target > A[mid] && target <= A[high-1])
                low = mid + 1;
            else
                high = mid;
        }
    }
    return -1;
}

bool search_rotate(int A[],int n,int target)
{
    // has duplicates
    int low = 0,high = n-1;
    while (low <= high)
    {
        int mid = low + (high-low>>1);
        if (A[mid] == target)
            return true;
        if (A[mid] < A[low])        //right order
        {
            if (target > A[mid] && target <= A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (A[mid] > A[low])   //left order
        {
            if (target >= A[low] && target < A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
            low++;
    }
    return false;
}

/**********************************************************************/


