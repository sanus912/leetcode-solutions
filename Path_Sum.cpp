#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

    bool hasPathSum_2(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == sum;

        return hasPathSum_2(root->left,sum-root->val)||hasPathSum_2(root->right,sum-root->val);
    }

    //DFS
    bool hasPathSum(TreeNode *root, int sum) {
       if (!root)
            return false;
        return dfs(root,0,sum);
    }
    
    bool dfs(TreeNode *root, int temp, int sum)
    {
        if(!root) 
            return false;

        temp += root->val;
        if (!root->left && !root->right)
        {
            return temp == sum;
        }

        return dfs(root->left,temp,sum) || dfs(root->right,temp,sum);
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

    vector<int> myvector;

    
    bool has;
    for(int i = 5; i < 25; i++) {
        has = mySol.hasPathSum_2(myTree, i);
        if(has)
            cout << "has sum = "<< i <<" ? Yes!" << endl;
        else
            cout << "has sum = "<< i <<" ? No!" << endl;
    }




    return 0;
}
