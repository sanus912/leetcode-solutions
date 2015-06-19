#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    //backtracking
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        if(n==0) return res;
        string one;

        generate(n, 0, 0, res, one);
        return res;
    }

    void generate(int n, int l, int r,  vector<string> &res, string &one) {

        if( l == n && r == n){
            res.push_back(one);
            return;
        }
        else{

            if( l < n) {
                one.push_back('('); l++;
                generate(n, l, r, res, one);
                one.pop_back(); l--;
            }

            if ( l > r) {
                one.push_back(')'); r++;
                generate(n, l, r, res, one);
                one.pop_back(); r--;
            }


        }
    }

    //recrusion
    void gp(string str, int l, int r, int n, vector<string> &res){

        if ( l == n && r == n ){
            res.push_back(str);
            return;
        }
        else{
            if ( l < n ) gp( str + "(", l + 1, r, n, res);
            if ( l > r ) gp( str + ")", l, r + 1, n, res);

        }
    }

    vector<string> generateParenthesis_2(int n) {

        vector<string> res;
        if ( n == 0 ) return res;

        gp("", 0, 0, n, res);
        return res;
    }
};


int main(int argc, char ** argv) {


    Solution mySol;
    vector<string> res = mySol.generateParenthesis(1);

    for(auto& a: res)
        cout << a << endl;
    cout << res.size() << endl;

    return 0;
}
