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


    vector<vector<int> > ss = mySol.levelOrder(myTree);
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }



    return 0;
}
