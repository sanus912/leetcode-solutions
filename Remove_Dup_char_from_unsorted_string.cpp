#include <iostream>
using namespace std;

class Solution {
public:
   //no additional space
   void rm(char * s) 
   {
       if (!s) 
       {
           cerr << "non-existed pointer!";
           exit(1);
       };
       int len = strlen(s);
       if (len < 2)
           return;
       int j, end = 1;
       for (int i =1;i<len;i++){
           for (j=0;j<end;j++)
               if (s[i] == s[j])
                   break;
            if (j == end)
                s[end++]=s[i];
       }
       s[end]='\0';
   }

   //or use hash map / bit shift
};


int main() {

    Solution mySol;

    char str[] = { "@abcd@efgh@" };
    char str1[] = {""};
    char str2[] = {"00"};
    char str3[] = {"1aa11a"};
    char * str4 = NULL;
    mySol.rm(str);
    cout << "@abcd@efgh@" << " --> " << str << endl;
    mySol.rm(str1);
    cout << "" << " --> " << str1 << endl;
    mySol.rm(str2);
    cout << "00" << " --> " << str2 << endl;
    mySol.rm(str3);
    cout << "1aa11a" << " --> " << str3 << endl;
    mySol.rm(str4);
    cout << "NULL" << " --> " << str4 << endl;

    return 0;
}
