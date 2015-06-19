/*
 * Ex_5_3.h
 *
 *  Created on: Sep 2, 2012
 *      Author: jliu
 */

/*
 * Given a positive integer, print the next smallest and next largest number that have the same
 * number of 1 bits in their binary representation.
 */

#include<iostream>
#include<bitset>
using namespace std;

int getNext(int num) {

    int temp = num;
	int c0 = 0;
	int c1 = 0;

	while (!(temp & 1)){
		c0++;
        temp >>= 1;
    }

	while (temp & 1) {
		c1++;
		temp >>= 1;
	}

    if (c0+c1 == 31)
        return -1;

    int p= c0+c1;

    num |= (1<<p);
    num &= ~((1<<p)-1);
    num |= (1 << (c1-1))-1;

	return num;
}

int getPrevious(int num) {

    int temp = num;
	int c0 = 0;
	int c1 = 0;

	while (temp & 1){
		c1++;
        temp >>= 1;
    }

    if (temp == 0)
        return -1;

	while (!(temp & 1)) {
		c0++;
		temp >>= 1;
	}

    if (c0+c1 == 31)
        return -1;

    int p= c0+c1;

    num &= ((~0)<<(p+1));
    num |= ((1 << (c1+1)) -1)<< (c0-1);

	return num;
}


int main() {
	int a = 27;
	cout << "Value:\t\t" << a << "\t" << bitset<32>(a) << endl;
	int b = getNext(a);
	cout << "Next:\t\t" << b << "\t" << bitset<32>(b) << endl;
	int c = getPrevious(a);
	cout << "Previous:\t" << c << "\t" << bitset<32>(c) << endl;

    return 0;
}

