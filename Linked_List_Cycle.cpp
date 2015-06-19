#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }

        return false;
    }
};


int main() {

    const int s = 13;
    int myArr1[s] = {1, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8, 8};
    ListNode * mylist;
    Solution mySol;

    // make & construct our linked list
    mylist = new ListNode[s];


    for(int i = 0; i < s; i++) {
        mylist[i].val = myArr1[i];
        mylist[i].next = &mylist[i+1];
        cout  << mylist[i].val << "  ";
    }
    cout << endl;
    mylist[s-1].next = NULL;
    cout <<" Has a cycle ? " << mySol.hasCycle(mylist) << endl;

    mylist[7].next = mylist+5;
    cout <<" Has a cycle ? " << mySol.hasCycle(mylist) << endl;


    return 0;
}
