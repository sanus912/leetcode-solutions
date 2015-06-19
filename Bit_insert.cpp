/*
 * Ex_5_1.h
 *
 *  Created on: Aug 30, 2012
 *      Author: jliu
 */

/*
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to set all bits between i and j in N equal to M (e.g., M becomes
 * a substring of N located at i and starting at j).
 * EXAMPLE:
 * Input: N = 10000000000, M = 10101, i=2,j=6
 * Output:N = 10001010100
 */

#include<iostream>
#include<bitset>
using namespace std;

void setBits(int & N, int M, int i, int j) {

    int mask = ~(((1<<(j-i+1))-1)<<i);
	M = M<<i;
	N = (N & mask) | M;
}

void setBits_2(int &N, int M, int i, int j){
    int max = ~0;
    int left = max - ((1 << (j+1)) - 1);
    int right = ((1 << i) -1);
    int mask = left | right;
    N =  (N & mask) | (M << i);
}

int main() {

	int N = 1 << 10; // N = 10000000000
	cout<<"N: "<<bitset<32>(N)<<endl;

	int M = 1 | 4 | 16; // M = 10101
	cout<<"M: "<<bitset<32>(M)<<endl;

	int i = 2, j = 6;
	setBits_2(N, M, i, j);
	cout<<"set bits of N from i: "<<i<<" to j: "<<j<<" : "<<endl;
	cout<<"N: "<<bitset<32>(N)<<endl;

    return 0;
}
