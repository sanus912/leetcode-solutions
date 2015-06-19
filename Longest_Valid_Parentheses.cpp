#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    //DP
    int longestValidParentheses(string s) {

        int n = s.size();
        if (n<2) return 0;
        vector<int> f(n,0);//以s[i]为底的最长有效括号
        int res = 0;
        for (int i=1;i<n;i++)
        {
            int j = i-f[i-1]-1;
            if (j>=0 && s[j]=='(' && s[i]==')'){
                f[i] = f[i-1]+2;
                if (j-1>=0)
                    f[i] += f[j-1];
            }

            res = max(res,f[i]);
        }
        return res;
    }

    //stack
    int longestValidParentheses_2(string s)
    {
        int maxlen = 0, last = -1;
        stack<int> stk;

        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
                stk.push(i);
            else
            {
                if (stk.empty())
                    last = i;
                else{
                    stk.pop();
                    if (stk.empty())
                        maxlen = max(maxlen,i-last);
                    else
                        maxlen = max(maxlen,i-stk.top());
                }

            }
        }
        return maxlen;
    }

};



int main(int argc, char ** argv) {

    string s("(((()(()");
    Solution mysol;

    int is = mysol.longestValidParentheses(s);
    cout << "string : " << s << "'s max is "<< is <<endl;


    return 0;
}
