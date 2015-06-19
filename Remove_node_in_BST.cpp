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

    TreeNode *removeNode(TreeNode * root, int value) 
    {   TreeNode * dummy = new TreeNode(0);
        dummy->left = root;
        
        TreeNode *parent = findNode(dummy, root, value);
        TreeNode *node;
        if (parent->left && parent->left->val == value) {
            node = parent->left;
        } else if (parent->right && parent->right->val == value) {
            node = parent->right;
        } else {
            return dummy->left;
        }
        
        deleteNode(parent, node);
        
        return dummy->left;
    }
    
    TreeNode * findNode(TreeNode *parent, TreeNode *node, int value) {
        if (!node) {
            return parent;
        }
        
        if (node->val == value) {
            return parent;
        }
        if (value < node->val) {
            return findNode(node, node->left, value);
        } else {
            return findNode(node, node->right, value);
        }
    }
    
    void deleteNode(TreeNode *parent, TreeNode *node) {
        if (!node->right) {
            if (parent->left == node) {
                parent->left = node->left;
            } else {
                parent->right = node->left;
            }
        } else {
            TreeNode *temp = node->right;
            TreeNode *father = node;
            
            while (temp->left) {
                father = temp;
                temp = temp->left;
            }
            
            if (father->left == temp) {
                father->left = temp->right;
            } else {
                father->right = temp->right;
            }
            
            if (parent->left == node) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            
            temp->left = node->left;
            temp->right = node->right;
        }
    }

    void inorder(TreeNode *root) {
        if(root) {
            inorder(root->left);
            cout << root->val << endl;
            inorder(root->right);
        }
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        queue<TreeNode *> level_nodes;
        vector<int> one;
        level_nodes.push(root);

        while (!level_nodes.empty()) {
            one.clear();
            int n = level_nodes.size();
            while(n>0)
            {
                TreeNode * q = level_nodes.front();
                one.push_back(q->val);
                level_nodes.pop();
                if(q->left)
                    level_nodes.push(q->left);
                if(q->right)
                    level_nodes.push(q->right);
                n--;
            }
            result.push_back(one);
        }

        //reverse(result.begin(), result.end());
        return result;

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
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    vector<vector<int> > ss = mySol.levelOrder(myTree);
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }

    TreeNode * newTree = mySol.removeNode(myTree,2);
    mySol.inorder(newTree);

    ss = mySol.levelOrder(myTree);
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }



    return 0;
}
