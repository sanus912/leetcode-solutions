#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()||grid[0].empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int group = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (grid[i][j] == '1' && !visited[i][j])
                {   
                    group++;
                    dfs(grid,visited,i,j);
                }
        return group;
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i<0 || j<0 || i>=grid.size() || j >= grid[0].size())
            return;

        if (visited[i][j])
            return;

        if (grid[i][j]=='0')
            return;

        visited[i][j]=true;
        
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }

};

int main() {

    Solution mySol;

    vector<vector<char> > matrix =
    {
        {'1','1'}
    };


    cout << mySol.numIslands(matrix) << endl;


    return 0;
}
