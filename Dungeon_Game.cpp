#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if( dungeon.empty() || dungeon[0].empty() ) return 0;
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> hp(n,vector<int>(m,0));
    
        hp[n-1][m-1] = max(1-dungeon[n-1][m-1],1);
        
        for(int j = m-2; j >= 0; j--)
            hp[n-1][j] = max(hp[n-1][j+1]-dungeon[n-1][j],1);
            
        for(int i = n-2; i >=0; i--) 
            hp[i][m-1] = max(hp[i+1][m-1]-dungeon[i][m-1],1);

        for(int i = n-2; i >=0; i--) 
            for(int j = m-2; j >=0; j--) 
                hp[i][j] = max(min(hp[i+1][j],hp[i][j+1])-dungeon[i][j],1);
        
        return hp[0][0];
    }

};


int main() {

    vector< vector<int> > grid = {{100}};

    

    Solution mySol;

    cout << mySol.calculateMinimumHP( grid ) << endl;

    return 0;
}
