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


static const int maxn = 1e5;
int INF = 1<<30;
int dp[maxn];

int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    memset(dp, 0, sizeof(dp));
    dp[nums.size() - 1] = 0;
    for(int i = nums.size() - 2; i >= 0; i --) {
        int minstep = INF;
        for(int j = 1; j <= nums[i]; j ++) {
            if(i+j >= nums.size()) break;
            minstep = min(minstep, dp[i+j]) + 1;
        }
//        printf("i:%d %d, minstep:%d\n", i, nums[i], minstep);
        dp[i] = minstep;
    }


    return dp[0];
}



int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v, 10);
    printVector(v);
    cout<<jump(v)<<endl;



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
    for(int i = 0; i < n; i ++) v.push_back(rand()%5+1);
//    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-9;
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
