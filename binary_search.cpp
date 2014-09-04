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

int find_kth(int A[],int m,int B[],int n,int k)
{
    //kth of two sorted arrays,can has duplicates
    //always assum that m <= n
    if (m > n)
        return find_kth(B,n,A,m,k);
    if (m == 0)
        return B[k-1];
    if (k == 1)
        return min(A[0],B[0]);
    //divide k into two parts
    int pa = min(k/2,m),pb = k-pa;
    if (A[pa-1] < B[pb-1])
        return find_kth(A+pa,m-pa,B,n,k-pa);
    else if (A[ps-1] > B[pb-1])
        return find_kth(A,m,B+pb,n-pb,k-pb);
    else
        return A[pa-1];
}

/**********************************************************************/

//no duplicates ----> see jianzhi offer
int searchMinInRotateArray(int A[],int n)
{
    if (n == 1)
        return 0;
    int low = 0,high = n-1;
    while (low < high-1)
    {
        int mid = low + (high-low>>1);
        if (A[mid] < A[low])
            high = mid;
        else
            low = mid;
    }
    return A[low] < A[low+1] ? low : low+1;
}

int searchKthInRotateArray(int A[],int n,int k)
{
    int posMin = searchMinInRotateArray(A,n);
    return (posMin+k-1)%n;
}
int rotateMin(int A[],int n)
{
    int low = 0,high = n-1;
    int mid = low;

    while (A[low] >= A[high])
    {
        if (high - low == 1)
        {
            mid = high;
            break;
        }
        mid low + (high-low>>1);
        if (A[low] == A[high] && A[mid] == A[high])
            return miInOrder(A,low,high);
        if (A[mid] >= A[low])
            low = mid;
        else if (A[mid] <= A[high])
            high = mid;
    }
    return A[mid];
}
int miInOrder(int A[],int low,int high)
{
    int ret = A[low];
    for(int i = low+1;i <= high;i++)
        if (A[i] < ret)
            ret = A[i];
    return ret;
}






















