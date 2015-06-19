#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
         if (!head || !head->next)
            return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * newdummy =dummy;
        ListNode * p = head;
        while(p && p->next)//先判断是否存在再取next
        {
            ListNode * q = p->next;
            p->next = q->next;
            newdummy->next = q;
            q->next = p;
            
            newdummy = p;
            p = newdummy->next;
        }
        return dummy->next;
        
    }

};


int main() {

    const int s = 9;
    int myArr[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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

    rlist = mySol.swapPairs(myList);
    do {
        cout  << rlist->val << "  ";
        rlist = rlist->next;
    }while(rlist);
    cout << endl;


    return 0;
}
