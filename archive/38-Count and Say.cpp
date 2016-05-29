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



void genAns(vector<string>& ans, int n) {
    ans.push_back("1");
    for(int i = 1; i < n; i ++) {
        string u = ans[i-1];
        int cnt = 0;
        string tmp;
        int j = 1;
        for(j = 1; j < u.length(); j ++) {
            if(u[j]!=u[j-1]) {
                tmp.push_back(cnt+1+'0');
                tmp.push_back(u[j-1]);
                cnt = 0;
            }
            else cnt ++;
        }
        tmp.push_back(cnt+1+'0');
        tmp.push_back(u[j-1]);
        ans.push_back(tmp);
    }
}


string countAndSay(int n) {
    vector<string> ans;
    genAns(ans, n);
    return ans[n-1];
}



int main() {
	srand(time(NULL));

    int n;
    while(cin>>n)
        cout<<countAndSay(n)<<endl;


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
