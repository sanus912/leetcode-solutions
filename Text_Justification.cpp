#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;



class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {

        const int n = words.size();
        vector<string> res;
        if( n == 0) {
            int more = L;
            string one;
            while(more-- > 0) one += " ";
            res.push_back(one);
            return res;
        }

        for(int i = 0; i < n; i++) {
            int sep = 0;
            int i0 = i;
            int len = words[i].length();
            while(i+1 < n && len + words[i+1].length()+ sep +1 <= L ) {
                i++;
                sep++;
                len += words[i].length(); 
            }

            string one = words[i0];
            if( sep > 0 && i < n-1) {
                vector<string> space(sep, " ");
                int more = L - len - sep;
                int t = 0;
                while(more > 0) {
                    space[t] += " ";
                    t = (t + 1) % sep;
                    --more;
                }
                for( int j = 0; j < sep; j++)
                    one += space[j] + words[i0+j+1];
            }
            else {
                for( int j = 0; j < sep; j++)
                    one += " " + words[i0+j+1];
                int more = L - len -sep;
                while(more-- > 0) one += " ";
            }
            res.push_back(one);
        }
        return res;
    }
};



int main() {

    Solution mySol;
    vector<string> words;
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("just");
    words.push_back("fon.");

    vector<string> res = mySol.fullJustify(words, 16);
    for(vector<string>::iterator it = res.begin(); it != res.end(); it++)
        cout << *it << endl;
    cout << endl;
    return 0;
}
