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



int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int l = 1, r = n;
    while(l<r) {
        int m = (l+r)/2;
        int sum_l = 0, sum_r = 0, sum_m = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] < m) {
                sum_l ++;
            }
            else if(nums[i] > m) {
                sum_r ++;
            }
            else {
                sum_m ++;
            }
        }
        if(sum_m > 1) return m;
        if(r-l == 1) return r;
        if(sum_l > m-1) r = m-1;
        else l = m+1;
    }

    return r;
}





int main() {
	srand(time(NULL));


	freopen("287-Find the Duplicate Number.in","r",stdin);


    int n = 0, tmp;
    while(scanf("%d", &n) != EOF) {
        vector<int> v;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        printVector(v);
        cout<<findDuplicate(v)<<endl;
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
    for(int i = 0; i < n; i ++) v.push_back(rand()%10+1);
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
