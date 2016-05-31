// corner cases
// understanding the problem

#include"mytest.h"

class ValidWordAbbr {
private:
    string getAbbr(string& s){
        int len = s.length();
        if(len <= 2) return s;
        string ret = s[0] + to_string((long long)len-2) + s[len-1];
        return ret;
    }

public:
    unordered_map<string, int> dict;
    unordered_set<string> words;
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto it:dictionary){
            if(words.count(it)) continue;
            dict[getAbbr(it)] ++;
            words.insert(it);
        }
    }

    bool isUnique(string& word) {
        int cnt = dict[getAbbr(word)];
        if(cnt > 1) return false;
        if(cnt == 0 || (cnt == 1 && words.count(word))) return true;
        return false;
    }
};




int main() {
	srand(time(NULL));

    vector<string> v;
    v.push_back("hello");
    v.push_back("hello");
//    read(v);

    ValidWordAbbr val = ValidWordAbbr(v);

    vector<string> v2;
    v2.push_back("hello");

    for(auto it:v2){
        cout<<val.isUnique(it)<<endl;
    }




    return 0;
}
