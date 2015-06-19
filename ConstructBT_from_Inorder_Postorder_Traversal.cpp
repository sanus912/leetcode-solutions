#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};
 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    vector<int> result;
public:

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> hs;
        int n = inorder.size();
        
        if( n != postorder.size() ) return NULL;
        for( int i = 0; i < n; i++) { hs[inorder[i]] = i; }

        return build(postorder, inorder, hs, n-1, 0, n-1);
        
    }

    TreeNode *build(vector<int> &post, vector<int> &in, unordered_map<int, int> &hs, int p, int i, int j) {

        if( i > j) return NULL;
        TreeNode *node = new TreeNode(post[p]);

        int m = hs[post[p]]; // We have m - i elements on left  j - m elemets on right, the total is j-i+1
        node -> left = build(post, in, hs, p-(j-m)-1, i, m-1);
        node -> right = build(post, in, hs, p-1, m+1, j);

        return node;
    }


    vector<int> postorderTraversal(TreeNode *root) {
        result.clear();
        postorder(root);
        return result;
    }
    
    void postorder(TreeNode *root) {
        if(root) {
            postorder(root->left);
            postorder(root->right);
            result.push_back(root->val);
        }
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


        vector<int> inorderTraversal(TreeNode *root) {
        result.clear();
        inorder(root);
        return result;
    }

    void inorder(TreeNode *root) {
        if(root) {
            inorder(root->left);
            result.push_back(root->val);
            inorder(root->right);
        }
    }

};


int main() {

    Solution mySol;
    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    TreeNode * myTree;
    vector<int> num (myArr1, myArr1+s);
    myTree = mySol.sortedArrayToBST(num);

    cout << "We have following inputed vector of int" << endl;
    for(vector<int>::iterator it = num.begin(); it != num.end(); it++) {
        cout  << "  " << *it ;
    }
    cout << endl;

    vector<int> inorder = mySol.inorderTraversal(myTree);
    cout << "The inorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;

    vector<int> postorder = mySol.postorderTraversal(myTree);
    cout << "postorder Traversal Recursively:" << endl; 
    for (vector<int>::iterator it = postorder.begin(); it != postorder.end(); ++it)
        cout << "  " << *it ;
    cout << endl;

    TreeNode* newTree = mySol.buildTree(inorder,postorder);

    inorder = mySol.inorderTraversal(newTree);
    cout << "The inorder traversal of the BST is" << endl;
    for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it)
        cout  << "  " << *it ;
    cout << endl;

    postorder = mySol.postorderTraversal(newTree);
    cout << "postorder Traversal Recursively:" << endl; 
    for (vector<int>::iterator it = postorder.begin(); it != postorder.end(); ++it)
        cout << "  " << *it ;
    cout << endl;
    


    return 0;
}
