#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};
 
class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        if (!head)
            return NULL;

        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p2&&p2->next){
            p1 = p1->next; //p1++
            p2 = p2->next->next; //p2++
            if(p1==p2)
                break;
        }

        if (!p2||!p2->next)
            return NULL;//not circular

        p1 = head;
        while (p1 != p2) {
            p1 = p1->next; //p1++
            p2 = p2->next; //p2++
        }

        return p1;
    }
};


int main() {

    const int s = 13;
    int myArr1[s] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
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

    mylist[7].next = mylist+3;
    cout <<" The cyclce starts at " << mySol.detectCycle(mylist)->val << endl;

    return 0;
}
