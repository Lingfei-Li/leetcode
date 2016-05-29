#include<cstdio>
#include<cstring>
#include<algorithm>

#include<vector>

#include<queue>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;


//Global Variables.

////

string intToRoman(int num) {
    string ans;

    for(int i = 0; i < num/1000; i ++) {
        ans.push_back('M');
    }
    num = num%1000;
    if(num/100 == 9) {
        ans.push_back('C');
        ans.push_back('M');
        num -= 900;
    }
    if(num/100 >= 5) {
        ans.push_back('D');
        num -= 500;
    }
    if(num/100 == 4) {
        ans.push_back('C');
        ans.push_back('D');
        num -= 400;
    }
    for(int i = 0; i < num/100; i ++) {
        ans.push_back('C');
    }
    num = num % 100;
    if(num/10 == 9) {
        ans.push_back('X');
        ans.push_back('C');
        num -= 90;
    }
    if(num/10 >= 5) {
        ans.push_back('L');
        num -= 50;
    }
    if(num/10 == 4) {
        ans.push_back('X');
        ans.push_back('L');
        num -= 40;
    }
    for(int i = 0; i < num/10; i ++) {
        ans.push_back('X');
    }
    num = num % 10;
    if(num == 9) {
        ans.push_back('I');
        ans.push_back('X');
        num = 0;
    }
    if(num >= 5) {
        ans.push_back('V');
        num -= 5;
    }
    if(num == 4) {
        ans.push_back('I');
        ans.push_back('V');
        num = 0;
    }
    for(int i = 0; i < num; i ++) ans.push_back('I');
    return ans;
}

int main()
{


    int x;
    while(cin>>x) cout<<intToRoman(x)<<endl;



    return 0;
}
