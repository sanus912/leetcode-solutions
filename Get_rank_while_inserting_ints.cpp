#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct RankTreeNode {
     int val;
     int leftsize;
     RankTreeNode *left;
     RankTreeNode *right;
     RankTreeNode(int x) : val(x), leftsize(0), left(NULL), right(NULL) {}
};
 
class Solution {
public:

    //recursion
    RankTreeNode* insertNode(RankTreeNode * root, int d) {
        if (!root) 
            return new RankTreeNode(d);

        if (d <= root->val) {
            root->left = insertNode(root->left, d);
            root->leftsize++;

        } else {
            root->right = insertNode(root->right, d);
        }
        return root;
    }

    int getRank(RankTreeNode * root, int d)
    {
        if (root->val == d)
            return root->leftsize;
        else if (d < root->val && root->left)
            return getRank(root->left,d);
        else if (d > root->val && root->right)
            return getRank(root->right,d) + 1 + root->leftsize;
        else
            return -1;
    }
    
    void levelOrder(RankTreeNode *root) {
        if (!root) 
            return;
        
        queue<RankTreeNode *> level_nodes;
        level_nodes.push(root);

        while (!level_nodes.empty()) {
            int n = level_nodes.size();
            while(n>0)
            {
                RankTreeNode * q = level_nodes.front();
                cout << q->val << "(" << q->leftsize << ")" << "   ";
                level_nodes.pop();
                if(q->left)
                    level_nodes.push(q->left);
                if(q->right)
                    level_nodes.push(q->right);
                n--;
            }
            cout << endl;
        }
    }
};

int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {20, 15, 25, 10, 5, 13, 23, 24};

    RankTreeNode* root = NULL;
    for (int a : myArr)
        root = mySol.insertNode(root,a);

    mySol.levelOrder(root);

    for (int a : myArr)
        cout << a << "'s rank is " << mySol.getRank(root,a) << endl;
        
     

    return 0;
}
