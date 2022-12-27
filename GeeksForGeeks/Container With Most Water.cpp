//User function template for C++

long long maxArea(long long A[], int len)
{
    long long max_area = 0;
    int i = 0, j = len - 1;
    while(i<j){
        max_area = max(max_area, (j-i) * min(A[i], A[j]));
        if(A[i] < A[j])
            i++;
        else
            j--;
    }
    return max_area;
}
