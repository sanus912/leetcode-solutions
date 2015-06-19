#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> hs;

inline bool cmp(string s1, string s2){//按长度从大到小排
    return s2.length() < s1.length();
}

bool MakeOfWords(string word, int length){
    //cout<<"curr: "<<word<<endl;
    int len = word.length();
    //cout<<"len:"<<len<<endl;
    if(len == 0) return true;

    for(int i=1; i<len; ++i){
        string str = word.substr(0, i);
        //cout<<str<<endl;
        if(hs.find(str)!=hs.end()|| MakeOfWords(word.substr(i), length))
                return true;
    }
    return false;
}

void PrintLongestWord(string word[], int n){
    for(int i=0; i<n; ++i)
        hs.insert(word[i]);
    sort(word, word+n, cmp);

    for(int i=0; i<n; ++i){
        if(MakeOfWords(word[i], word[i].length())){
            cout<<"Longest Word: "<<word[i]<<endl;
            return;
        }
    }
}

int main(){
    string arr[] = {"test", "tester", "testertest", "testing", 
				"apple", "seattle", "banana",  "batting", "ngcat", 
                "batti","bat", "testingtester", "testbattingcat"};
    int len = 13;
    PrintLongestWord(arr, len);
    return 0;
}
