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
    bool isSymmetric(TreeNode * root)
    {
        if (!root)
            return true;
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        
        if( !p && !q)  return true;
        if( p && q && p->val == q->val) return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
        return false;
        
    }

    //iterative
    bool isSymmetric_I(TreeNode *p, TreeNode *q)
    {
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
            stk.push(q->right);
            stk.push(p->right);
            stk.push(p->left);
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
    const int s = 7;
    int myArr1[s] = {3, 2, 3, 1, 3, 2, 3};
    TreeNode * myTree = makeBST(myArr1, 0, s-1);
    

    bool has;
    has = mySol.isSymmetric(myTree);
    if(has)
        cout << "This tree is Symmetry? " <<"  Yes!" << endl;
    else
        cout << "This tree is Symmetry? " <<"  No!" << endl;




    return 0;

}
