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
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        int res=0;
        dfs(root,0,res);
        return res;
    }
    
    void dfs(TreeNode *root, int sum, int &res)
    {
        if (!root) return;

        sum = sum*10 + root->val;
        if (!root->left && !root->right)
        {
            res += sum;
            return;
        }
        dfs(root->left,sum,res);
        dfs(root->right,sum,res);
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
    const int s = 7;
    int myArr1[s] = {3, 2, 3, 1, 3, 2, 3};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    int sum = mySol.sumNumbers(myTree);
    cout << "We have Sum Root to Leaf Numbers " << sum << endl;





    return 0;
}
