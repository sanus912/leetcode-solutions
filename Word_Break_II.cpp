#include <iostream> 
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        //need f
        vector<bool> f(s.size()+1,false);
        f[0]=true;
        vector<vector<bool>> prev(s.length()+1,vector<bool>(s.length()));
        for (int i=1;i<=s.size();i++)
            for (int j=i-1;j>=0;j--)
            {
                if (f[j] && dict.find(s.substr(j,i-j))!=dict.end())
                {   
                    f[i]=true;
                    prev[i][j] = true;//[j,i) is found in dict.
                }
            } 

        vector<string> result;
        vector<string> path;
        gen_path(s,prev,s.length(),path,result);
        return result;

    }

    void gen_path(string &s, vector<vector<bool>> & prev, int cur,
            vector<string> &path, vector<string> &result)
    {
        if (cur == 0)
        {
            string temp;
            for (auto it = path.rbegin();it!=path.rend();it++)
                temp += *it + " ";
            temp.erase(temp.end()-1);
            result.push_back(temp);
        }
        for (int i=0;i<s.size();i++)
        {
            if (prev[cur][i])
            {
                path.push_back(s.substr(i,cur-i));
                gen_path(s,prev,i,path,result);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    string t("aaaleetcodeaaaa");
    unordered_set<string> dict;
    
    dict.insert("leet");
    dict.insert("code");
    dict.insert("lee");
    dict.insert("tco");
    dict.insert("de");
    dict.insert("aaaaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaa");
    dict.insert("aaaa");
    dict.insert("aaa");
    dict.insert("aa");
    //dict.insert("a");



    vector<string> res = mySol.wordBreak(t, dict);
    vector<string>::iterator is;
    for(is = res.begin(); is != res.end(); is++)
            cout << " "<< *is << " " << endl;
    cout << endl;

    return 0; 
}
