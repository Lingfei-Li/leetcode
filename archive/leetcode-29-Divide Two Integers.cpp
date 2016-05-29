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
#include<climits>

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




int divide(int dividend, int divisor) {
    long long l, r, tmp, ans = 0, tmp_ans;
    long long a = dividend, b = divisor;
    int neg = 0;
    if(a < 0) a = -a, neg ^=1;
    if(b < 0) b = -b, neg ^=1;
    while(a) {
        if(a < b) break;
        l = r = 0;
        tmp = b;
        tmp_ans = 1;
        while(l <= a && r <= a) {
            l = tmp;
            tmp = tmp<<1;
            tmp_ans = tmp_ans<<1;
            r = tmp;
        }
        a -= l;
        ans += tmp_ans>>1;
    }
    if(neg) ans = -ans;
    if(ans>INT_MAX || ans < INT_MIN) return INT_MAX;
    return ans;
}




int main() {
	srand(time(NULL));

    int a, b;
    while(cin>>a>>b) {
//        a = INT_MIN, b = 1;
//        cout<<a<<" "<<b<<endl;
        cout<<divide(a, b)<<endl;
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
