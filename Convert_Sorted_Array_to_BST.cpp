#include <iostream>
#include <vector>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {

        return arrayToBST(num, 0, num.size()-1);

    }

    TreeNode *arrayToBST(vector<int> &num, int start, int end) {

        if( start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *node = new TreeNode(num[mid]);
        node->left = arrayToBST(num, start, mid-1);
        node->right = arrayToBST(num, mid+1, end);

        return node;
    }


    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        result.clear();
        preorder(root);
        return result;
    }

    void preorder(TreeNode *root) {
        if(root) {
            //cout << root->val << "  ";
            result.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }

};

int main() {

    Solution mySol;
    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};


    vector<int> num (myArr1, myArr1+s);
    vector<int>::iterator it;

    for(it = num.begin(); it != num.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;

    TreeNode * myTree = mySol.sortedArrayToBST(num);

    myTree = mySol.sortedArrayToBST(num);
vector<int> myvector;
    myvector = mySol.preorderTraversal(myTree);
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;
    

    return 0;
}
