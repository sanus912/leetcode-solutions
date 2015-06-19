/*
 * Ex_5_5.h
 *
 *  Created on: Sep 3, 2012
 *      Author: jliu
 */

/*
 * Write a function to determine the number of bits required to convert integer A to integer B.
 * Input: 31, 14
 * Output: 2
 */


#include<iostream>
using namespace std;

//better
int bitsDistance(int a, int b) {
	 // cancel all identical bits
	int result = 0;
    for (int num = a ^ b; num != 0; num = num & (num-1))//clear the least siginificant 1
        result++;
	return result;
}

int bitsDistance_2(int a, int b) {
	 // cancel all identical bits
	int result = 0;
    for (int num = a ^ b; num != 0; num = num>>1)
        result += num & 1;
	return result;
}

int main() {

	int a = 31, b = 14;
	cout<<"Input: "<<a<<", "<<b<<endl;
	cout<<"Output:"<<bitsDistance(a,b) << endl;
	cout<<"Output:"<<bitsDistance_2(a,b);

    return 0;
}


