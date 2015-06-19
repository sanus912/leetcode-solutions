#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string> >  res;

public:

    int totalNQueens(int n) {
        
        int tot = 0;
        if(n <= 0) return tot;
        vector<int> A(n, -1);

        dfs_tot(A, 0, n, tot);
        return tot;
        
    }

    void dfs_tot(vector<int> &A, int p, int n, int & tot) {
        if(p == n) {          // Find one solution
            tot ++;
        }
        else {
            for(int i = 0; i < n; i++) {    // Try all possible position
                A[p] = i;
                if(validConf(A, p)) dfs_tot(A, p + 1, n, tot);
            }
        }
    }

    bool validConf(vector<int> &A, int p) {
        for(int i = 0; i < p; i++)
            if(A[p] == A[i] || abs(A[p]-A[i]) == p - i) return false;
        return true;
    }

};

int main() {

    const int s = 8;
    Solution mySol;

        cout << endl;
    cout << "We have " << mySol.totalNQueens(s) << " different results" << endl;


    return 0;
}
