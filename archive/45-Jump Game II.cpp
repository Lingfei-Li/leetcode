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


int jump(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    if(n <= 1) return ans;
    ans = 1;
    int max_start = nums[0], max_end = nums[0];
    if(max_end >= n) return ans;
    for(int i = 1; i < n-1; i ++) {
        max_end = max(max_end, i+nums[i]);
//        printf("i:%d, max_start:%d, max_end:%d, ans:%d\n", i, max_start, max_end, ans);
        if(i == max_start) {            //if we reached the furthest in current step, switch to next step
            max_start = max_end;    //start from the new beginning
            ans ++;
        }
    }
    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v, 2);
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
    for(int i = 0; i < n; i ++) v.push_back(rand()%2+1);
//    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%2;
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
