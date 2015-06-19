#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x=0) : val(x), next(NULL) {}
};
 
class Solution {
public:

    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int len=1;
        ListNode * p=head;
        while(p->next)
        {
            p=p->next;
            len++;
        }
        p->next = head;
        k %= len;
        int count = len - k;
        while(count--)
        {
            p = p->next;
        }
        ListNode * q=p->next;
        p->next = NULL;
        
        return q;
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

    ListNode * rlist = mySol.rotateRight(mylist, 2);
    printlist(rlist);

    return 0;
}
