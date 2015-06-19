#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    //DP
    bool canJump_1(int A[], int n) {
        int f[n];
        f[0]=0;

        for (int i = 1;i<n;i++)
        {
            f[i] = max(f[i-1],A[i-1])-1;
            if (f[i]<0)
                return false;
        }
        return f[n-1]>=0;
    }

    //DP
    bool canJump_2(int A[], int n) {
        bool f[n];
        for (int i=0;i<n;i++)
            f[i]=false;
        
        f[0]=true;

        for (int i = 1;i<n;i++)
        {
            for (int j=0;j<i;j++)
                if (f[j] && j+A[j] >=i){
                    f[i]=true;
                    break;
                }
            if (f[i] == false)
                return false;
        }
        return f[n-1];
    }
    
    //greedy
    bool canJump(int A[], int n) {
        int reach = 0;
        for(int i=0;i<=reach && reach<n-1;i++)
        {
            reach = max(reach, i+A[i]);
        }
        return reach >= n-1;
    }

    

    


};


int main() {

    const int s = 1;
    int myArr[s] = {0};
    Solution mySol;

    if(mySol.canJump(myArr, s))
        cout << "Can Jump ? " << " True"<< endl;
    else
        cout << "Can Jump ? " << " False"<< endl;

    return 0;
}
