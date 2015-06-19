#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

    //non-recursion
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!root) 
            return node;

        TreeNode * p = root;
        TreeNode * last = NULL;
        while(p)
        {
            last = p;
            if (node->val <= p->val)
                p = p->left;
            else
                p = p->right;
        }

        if (node->val <= last->val)
            last->left = node;
        else
            last->right = node;

        return root;
    }

    //recursion
    TreeNode* insertNode_R(TreeNode* root, TreeNode* node) {
        if (!root) 
            return node;

        if (node->val <= root->val) {
            root->left = insertNode(root->left, node);

        } else {
            root->right = insertNode(root->right, node);
        }
        return root;
    }

    void inorder(TreeNode *root) {
        if(root) {
            inorder(root->left);
            cout << root->val << endl;
            inorder(root->right);
        }
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

    TreeNode * node = new TreeNode(0);

    TreeNode * newTree = mySol.insertNode(myTree,node);
    mySol.inorder(newTree);


    return 0;
}
