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
using namespace std;

string print_binary(string val)//string->double->binary->string
{
    if (val.empty()) { // empty check
		cout << "Empty String. ";
		return "";
	}

    int sign = 0;
	if (val.front() == '-') { // negative check
		sign = 1;
		val.erase(val.begin());
	}
    else if (val.front() == '+') { 
		val.erase(val.begin());
	}
    
    bool flag = true;
    int pos = val.find('.');
    if (pos == string::npos){
        flag = false;//no decimal part
        pos = val.length();
    }

    int intpart = atoi(val.substr(0, pos).c_str());
    double decpart = atof(val.substr(pos, val.length()-pos).c_str());
    //cout << intpart << "+" << decpart << endl; 
    string intstr = "", decstr = "";
    if (intpart == 0)
        intstr = '0';
    while(intpart > 0){
        if(intpart&1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1;
    }
    while(decpart > 0){
        //cout << decstr << " " << decpart << endl;
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
/*
    double frac = 0.5;
    while(decpart > 0){
        //cout << decstr << " " << decpart << " " << frac << endl;
        if(decstr.length() > 32) return "ERROR";
        if (decpart >= frac){
            decstr += "1";
            decpart -= frac;
        }
        else
            decstr += "0";
        frac /= 2.;
    }
*/
    return char(sign + '0') + string(" ") + intstr + (flag?".":"") + decstr;
}

/*
 * use fix-point representation
 * 32 bits : 1 bit <sign> + 15 bits <integer bits> + 16 <fractional bits>
 */
void toFixPointBinary(char * str) {

	if (!str || *str == '\0') { // empty check
		cout << "Empty String or Pointer. " << endl;
		return;
	}
	int sign = 0;
	if (*str == '-') { // negative check
		sign = 1;
		str++;
	}
    else if (*str == '+')
        str++;

	int integerPart = 0;
	while (*str != '\0' && *str != '.') { // char to integer (atoi)
		if (*str >= '0' && *str <= '9') { // digital check
			integerPart = 10 * integerPart + static_cast<int>(*str - '0');
			str++;
		} else {
			cout << "Invalid Digit String. " << endl;
			return;
		}
	}

	double fractionalPart = 0.;
    if (*str == '.'){
        str++; 

        while (*str != '\0') { // points to the end
            if (*str >= '0' && *str <= '9') // digital check
                str++;
            else {
                cout << "Invalid Digit String. " << endl;
                return;
            }
        }
        str--; // points to the last digit
        while (*str != '.') { // traversal back to the '.'
            fractionalPart = fractionalPart / 10 + static_cast<int>(*str - '0');
            str--;
        }
        fractionalPart /= 10;
    }

    // to binary string

    string result = "";
    while (integerPart > 0) {
        if (result.length() > 15) {
            cout << "ERROR" << endl;
            return;
        }
        result = char((integerPart & 1) + '0') + result;
        integerPart >>= 1;
    }
    
    int length = result.length();
    while (length++ != 15) {
        result = "0" + result;
    }

    result = char(sign + '0') + string(" ") + result + ' '; // <sign> + <integer bits> + .

    while (fractionalPart > 0) {
        //cout << result << " " << fractionalPart << endl;
        if (result.length() > 34) {
            cout << "ERROR" << endl;
            return;
        }
        fractionalPart *= 2.;
        result += fractionalPart >= 1 ? "1" : "0";
        if (fractionalPart >= 1)
            fractionalPart -= 1.;
    }

    length = result.length();
    while (length++ != 34) { // <sign> + <integer bits> + . + <fractional bits>
        result += "0";
    }

    cout << result << endl;

}

/*
 * use floating-point representation (IEEE 745)
 * <sign> × (1 . <fractional significand>) × 2 ^ (<exponent> - 127)
 * 32-bits double-precision floating-point:
 * 1 bit <sign> + 8 bits <exponent> + 23 bits <fractional significand>
 */
void toFloatingPointBinary(char * str) {
    if (!str || *str == '\0') { // empty check
        cout << "Empty String or Pointer. " << endl;
        return;
    }
    int sign = 0;
    if (*str == '-') { // negative check
        sign = 1;
        str++;
    }
    else if (*str == '+')
        str++;

    int integerPart = 0;
    while (*str != '\0' && *str != '.') { // char to integer (atoi)
        if (*str >= '0' && *str <= '9') { // digital check
            integerPart = 10 * integerPart + static_cast<int>(*str - '0');
            str++;
        } else {
            cout << "Invalid Digit String. " << endl;
            return;
        }
    }

    double fractionalPart = 0.;
    if (*str == '.'){
        str++; 

        while (*str != '\0') { // points to the end
            if (*str >= '0' && *str <= '9') // digital check
                str++;
            else {
                cout << "Invalid Digit String. " << endl;
                return;
            }
        }
        str--; // points to the last digit
        while (*str != '.') { // traversal back to the '.'
            fractionalPart = fractionalPart / 10 + static_cast<int>(*str - '0');
            str--;
        }
        fractionalPart /= 10;
    }

    // to binary string

    string result = "";
    while (integerPart > 0) {
        result = char((integerPart & 1) + '0') + result;
        integerPart >>= 1;
    }

    int exponent = result.length()-1;

    if (exponent > 128) { 
        cout << "ERROR" << endl;
		return;
	}

	// find the exponent value
	if (exponent >= 0 && exponent <= 128) { // integer part >= 1
		exponent += 127; 
		result.erase(result.begin()); // remove the default 1
	} else { // integer part == 0, result == ""
        exponent = 0;
		while (fractionalPart > 0 && fractionalPart < 1) {
			fractionalPart *= 2.;
			exponent++;
		}
		if (exponent > 127) {
			cout << "ERROR" << endl;
			return;
		}
		exponent = - exponent + 127; // get the bias exponent value

		if (fractionalPart >= 1)
			fractionalPart -= 1; // remove the default 1
	}

    result = " " + result;
	// add exponent part prior to the fractional part
	for (int i = 0; i < 8; i++) {
		result = char((exponent & 1) + '0') + result;
		exponent >>= 1;
	}

	result = char(sign + '0') + string(" ") + result; // 1 bit <sign> + 8 bits <exponent> + integer part (except the 1st bits)

	// 1 bit <sign> + 8 bits <exponent> + 23 bits <fractional significand>
	while (fractionalPart != 0) {
        //cout << result << " " << fractionalPart << endl;
        if (result.length() > 34) {
			cout << "ERROR" << endl;
			return;
		}
		fractionalPart *= 2;
		result += fractionalPart >= 1 ? "1" : "0";
		if (fractionalPart >= 1)
			fractionalPart -= 1;
		
	}
	int length = result.length();
	while (length++ != 34)
		result += "0";

	cout << result << endl;

}

int main() {

	char num[][10] = { "1.25", "-1.25", "0", "-0", "0.25",""};

	for (int i = 0; i < 6; i++) {
		cout << num[i] << " : " << endl;
        cout << print_binary(num[i]) << endl;
		cout << "fix-point:\t";
		toFixPointBinary(num[i]);
		cout << "floating-point:\t";
		toFloatingPointBinary(num[i]);
		cout << endl;
	}

    return 0;

}

