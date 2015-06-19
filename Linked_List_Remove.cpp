#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = 0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = p->next;
        while(q)
        {
            if (q->val == val)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p=q;q=q->next;
            }
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

int main() {

    int myArr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode * mylist1 = arraytolist(myArr1,8);

    Solution mySol;

    ListNode * res = mySol.removeElements(mylist1,5);
    if (!res) 
        cout << "NULL" << endl;
    else
    {
        while (res)
        {
        cout << res->val << endl;
        res = res->next;
        }
    }


    return 0;
}
