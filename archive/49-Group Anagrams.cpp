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

struct ANAGroup {
    string s;
    string ana;
};

static bool cmp(const ANAGroup& lhs, const ANAGroup& rhs) {
    if(lhs.ana == rhs.ana) {
        return lhs.s < rhs.s;
    }
    return lhs.ana < rhs.ana;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;
    if(strs.empty()) return ans;

    vector<ANAGroup> anagroup;
    anagroup.resize(strs.size());
    for(int i = 0; i < strs.size(); i ++) {
        ANAGroup tmp;
        tmp.s = strs[i];
        string s = strs[i];
        sort(s.begin(), s.end());
        tmp.ana = s;
        anagroup[i] = tmp;
    }

    sort(anagroup.begin(), anagroup.end(), cmp);

    cout<<anagroup.size()<<endl;
    string tmp_ana = anagroup[0].ana;
    vector<string> tmp_ans;
    tmp_ans.push_back(anagroup[0].s);
    for(int i = 1; i < anagroup.size(); i ++) {
        if(tmp_ana != anagroup[i].ana) {
            ans.push_back(tmp_ans);
            tmp_ans.clear();
            tmp_ana = anagroup[i].ana;
        }
        tmp_ans.push_back(anagroup[i].s);
    }
    if(!tmp_ans.empty()) ans.push_back(tmp_ans);
//    for(int i = 0; i < ans.size(); i ++) {
//        for(int j = 0; j < ans[i].size(); j ++) {
//            cout<<ans[i][j]<<endl;
//        }
//        cout<<endl;
//    }

    return ans;
}






int main() {
	srand(time(NULL));

    string s;
    vector<string> v;
    while(cin>>s && s != "q") {
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
    groupAnagrams(v);


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
