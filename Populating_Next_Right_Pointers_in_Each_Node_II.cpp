#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:

    //O(1) space
    void connect(TreeLinkNode *root) {
        while(root)
        {
            
            TreeLinkNode * prev = NULL;
            TreeLinkNode * next = NULL;
            while(root)
            {
                if(!next)
                    next = root->left? root->left : root->right;
                
                if(root->left)
                {
                    if(prev)
                       prev->next = root->left;
                    prev = root->left;
                }
                
                if(root->right)
                {
                    if(prev)
                       prev->next = root->right;
                    prev = root->right;
                }
                
                root = root->next;
            }
            root = next;
        }
    }
    
    //BFS, O(n) space
    void connect_2(TreeLinkNode *root) {

        if( !root ) 
            return;

        queue<TreeLinkNode *> level_nodes;
        vector<TreeLinkNode *> one;
        level_nodes.push(root);

        while (!level_nodes.empty()) {
            one.clear();
            int n = level_nodes.size();
            while(n>0)
            {
                TreeLinkNode * q = level_nodes.front();
                one.push_back(q);
                level_nodes.pop();
                if(q->left)
                    level_nodes.push(q->left);
                if(q->right)
                    level_nodes.push(q->right);
                n--;
            }
            for (int i = 1;i<one.size();i++)
            {
                one[i-1]->next = one[i];
            }
        }

    }
};

TreeLinkNode* makeBST(int *arr, int start, int end) {

    if(start > end) return NULL;
    int mid = (start + end)>>1;

    TreeLinkNode *node = new TreeLinkNode(arr[mid]);
    node->left = makeBST(arr, start, mid-1);
    node->right = makeBST(arr, mid+1, end);

    return node;
}

int main() {

    Solution mySol;
    const int s = 7;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7};
    TreeLinkNode * myTree = makeBST(myArr1, 0, s-1);

    mySol.connect(myTree);

    cout << myTree->left->next->val << endl;


    return 0;
}
