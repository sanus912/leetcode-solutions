#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            n = (n & n-1);
            count++;
        }
        return count;
    }

int main() {

	uint32_t a = 31, b = 14;
	cout<< hammingWeight(a)<< endl;
	cout<< hammingWeight(b)<< endl;

    return 0;
}


