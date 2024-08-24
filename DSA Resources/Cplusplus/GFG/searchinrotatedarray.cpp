class Solution
{
public:
    int search(int A[], int l, int h, int key)
    {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int mid;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (A[mid] == key)
                return mid;
            // Identify which half portion of array is sorted
            if (A[l] <= A[mid])
            { // first half is sorted
                if (A[l] <= key and key <= A[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else
            { // second half is sorted
                if (A[mid] <= key and key <= A[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};