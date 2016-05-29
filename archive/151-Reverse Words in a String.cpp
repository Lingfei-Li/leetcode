
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



//void reverseWords(string &s) {
//    stack<string> stk;
//    int n = s.length(), p = 0;
//    for(int i = 0; i <= n; i ++) {
//        if(i == n) {
//            if(i > p) {
//                stk.push(s.substr(p, i-p));
//            }
//        }
//        if(s[i] == ' '){
//            if(i > p) {
//                stk.push(s.substr(p, i-p));
//            }
//            p = i+1;
//        }
//    }
//    string ans;
//    while(!stk.empty()) {
//        ans += stk.top();
//        stk.pop();
//        if(!stk.empty()) ans += " ";
//    }
//    s = ans;
//}

void reverseWords(string &s) {
    stringstream ss(s);
    stack<string> stk;
    string tmp;
    while(ss>>tmp) {
        stk.push(tmp);
    }
    tmp.clear();
    while(!stk.empty()) {
        tmp += stk.top();
        stk.pop();
        if(!stk.empty()) tmp += " ";
    }
    s = tmp;
}

int main() {
	srand(time(NULL));
//    freopen("151.out","w",stdout);

    string s;
    while(getline(cin, s)) {
        reverseWords(s);
        cout<<s<<endl;
    }




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
