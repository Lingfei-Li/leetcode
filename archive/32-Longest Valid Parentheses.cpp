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
void printArray(int* A, int n);
void printListkedList(ListNode *u);
void genArray(int* A, int n);
ListNode* genLinkedList(int n);


int p = 0, n;
int d[500000];
int match(string& str, int i, int j) {
    if(str[i] == '(' && str[j] == ')') return 1;
    return 0;
}

int recurse(string& str) {         //d[i]: longest valid parentheses starting from position i;
    int& u = d[p];
    if(u != -1) return u;
    if(p >= n) return u = 0;
    if(str[p] == ')') return u = 0;
    else if(str[p+1] == ')') {
        p += 2;
        int tmp = recurse(str);
        u = 2+tmp;
        return u;
    }
    else {
        int a = p++;
        int tmp = recurse(str);
        if(p < n && match(str, a, p)) {
            p++;
            return u = 2+tmp+recurse(str);
        }
        else return u = 0;
    }
}

int longestValidParentheses(string s) {
    n = s.length();
    p = 0;
    memset(d, -1, sizeof(d));
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        p = i;
        ans = max(ans, recurse(s));
    }
    return ans;
}




int main() {
	srand(time(NULL));


    string s;
    while(cin>>s) {
        cout<<longestValidParentheses(s)<<endl;

    }


    return 0;
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



//    if(match(p, p+1)) {
//        p += 2;
//        if(cnt) return u = 2;
//        else return u = recurse(0)+2;
//    }
//    else{
//        int a = p++;
//        int& v = d[a];
//        if(str[a] == ')') return v = 0;
//        int tmp = recurse(1);
//        if(!tmp) return v = 0;
//        if(p < n && match(a, p)) {
//            p++;
//            cnt = max(0, cnt-1);
//            return v = recurse(cnt)+tmp+2;
//        }
//        return v = 0;
//    }
