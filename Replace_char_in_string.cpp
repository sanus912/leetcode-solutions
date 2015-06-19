/*
 * Ex_1_5.h
 *
 *  Created on: Aug 3, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method to replace all spaces in a string with '%20'.
 * [Amazon Question]
 */

#include <iostream>
using namespace std;

/*
 * in place
 * O(n) time, O(1) space
 * this method may cause heap overflow!
 * to address this issue, simply allocates new memory to the string
 */

void replace(char *c){
    if(c == NULL) { cout << "1" << endl;return;}
    int len = strlen(c);
    if(len == 0)  { cout << "2" << endl;return;}
    int cnt = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
            ++cnt;
    }
    int p = len + 2*cnt;
    c[p--] = '\0';//the space must be allocated first.
    for(int i=len-1; i>=0; --i)
    {
        if(c[i] == ' ')
        {
            c[p] = '0';
            c[p-1] = '2';
            c[p-2] = '%';
            p -= 3;
        }
        else
        {
            c[p] = c[i];
            --p;
        }
    }
}

char* replace1(char *c){
    if(c == NULL) return NULL;
    int len = strlen(c);
    if(len == 0) return NULL;
    int cnt = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
            ++cnt;
    }
    char *cc = new char[len+2*cnt+1];//+1 <-- '\0'

    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
        {
            cc[p] = '%';
            cc[p+1] = '2';
            cc[p+2] = '0';
            p += 3;
        }
        else
        {
            cc[p] = c[i];
            ++p;
        }
    }
    cc[p] = '\0';
    return cc;
}

int main() {
    char str[] = { " H" };
    cout << replace1(str)<<endl;
    cout << "\"" << str << "\"";
    replace(str);
    cout << " --> " << str << endl;

    char * str1 = NULL;
    replace(str1);

    return 0;
}

