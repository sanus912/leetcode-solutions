#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
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

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        unordered_map<int, int> hs;
        int n = inorder.size();
        
        if( n != preorder.size() ) return NULL;
        for( int i = 0; i < n; i++) { hs[inorder[i]] = i; }

        return build(preorder, inorder, hs, 0, 0, n-1);
        
    }

    TreeNode *build(vector<int> &pre, vector<int> &in, unordered_map<int, int> &hs, int p, int i, int j) {

        if( i > j) return NULL;
        TreeNode *node = new TreeNode(pre[p]);

        int m = hs[pre[p]]; // We have m - i elements on left  j - m elemets on right, the total is j-i+1
        node -> left = build(pre, in, hs, p+1, i, m-1);
        node -> right = build(pre, in, hs, p+m-i+1, m+1, j);

        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {

        return arrayToBST(num, 0, num.size()-1);

    }

    TreeNode *arrayToBST(vector<int> &num, int start, int end) {

        if( start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *node = new TreeNode(num[mid]);
        node->left = arrayToBST(num, start, mid-1);
        node->right = arrayToBST(num, mid+1, end);

        return node;
    }


    vector<int> preorderTraversal(TreeNode *root) {
        result.clear();
        preorder(root);
        return result;
    }

    void preorder(TreeNode *root) {
        if(root) {
            //cout << root->val << "  ";
            result.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode *root) {
        result.clear();
        inorder(root);
        return result;
    }

    void inorder(TreeNode *root) {
        if(root) {
            //cout << root->val << "  ";
            inorder(root->left);
            result.push_back(root->val);
            inorder(root->right);
        }
    }




};


int main() {

    Solution mySol;
    const int s = 8;
    int myArr1[s] = {-4,-10,3,-1,7,11,-8,2};

    TreeNode * myTree;
    vector<int> num (myArr1, myArr1+s);
    myTree = mySol.sortedArrayToBST(num);

    cout << "We have following inputed vector of int" << endl;
    for(vector<int>::iterator it = num.begin(); it != num.end(); it++) {
        cout  << "  " << *it ;
    }
    cout << endl;

    vector<int> preorder = mySol.preorderTraversal(myTree);
    cout << "The preorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = preorder.begin(); it != preorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;

    vector<int> inorder = mySol.inorderTraversal(myTree);
    cout << "The inorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;


    TreeNode* newTree = mySol.buildTree(preorder, inorder);

    preorder = mySol.preorderTraversal(newTree);
    cout << "The preorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = preorder.begin(); it != preorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;

   inorder = mySol.inorderTraversal(newTree);
    cout << "The inorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;

    return 0;
}
