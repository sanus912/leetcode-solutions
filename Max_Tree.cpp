#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};

class Solution {
    public:

        TreeNode* maxTree_2(vector<int> A) {
            stack<TreeNode *> stk;
            A.push_back(INT_MAX);

            for (int i = 0; i < A.size(); ++i) {
                TreeNode *tmp = new TreeNode(A[i]);
                if (stk.empty() || A[i] < stk.top()->val)
                {
                    stk.push(tmp);
                    continue;
                }
                while(!stk.empty() && A[i] >= stk.top()->val)
                {
                    TreeNode * t = stk.top();
                    stk.pop();
                    if (stk.empty())
                        tmp->left = t;
                    else
                    {
                        if (A[i] > stk.top()->val)
                            stk.top()->right = t;
                        else
                            tmp->left = t;
                    }
                }
                stk.push(tmp);
            }
            return stk.top()->left;
        }

        TreeNode* maxTree(vector<int> A) {
            vector<TreeNode *> stk;
            int len = A.size();
            for (int i = 0; i < len; ++i) {
                TreeNode *tmp = new TreeNode(A[i]);
                while (stk.size() > 0 && A[i] > stk.back()->val) {
                    tmp->left = stk.back();
                    stk.pop_back();
                }
                if (stk.size() > 0)
                    stk.back()->right = tmp;
                stk.push_back(tmp);
            }
            return stk[0];
        }

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

int main() {

    const int s = 6;
    int myArr[s] = {2, 5,6,0,3,1};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    TreeNode * mTree= mySol.maxTree_2(myv);

    vector<vector<int> > ss = mySol.levelOrder(mTree);
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
