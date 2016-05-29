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


int removeDuplicates(int A[], int n) {
    if(n<=1) return n;
    int p1 = 0, p2 = 0;
    for(p2 = 0; p2 < n; p2 ++) {
        if( !p2 || A[p2] != A[p2-1] ){
            A[p1++] = A[p2];
        }
    }
    return p1;
}

int main() {
	srand(time(NULL));

    int n = 10;
    int A[10];
    for(int i = 0; i < n; i ++) {
        A[i] = rand()%20-10;
    }
    sort(A, A+n);
    for(int i = 0; i < n; i ++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    int newlen = removeDuplicates(A, n);
    cout<<newlen<<endl;
    for(int i = 0; i < newlen; i ++) {
        printf("%d ", A[i]);
    }
    printf("\n");


    return 0;
}



