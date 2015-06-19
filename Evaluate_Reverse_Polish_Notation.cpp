#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stack>
#include <map>
using namespace std;



class Solution {
public:
    int evalRPN(vector<string> &tokens) {

        const int n = tokens.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {

            string tmp = tokens[i];

            if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
                char c = tmp[0];
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.pop();
                int tr = 0;
                switch (c) {
                    case '+':
                        tr = t2 + t1;
                        break;
                    case '-':
                        tr = t2 - t1;
                        break;
                    case '*':
                        tr = t2 * t1;
                        break;
                    case '/':
                        tr = t2 / t1;
                        break;
                } 
                s.push(tr);
            }
            else {
                int dig = stoi(tmp);
                s.push(dig);
            }
        }
        
        return s.top();
    }

};



int main() {

    Solution mySol;
    string s1("2");
    string s2("-1");
    string s3("+");
    string s4("3");
    string s5("*");
    vector<string> token;

    token.push_back(s1);
    token.push_back(s2);
    token.push_back(s3);
    token.push_back(s4);
    token.push_back(s5);

    int ans = mySol.evalRPN(token);
    cout << ans << endl;

    return 0;
}
