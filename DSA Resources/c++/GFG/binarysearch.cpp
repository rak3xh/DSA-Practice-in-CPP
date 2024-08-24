
class Solution
{
public:
    int binarysearch(int arr[], int n, int k)
    {
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (arr[mid] == k)
            {
                return mid;
            }
            else if (k > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
};