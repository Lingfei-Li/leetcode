// 43.5% med
// string
// bitmap

#include"mytest.h"

int maxProduct(vector<string>& words) {
    int n = words.size();
    if(n < 2) return 0;
    vector<int> mask;
    mask.resize(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < words[i].length(); j ++) {
            mask[i] |= (1<<(words[i][j]-'a'));
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i+1; j < n; j ++) {
            if((mask[i] & mask[j]) == 0) {
                ans = max(ans, (int)(words[i].length()* words[j].length()));
            }
        }
    }
    return ans;
}

//a ab abc d cd cbd abcd
//abcw baz foo bar xtfn abcdef


int main() {
	srand(time(NULL));

    string s;
    vector<string> v;
    read(v);
    cout<<maxProduct(v)<<endl;




    return 0;
}
