#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if( grid.empty() || grid[0].empty() ) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> path(n,vector<int>(m,0));
    
        path[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) 
            path[i][0] = path[i-1][0] + grid[i][0];
        
        for(int j = 1; j < m; j++)
            path[0][j] = path[0][j-1] + grid[0][j];

        for(int i = 1; i < n; i++) 
            for(int j = 1; j < m; j++) 
                path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
        
        return path[n-1][m-1];
        
        
        
    }

};


int main() {

    int num_row = 5;
    int num_col = 9;
    vector< vector<int> > grid;

    grid.resize(num_row, vector<int> (num_col, 1));

    Solution mySol;

    cout << mySol.minPathSum( grid ) << endl;

    return 0;
}
