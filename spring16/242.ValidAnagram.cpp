// 45% 2nd group
// hashtable/sort
// anagrams

#include"mytest.h"


bool isAnagram_1(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s==t;
}

bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> mp;
    unordered_map<char,int> mp2;
    return mp == mp2;

    for(int i = 0; i < s.length(); i ++) {
        mp[s[i]] ++;
    }
    for(int i = 0; i < t.length(); i ++) {
        mp[t[i]] --;
        if(mp[t[i]] == 0) mp.erase(t[i]);
    }
    return mp.empty();

}


int main() {
	srand(time(NULL));


    cout<<isAnagram("asd","asd");


    return 0;
}
