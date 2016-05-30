// 35.18%
// KMP algorithm

#include"mytest.h"



vector<int> buildprefix(string& pattern) {
    int i, j;
    i = 1, j = 0;
    vector<int> prefix;
    prefix.resize(pattern.size());
    prefix[0] = 0;


    while(i < pattern.length() && j < pattern.length()) {
        if(pattern[i] == pattern[j]) {
            prefix[i] = j+1;
            i++;
            j++;
        }
        else {
            //p[i] and p[j] don't match
            while(j > 0 && pattern[i] != pattern[j]) {
                j = prefix[j-1];        //j doesn't need to increment 1, because array starts from 0
            }
            if(pattern[i] == pattern[j]) {
                prefix[i] = j+1;
                i++;
                j++;
            }
            else {
                assert(j==0);
                prefix[i] = 0;
                i++;
            }
        }
    }
    return prefix;
}

int search_variant(vector<int>& prefix, string& text, string& pattern) {
    int i, j;
    i = j = 0;
    int n = text.length(), m = pattern.length();
//    if(m > n) return -1;
    //i: position in text
    //j: position in pattern
    while(i < n && j < m) {
        if(text[i] == pattern[j]) {
            i ++;
            j ++;
        }
        else {
            if(j != 0) {
                j = prefix[j-1];
            }
            else {
                i ++;
            }
        }
    }
    if(i >= n || j >= m) {
        //search is successful
        return i-j;     
        //if i >= n, j is the length of matched string
        //if j >= m, j is the length of the pattern string.
    }
    else {
        return -1;
    }
}

int match(string& text, string& pattern) {

    vector<int> prefix = buildprefix(pattern);
//    cout<<"Prefix:\n";
//    printVector(prefix);
    int matchingpos = search_variant(prefix, text, pattern);
    if(matchingpos == -1) {
//        cout<<"No match\n";
        return -1;
    }
//    cout<<text<<endl;
    for(int i = 0; i < matchingpos; i ++) {
//        cout<<" ";
    }
//    cout<<"|"<<endl;
//    cout<<search_variant(prefix, text, pattern)<<endl;



    return matchingpos;
}



string shortestPalindrome(string s) {
    int n = s.length(), k;
    if(!n) return "";

    string t;
    t.resize(n);
    for(int i = 0; i < n; i ++) {
        t[n-1-i] = s[i];
    }
//    cout<<s<<endl;
//    cout<<t<<endl;
//    match(s, t);
    k = match(t, s);        //note the order
    //we want to find the maximum match between the two.
    //first we write s and t parallel
    //if not match, we move t leftward by 1, then try to match again.
    //this is the same as exchanging s and t and do the same thing as in kmp 
    //now, matching position to end of t is the matched palindrom. 
    //matching position -1 to the start of t is what we need to append to the start of s

    string ans;
    for(int i = 0; i < k; i ++) {
        ans.push_back(s[n-1-i]);
    }
//    cout<<ans<<endl;
    ans.insert(ans.end(), s.begin(), s.end());


//    cout<<"Ans:\n"<<ans<<endl<<endl;

    return ans;
}

bool ispalindrom(string& s, int l, int r) {
    while(l<r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

string shortestPalindrome_slow(string s) {

    int n = s.length(), k;
    for(k = n-1; k > 0 ; k --) {
        if(ispalindrom(s, 0, k)) {
            break;
        }
    }
//    printf("%d\n", k);

    string ans;
    for(int i = 0; i < n-1-k; i ++) {
        ans.push_back(s[n-1-i]);
    }
    ans.insert(ans.end(), s.begin(), s.end());

//    cout<<ans<<endl;

    return ans;
}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<shortestPalindrome(s)<<endl;
        cout<<shortestPalindrome_slow(s)<<endl;
        cout<<endl;
    }




    return 0;
}
