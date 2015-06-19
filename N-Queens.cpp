#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:     
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n <= 0) return res;
        vector<int> A(n, -1);
        
        dfs(A, 0, n, res);
        return res;
    }
    
    void dfs(vector<int> &A, int p, int n,  vector<vector<string> > & res) {
        if(p == n) {
            print(A, n, res);
            return;
        }
        for(int i = 0; i < n; i++) {
            A[p] = i;
            if(validConf(A, p)) dfs(A, p + 1, n, res);
        }
    }
    
    bool validConf(vector<int> &A, int p) {
        for(int i = 0; i < p; i++) {
            if(A[p] == A[i] || abs(A[p]-A[i]) == p-i) return false;
        }
        return true;
    }
    
    void print(vector<int> &A, int n, vector<vector<string> > & res) {
        string line(n, '.');
        vector<string> one(n, line);
        for(int i = 0; i < n; i++) one[A[i]][i] = 'Q';
        res.push_back(one);
    }
};

int main() {

    const int s = 4;
    Solution mySol;

    vector<vector<string> > ans = mySol.solveNQueens(s);
    vector<vector<string> >::iterator it;
    vector<string>::iterator is;
    for(it = ans.begin(); it != ans.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << endl; ;
        }
        cout << endl;
    }
    cout << endl;
    cout << "We have " << ans.size() << " different results" << endl;


    return 0;
}
