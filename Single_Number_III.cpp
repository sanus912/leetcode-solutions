#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    void get2NonRepeatingNos(int arr[], int n, int &x, int &y)
    {
        int set_bit_no;  /* Will have only single set bit of xor */
        int i;

        int XOR = 0; /* Will hold xor of all elements */
        /* Get the xor of all elements */
        for(i = 0; i < n; i++)
            XOR ^= arr[i];

        /* Get the rightmost set bit in set_bit_no */
        set_bit_no = XOR & ~(XOR-1);

        /* Now divide elements in two sets by comparing rightmost set
           bit of xor with bit at same position in each element. */
        for(i = 0; i < n; i++)
        {
            if(arr[i] & set_bit_no)
                x = x ^ arr[i]; /*XOR of first set */
            else
                y = y ^ arr[i]; /*XOR of second set*/
        }
    }

};


int main(int argc, char ** argv) {

    const int s = 8;
    int myArr[s] = {2, 3, 7, 9, 11, 2, 3, 11};
    Solution mySol;
    int x =0, y=0;

     mySol.get2NonRepeatingNos(myArr,s,x,y);
     cout << x << endl;
     cout << y << endl;


    return 0;
}
