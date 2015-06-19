#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isValid(string s) {

        if( s.empty() ) return true;

        string left = {'(','[','{'};
        string right = {')',']','}'};

        stack<char> stk;

        for(auto c : s) {

            if(left.find(c) != string::npos ) {
                stk.push(c);
            }
            else{

                if( stk.empty() || stk.top() != left[right.find(c)]) 
                    return false;
                else
                    stk.pop();
            }
        }

        return stk.empty();
    }

};


int main(int argc, char ** argv) {

    
    string s("{[()]}");
    Solution mySol;

    bool is = mySol.isValid(s);

    if( is)
        cout << "String : " << s << " is valid ? Yes!" <<endl;
    else
        cout << "String : " << s << " is valid ? No!" <<endl;


    return 0;
}
