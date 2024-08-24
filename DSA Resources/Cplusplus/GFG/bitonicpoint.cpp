class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        // code here
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return arr[s];
    }
};