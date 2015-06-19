/*
 * Ex_19_1.h
 *
 *  Created on: Oct 16, 2012
 *      Author: MiTKooK
 */

/*
 * Write a function to swap a number in place without temporary variables.
 */

#include<iostream>
using namespace std;
//如果引用同一变量则出错为零

template<class T>
void swapT(T & a, T & b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

template<class T>
void swapT_bit(T & a, T & b) {
    a ^= b;
    b ^= a;
	a ^= b;
}

int main() {
	int a = 5, b = 6;
	swapT(a, b);
	cout<<a<<" "<<b<<endl;
    cout << endl;

	swapT_bit(a, b);
	cout<<a<<" "<<b<<endl;
    cout << endl;

    char ca = '-', cb = '+';
	swapT(ca, cb);
	cout<<ca<<" "<<cb<<endl;

	swapT_bit(ca, cb);
	cout<<ca<<" "<<cb<<endl;

}


