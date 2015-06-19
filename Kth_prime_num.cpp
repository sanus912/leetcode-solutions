/*
 * Ex_10_7.h
 *
 *  Created on: Oct 15, 2012
 *      Author: MiTKooK
 */

/*
 * Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
 *
 * e.g., numbers are: 3, 5, 7, 9, 15 ...
 */

#include<iostream>
#include<queue>
using namespace std;

#define min(x,y) (x<y?x:y)

long long kthPrimeNumber(int k) {
    if (k<=0) return 0;
    queue<long long> Q3,Q5,Q7;
    Q3.push(3);Q5.push(5);Q7.push(7);
    long long val; 
    while(k--)
    {
        val = min(Q3.front(),min(Q5.front(),Q7.front()));
        if (val == Q3.front())
        {
            Q3.pop();
            Q3.push(val*3);
            Q5.push(val*5);
            Q7.push(val*7);
        }
        else if (val == Q5.front())
        {
            Q5.pop();
            Q5.push(val*5);
            Q7.push(val*7);
        }
        else
        {
            Q7.pop();
            Q7.push(val*7);
        }
    }
    return val;
}

int main() {
    for (int i = 1; i < 14; i++) {
        cout << i << " : " << kthPrimeNumber(i) << endl;
    }
}

