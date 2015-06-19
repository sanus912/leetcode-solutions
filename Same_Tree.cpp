#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    vector<int> result;
public:
    //recursive
    bool isSameTree(TreeNode *p, TreeNode *q) {
        
        if( !p && !q)  return true;
        if( p && q && p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
        
    }

    //iterative
    bool isSameTree_I(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> stk;
        stk.push(p);
        stk.push(q);

        while( !stk.empty() ) {

            p = stk.top();
            stk.pop();
            q = stk.top();
            stk.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            stk.push(p->left);
            stk.push(q->left);
            stk.push(p->right);
            stk.push(q->right);
        }
        return true;
        
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
    const int s1 = 13, s2=12;
    int myArr1[s1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int myArr2[s2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    TreeNode * myTree1 = makeBST(myArr1, 0, s1-1);
    TreeNode * myTree2 = makeBST(myArr2, 0, s2-1);

    if(mySol.isSameTree(myTree1, myTree2))
        cout << "They are same ? " << "  Yes! "<< endl;
    else
        cout << "They are same ? " << "  No! "<< endl;
    

    return 0;
}
