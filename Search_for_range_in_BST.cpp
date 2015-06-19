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

    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> res;
        searchRange(root,k1,k2,res);
        return res;
    }
    void searchRange(TreeNode* root, int k1, int k2, vector<int> &res)
    {
        if (!root) {
            return;
        }
        if (root->val > k1) {
            searchRange(root->left, k1, k2,res);
        }
        if (root->val >= k1 && root->val <= k2) {
            res.push_back(root->val);
        }
        if (root->val < k2) {
            searchRange(root->right, k1, k2,res);
        }
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

    vector<int> myvec = mySol.searchRange(myTree,2,6);
    for(auto r : myvec)
        cout << r << " ";


    return 0;
}
