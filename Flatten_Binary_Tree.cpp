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
    void flatten(TreeNode *root) {
        if(!root) return;

        flatten(root->left);
        flatten(root->right);
        if (root->left)
        {
            TreeNode* p = root->left;
            while(p->right)
            { p = p->right;}
            p->right = root->right;
            root->right = root->left;
            root->left = NULL;
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
    const int s = 7;
    int myArr1[s] = {3, 2, 4, 1, 6, 5, 7};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    mySol.flatten(myTree);
    TreeNode *node = myTree;
    cout << "Check Flatten   : ";
    while( node) {
        cout << node->val << ", ";
        if( !node->left)  
            cout << "#, ";
        node = node->right;
    }
    cout << endl;

    return 0;
}
