#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //recursive
private:
    vector<int> result;
public:
     int minDepth(TreeNode *root) {
        return minDepth(root,false);
    }
    
    int minDepth(TreeNode *root, bool hasbrother)
    {
        if(!root) return hasbrother?INT_MAX:0;
        return 1 + min(minDepth(root->left,root->right), minDepth(root->right,root->left));
    }
    
    //simpler recursive
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right)+1;
        if (!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }


    //BFS
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int n = q.size();
            while(n--)
            {
                TreeNode * node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
            }
        }
        return depth;
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
    const int s = 9;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);
    
    int depth = mySol.minDepth(myTree);

    cout << "Minimum deepth : " << depth << endl;


    return 0;
}
