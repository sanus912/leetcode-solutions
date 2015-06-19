#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = 0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    //merge sort
    ListNode *sortList(ListNode *head) {
        
        if(!head || !(head->next)) return head;

        ListNode *slow, *fast;
        slow = head;
        fast = head;

        while(fast->next && fast->next->next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeTwoLists(l1, l2);
    }

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

ListNode * arraytolist(int A[], int n)
{
    if (n<=0) return NULL;

    ListNode * head = new ListNode(A[0]);
    ListNode * p = head;

    for (int i =1;i<n;i++)
    {
        ListNode * node = new ListNode(A[i]);
        p->next = node;
        p = p->next;
    }
    return head;
}

void printlist(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";	
        head = head->next;
    }
    cout << endl;
}

int main() {

    int arr[] = {4, 2, 3, 1, 6, 7, 5, 0};
    Solution mySol;

    ListNode * mylist = arraytolist(arr,8);

    ListNode * rlist = mySol.sortList(mylist);
    printlist(rlist);


    return 0;
}
