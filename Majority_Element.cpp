#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //Runtime: O(n) — Moore voting algorithm
    int majorityElement(int num[], int n) 
    {
        int result = 0;
        int count = 0;
        for (int i = 0;i < n; ++i) {
            if (count == 0 || result == num[i]) {
                result = num[i];
                count++;
            } else {
                count--;
            }
        } 
        return result;
    }

    int majorityElement_2(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[num.size()/2];
    }
};


int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {1, 2, 2, 2, 2, 5, 6, 6};


    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;

    cout << mySol.majorityElement(myArr, s) << endl;





    return 0;
}
