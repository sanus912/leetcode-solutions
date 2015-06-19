#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    //dict = visited
    int ladderLength(string start, string end, unordered_set<string> &dict) {

        if(start.empty() || end.empty()) return 0;

        int size = start.size();

        queue<string> path;
        path.push(start);

        int level = 1;
        while( !path.empty() ) {

            int n = path.size();
            while (n>0)
            {

                string cur = path.front();
                path.pop(); 

                for(int i= 0; i < size; i++) {

                    string tmp = cur;
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(cur[i] == j) continue;
                        tmp[i] = j;
                        if(tmp == end) {
                            return level + 1;
                        }
                        if(dict.find(tmp) != dict.end()) {
                            path.push(tmp);
                            dict.erase(tmp);
                        }
                    }
                }

                n--;
            }

            level++;
        }

        return 0;
    }

};


int main() {

    Solution mySol;
    string s("hit");
    string e("cog");
    unordered_set<string> dict;

    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    int len = mySol.ladderLength(s, e, dict);

    cout <<  " The ladder length is "<< len << endl;
    return 0;
}
