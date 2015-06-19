#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return NULL;
        if (n==0) return head;
        
        ListNode * p = head;
        ListNode * q = head;
        while(n>0 && q)
        {
            q = q->next;
            n--;
        }
        if (!q && n==0) return head->next;
        if (!q && n>0) return NULL;
        
        while(q->next)
        {
            p = p->next;
            q = q->next;
        }
        
        q = p->next;
        p->next = q->next;
        delete q;
        
        return head;
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

    int myArr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution mySol;

    // make & construct our linked list
    ListNode * mylist = arraytolist(myArr1,9);

    printlist(mylist);

    ListNode * rlist = mySol.removeNthFromEnd(mylist, 1);

    printlist(rlist);

    return 0;
}
