#include <iostream>
#include <stack>
using namespace std;
 
class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    
    MinStack() {}

    void push(int number) {
        s.push(number);
        
        if (mins.empty() || number <= mins.top())
            mins.push(number);
    }

    void pop() {
        int v = s.top();
            s.pop();
        if (v == mins.top())
            mins.pop();
    }
    
    int top()
    {
        return s.top();
    }

    int getMin() {
        if (mins.empty())
            return INT_MAX;
        else
            return mins.top();
    }
};


int main() {

    MinStack ms;
	for (int i = 0; i < 15; i++) {
		int value = rand()%10;
		ms.push(value);
		cout<<value<<", ";
	}
	cout<<endl;
	for (int i = 0; i < 15; i++) {
		cout<<"Popped "<<ms.top()<<" ; ";
        ms.pop();
		cout<<"New min is "<<ms.getMin()<<endl;
	}
    return 0;
}
