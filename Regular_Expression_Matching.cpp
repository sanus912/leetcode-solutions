#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> f(n+1,vector<bool>(m+1,false));
        f[0][0] = true;
        for(int i = 1;i<=m;i++)
        {
            if(p[i-1]=='*')
                f[0][i] = f[0][i-2];
        }
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]!='*')
                {
                    if((s[i-1]==p[j-1] || p[j-1]=='.') && f[i-1][j-1])
                        f[i][j]=true;
                }
                else
                {
                    if(f[i][j-2] || ((s[i-1]==p[j-1-1] || p[j-1-1]=='.') && f[i-1][j]))
                        f[i][j]=true;
                }
            }
        return f[n][m];
    }
    
    bool isMatch(string s, string p) {
        if(s.empty()) return ifempty(p);
        if(p.empty()) return s.empty();
        char d = '0';
        if (p.size()>=2)
            d = p[1];
        if(d!='*')
        {
            if(s[0]==p[0] || p[0]=='.')
                return isMatch(s.substr(1),p.substr(1));
            else
                return false;
        }
        else
        {
            if(s[0]==p[0] || p[0]=='.')
            {
                return isMatch(s.substr(1),p) || isMatch(s,p.substr(2));
            }
            else
                return isMatch(s,p.substr(2));
        }
    }
    
    bool ifempty(string p)
    {
        if (p.size()%2 != 0) {
            return false;  
        }
 
        for (int i = 1; i < p.size(); i+=2) {
            if (p[i] != '*') {
                return false;
            }
        }
        return true;    
    }

    bool isMatch(const char *s, const char *p) {
        
        if(*p == '\0') return *s == '\0';

        if(*(p+1) != '*') {
            if(*s && (*s == *p || *p == '.')) 
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else{
            while (*s &&  (*s == *p || *p == '.')) {
                if(isMatch(s, p+2) ) 
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
    }

    //another input version
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int a = 0;
        int b = 0;
        if(p[b+1]!='*')
        {
            if(a<s.size() && (s[a]==p[b] || p[b]=='.'))
                return isMatch(s.substr(a+1),p.substr(b+1));
            else
                return false;
        }
        else
        {
            while(a<s.size() && (s[a]==p[b] || p[b]=='.'))
            {
                if(isMatch(s.substr(a),p.substr(b+2)))
                    return true;
                a++;
            }
            return isMatch(s.substr(a),p.substr(b+2));
        }
    }

};

int main(int argc, char ** argv) { 

    Solution mySol;

    char cs1[] = "a";
    char cs2[] = "a.*"; 

    bool is = mySol.isMatch(cs1, cs2);

    if (is)
        cout << cs2 << " Matching " << cs1 << "? "<< " True " <<endl;
    else
        cout << cs2 << " Matching " << cs1 << "? "<< " False " <<endl;


    return 0; 
}
