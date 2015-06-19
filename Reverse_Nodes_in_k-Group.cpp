#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return NULL;

        ListNode * dummy = new ListNode(-1);
        dummy->next =head;

        ListNode * newdummy = dummy;
        while(true)
        {
            ListNode * t = newdummy;
            int i;
            for (i=0;i<k && t->next;i++)
            {
                t =t->next;
            }
            if (i!=k)
                break;

            ListNode * p =newdummy->next;
            ListNode * q =p->next;
            for (int i=0;i<k-1;i++)
            {
                p->next = q->next;
                q->next = newdummy->next;
                newdummy->next = q;

                q = p->next;
            }

            newdummy = p;


        }


        return dummy->next;
    }

};


int main() {

    const int s = 9;
    int myArr[s] = {1, 2,3,4,5,6,7,8,9};
    ListNode * myList;
    ListNode * rlist;
    Solution mySol;

    // make & construct our linked list
    myList = new ListNode[s];


    for(int i = 0; i < s; i++) {
        myList[i].val = myArr[i];
        myList[i].next = &myList[i+1];
        cout  << myList[i].val << "  ";
    }
    cout << endl;
    myList[s-1].next = NULL;

    rlist = mySol.reverseKGroup(myList, 4);
    do {
        cout  << rlist->val << "  ";
        rlist = rlist->next;
    }while(rlist);
    cout << endl;


    return 0;
}
