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

    //iterative DFS
    vector<int> preorderTraversal(TreeNode *root) {   
        vector<int> res;
        if( !root ) return res;

        unordered_map<TreeNode*,bool> visited;
        stack<TreeNode*> stk;
        stk.push(root);

        while( !stk.empty() ) {
            TreeNode* node = stk.top();
            if (!visited[node])
            {
                res.push_back(node->val);
                visited[node] = true;
            }

            if (node->left && !visited[node->left])
            {
                stk.push(node->left);
                continue;
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

    //iterative DFS --- simple
    vector<int> preorderTraversal_it(TreeNode *root) {

        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *p;

        if( !root ) return res;
        stk.push(root);

        while( !stk.empty() ) {

            p = stk.top();
            stk.pop();
            res.push_back(p->val);

            if(p->right) stk.push(p->right);
            if(p->left) stk.push(p->left);
        }
        return res;
    }

    //Recursive
    vector<int> preorderTraversal_R(TreeNode *root) {

        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode *root, vector<int> &res) {
        if(root) {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
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

    myvector = mySol.preorderTraversal_R(myTree);
    cout << "Preorder Traversal Recursively :" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.preorderTraversal_it(myTree);
    cout << "Preorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.preorderTraversal(myTree);
    cout << "Preorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    

    return 0;
}
