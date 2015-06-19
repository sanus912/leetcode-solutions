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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (!root)
            return NULL;

        if (root == A || root == B)
            return root;

        TreeNode * x = lowestCommonAncestor(root->left, A, B);         
        TreeNode * y = lowestCommonAncestor(root->right, A, B); 

        if (x && y)
            return root;
        else if (x)
            return x;
        else if (y)
            return y;
        else
            return NULL;
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

TreeNode * find(TreeNode * tree_root, int data) {
	if (tree_root->val == data)
		return tree_root;
	else if (tree_root->right && tree_root->val < data)
		return find(tree_root->right, data);
	else if (tree_root->left && tree_root->val > data)
		return find(tree_root->left, data);
	else
		return NULL;
}

int main() {

    Solution mySol;
    const int s = 7;
    int myArr1[s] = {1,2,3,4,5,6,7};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    TreeNode * A = find(myTree, 3);
    TreeNode * B = find(myTree, 1);
    cout << A->val << endl;
    cout << B->val << endl;

    TreeNode * p = mySol.lowestCommonAncestor(myTree, A, B);

    cout << p->val << endl;





    return 0;
}
