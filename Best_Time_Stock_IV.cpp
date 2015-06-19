#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
// General method for any m times buy and sold
// http://www.cnblogs.com/caijinlong/archive/2013/05/01/3053165.html
// http://www.mitbbs.com/article_t/JobHunting/32602317.html
    int maxProfit(int m, vector<int> &prices) {
        const int n = prices.size();
        if (n==0) return 0;
        if (m > n) m = n;

        vector<int> f(m+1,0);
        vector<int> g(m+1,0);

        for(int i = 1; i < n; i ++) {
            int diff = prices[i] - prices[i-1];
            for(int j = min(i, m); j > 0; j--) {
                if (i>j){
                    f[j] = max(f[j], g[j-1]) + diff;
                    g[j] = max(f[j], g[j]);
                }
                else if (i==j)
                {
                    f[j] = g[j-1] + diff;
                    g[j] = f[j];
                }
            }
        }

        int res = 0;
        for(int j = m; j > 0; j--) {
            res = max(res, g[j]);
        }
        return res;
    }


    int maxProfit_2(int m, vector<int> &prices) {
        const int n = prices.size();
        if (n==0) return 0;
        if (m > n) m = n;
        vector<vector<int>> f(n, vector<int>(m+1,0));
        vector<vector<int>> g(n, vector<int>(m+1,0));

        for (int i =0;i<n;i++)
            for (int j =i+1;j<=m;j++)
            {
                f[i][j] = INT_MIN;
                g[i][j] = INT_MIN;
            }


        for (int i=1;i<n;i++)
        {
            int diff = prices[i] - prices[i-1];
            for (int j=1;j<=min(m,i);j++)//j<=i
            {
                f[i][j] = max(g[i-1][j-1], f[i-1][j]) + diff;
                g[i][j] = max(g[i-1][j],f[i][j]);
            }
        }


        int res = 0;
        for(int i =1;i<=m;i++)
            res = max(res,g[n-1][m]);
        return res;
    }
};


int main() {

    const int s =3;
    int myArr[s] = {3,2,1};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;

    cout << mySol.maxProfit(2,myv) << endl;
    cout << mySol.maxProfit_2(2,myv) << endl;


    return 0;
}
