#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    //DP
    int Jump_2(int A[], int n) {
        int f[n];
        
        f[0]=0;

        for (int i = 1;i<n;i++)
        {
            f[i] = INT_MAX;
            for (int j=0;j<i;j++)
                if (f[j]!=INT_MAX && j+A[j] >=i){
                    f[i]=min(f[i],f[j]+1);
                    break;
                }
        }

        
        return f[n-1];
    }


    //greedy
    int jump(int A[], int n) {

        if (!A || n == 0) {
            return -1;
        }
        int start = 0, end = 0, jumps = 0;
        while (end < n - 1) {
            jumps++;
            int farthest = end;
            for (int i = start; i <= end; i++) {
                if (A[i] + i > farthest) {
                    farthest = A[i] + i;
                }
            }
            start = end + 1;
            end = farthest;
        }
        return jumps;

    }
    
    
    

};


int main() {

    const int s = 5;
    int myArr[s] = {2,3,1,1,4};
    Solution mySol;

    int st = mySol.Jump_2(myArr, s);

    cout << " min steps needed : "  << st << endl; 

    return 0;
}
