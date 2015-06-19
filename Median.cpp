#include<iostream>  
#include<algorithm>  
#include<functional>  
#include <queue>
using namespace std;  

class Solution {
public:
    //Quick select O(n)
    int median(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int k = left + (right - left)/2 + 1;
        return quickselect(nums,left,right,k);
    }

    int quickselect(vector<int> &a, int left, int right, int k)
    {
        if (left <= right)
        {
            int q = partition(a,left,right);
            int id = q-left+1;
            if (id == k)
                return a[q];
            else if (k < id)
                return quickselect(a,left,q-1,k);
            else
                return quickselect(a,q+1,right,k-id);
        }
    }

    int partition(vector<int> &a, int left, int right) {
        int i = left;
        for (int j = left; j < right; j++) {
            if (a[j] <= a[right]) {
                swap(a[i], a[j]);
                i++;
            }
        }
        swap(a[i],a[right]);
        return i;
    }


    int median_2(vector<int> &nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        priority_queue<int,vector<int>,less<int> > 
            max_heap(nums.begin(),nums.begin()+(n+1)/2);//左边的数
        priority_queue<int,vector<int>,greater<int> > 
            min_heap(nums.begin()+(n+1)/2,nums.end());//右边的数

        while (max_heap.top()>min_heap.top())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        return max_heap.top();
    }


};

int main()  
{  
    Solution mySol;
    vector<int> myvec={1,2,3,4,5};  

    cout << mySol.median(myvec) << endl;
    return 0;  
} 


