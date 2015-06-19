#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //左右夹逼  O(n^3)
    vector<vector<int> > fourSum(vector<int> &num, int target) {

        vector<vector<int> > res;
        int n =num.size();
        int p1, p2, p3, p4;
        if(n < 4) return res;

        sort(num.begin(), num.end());

        for (p1 = 0; p1 < n-3; p1++) {
            if (p1 > 0 && num[p1] == num[p1-1]) 
                continue;
            for (p2 = p1 + 1; p2 < n-2; p2++) {
                if (p2 > p1 + 1 && num[p2] == num[p2-1]) 
                    continue;
                int tmp = target - num[p1] - num[p2];
                p3 = p2 + 1;
                p4 = n - 1;
                while ( p3 < p4) {
                    if(num[p3]+ num[p4] < tmp) p3++;
                    else if(num[p3]+ num[p4] > tmp) p4--;
                    else if(num[p3]+ num[p4] == tmp) {
                        res.push_back({num[p1],num[p2],num[p3],num[p4]});
                        p3++; p4--;
                        while(num[p3]==num[p3-1]) p3++;
                        while(num[p4]==num[p4+1]) p4--;
                    }
                }
            }
        }

        return res;
    }

    //multimap缓存两个数的和  O(n^2)
    vector<vector<int> > fourSum_2(vector<int> &num, int target) {

        vector<vector<int> > res;
        int n =num.size();
        if(n < 4) return res;
        
        sort(num.begin(), num.end());

        unordered_multimap<int,pair<int,int>> twosum;
        

        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                twosum.insert({num[i]+num[j],make_pair(i,j)});

        for (auto it = twosum.begin();it!=twosum.end();it++)
        {
            auto a = it->second.first;
            auto b = it->second.second;
            int temp = target - it->first;
            auto range = twosum.equal_range(temp);
            for (auto r = range.first;r!=range.second;r++)
            {
                auto c = r->second.first;
                auto d = r->second.second;
                if (c>b)
                    res.push_back({num[a],num[b],num[c],num[d]});
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        //it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
        //myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10
        return res;
    }

    //multimap缓存两个数的和---2
    vector<vector<int> > fourSum_3(vector<int> &num, int target) {
        vector<vector<int> > res;
        int n =num.size();
        if(n < 4) return res;
        
        sort(num.begin(), num.end());

        unordered_map<int,vector<pair<int,int>>> twosum;
        

        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                twosum[num[i]+num[j]].push_back(make_pair(i,j));

        for (auto it = twosum.begin();it!=twosum.end();it++)
        {
            int gap = target - it->first;
            if (twosum.find(gap)!=twosum.end())
            {
                for (auto p1 : it->second)
                    for (auto p2: twosum[gap])
                    {
                        int a = p1.first;
                        int b = p1.second;
                        int c = p2.first;
                        int d = p2.second;
                        if (c>b)
                            res.push_back({num[a],num[b],num[c],num[d]});
                            
                    }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;

    }
};


int main() {

    const int s = 13;
    int myArr[s] = {0, 2, 0, -4, -2, 6, -4, -2, 3, -4, 1,  3, -1};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    vector<vector<int> > ss = mySol.fourSum(myv, 5);

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
    //左右夹逼
