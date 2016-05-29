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




int maxProfit(vector<int>& prices) {
    int ans = 0, buyprice = 0, buyflag = 0;
    for(int i = 0; i < prices.size(); i ++) {
        if(!buyflag && i != prices.size()-1) {
            if((!i && prices[i+1] > prices[i])
               || (i && prices[i-1] >= prices[i] && prices[i+1] >= prices[i] ) //&& !(prices[i-1] == prices[i+1] && prices[i] == prices[i+1]))
               ) {
                buyprice = prices[i];
                buyflag = 1;
                continue;
            }
        }
        if(buyflag && i) {
            if((i==prices.size()-1)
               || ( i!=prices.size()-1 && prices[i-1] <= prices[i] && prices[i+1] <= prices[i] ) //&& !(prices[i-1] == prices[i+1] && prices[i] == prices[i+1]))
               ) {
                ans += prices[i] - buyprice;
                buyflag = 0;
                continue;
            }
        }
    }
    return ans;
}




int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v, 10);
    printVector(v);
    cout<<maxProfit(v)<<endl;



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
    for(int i = 0; i < n; i ++) v.push_back(rand()%20);
//    sort(v.begin(), v.end());
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
