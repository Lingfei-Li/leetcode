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


int firstMissingPositive_1(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 1;
    for(int i = 0; i < n; i ++) {
        if(nums[i] <= 0) {
            nums[i] = n+1;
        }
    }

    for(int i = 0; i < n; i ++) {
        if(abs(nums[i]) < n+1) {
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
    }

    for(int i = 0; i < n; i ++) {
        if(nums[i] >= 0) {
            return i+1;
        }
    }
    return n+1;
}

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int flag = 1;
    int cnt = 0;
    while(flag) {
        flag = 0;
        for(int i = 0; i < n; i ++) {
            if(nums[i] > 0 && nums[i] <= n) {
                if(nums[i] != i+1 && nums[nums[i]-1] != nums[i]) {
                    swap(nums[i], nums[nums[i]-1]);
                    flag = 1;
                }
            }
        }
        cnt++;
    }
    printf("cnt: %d\n", cnt);

    for(int i = 0; i < n; i ++) {
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
}




int main() {
	srand(time(NULL));

    for(int i = 0; i < 100; i ++) {


        vector<int> v;
    //    v.push_back(1);
        genVector(v, 10);
//        printVector(v);
//        cout<<firstMissingPositive(v)<<endl;
        firstMissingPositive(v);
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
