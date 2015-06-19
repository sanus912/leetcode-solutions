#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> sortrange(vector<int> v)
    {
        int n = v.size();
        if (n==0) return vector<int>();
        if (n==1) return {0,0};
        int start = 0;
        int end = n-1;
        for (int i=1;i<n;i++)
        {
            if (v[i]<v[i-1])
            { start = i;break;}
        }
        for (int i = n-2;i>=0;i--)
        {
            if (v[i]>v[i+1])
            {end = i;break;}
        }
        if (start>end) return vector<int>();
        int min=INT_MAX;
        int max=INT_MIN;
        for (int i = start;i<=end;i++)
        {
            if (v[i]<min)
                min = v[i];
            if (v[i]>max)
                max = v[i];
        }
        bool flag = true;
        while(flag)
        {
            flag = false;
            for (int i = start-1;i>=0;i--)
            {
                if (v[i]<min)
                    break;
                start = i;
                if(v[i]>max)
                {
                    max = v[i];
                    flag = true;
                }
            }
            for (int i = end+1;i<n;i++)
            {
                if (v[i]>max)
                    break;
                end = i;
                if(v[i]<min)
                {
                    min = v[i];
                    flag = true;
                }
            }
        }
        return {start,end};

    }

};


int main() {

    vector<int> v = {1,2,6,7,10,11,7,12,5,7,16,18,19};

    Solution mySol;
    vector<int> res = mySol.sortrange(v);
    cout << res[0] << " -> " << res[1] << endl;

    return 0;
}
