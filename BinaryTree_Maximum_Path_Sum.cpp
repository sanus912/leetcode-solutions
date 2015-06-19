#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
    vector<int> result;
public:
    int maxPathSum(TreeNode *root) {
        int maxsum = INT_MIN;
        Helper(root,maxsum);
        return maxsum;
    }
  
    //return single path >= 0
    int Helper(TreeNode *root, int &maxsum)
    {
        if(!root)
            return 0;
        
        int l = Helper(root->left, maxsum);
        int r = Helper(root->right, maxsum);
        
        maxsum = max(maxsum,root->val+l+r);

        return max(max(r,l)+root->val,0);
        
    }
};

TreeNode* makeBST(int *arr, int start, int end) {
   
    if(start > end) return NULL;
    int mid = (start + end)>>1;

    TreeNode *node = new TreeNode(arr[mid]);
    node->left = makeBST(arr, start, mid-1);
    node->right = makeBST(arr, mid+1, end);

    return node;
}

int main() {

    Solution mySol;
    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    int maxpath = mySol.maxPathSum(myTree);
    cout << "Maxium Sum is " << maxpath << endl;
    

    return 0;
}
