#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode * dummy = new ListNode(-1);
        
                
        ListNode *p = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (!l1) 
        {
            p->next = l2;
        }
        if (!l2)
        {
            p->next = l1;
        }
        return dummy->next;
     
    }

};


int main() {

    const int s1 = 8;
    const int s2 = 8;
    int arr1[s1] = {1, 2, 5, 6, 7, 9, 9, 9};
    int arr2[s2] = {3, 4, 5, 6, 7, 8, 8, 8};
    ListNode * mylist1;
    ListNode * mylist2;

    Solution mySol;
    
    // make & construct our linked list
    mylist1 = new ListNode(arr1[0]);
    mylist2 = new ListNode(arr2[0]);


    ListNode * p1 = mylist1;
    cout  << p1->val << "  ";
    for(int i = 1; i < s1; i++) {
        ListNode * node = new ListNode(arr1[i]);
        p1->next = node;
        p1 = p1->next;
        cout  << p1->val << "  ";
    }
    cout << endl;

    ListNode * p2 = mylist2;
    cout  << p2->val << "  ";
    for(int i = 1; i < s2; i++) {
        ListNode * node = new ListNode(arr2[i]);
        p2->next = node;
        p2 = p2->next;
        cout  << p2->val << "  ";
    }
    cout << endl;

    ListNode * rlist = mySol.mergeTwoLists(mylist1, mylist2);

    while(rlist) {
        cout  << rlist->val << "  ";
        rlist = rlist->next;
    }
    cout << endl;

    return 0;
}
