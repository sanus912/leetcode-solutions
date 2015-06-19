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

    bool isBalanced(TreeNode *root) {
        int height = 0;
        return Helper(root,height);
    }
    
    bool Helper(TreeNode *root, int & height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        int l,r;
        bool flag1 = Helper(root->left,l);
        bool flag2 = Helper(root->right,r);
        height = max(l,r)+1;
        return (flag1 && flag2 && abs(l-r)<=1);
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
    
    cout << mySol.isBalanced(myTree) << endl;


    return 0;
}
