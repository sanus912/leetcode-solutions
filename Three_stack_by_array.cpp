/*
 * Ex_3_1.h
 *
 *  Created on: Aug 11, 2012
 *      Author: MiTKooK
 */

/*
 * Describe how you could use a single array to implement three stacks.
 */

#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

/*
 * Method 1: equally assign spaces for each stack
 * O(1) time for push and pop, O(1) space
 *
 */

template<class T>
class ThreeStacks {
public:
	ThreeStacks<T>(int size = 10) {
		STACKSIZE = size;
		_array = new T[STACKSIZE*3];
		_top[0] = -1;
		_top[1] = -1;
		_top[2] = -1;
	}
    ~ThreeStacks<T>()
    {
        delete [] _array;
    }
	bool empty(int stack_num) const {
		return _top[stack_num] == -1;
	}
	int size(int stack_num) const{
        return _top[stack_num] + 1;
    }
	T& top(int stack_num) {
		return _array[_top[stack_num]+stack_num*STACKSIZE];
	}
	const T& top(int stack_num) const {
		return _array[_top[stack_num]+stack_num*STACKSIZE];
	}
	void push(int stack_num, const T& data);
	void pop(int stack_num);

private:
	T *_array;
	int _top[3];
	int STACKSIZE;
};

template<class T>
void ThreeStacks<T>::push(int stack_num, const T& data) {
	if (size(stack_num) < STACKSIZE) {
		_array[++_top[stack_num]+stack_num*STACKSIZE] = data;
	} else {
		cout << " Stack Overflow!" << endl;
	}
}

template<class T>
void ThreeStacks<T>::pop(int stack_num) {
	if (size(stack_num)>0) 
		_top[stack_num]--;
    else 
        std::cout << "Stack Underflow!" << std::endl;
}

/*
 * Method 2: flexible division 
 *
 */

template<class T>
struct node{
    T val;
    int preIdx = -2;
};

template<class T>
class ThreeFlexStacks {
public:
	ThreeFlexStacks<T>(int s = 30) {
		TOTALSIZE = s;
		_array = new node<T> [TOTALSIZE];
		_top[0] = -1;
		_top[1] = -1;
		_top[2] = -1;
        cur = 0;
        _size[0] = 0;
        _size[1] = 0;
        _size[2] = 0;
	}
    ~ThreeFlexStacks<T>()
    {
        delete [] _array;
    }
	bool empty(int stack_num) const {
		return _top[stack_num] == -1;
	}
    int size(int stack_num) const{
        return _size[stack_num];
    }
	T& top(int stack_num) {
        if (!empty(stack_num))
            return _array[_top[stack_num]].val;
        else
        {
            cout << "empty stack!" << endl;
            exit(1);
        }
	}
	const T& top(int stack_num) const {
		if (!empty(stack_num))
            return _array[_top[stack_num]].val;
        else
        {
            cout << "empty stack!" << endl;
            exit(1);
        }
	}
	void push(int stack_num, const T& data);
	void pop(int stack_num);

private:
	node<T> *_array;
	int _top[3];
	int TOTALSIZE;
    int cur;
    int _size[3];
};

template<class T>
void ThreeFlexStacks<T>::push(int stack_num, const T& data) {
	if (_size[0]+_size[1]+_size[2] < TOTALSIZE) {
		_array[cur].val = data;
		_array[cur].preIdx = _top[stack_num];
        _top[stack_num] = cur;
        _size[stack_num]++;
        while(_array[cur].preIdx != -2 && _size[0]+_size[1]+_size[2] < TOTALSIZE)
            cur = (cur+1)%TOTALSIZE;
	} else {
		cout << " Stack Overflow!" << endl;
	}
}

template<class T>
void ThreeFlexStacks<T>::pop(int stack_num) {
	if (size(stack_num)>0) {
        int t = _array[_top[stack_num]].preIdx;
        _array[_top[stack_num]].preIdx = -2;
		_top[stack_num] = t;
        _size[stack_num]--;
    }
    else 
        std::cout << "Stack Underflow!" << std::endl;
}


/*
 * Method 3: using extra list to store free spaces, based on linked list idea
 * O(1) time for push and pop, O(n) space: could maximize array usage
 */
template<class T>
struct StackNode {
	StackNode() :
			_data(0), _next(NULL) {
	}
	StackNode(T data) :
			_data(data), _next(NULL) {
	}
	T _data;
	StackNode<T> * _next;
};

template<class T>
class ThreeFlexStacks2 {
public:
	ThreeFlexStacks2<T>(int size = 30) {
	    totalsize = size;
		_array = new StackNode<T> [totalsize];
		_top[0] = NULL;
		_top[1] = NULL;
		_top[2] = NULL;
		for (int i = 0; i < totalsize; i++) {
			_free.push_front(&_array[i]);
		}
	}
	bool empty(int stack_num) const {
		return _top[stack_num] == NULL;
	}
	int size(int stack_num) const;
	T& top(int stack_num) {
        if (_top[stack_num])
            return _top[stack_num]->_data;
        else
        {
            cout << "empty stack!" << endl;
            exit(1);
        }
	}
	const T& top(int stack_num) const {
        if (_top[stack_num])
            return _top[stack_num]->_data;
        else
        {
            cout << "empty stack!" << endl;
            exit(1);
        }
	}
	void push(int stack_num, const T& data);
	void pop(int stack_num);

private:
	StackNode<T> *_array;
	list<StackNode<T> *> _free;
	StackNode<T> *_top[3];
	int totalsize;
};

template<class T>
int ThreeFlexStacks2<T>::size(int stack_num) const {
	if (_top[stack_num] == NULL)
		return 0;
	else {
		int size = 0;
		StackNode<T> * p = _top[stack_num];
		while (p) {
			size++;
			p = p->_next;
		}
		return size;
	}
}

template<class T>
void ThreeFlexStacks2<T>::push(int stack_num, const T& data) {
	if (!_free.empty()) {
		StackNode<T> *top = _top[stack_num];
		_top[stack_num] = _free.front();
		_top[stack_num]->_next = top;
		_top[stack_num]->_data = data;
		_free.pop_front();
	} else
		cout << " Stack Overflow!" << endl;
}

template<class T>
void ThreeFlexStacks2<T>::pop(int stack_num) {
	if (_top[stack_num]) {
		StackNode<T> *free_node = _top[stack_num];
		_top[stack_num] = _top[stack_num]->_next;
		_free.push_front(free_node);
	}else {
		cout << "Stack Underflow!" << endl;
	}
}

int main() {

	ThreeFlexStacks<int> *ts = new ThreeFlexStacks<int>();
    ts->pop(0);
	ts->push(2, 4);
	cout << ts->top(2) << endl;
	ts->push(1, 3);
	ts->push(1, 7);
	ts->push(1, 5);
	cout << ts->top(1) << endl;
	cout << "size of 1: " << ts->size(1) << endl;
	ts->pop(1);
	cout << ts->top(1) << endl;
	ts->pop(1);
	cout << ts->top(1) << endl;
	ts->pop(1);
	cout << ts->top(1) << endl;//decide if top exists!

    return 0;
}

