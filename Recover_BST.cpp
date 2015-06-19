#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    //inorder-traversal
    void recoverTree(TreeNode *root) {   
        if( !root ) return;
        unordered_map<TreeNode*,bool> visited;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *p1, *p2;
        p1 = p2 = NULL;

        while( !stk.empty() ) {
            TreeNode* node = stk.top();

            if (node->left && !visited[node->left])
            {
                stk.push(node->left);
                continue;
            }

            if (!visited[node])
            {
                if(pre->val > node->val) {
                    if(p1 == NULL) p1 = pre;
                    p2 = node;
                }
                pre = node;

                visited[node] = true;
            }

            if (node->right && !visited[node->right])
            {
                stk.push(node->right);
                continue;
            }
            stk.pop();
          
        }

        if(p1 && p2) swap(p1->val, p2->val);

        return;
    }

    //inorder-traversal
    void recoverTree_2(TreeNode *root) {
        if( !root ) return;
        stack<TreeNode*> stk;
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *cur = root;
        TreeNode *p1, *p2;
        p1 = p2 = NULL;
        
        while(!stk.empty() || cur) {
            if(cur) {
                stk.push(cur);
                cur = cur -> left;
            }
            else {
                cur = stk.top(); stk.pop();
                if(pre->val > cur->val) {
                    if(p1 == NULL) p1 = pre;
                    p2 = cur;
                }
                pre = cur;
                cur = cur -> right;
            }
            
        }
        if(p1 && p2) swap(p1->val, p2->val);
        
        return;
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) 
            return result;
        
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
    int myArr1[s] = {1, 3, 2, 4, 5, 6, 7};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    mySol.recoverTree(myTree);

    vector<vector<int> > ss = mySol.levelOrder(myTree);
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }

    return 0;
}
