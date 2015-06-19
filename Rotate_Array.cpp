#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //三步翻转法
    void rotate(int nums[], int n, int k) {
        k = k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
    
    void reverse(int nums[], int b, int e)
    {
        while(b<e)
        {
            swap(nums[b],nums[e]);
            b++;
            e--;
        }
    }

    //stupid
    void rotate(int nums[], int n, int k) {
        k = k%n;
        if (k==0) return;
        vector<int> temp(nums+n-k,nums+n);
        for (int i=0;i<n-k;i++)
        {
            temp.push_back(nums[i]);
        }
        for (int i=0;i<n;i++)
        {
            nums[i]=temp[i];
        }
        
    }
};

int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {1, 2, 2, 2, 4, 5, 6, 6};


    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;

    mySol.rotate(myArr, s, 2);

    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;



    return 0;
}
