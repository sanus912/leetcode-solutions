#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int maxProfitS(vector<int> &prices) {

        int n = prices.size();
        if (n<2) return 0;

        int sum = 0; 

        for( int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            if (diff>0)
                sum+=diff;
        }
    
        return sum;
        
    }

    
};


int main() {

    const int s = 9;
    int myArr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;

    int max = mySol.maxProfitS(myv);
    cout << " The maximum of subarray is " << max <<endl;


    return 0;
}
