#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        
        if(path.empty()) return path;
        const int n = path.size();
        vector<string> stk;
        int i = 0;
        
        while(i < n) {
            while(i < n && path[i] == '/') i++;
            if(i == n) break;
            int i0 = i;
            while(i < n && path[i] != '/') i++;
            string sub = path.substr(i0, i-i0);
            
            if(sub == ".") continue;
            if(sub == "..") {
                if(!stk.empty()) stk.pop_back(); 
                continue;
            }
            stk.push_back(sub);
        }
        
        if (stk.size() == 0) return "/";

        string simple;
        for(vector<string>::iterator it = stk.begin(); it != stk.end(); it++) 
            simple += "/" + (*it);

        return simple;
    }

};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s("/..");

    cout << s << endl;
    cout << "After Simplification:" << endl;
    cout << mySol.simplifyPath(s) << endl;



    return 0; 
}
