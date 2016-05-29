#include"mytest.cpp"


using namespace std;


vector<int> plusOne(vector<int>& digits) {
    int c = 0, firstdigit = 1;
    for(int i = digits.size() - 1; i >= 0; i --) {
        digits[i] = digits[i]+firstdigit+c;
        firstdigit = 0;
        if(digits[i] >= 10) {
            c = 1;
            digits[i] -= 10;
        }
        else
            c = 0;
    }
    vector<int> ans;
    if(c) {
        ans.resize(digits.size() + 1);
        for(int i = 0; i < digits.size(); i ++) ans[i+1] = digits[i];
        ans[0] = 1;
        return ans;
    }
    return digits;
}


int main() {
	srand(time(NULL));


    string s;
    while(cin>>s) {
        vector<int> v;
        for(int i = 0; i < s.length(); i ++) {
            v.push_back(s[i]-'0');
        }
        for(int i = 0; i < v.size(); i ++) {
            cout<<v[i]<<endl;
        }
        vector<int> ans = plusOne(v);
        for(int i = 0; i < ans.size(); i ++) cout<<ans[i]<<" ";
//        cout<<endl;
    }



    return 0;
}
