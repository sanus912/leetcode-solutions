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
public:

    //recursive DFS
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if (!root)
            return res;
        preorder(root,0,sum,path,res);
        return res;
    }
    
    void preorder(TreeNode *root, int temp, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (!root)
            return;

        path.push_back(root->val);
        temp += root->val;
        if (!root->left && !root->right)
        {
           if (temp == sum)
                res.push_back(path);
            
        }
        preorder(root->left,temp,sum,path,res);
        preorder(root->right,temp,sum,path,res);
        path.pop_back();
    }

    //iterative DFS, stack, preorder
    vector<vector<int>> path(TreeNode *root)
    {
        vector<int> path;
        
        vector<vector<int>> res;
        if( !root ) return res;

        unordered_map<TreeNode*,bool> visited;
        stack<TreeNode*> stk;
        stk.push(root);

        while( !stk.empty() ) {
            TreeNode* node = stk.top();
            if (!visited[node])
            {
                path.push_back(node->val);
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

            if (!node->left && !node->right)
            {
                res.push_back(path);
            }
            path.pop_back();
            stk.pop();
          
        }
        return res;

    }

    //iterative DFS, stack, print out stack
    vector<stack<TreeNode*>> path_2(TreeNode *root)
    {
        
        vector<stack<TreeNode*>> res;
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
                visited[node] = true;
            }

            if (!node->left && !node->right)
            {
                res.push_back(stk);
            }
            stk.pop();
          
        }
        return res;

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

    vector<vector<int> > ss = mySol.path(myTree);
    
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    vector<stack<TreeNode*>> res = mySol.path_2(myTree);

    for (auto a : res){
        while(!a.empty())
        {
            cout << a.top()->val << " ";
            a.pop();
        }
        cout << endl;
    }

    return 0;
}
