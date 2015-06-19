#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next && p->next->next)
        {
            if(p->next->val == p->next->next->val)
            {
                int d = p->next->val;
                while(p->next && p->next->val == d)//先判断指针存在!
                {
                    ListNode* q = p->next;
                    p->next = q->next;
                    delete q;
                }
            }
            else
                p = p->next;
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

    int myArr1[] = {1, 1, 2, 3, 4, 4, 5, 6, 6, 6, 8, 8, 9};
    int myArr2[] = {1, 1};
    Solution mySol;

    // make & construct our linked list
    ListNode * mylist = arraytolist(myArr1,13);

    printlist(mylist);

    ListNode * rlist = mySol.deleteDuplicates(mylist);

    printlist(rlist);

    return 0;
}
