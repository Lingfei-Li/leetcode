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





double myPowSlow(double x, int n) {
    if(!n) return 1;
    if(n<0) {
        x = 1/x;
        n = -n;
    }
    double ans = 1;
    while(n--) {
        ans = x*ans;
    }
    return ans;
}

double myPow(double x, int n) {
    if(!n) return 1;
    if(n<0) {
        x = 1/x;
        n = -n;
    }

    double ans = 1;
    ans = myPow(x, n/2);
    ans *= ans;
    if(n%2) ans *= x;
    return ans;
}





int main() {
	srand(time(NULL));


    for(int i = 0; i < 10; i ++) {
        double x = (rand()%100)/10;
        int n = rand()%100;
        cout<<myPowSlow(x, n)<<endl<<myPow(x, n)<<endl<<endl;
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
