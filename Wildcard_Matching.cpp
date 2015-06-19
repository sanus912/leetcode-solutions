#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        int n = s.length();
        int m = p.length();
        int count = 0;
        for (char c : p) {
            if (c == '*')
                count++;
        }
        if (m - count > n)
            return false;

        vector<vector<bool>> f(n+1,vector<bool>(m+1,false));
        f[0][0] = true;
        for(int i = 1;i<=m;i++)
        {
            if(p[i-1]=='*')
                f[0][i] = f[0][i-1];
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]!='*')
                {
                    if((s[i-1]==p[j-1] || p[j-1]=='?') && f[i-1][j-1])
                        f[i][j]=true;
                }
                else
                {
                    if(f[i][j-1] || f[i-1][j])
                        f[i][j]=true;
                }
            }
        return f[n][m];
    }

    bool isMatch(const char *s, const char *p) {

        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }

    bool isMatch(string s, string p) {
        int a=0;
        int b=0;
        int star = -1;
        int ss;
        while(a<s.size())
        {
            if(s[a]==p[b] || p[b] =='?'){a++;b++;continue;}
            if(p[b]=='*'){star = b; b++; ss=a; continue;}
            if(star>=0){b=star+1;ss++;a=ss;continue;}
            return false;
        }
        while(p[b]=='*')
            b++;
        return b == p.size();
    }

};

int main(int argc, char ** argv) { 

    Solution mySol;

    char cs1[] = "abcasdfasdfasdzfalksdjfalsdfjzasdklfjasdfkjasldfjt";
    char cs2[] = "abc*z*t"; 

    bool is = mySol.isMatch( cs1, cs2);

    if (is)
        cout << cs2 << " Matching " << cs1 << "? "<< " True " <<endl;
    else
        cout << cs2 << " Matching " << cs1 << "? "<< " False " <<endl;


    return 0; 
}
