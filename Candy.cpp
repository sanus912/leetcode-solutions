#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:

    int candy(vector<int> &ratings) {

        int len = ratings.size();
        if(len == 0 || len == 1)    return len;
        int cur, sum = 0;
        vector<int> can(len, 1); 

        cur = 1;
        for(int i = 1; i < len; i++) {
            if(ratings[i-1] < ratings[i]) 
                cur++;
            else
                cur = 1;
            can[i] = cur;
        }

        cur = 1;
        for(int i = len - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                cur++;
            else
                cur = 1;
            can[i] = max(can[i], cur);
        }

        for(int i = 0; i < len; i++) {
            //cout << can[i] << endl;
            sum += can[i];
        }

        return sum;
    }

};


int main(int argc, char ** argv) {

    const int s = 3;
    int myArr[s] = {1,2,2};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    for( vector<int>::iterator it = myv.begin(); it != myv.end(); it++)
        cout << *it << " ";
    cout << endl;

    Solution mySol;
    int min = mySol.candy(myv);
    cout << "The minimum candies you must give " << min <<endl;


    return 0;
}
