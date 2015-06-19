#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int maximumGap(vector<int> &num) {
        if (num.size()<2)
            return 0;
        radix_sort(num);
        int res = INT_MIN;
        for (int i =1;i<num.size();i++)
        {
            int diff = num[i]-num[i-1];
            if (res<diff)
                res = diff;
        }
        return res;
    }

    void radix_sort(vector<int> &a) {
        int n = a.size();
        int i, max = a[0], radix = 1;
        // find max value
        for (i = 1; i < n; i++)
            if (a[i] > max)
                max = a[i];

        vector<int> b(n,0);

        while (max / radix > 0) {
            int bucket[10] = { 0 };
            for (i = 0; i < n; i++) // put values in the bucket base on LSD
                bucket[a[i] / radix % 10]++;
            for (i = 1; i < 10; i++) // calculate the start index in a[] for each bucket
                bucket[i] += bucket[i - 1];
            for (i = n - 1; i >= 0; i--) // counting sort, stable
                b[--bucket[a[i] / radix % 10]] = a[i];
            for (i = 0; i < n; i++)
                a[i] = b[i];
            radix *= 10;
        }
    }
};


int main() {

    Solution mySol;
    vector<int> v = {1,10000000};


    cout << mySol.maximumGap(v) << endl;





    return 0;
}
