/*
 * Ex_5_2.h
 *
 *  Created on: Aug 30, 2012
 *      Author: jliu
 */

/*
 *	Given a (decimal - e.g., 3.72) number that is passed in as a string, print the binary
 *	representation. If the number can not be represented accurately in binary with at most
 *  32 characters, print "ERROR".
 *
 *	ref: http://en.wikipedia.org/wiki/Computer_number_format
 */

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return "0";
    string res;
    if (numerator>0 ^ denominator > 0 )
        res.append("-");

    long num = abs((long)numerator);
    long den = abs((long)denominator);

    long intpart = num/den;

    string intstr = "";
    if (intpart==0)
        intstr = "0";
    while(intpart>0)
    {
        intstr = char(intpart%10+'0')+intstr;
        intpart /= 10;
    }

    res = res + intstr;

    num %= den;
    if (num == 0)
        return res;

    res.append(".");

    unordered_map<long,int> hs;
    hs[num]=res.size();

    while(num!=0)
    {
        num *= 10;
        res += char(num/den + '0');
        num %= den;
        if (hs.find(num)!=hs.end())
        {
            res.insert(hs[num],"(");
            res.append(")");
            break;
        }
        else
            hs[num]=res.size();
        
    }
    
    return res;

}

int main() {

    cout << fractionToDecimal(-1,INT_MIN) << endl;
    return 0;

}

