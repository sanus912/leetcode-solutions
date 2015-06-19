#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        const int n = num.size();
        int res, dis_min = INT_MAX;
        int p0, p1, p2;
        
        sort(num.begin(), num.end());
        for(p0 = 0; p0 < n; p0++) {
            p1 = p0 + 1;
            p2 = n - 1;
            while(p1 < p2) {
                int tmp = num[p0] + num[p1] + num[p2];
                int dis = abs(target - tmp);
                if(dis < dis_min) {
                    dis_min = dis;
                    res = tmp;
                }
                if(tmp == target) return target;
                if(tmp < target) p1++;
                if(tmp > target) p2--;
            }
        }
        
        return res;
    }

};


int main() {

    const int s = 5;
    int myArr[s] = {0, 1, 2};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    int dis;
        
    
    for( int i = -10; i < 18; i++) {
        dis = mySol.threeSumClosest(myv, i);
        cout << "The closest 3sum to "<<i<< " is " << dis << endl;
    }

    return 0;
}
