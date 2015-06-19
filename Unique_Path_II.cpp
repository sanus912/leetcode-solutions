#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if( obstacleGrid.empty() || obstacleGrid[0].empty() ) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
  
        vector<int> route(n, 0);
        if (obstacleGrid[0][0] == 1) return 0;
        route[0] = 1;
        
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 0)
                route[j] = route[j-1] ;
        }
        
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1) 
                route[0] = 0;
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 0)
                    route[j] += route[j-1];
                else
                    route[j] = 0;
            }
        }
        
        return route[n-1];
    }

    int uniquePathsWithObstacles_1(vector<vector<int> > &obstacleGrid) {

        if( obstacleGrid.empty() ) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if( m <=0 || n<=0 ) return 0;
        vector<vector<int> > route(m, vector<int>(n, 0));

        if(obstacleGrid[0][0] == 0) route[0][0] = 1;

        for( int i = 1; i < m; i++ )
            if(obstacleGrid[i][0] == 0) route[i][0] = route[i-1][0]; 

        for( int j = 1; j < n; j++ )
            if(obstacleGrid[0][j] == 0) route[0][j] = route[0][j-1]; 

        for( int i = 1; i < m; i++ ) 
            for( int j = 1; j < n; j++ )
                if(obstacleGrid[i][j] == 0) route[i][j] = route[i-1][j] + route[i][j-1]; 

        return route[m-1][n-1];

    }
};


int main() {

    Solution mySol;
    vector<vector<int> > matrix(3, vector<int>(3, 0));

    matrix[1][1] = 1;
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "\t" ;
        }
        cout << endl;
    }


    cout << mySol.uniquePathsWithObstacles(matrix) << endl;


    return 0;
}
