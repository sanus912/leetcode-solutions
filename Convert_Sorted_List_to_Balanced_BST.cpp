#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = 0) : val(x), next(NULL) {}
};
 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {

        ListNode *cur = head;
        int n = 0;

        while( cur ) {cur = cur ->next; n++;} 
        return STtoBST(head, 0, n-1);
        
    }

    TreeNode *STtoBST(ListNode *& list, int start, int end) {

        if(start > end) return NULL;
        //cout << start << " to " << end << endl;
        int mid = start + (end - start) / 2;
        TreeNode *lc = STtoBST(list, start, mid - 1);
        TreeNode *tp = new TreeNode(list->val);
        tp -> left = lc;
        list = list -> next ;
        tp -> right = STtoBST(list, mid + 1, end);

        return tp;

    }

    vector<vector<int> > levelOrder(TreeNode *root) {
    
        vector<vector<int> > res;
        vector<int> one;
        if( !root ) return res;
        queue<TreeNode*> q;

        int br_now, br_next;
        q.push(root);
        br_now = 1;
        br_next = 0;

        while( !q.empty() ) {

            TreeNode *t = q.front();
            q.pop();
            br_now--;

            if( t->left ){br_next++; q.push(t->left);}
            if( t->right ){br_next++; q.push(t->right);}

            one.push_back(t->val);
            if( br_now == 0) { 
                res.push_back(one);
                one.clear();
                br_now = br_next;
                br_next = 0;
            }
        }

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

    ListNode * myList = new ListNode(myArr1[0]);
    ListNode * p = myList;
    for(int i = 1; i < s; i++) {
        ListNode * newnode = new ListNode(myArr1[i]);
        p->next = newnode;
        p = p->next;
    }

    myTree = mySol.sortedListToBST(myList);

    ss = mySol.levelOrder(myTree);
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }

 

    return 0;
}
