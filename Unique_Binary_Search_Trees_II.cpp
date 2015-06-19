#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        
        vector<TreeNode*> res;
        
        res = gen(1, n);
        return res;
    }
    
    vector<TreeNode*> gen(int s, int n) {
        
        vector<TreeNode*> res;
        if(s > n) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = s; i <= n; i++) {
            vector<TreeNode*> l_tree = gen(s, i-1);
            vector<TreeNode*> r_tree = gen(i+1, n);
            for(int p = 0; p < l_tree.size(); p++) 
                for(int q = 0; q < r_tree.size(); q++) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> left = l_tree[p];
                    cur -> right = r_tree[q];
                    res.push_back(cur);
                }
        }
        return res;
    }

    int numTrees(int n) {

        if( n < 0 ) return 0;
        vector<int> bst(n+1, 0);

        bst[0] = 1;
        for(int i = 1; i <= n; i++)
            for( int j = 1; j <= i; j++) 
                bst[i] += bst[j-1] * bst[i-j];
            
        return bst[n];
    }
};

int main() {

    Solution mySol;
    const int s = 10;

    for( int i = 0; i < s; i++) 
        cout << "Unique BST("<<i<<") = "<< mySol.numTrees(i) << endl;
    cout << endl;


    for( int i = 0; i < s; i++)  {
        vector<TreeNode*> t = mySol.generateTrees(i);
        cout << "Unique BST("<<i<<") = "<< t.size() << endl;
    }
    cout << endl;


    return 0;
}
