#include <iostream>
using namespace std;
// for understanding logic

void reverse(int a[], int n, int k)
{

    for (int i = 0; i < k; i++)
    {
        int start = (n - 1);
        int next = start - 1;
        while (start > 0)
        {
            swap(a[start], a[next]);
            start--;
            next--;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    reverse(a, n, k);
}

/*
//Solution one --------->

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            int start=(nums.size())-1;
            int next=start-1;
            while(start>0){
                swap(nums[start],nums[next]);
                start--;
                next--;
            }
        }
    }
};

//Solution two ------------->

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};

*/