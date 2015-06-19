#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:

    int hashCode(string key,int HASH_SIZE) {
        if (key.size()==0) return 0;
        int res = 0;
        int base = 1;
        for (int i=key.size()-1;i>=0;i--){
            res += modMultiply((int)key[i],base,HASH_SIZE);
            res %= HASH_SIZE;
            base = modMultiply(base,33,HASH_SIZE);
        }
        return res;
    }

    int modMultiply(long a, long b, int HASH_SIZE){        
        long temp = a*b%HASH_SIZE;
        return (int) temp;
    }


};

int main() { 

    Solution mySol;

    cout << mySol.hashCode("ubuntu",1007) << endl;
    cout << sizeof(int) << " " <<  sizeof(long) << " " <<  sizeof(long long) << endl;

    return 0; 
}
