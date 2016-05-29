// 20.9%
// corner cases

#include"mytest.h"

string numberToWords(int num) {

    char word[][10] = {"", "Thousand", "Million", "Billion"};
    char number[][10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char doublenum[][10] = {"", "ERROR!!!", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char tens[][10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};


    if(!num) return string("Zero");
    int pow = 0;
    vector<string> v;
    cout<<num<<endl;
    while(num) {
        string s = "";
        int tmp = num%1000;
        num /= 1000;
//        cout<<tmp<<endl;
        int pos[3];
        pos[0] = tmp%10;
        pos[1] = (tmp/10)%10;
        pos[2] = (tmp/100)%10;

        if(pos[2])
            s += string(number[pos[2]]) + " Hundred";
        if(pos[1] == 1) {
            if(pos[2] && pos[1]) s+=" ";
            s += string(tens[pos[0]]);
        }
        else {
            if(pos[2] && pos[1]) s+=" ";
            s += string(doublenum[pos[1]]);
            if((pos[2] || pos[1]) && pos[0]) s += " ";
            s += string(number[pos[0]]);
        }
        if(pow && tmp)
            s = s+" "+word[pow];
        pow ++;
//        cout<<s<<endl;
        v.push_back(s);
    }

    string ans;
    for(int i = v.size()-1; i >= 0; i --) {
        if(i!=v.size()-1 && v[i] != "") ans += " ";
        ans += v[i];
    }
//    ans.push_back('_');
    return ans;

                
}



int main() {
	srand(time(NULL));

    int a;
    while(cin>>a)
        cout<<numberToWords(a)<<endl;



    return 0;
}
