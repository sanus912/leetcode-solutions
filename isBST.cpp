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

    //recursive
    bool flag = true;
    int pre;
    bool isValidBST(TreeNode *root) {
        if( !root ) return true;


        if (!isValidBST(root->left))
            return false;


        if( root->val <= pre && !flag) 
            return false;
        flag = false;
        pre = root->val;

        if (!isValidBST(root->right))
            return false;

        return true;
    }

    //iterative
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        unordered_map<TreeNode *, bool> visited;
        stack<TreeNode *> stk;
        stk.push(root);
        int pre;
        bool flag = true;
        while(!stk.empty())
        {
            TreeNode * node = stk.top();
            if (node->left && !visited[node->left])
            {
                stk.push(node->left);        
                continue;
            }

            if (!visited[node])
            {
                if (pre >= node->val&& !flag)
                    return false;
                pre = node->val;
                flag = false;

                visited[node] = true;

            }

            if (node->right && !visited[node->right])
            {
                stk.push(node->right);
                continue;
            }

            stk.pop();
        }
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if( !root ) return true;
        stack<TreeNode*> s;
        int pre;
        bool flag = true;

        // inorder Traversal
        while( !s.empty() || root ) {
            if( root) {
                s.push(root);
                root = root -> left;
            }
            else{
                root = s.top();
                s.pop();

                // check order here
                if( root -> val <= pre && !flag) 
                    return false;

                flag = false;

                pre = root -> val;

                root = root -> right;
            }
        }

        return true;
    }

    //min~max
    bool isValidBST(TreeNode *root) 
    {
        return isValid(root,NULL,NULL);
    }
    bool isValid(TreeNode *root, int * min, int * max)
    {
        if (root == NULL)
                return true;
        return ((min==NULL || root->val > *min) 
                && (max==NULL || root->val < *max)
                && isValid(root->left, min, &(root->val))
                && isValid(root->right, &(root->val), max));
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

    cout << mySol.isValidBST(myTree);


    return 0;
}
