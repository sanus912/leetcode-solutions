#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int maxProfit(vector<int> &prices) {

        int n = prices.size();
        if (n<2) return 0;

        int profit = 0;
        int curmin = prices[0];
        for( int i = 1; i < n; i++) {
            curmin = min(curmin,prices[i]);
            profit = max(profit, prices[i] - curmin);
        }
    
        return profit;
        
    }


    //from maxsubarray
    int maxProfit_2(vector<int> &prices) {
        int f = 0;
        int res = INT_MIN;
        for (int i = 1;i<prices.size();i++)
        {
            int diff = prices[i] - prices[i-1];
            f = max(f,0) + diff;
            res = max(res,f);
        }
        return res;
    }
};


int main() {

    const int s = 9;
    int myArr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;

    cout << mySol.maxProfit(myv) << endl;
    cout << mySol.maxProfit_2(myv) << endl;


    return 0;
}
