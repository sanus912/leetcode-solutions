#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //左右夹逼O(n^2)
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > res;
        int n = num.size();
        int p1, p2, p0;

        if(n < 3) return res;
        sort(num.begin(), num.end());

        for(p0 = 0; p0 < n-2; p0++) {
            if (p0 > 0 && num[p0] == num[p0-1]) 
                continue;
            int tar = -num[p0];
            p1 = p0 + 1; 
            p2 = n -1;
            while(p1 < p2) {
                if(num[p1] + num[p2] < tar) 
                    p1 ++;
                else if(num[p1] + num[p2] > tar) 
                    p2 --;
                else if(num[p1] + num[p2] == tar){
                    res.push_back({num[p0],num[p1],num[p2]});
                    p1++; 
                    p2--;
                    while(p1 < p2 && num[p1] == num[p1-1]) p1++;
                    while(p1 < p2 && num[p2] == num[p2+1]) p2--;
                }
            } 
        }

        return res;
    }

    //multimap缓存两个数的和O(n^2)
    vector<vector<int> > threeSum_2(vector<int> &num) {

        vector<vector<int> > res;
        int n =num.size();
        if(n < 3) return res;
        
        sort(num.begin(), num.end());

        unordered_multimap<int,pair<int,int>> twosum;

        for (int i=0;i<n;i++)
        {
            if (i>0 && num[i]==num[i-1])
                continue;
            for (int j=i+1;j<n;j++)
            {
                if (j>i+1 && num[j]==num[j-1])
                continue;
                twosum.insert({num[i]+num[j],make_pair(i,j)});
                //cout << num[i] << " " << num[j] << endl;
            }
        }

        for (int i=n-1;i>=0;i--)
        {
            if (i<n-1 && num[i]==num[i+1])
                continue;
            int temp = - num[i];
            auto range = twosum.equal_range(temp);
            for (auto r = range.first;r!=range.second;r++)
            {
                int c = r->second.first;
                int d = r->second.second;
                if (i>d)
                    res.push_back({num[c],num[d],num[i]});

            }
        }
        
        return res;
    }

};


int main() {

    const int s = 5;
    int myArr[s] = {-2,0,1,1,2};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    clock_t startTime = clock();
    vector<vector<int> > ss = mySol.threeSum_2(myv);
    cout << double( clock() - startTime ) /(double)CLOCKS_PER_SEC *1000 << " ms." << endl; 

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  ";
        }
        cout << endl;
    }
    return 0;
}
