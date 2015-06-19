#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:

    bool nextPermutation(vector<int> &num) {
        
        if( num.empty() ) return;
        const int n =  num.size();
        
        int i = n - 2;
        while(i >= 0 && num[i] >= num[i+1]) i--;

        if(i == -1) {
            reverse(num.begin(), num.end());
            return false;
        }

        int j = n - 1;
        while(num[j] <= num[i]) j--;

        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());

        return true;
    }

};

int main() {

    const int s = 6;
    int myArr[s] = {6, 8, 7, 4, 3, 2};
    vector<int> myv;

    myv.assign(myArr, myArr+s);

    vector<int>::iterator it;

    for(it = myv.begin(); it != myv.end(); it++)
        cout << *it << "  ";
    cout << endl;

    Solution mySol;
    mySol.nextPermutation(myv);

    for(it = myv.begin(); it != myv.end(); it++)
        cout << *it << "  ";
    cout << endl;

    return 0;
}
