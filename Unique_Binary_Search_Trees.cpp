#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:

    int numTrees(int n) {

        if( n < 0 ) return 0;
        vector<int> bst(n+1, 0);

        bst[0] = 1;
        for(int i = 1; i <= n; i++)
            for( int j = 0; j < i; j++) 
                bst[i] += bst[j] * bst[i-j-1];
            
        return bst[n];
    }

     int numTrees_2(int n) {
        
        if(n < 0) return 0;

        int res = 1;
        for(int i = 0; i < n; i++) 
            res = (2 * (2 * i + 1) * res ) / (i + 2);
        
        return res;
    }


};

int main() {

    Solution mySol;
    const int s = 12;

    for( int i = 0; i < s; i++) 
        cout << "Unique BST("<<i<<") = "<< mySol.numTrees(i) << "\t" << mySol.numTrees_2(i) <<endl;
    cout << endl;


    return 0;
}
