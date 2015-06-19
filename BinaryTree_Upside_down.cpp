#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    //bottom-up
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        return dfs(root,NULL);
    }
    
    TreeNode * dfs(TreeNode *node, TreeNode *parent)
    {
        if (!node) return parent;
        
        TreeNode *root = dfs(node->left,node);
        node->left = parent?parent->right:NULL;
        node->right = parent;
        return root;
    }


    //stack
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root)
            return NULL;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode * q = root;
        TreeNode * npt = NULL;
        while(q->left)
        {
            if (q->right)
                stk.push(q->right);
            else
                stk.push(npt);
            
            stk.push(q->left);
            q = q->left;
        }
        
        TreeNode * res = new TreeNode(stk.top()->val);
        stk.pop();
        TreeNode * r = res;
        while(!stk.empty())
        {
            if (stk.top())
                r->left = new TreeNode(stk.top()->val);
            stk.pop();

            if (stk.top())
                r->right = new TreeNode(stk.top()->val);
            stk.pop();
            r = r->right;
        }
        
        return res;
    } 

};

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

int main() {

    Solution mySol;
    TreeNode * myTree = new TreeNode(1);
    myTree->left = new TreeNode(2);

    TreeNode * newTree = mySol.upsideDownBinaryTree(myTree);

    vector<vector<int> > ss = levelOrder(newTree);
    for(auto it = ss.begin(); it != ss.end(); it++) {
        for(auto is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }

    return 0;
}
