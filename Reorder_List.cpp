#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:

    void reorderList(ListNode *head) {
        
        if(!head || !head->next) return;
        ListNode *slow, *fast;
        slow = fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = reverse(slow->next);
        slow -> next = NULL;
        

        while(p2) {
            ListNode *p1n = p1 -> next;
            ListNode *p2n = p2 -> next;
            p1 -> next = p2;
            p2 -> next = p1n;
            p1 = p1n;
            p2 = p2n;
        }
        
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode * p = head;
        ListNode * q = p->next;
        while(q)
        {
            p->next = q->next;
            q->next = dummy->next;
            dummy->next = q;
            
            q = p->next;
        }
        
        return dummy->next;
    }

    

};

int main() {

    const int s = 5;
    int myArr[s] = {1, 2, 3, 4, 5};
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


    
    mySol.reorderList(myList) ;

    rlist = myList;
    do {
        cout  << rlist->val << "  ";
        rlist = rlist->next;
    }while(rlist);
    cout << endl;

    return 0;
}
