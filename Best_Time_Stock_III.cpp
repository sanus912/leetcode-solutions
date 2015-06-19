#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        if (n<2) return 0;

        vector<int> f(n,0);
        vector<int> g(n,0);

        for (int i =1, valley = prices[0]; i<n;i++)
        {
            valley = min(valley,prices[i]);
            f[i] = max(f[i-1],prices[i]-valley); 
        }

        for (int i =n-2, peak = prices[n-1]; i>=0;i--)
        {
            peak = max(peak,prices[i]);
            g[i] = max(g[i+1],peak - prices[i]); 
        }

        int maxprofit = 0;
        for (int i = 0;i<n;i++)
        {
            maxprofit = max(maxprofit, f[i]+g[i]);
        }
        return maxprofit;

    }
};


int main() {

    const int s = 12;
    int myArr[s] = {-2, 1, -3, 4, -1, 2, -2, -3, 4, 7, 5, -1};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;

    int max = mySol.maxProfit2(myv);
    cout << " The maximum profit is " << max <<endl;


    return 0;
}
