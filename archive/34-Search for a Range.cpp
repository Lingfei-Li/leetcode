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



vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size(), l = 0, r = n;
    int m, ansl = -1, ansr = -1;
    while(l < r) {
        m = (l+r)/2;
        if(nums[m] <= target)
            l = m+1;
        else if(nums[m] > target)
            r = m;
    }
    ansr = r-1;

    l = 0;
    while(l <r ) {
        m = (l+r)/2;
        if(nums[m] >= target)
            r = m;
        else if(nums[m] < target)
            l = m+1;
    }

    vector<int> ans(2,-1);
    if(l<=ansr) ans[0] = l, ans[1] = ansr;
    return ans;

}


int main() {
	srand(time(NULL));


    vector<int> v;
    genVector(v, 2);
    printVector(v);
    vector<int> a = searchRange(v, 1);
    printVector(a);



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
    for(int i = 0; i < n; i ++) v.push_back(rand()%3);
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
