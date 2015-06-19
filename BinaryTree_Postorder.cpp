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

    vector<int> postorderTraversal(TreeNode *root) {   
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

            if (node->right && !visited[node->right])
            {
                stk.push(node->right);
                continue;
            }

            if (!visited[node])
            {
                res.push_back(node->val);
                visited[node] = true;
            }
            stk.pop();
          
        }
        return res;
    }

    //similar to preorderTraversal
     vector<int> postorderTraversal_s(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *p;
        
        if(!root) return res;
        stk.push(root);
        
        while( !stk.empty() ) {
            p = stk.top(); 
            stk.pop();
            res.push_back(p->val);
            if(p->left) stk.push(p->left);
            if(p->right) stk.push(p->right);
        }
        
        reverse(res.begin(), res.end());
        return res;  
    }

    //iterative 
   vector<int> postorderTraversal_IT(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        TreeNode *pre, *cur;
        stack<TreeNode*> s;
        
        pre = NULL;
        s.push(root);

        while(!s.empty()) {
            cur = s.top();
            if(!pre || pre->left == cur || pre->right ==cur) {
                if(cur->left) 
                    s.push(cur->left);
                else if (cur->right)
                    s.push(cur->right);
            } else {
                if(cur->left == pre) {
                    if(cur->right) s.push(cur->right);
                } else {
                    res.push_back(cur->val);
                    s.pop();
                }
            }
            pre = cur;
        }
        
        return res;
    }

    //Recursive
    vector<int> postorderTraversal_R(TreeNode *root) {

        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode *root, vector<int> &res) {
        if(root) {
            preorder(root->left, res);
            preorder(root->right, res);
            res.push_back(root->val);
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

    myvector = mySol.postorderTraversal(myTree);
    cout << "Postorder Traversal Iteratively :" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.postorderTraversal_R(myTree);
    cout << "Postorder Traversal Recursively :" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    myvector = mySol.postorderTraversal_IT(myTree);
    cout << "Postorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    

    return 0;
}
