#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        if (dict.empty()) return res;
        
        unordered_map<string,int> spath;
        for (auto r : dict)
            spath.insert({r,INT_MAX});
        spath[start] = 1;
        spath[end] = INT_MAX;
        ladderLength(start,end,dict,spath);

        if (spath[end] == INT_MAX)
            return res;
        vector<string> one;
        one.push_back(end);
        dfs(start,end,dict,spath,one,res,spath[end]-1);

        return res;
    }

    //DFS
    void dfs(string start, string end, unordered_set<string> &dict, unordered_map<string,int> &spath, vector<string> &one, vector<vector<string>> &res, int s)
    {
        if (one.size() == s)
        {
            vector<string> newone = one;
            newone.push_back(start);

            reverse(newone.begin(),newone.end());
            res.push_back(newone);
            return;
        }
        for(int i= 0; i < end.size(); i++) {

            string tmp = end;
            for(char j = 'a'; j <= 'z'; j++) {
                if(end[i] == j) continue;
                tmp[i] = j;
                if(dict.find(tmp) != dict.end() && spath[tmp] < spath[end]) {
                    one.push_back(tmp);
                    dfs(start,tmp,dict,spath,one,res,s);
                    one.pop_back();
                }
            }
        }
    }

    //BFS
    void ladderLength(string start, string end, unordered_set<string> dict,unordered_map<string,int> &spath)
    {
        if(start.empty() || end.empty()) return;

        int size = start.size();

        queue<string> q;
        dict.erase(start);//相当于visited
        q.push(start);

        int level = 2;
        while( !q.empty() ) {

            int n = q.size();
            while (n>0)
            {

                string cur = q.front();
                q.pop(); 

                for(int i= 0; i < size; i++) {

                    string tmp = cur;
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(cur[i] == j) continue;
                        tmp[i] = j;
                        if(tmp == end) {
                            spath[end] = level;
                            return;
                        }
                        if(dict.find(tmp) != dict.end()) {
                            q.push(tmp);
                            dict.erase(tmp);
                            spath[tmp] = level;
                        }
                    }
                }

                n--;
            }

            level++;
        }

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

    vector<vector<string>> res = mySol.findLadders(s, e, dict);

    for(auto it = res.begin(); it != res.end(); it++) {
        for(auto is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    return 0;
}
