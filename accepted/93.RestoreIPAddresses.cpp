// Feature:
// Backtracking
// Comprehensive analysis of valid condition

#include"mytest.h"


using namespace std;

void solve(string& s, vector<string>& ans, string& ip, int pos, int rnd) {
    if(rnd == 4){       //base case
        if(pos == s.length()) {
            ans.push_back(ip);
        }
        return;
    }

    for(int i = 1; i <= 3; i ++) {
        string addr = s.substr(pos, i);
        //Invalid:
        // (a) >255
        // (b) 0*
        if((addr[0] == '0' && i != 1)|| atoi(addr.c_str()) > 255) { //if not valid address, pass 
//        if(atoi(addr.c_str()) > 255) { //if not valid address, pass 
            continue;
        }

        //pruning
        if((4-rnd)*3 < s.length()-pos-i) continue;


        int initsize = ip.length();
        ip.append(addr);
        if(rnd != 3) ip.push_back('.');
        solve(s, ans, ip, pos+i, rnd+1);
        ip.resize(initsize);
    }
}



vector<string> restoreIpAddresses(string s) {
    vector<string> ans;

    string dummy;
    solve(s, ans, dummy, 0, 0);


    return ans;    
}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<s<<endl;
        vector<string> ans = restoreIpAddresses(s);
        for(int i = 0; i < ans.size(); i ++) {
            cout<<ans[i]<<endl;
        }
    }




    return 0;
}
