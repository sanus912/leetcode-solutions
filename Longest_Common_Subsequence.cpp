#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> f(n+1, vector<int>(m+1,0)); 
        for (int i = 0; i<n;i++)
            for (int j = 0; j < m ; j++)
            {
                if (A[i]==B[j])
                    f[i+1][j+1] = f[i][j] + 1;
                else
                    f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
            }
        return f[n][m];
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;

    string A = "Hello World!";
    string B = "Hello !World!";
    
    cout <<  mySol.longestCommonSubsequence(A,B);




    return 0; 
}
