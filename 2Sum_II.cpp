#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //sorted ---> 左右夹逼
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        if (n<2) return vector<int>();
        int b = 0;
        int e = n-1;
        while(b<e)
        {
            int sum = numbers[b] + numbers[e];
            if (sum == target)
                return {b+1,e+1};
            else if (sum<target)
                b++;
            else
                e--;
        }
    }
};

int main() {

    const int s = 6;
    int myArr[s] = {2, 3, 4, 5, 7, 15};
    int target = 6;
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    vector<int> ss = mySol.twoSum(myv, target);

    for(auto is = myv.begin(); is != myv.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;
    for(auto is = ss.begin(); is != ss.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;


    return 0;
}
