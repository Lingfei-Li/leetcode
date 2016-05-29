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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printVector(vector<int>& v);
void printArray(int* A, int n);
void printListkedList(ListNode *u);
void genVector(vector<int>& v, int n);
void genArray(int* A, int n);
ListNode* genLinkedList(int n);


string add(string& num1, string& num2) {
    if(!num1.length()) return num2;
    else if(!num2.length()) return num1;

    int n = max(num1.size(), num2.size());
    string ans;
    ans.resize(n+1);
    int s = 0, c = 0;
    for(int i = 0; i < n; i ++) {
        int n1 = 0, n2 = 0;
        if(i < num1.size()) {
            n1 = num1[num1.size()-1-i]-'0';
        }
        if(i < num2.size()) {
            n2 = num2[num2.size()-1-i]-'0';
        }
        ans[n-i] = (n1 + n2 + c)%10 + '0';
        c = (n1 + n2 + c)/10;
    }
    if(c) ans[0] = c+'0';
    else ans = ans.substr(1, ans.length()-1);
    return ans;
}

string multiply_single(string& num1, char& ch) {
    string ans;
    ans.resize(num1.length()+1);
    int c = 0;
    for(int i = num1.length()-1; i >= 0; i --) {
        int s = (ch-'0') * (num1[i]-'0') + c;
        ans[i+1] = s%10+'0';
        c = s/10;
    }
    if(c) {
        ans[0] = c+'0';
    }
    else {
        ans = ans.substr(1, ans.length()-1);
    }
    return ans;
}

string multiply(string num1, string num2) {
    int multiplier = 0;
    string ans;
    for(int i = num2.length() - 1; i >= 0; i --) {
        string tmp = multiply_single(num1, num2[i]);
        for(int j = 0; j < multiplier; j ++) {
            tmp.append("0");
        }
        ans = add(ans, tmp);
        multiplier ++;
    }
    while(ans.length() > 1 && ans[0] == '0') {
        ans = ans.substr(1, ans.length()-1);
    }
    return ans;
}




int main() {
	srand(time(NULL));

    ofstream fout("out.out");
	cout.rdbuf(fout.rdbuf());

    string num1 = "800000000000000000000", num2 = "800000000000000000000";
    char ch = '9';

    cout<<multiply(num1, num2)<<endl;

//    cout<<multiply_single(num1, ch)<<endl;
//    cout<<add(num1, num2)<<endl;



    return 0;
}
void printVector(vector<int>& v) {
    for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
    printf("\n");
}
void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}
void printListkedList(ListNode *u) {
    while(u) {
        printf("%d -> ", u->val);
        u = u->next;
    }
	printf("\n");
}
void genVector(vector<int>& v, int n) {
    for(int i = 0; i < n; i ++) v.push_back(rand()%20-10);
    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-10;
    sort(A, A+n);
}

ListNode* genLinkedList(int n) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    return head;
}
