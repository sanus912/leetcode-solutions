/*
 * Ex_1_5_v5.h
 */

/*
 * Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 * append strings, using additional space: O(n+k^2) time, k=num of character sequences, O(n) space
 */
string stringcompression1(string s)
{
	int len=s.length();
	if (len<2) return s;

	string result;
	int i=0, j=1;
	for (;j<len; j++) {
		if (s[j]!=s[i]){
			result += s[i]+to_string(j-i);
			i = j;
		}
	}
	result += s[i]+to_string(j-i);

	return result.length()>len? s : result;
}

/*
 * compute size, using additional space: O(n) time, O(n) space
 */

int countcompression(string s)
{
	int len=s.length();
	int i=0, j=1;
	int size=0;
	for (;j<len; j++) {
		if (s[j]!=s[i]){
			size += 1+to_string(j-i).length();
			i = j;
		}
	}
	size += 1+to_string(j-i).length();
	return size;
}

string stringcompression2(string s)
{
	int len=s.length();
	if (len<2) return s;
	int size=countcompression(s);
	if (len<size) return s;

	char result[size+1];
	int index=0;
	int i=0, j=1;
	for (;j<len; j++) {
		if (s[j]!=s[i]){
			result[index++] = s[i];
			for (char x : to_string(j-i))
				result[index++] = x;
			i = j;
		}
	}
	result[index++] = s[i];
	for (char x : to_string(j-i))
		result[index++] = x;
	result[index]='\0';
	return result;//use char array to assign a string, '\0' is ignored in the string
}

/*
 * compute size, in place: O(n) time
 */

int count1(string s)
{
	int len=s.length();
	int i=0, j=1;
	int count=0;
	for (;j<len; j++) {
		if (s[j]!=s[i])
		{
			if (j-i==1)
				count++;
			i = j;
		}
	}
	if (j-i==1)
		count++;
	return count;
}

void stringcompression3(char * s)
{
	int len=strlen(s);
	if (len<2) return;
	int size=countcompression(s);
	if (len<size) return;

	int count=count1(s);
	//cout << count << endl;
	int newlen = len+count;
	int p = newlen;

	s[p--]='\0';
	int i=len-1,j=len-2;
	for(; j>=0; --j)
		if (s[j]!=s[i])
		{
			if (i-j==1)
			{
				s[p] = '1';
				s[p-1] = s[i];
				p -= 2;
			}
			else
			{
				for (int x=0;x<i-j;x++)
					s[p--] = s[i];
			}
			i = j;
		}
	if (i-j==1)
	{
		s[p] = '1';
		s[p-1] = s[i];
		p -= 2;
	}
	else
	{
		for (int x=0;x<i-j;x++)
			s[p--] = s[i];
	}

	cout << " ---> " << s ;

	int index=0;
	i=0, j=1;
	for (;j<newlen; j++) 
	{
		while (s[j]=='1')
		{
			s[index++] = s[i];
			s[index++] = '1';
			i+=2;
			j+=2;
	
		}
		if (s[j]!=s[i]){
			s[index++] = s[i];
			for (char x : to_string(j-i))
				s[index++] = x;
			i = j;
		}
	}
	s[index++] = s[i];
	for (char x : to_string(j-i))
		s[index++] = x;
    
	s[size]='\0';

}

int main() 
{
	char s[] = { "ccccabdddd" };

	cout << s << " ---> " << stringcompression1(s) << endl;
	cout << s << " ---> " << stringcompression2(s) << endl;
	cout << s ;
	stringcompression3(s);
	cout << " ---> " << s << endl;

    return 0;

}

