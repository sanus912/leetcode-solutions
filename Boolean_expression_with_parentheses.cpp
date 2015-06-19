#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    //better to use hashmap<string,int>, string = ""+target+i+j
    int f(string s, bool target) {

        if( s.empty() ) return 0;

        return dfs(s, target, 0, s.size()-1);
    }

    int dfs(string &s, bool target, int i, int j) {

        if( i==j) 
        {
            if (s[i]=='1' && target)
                return 1;
            else if (s[i]=='0' && !target)
                return 1;
            else
                return 0;
        }

        int c = 0;
        if (target)
        {

            for(int p = i+1; p <= j; p += 2) {

                if (s[p]=='&')
                    c += dfs(s,true,i,p-1) * dfs(s,true,p+1,j);
                else if (s[p]=='|'){
                    c += dfs(s,true,i,p-1) * dfs(s,true,p+1,j);
                    c += dfs(s,true,i,p-1) * dfs(s,false,p+1,j);
                    c += dfs(s,false,i,p-1) * dfs(s,true,p+1,j);
                }
                else if (s[p]=='^'){
                    c += dfs(s,true,i,p-1) * dfs(s,false,p+1,j);
                    c += dfs(s,false,i,p-1) * dfs(s,true,p+1,j);
                }
            }

        }
        else
        {

            for(int p = i+1; p <= j; p += 2) {

                if (s[p]=='&'){
                    c += dfs(s,false,i,p-1) * dfs(s,false,p+1,j);
                    c += dfs(s,true,i,p-1) * dfs(s,false,p+1,j);
                    c += dfs(s,false,i,p-1) * dfs(s,true,p+1,j);
                }
                else if (s[p]=='|'){
                    c += dfs(s,false,i,p-1) * dfs(s,false,p+1,j);
                }
                else if (s[p]=='^'){
                    c += dfs(s,true,i,p-1) * dfs(s,true,p+1,j);
                    c += dfs(s,false,i,p-1) * dfs(s,false,p+1,j);
                }
            }
        }

        return c;
    }

};


int main() {

    string myStr("1^0|0&1");
    Solution mySol;

    cout << mySol.f(myStr,true) << endl;

    return 0;
}
