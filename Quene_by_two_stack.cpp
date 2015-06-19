#include <iostream>
#include <stack>
using namespace std;
 
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack2.push(element);
    }
    
    int pop() {
        if (stack1.empty())
            transfer();
        int v = stack1.top();
        stack1.pop();
        return v;
    }

    int top() //=front
    {
        if (stack1.empty())
            transfer();
        return stack1.top();
    }
    
    void transfer()
    {
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
};


int main() {

    cout << "queue using two stacks." << endl;
	Queue mq;
	cout << "Enqueue: ";
	for (int i = 0; i < 5; i++) {
		mq.push(i);
		cout << i << " ";
	}
    cout << endl;
    cout << mq.top() << endl;

	cout << endl << "Dequeue: ";
	for (int i = 0; i < 5; i++) {
		cout << mq.pop() << " ";
	}
    return 0;
}
