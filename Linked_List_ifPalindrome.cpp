#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x = 0) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool isPar(ListNode *head) {
        
        if (!head) return false;
        if (!head->next) return true;

        ListNode *slow, *fast;
        slow = head;
        fast = head;

        stack<int> stk;
        while(fast&& fast->next) {
            stk.push(slow->val);
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if (fast)
            slow = slow->next;

        while (slow)
        {
            int val=stk.top();
            if (val!=slow->val)
                return false;
            stk.pop();
            slow=slow->next;
        }

        return true;
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

    int arr[] = {4, 2, 3, 1, 1, 3, 2, 4};
    Solution mySol;

    ListNode * mylist = arraytolist(arr,8);

    cout << mySol.isPar(mylist) << endl;


    return 0;
}
