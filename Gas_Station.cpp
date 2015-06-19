#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        const int n = gas.size();
        if(n != cost.size() || n  == 0 ) 
            return -1;

        int total = 0;
        int j = -1;

        for (int i=0, sum=0; i<n; i++)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0)
            {
                j = i;
                sum = 0;
            }

        }
        return total >= 0? j+1 : -1;
    }
        
};


int main() {

    Solution mySol;

    const int s = 4;
    int g[s] = {4, 3, 2, 6};
    int c[s] = {5, 4, 3, 2};

    vector<int> gas(g, g+s);
    vector<int> cost(c, c+s);

    int ans = mySol.canCompleteCircuit(gas, cost);
    cout << "We could make the circle trip starting from station : " << ans << endl;

    return 0;
}
