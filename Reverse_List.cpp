#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:

    //换方向
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m >= n || !head) {
            return head;
        }

        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode * pt = dummy;
        for (int i = 0; i<m-1;i++)
        {
            if (!pt) return NULL;
            pt = pt->next;
        }
        
        ListNode * tail = pt->next;
        ListNode * p = tail;
        ListNode * q = p->next;
        ListNode * temp;
        for (int i = m;i<n;i++)
        {
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        
        pt->next = p;
        tail->next = temp;
        return dummy->next;
    }

    //换方向
    ListNode *reverse(ListNode *head) {
        
        
        ListNode * p = NULL;

        while(head)
        {
            ListNode * temp = head->next;
            head->next = p;
            p = head;
            head = temp;
        }
        
        return p;
    }

    //插头法
    ListNode *reverseBetween_2(ListNode *head, int m, int n) {
        if (m >= n || !head) {
            return head;
        }

        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode * p = dummy;
        for (int i = 0; i<m-1;i++)
            p = p->next;
        
        ListNode * newdummy = p;
        p = newdummy->next;
        ListNode * q = p->next;
        for (int i = m;i<n;i++)
        {
            p->next = q->next;
            q->next = newdummy->next;
            newdummy->next = q;
            
            q = p->next;
        }
        
        return dummy->next;
    }

    //插头法
    ListNode *reverse_2(ListNode *head) {
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

    int myArr[] = {1, 4, 3, 2, 5, 2};
    Solution mySol;

    // make & construct our linked list
    ListNode * mylist = arraytolist(myArr,6);
    printlist(mylist);

    ListNode * rlist = mySol.reverseBetween(mylist, 2,4);
    printlist(rlist);

    rlist = mySol.reverse_2(rlist);
    printlist(rlist);

    return 0;
}
