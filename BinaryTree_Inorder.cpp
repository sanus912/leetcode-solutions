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

    vector<int> inorderTraversal_it(TreeNode *root) {   

        vector<int> res;
        if( !root ) return res;

        unordered_map<TreeNode*,bool> visited;
        stack<TreeNode*> stk;
        stk.push(root);

        while( !stk.empty() ) {
            TreeNode* node = stk.top();

            if (node->left && !visited[node->left])
            {
                stk.push(node->left);
                continue;
            }

            if (!visited[node])
            {
                res.push_back(node->val);
                visited[node] = true;
            }

            if (node->right && !visited[node->right])
            {
                stk.push(node->right);
                continue;
            }
            stk.pop();
          
        }
        return res;
    }

    vector<int> inorderTraversal_it2(TreeNode *root) {   // hackersun007 or  wiki

        vector<int> res;
        if( !root ) return res;

        stack<TreeNode*> stk;
        TreeNode *p=root;

        while( !stk.empty() || p ) {

            if( p) {
                stk.push(p);
                p = p -> left;
            }
            else {
                p = stk.top();
                stk.pop();
                res.push_back(p->val);
                p = p -> right;
            }
        }


        return res;
    }

    //Recursive
    vector<int> inorderTraversal_R(TreeNode *root) {

        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode *node, vector<int> &res ) {
        if(node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
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
    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);
    vector<int> myvector;

    myvector = mySol.inorderTraversal_R(myTree);
    cout << "Preorder Traversal Recursively :" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.inorderTraversal_it(myTree);
    cout << "Preorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.inorderTraversal_it2(myTree);
    cout << "Preorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    

    return 0;
}
