// 34.29% med
// long division
// corner cases

#include"mytest.h"


string fractionToDecimal(int numerator_int, int denominator_int) {

    long long numerator = (long long)numerator_int;
    long long denominator = (long long)denominator_int;
    cout<<numerator<<" "<<denominator<<endl;

    string ans;
    unordered_map<long long,int> pos;

    if(numerator*denominator < 0)       //shouldn't overflow: int*int
        ans.push_back('-');

    numerator = abs(numerator);
    denominator = abs(denominator);

    //integer part.
    long long times = numerator/denominator;
    numerator = numerator%denominator;
    ans += to_string(times);
    if(!numerator) return ans;

    //fraction part.
    ans.push_back('.');

    while(numerator) {
        numerator*= 10;
        if(pos.count(numerator)) {
            ans.insert(ans.begin()+pos[numerator], '(');
            ans.push_back(')');
            break;
        }
        times = numerator/denominator;
        ans.push_back(times+'0');
        pos[numerator] = ans.length()-1;
        numerator = numerator%denominator;
    }

    return ans;

}


int main() {
	srand(time(NULL));

    int numerator, denominator;
    while(cin>>numerator>>denominator) {
        cout<<fractionToDecimal(numerator, denominator)<<endl;
    }




    return 0;
}
