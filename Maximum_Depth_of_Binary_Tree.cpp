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
private:
    vector<int> result;
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
    const int s = 9;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    int depth = mySol.maxDepth(myTree);

    cout << "Maximum deepth : " << depth << endl;


    return 0;
}
