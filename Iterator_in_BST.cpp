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
 
class BSTIterator {
public:

    TreeNode * cur;
    stack<TreeNode*> stk;
    
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!stk.empty() || cur);
    }

    /** @return the next smallest number */
    int next() {
        while(cur) 
        {
            stk.push(cur);
            cur = cur -> left;
        }
         
        cur = stk.top();
        stk.pop();
        int res = cur->val;
        cur = cur -> right;
            
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

    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);

    BSTIterator i = BSTIterator(myTree);
     
    while (i.hasNext()) cout << i.next() << " ";


    return 0;
}
