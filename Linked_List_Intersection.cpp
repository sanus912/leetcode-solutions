#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = 0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * pa = headA;
        ListNode * pb = headB;
        while (pa && pb)
        {
            if (pa == pb)
                return pa;
            pa = pa->next;
            pb = pb->next;
        }
        int l1=0,l2=0;
        if (pa)
        {
            while(pa)
            {
                l1++;
                pa = pa->next;
            }
            pa = headA;
            while(l1--)
            {
                pa = pa->next;
            }
            pb = headB;
        }
        else if (pb)
        {
            while(pb)
            {
                l2++;
                pb = pb->next;
            }
            pb = headB;
            while(l2--)
            {
                pb = pb->next;
            }
            pa = headA;
        }
        while (pa && pb)
        {
            if (pa == pb)
                return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
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

int main() {

    int myArr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int myArr2[] = {9, 10, 11, 12};
    ListNode * mylist1 = arraytolist(myArr1,8);
    ListNode * mylist2 = arraytolist(myArr2,4);
    ListNode * p = mylist2;
    while (p->next) p=p->next;
    ListNode * q = mylist1;
    int t = 3;
    while (t--) q=q->next;
    p->next = q;

    Solution mySol;

    ListNode * res = mySol.getIntersectionNode(mylist1, mylist2);
    if (!res) 
        cout << "NULL" << endl;
    else
        cout << res->val << endl;


    return 0;
}
