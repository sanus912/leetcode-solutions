#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<Algorithm>
using namespace std;


class Solution {
public:

/*
 * using additional space: O(n) time, O(1) space
 */
bool is_anagrams_func(char * str1, char * str2) {

	if (!str1 || !str2)
		return false;
	if (strlen(str1) != strlen(str2))
		return false;

	int ascii[256] = { 0 };

	for (int i = 0; str1[i] != '\0'; i++) {
		ascii[(int) str1[i]]++;
		ascii[(int) str2[i]]--;
	}

	for (int i = 0; i<256; i++) {
		if (ascii[i]!=0) return false;
	}
	return true;
}

/*
 *sorting
 */

bool isAnagram1(string s, string t){
    if(s.length() != t.length()) return false;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) return true;
    else return false;
}


};


int main(int argc, char ** argv) {

    Solution mySol;

    char result[2][6] = { "False", "True" };

    char str[] = { "abcda" };
	char str1[] = { "adcba" };
	char str2[] = { "dcbea" };
	char str3[] = { "dcaaa" };

	cout << str << " vs. " << str1 << " : " << result[mySol.is_anagrams_func(str,
			str1)] << endl;
	cout << str << " vs. " << str2 << " : " << result[mySol.is_anagrams_func(str,
			str2)] << endl;
	cout << str << " vs. " << str3 << " : " << result[mySol.is_anagrams_func(str,
			str3)] << endl;

	cout << str << " vs. " << str3 << " : " << result[mySol.isAnagram1(str,
			str3)] << endl;


    return 0;
}
