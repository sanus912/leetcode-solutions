#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        
        vector<int> res = digits;
        int i = n-1;
        while(i>=0 && carry > 0)
        {
            int sum = digits[i]+carry;
            res[i] = sum%10;
            carry = sum/10;
            i--;
        }
        if (carry>0)
            res.insert(res.begin(),carry);
        return res;
    }
};


int main() {

    Solution mySol;
    const int s = 3;
    int A[s] = {9, 9, 9};

    vector<int> myVec(A, A+s);

    vector<int> ans = mySol.plusOne(myVec);


    vector<int>::iterator it;
   
    for( it = ans.begin(); it != ans.end(); it++)
        cout << *it << "  " ;
    cout << endl;



    return 0;
}
