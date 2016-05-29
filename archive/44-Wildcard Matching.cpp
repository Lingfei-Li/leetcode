#define UVa  "44-Wildcard Matching.cpp"     //

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

//int dp[10000][10000];
int dp[10000][2];

bool charMatch(char a, char b) {
    return (a == b || b == '?' || b == '*');
}

bool isMatch(string s, string p) {


    //For cases where s.length() or p.length is 0.
    if(s.length() == 0) {
        if(p.length() == 0) return true;
        for(int i = 0; i < p.length(); i ++) {
            if(p[i] != '*') return false;
        }
        return true;
    }
    if(p.length() == 0) return false;

    //Now length of s and p both >= 1.
    memset(dp, 0, sizeof(dp));
    int n = s.length(), m = p.length();
    int t = 0;
    if(charMatch(s[n-1], p[m-1])) dp[m-1][t] = 1;
//    if(p[m-1] == '*') {
//        for(int i = 0; i < n; i ++) {
//            dp[i][t] = 1;
//        }
//    }

    for(int i = n-2; i >= 0; i --) {        //iterating through s
        t ^= 1;
        for(int k = 0; k < m; k ++) dp[k][t] = 0;
        if(p[m-1] == '*') dp[n-1][t] = 1;
        for(int j = m-2; j >= 0; j --) {     //iterating through p
            dp[j][t] = (dp[j+1][t^1] && charMatch(s[i], p[j])) ||           //for characters and ?, only one case: current match, previous match.
                        (p[j] == '*' && (dp[j+1][t] || dp[j][t^1]));        //for *, 2 cases: * is continuous matching / * is ignored

        }
    }

//    for(int j = m - 2; j >= 0; j --) {
//        t ^= 1;
//        for(int k = 0; k < n-2; k ++) dp[k][t] = 0;
//        for(int i = n - 2 - (m-2-j); i >= 0; i --) {
//            dp[i][t] = (p[j] == '*' && (dp[i][t^1] || dp[i+1][t])) || (dp[i+1][t^1] && charMatch(s[i], p[j]));
//        }
//    }
    return dp[0][t];
}


int main() {
    #define DEBUG 1
    #ifdef DEBUG
    char fileIn[30] = UVa, fileOut[30] = UVa;
    strncpy(&fileIn[strlen(fileIn) - 4], ".in\0", 5); strncpy(&fileOut[strlen(fileOut) - 4], ".out\0", 5);
    freopen(fileIn,"r",stdin);
//    freopen(fileOut,"w",stdout);
    #endif


	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2) {
        if(isMatch(s1, s2)) cout<<"Match"<<endl;
        else cout<<"Fail"<<endl;
//        cout<<s1.substr(3, 3);
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
