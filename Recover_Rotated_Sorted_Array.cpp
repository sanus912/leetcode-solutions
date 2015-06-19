#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recover(int nums[], int n) {
        for (int i=0;i<n;i++)
        {
            if (nums[i]>nums[i+1])
            {
                reverse(nums,0,i);
                reverse(nums,i+1,n-1);
                reverse(nums,0,n-1);
                return;
            }
        }
    }

    void reverse(int nums[],int start, int end)
    {
        while(start<end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};

int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {6, 7, 2, 2, 4, 5, 6, 6};


    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;

    mySol.recover(myArr, s);

    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;



    return 0;
}
