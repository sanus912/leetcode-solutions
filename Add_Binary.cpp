#include <iostream> 

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
        return b;
        if (b.empty())
        return a;
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        auto pa = a.begin();
        auto pb = b.begin();
        int sum = 0;
        int carry = 0;
        string res;
        
        while(pa!=a.end()||pb!=b.end())
        {
            sum = carry;
            if (pa!=a.end())
            {
            sum += *pa-'0';
            pa++;
            }
            if (pb!=b.end())
            {
            sum += *pb-'0';
            pb++;
            }
            
            carry = sum/2;
            sum = sum%2;
            res.insert(res.begin(), sum+'0');
        }
        if (carry)
        res.insert(res.begin(),'1');
        
        return res;
        
    }

    string addBinary_1(string a, string b) {

        int id = 0;
        string res;
        int as = a.size();
        int bs = b.size();
        int max = as > bs? as : bs;

        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );

        for(int i = 0; i < max; i++) {
            int ia = i < as ? a[i] - '0' : 0;
            int ib = i < bs ? b[i] - '0' : 0;
            int ic = (ia+ib+id) % 2;
            id = (ia+ib+id) / 2;

            res.insert( res.begin(), ic+'0');
        }

        if ( id > 0)
            res.insert( res.begin(), id+'0');

        return res;
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;

    string sa = "1101";
    string sb = "1110";



    cout << mySol.addBinary_1(sa, sb) << endl;

    return 0; 
}
