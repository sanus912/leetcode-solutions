#include <iostream> 

using namespace std;

class Solution {
public:
    //DP
    int climbStairs(int n) {
        vector<int> f(n+1,-1);
        f[0]=1;
        f[1]=1;
        for( int i = 2; i <= n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
    //dfs
    int climbStairs(int n) {
        vector<int> f(n+1,-1);
        f[0]=1;
        f[1]=1;
        dfs(n,f);
        return f[n];
    }
    
    int dfs(int i, vector<int> &f)
    {   
        if (f[i]!=-1)
            return f[i];
        
        f[i] = dfs(i-1,f)+dfs(i-2,f);
        return f[i];
    }

    
    int climbStairs(int n) {

        return fb1(n);
        
    }

    //iterative
    int fb2(int n) {

        if( n==0 ) return 1;
        if( n==1 ) return 1;

        int res, t1, t2;
        
        t1 = 1;
        t2 = 1;
        for( int i = 2; i <= n; i++) {
            res = t1 + t2;
            t1 = t2;
            t2 = res;
        }

        return res;
    }

    //recursive
    int fb1(int n) {                    // Bad Way! Exceeding time limit!
        
        if( n==0 ) return 1;//!
        if( n==1 ) return 1;

        return fb1(n-1) + fb1(n-2);
    }


};

int main() { 

    Solution mySol;

    for( int i = 0; i < 40; i++)
        cout << " Climb Stairs " << i << " has methods  : " << mySol.climbStairs(i) << endl;

    return 0; 
}
