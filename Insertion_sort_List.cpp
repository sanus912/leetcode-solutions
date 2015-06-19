#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        ListNode * dummy = new ListNode(INT_MIN);
        dummy->next = head;
        
        ListNode * pre = head;
        ListNode * cur = head->next;
        while(cur)
        {
            auto pos = findintertpos(dummy, cur, cur->val);
            if (pos == pre)
            { pre = pre->next;
            cur=cur->next;
            }
            else
            {
            pre->next = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            
            cur = pre->next;
            }
            
        }
        return dummy->next;
    }
    
    ListNode *findintertpos(ListNode *dummy, ListNode *end, int x) {
        ListNode * pre = dummy;
        ListNode * cur = dummy->next;
        while (cur != end && cur->val<=x)
        {
            pre = pre->next;
            cur=cur->next;
        }
        return pre;
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

    ListNode * rlist = mySol.insertionSortList(mylist);
    printlist(rlist);

    return 0;
}
