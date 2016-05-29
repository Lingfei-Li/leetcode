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



int longestValidParentheses(string s) {
    int n = s.length();
    int d[500000];
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '(') {
            d[i] = 0;
            cnt++;
        }
        else {
            if(cnt) {
                cnt--;
                d[i] = 2;
                if(i-1 >= 0) d[i] += d[i-1];
                if(i-d[i] >= 0) d[i] += d[i-d[i]];
            }
            else {
                d[i] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(d[i] > ans) ans = d[i];
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
