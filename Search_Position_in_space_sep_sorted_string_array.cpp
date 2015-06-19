#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // binary search O(log n)
int search(string str[], string s, int start, int end) {
	while (start <= end) {
		// Ensure there is something at the end
		while (start <= end && str[end] == "") {
			--end;
		}
		if (end < start) {
			return -1; // this block was empty, so fail
		}
		int mid = (start + end) >> 1; // ( start + end ) / 2
		while (str[mid] == "") {
			++mid; // will always find one
		}
		if (str[mid] == s)
			return mid;
		if (str[mid] < s) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return -1;
}

int find(string str[], int n, string s) {

	if (s == "") { // special case 2: empty target O(n) time
		for (int i = 0; i < n; i++) {
			if (str[i] == "") {
				return i;
			}
		}
		return -1;
	}
	return search(str, s, 0, n - 1);
}
};



int main() {

    Solution mySol;
    
    string str1[] = { "at", "", "", "", "ball", "", "", "car", "", "", "dad",
			"", "" };
	string str2[] = { "at", "", "", "", "", "ball", "car", "", "", "dad", "",
			"" };

	cout << mySol.find(str1, 13, "ball") << endl << mySol.find(str2, 12, "ballcar");



    return 0;
}
