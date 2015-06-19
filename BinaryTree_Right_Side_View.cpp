#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        Helper(root,res,1);
        return res;
    }
    
    void Helper(TreeNode *root,vector<int> &res, int level)
    {
        if (!root)
            return;
        if (level>res.size())
            res.push_back(root->val);
       
        Helper(root->right,res,level+1);
        Helper(root->left,res,level+1);
        
    } 

};

TreeNode* makeBST(int *arr, int start, int end) {
   
    if(start > end) return NULL;
    int mid = start + (end-start)/2; 

    TreeNode *node = new TreeNode(arr[mid]);
    node->left = makeBST(arr, start, mid-1);
    node->right = makeBST(arr, mid+1, end);

    return node;
}

int main() {

    Solution mySol;
    const int s = 5;
    int myArr1[s] = {1, 2, 3, 4, 5};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);
    myTree->right->right=NULL;
    vector<int> myvector;

    myvector = mySol.rightSideView(myTree);
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    
    

    return 0;
}
