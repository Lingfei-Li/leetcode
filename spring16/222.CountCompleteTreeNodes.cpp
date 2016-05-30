// 91.5% 2nd group
// binary search

#include"mytest.h"


int countNodes(TreeNode* root) {
    if(!root) return 0;
    TreeNode* u = root;
    int depth = 0;
    while(u) {
        u = u->left;
        depth ++;
    }
//    cout<<"depth: "<<depth<<endl;

    int ans = 0;
    for(int i = 0; i < depth-1; i ++) {
        ans += 1<<(i);
//        cout<<ans<<endl;
    }

    int d = 1;
    u = root;
    while(u && d < depth) {      //current visiting node
//        printf("u: %d, ans: %d, d: %d\n", u->val, ans, d);
        TreeNode* v = u->right;
        int tmp = d+1;  //1 level more than u
        while(v) {
            v = v->left;
            tmp ++;
        }

        //v reached bottom
        if(tmp == depth) {
            u = u->left;
        }
        else {
            u = u->right;
            ans += 1<<(depth-1-d);    //1<<(depth-d) nodes must be leaf
//            printf("%d %d\n", d, 1<<(depth-1-d));
        }
        d ++;
    }
    ans ++;     //the last leaf node



    return ans;
}



int main() {
	srand(time(NULL));

    TreeNode* root;
    root = readTree();
    printTree(root);
    cout<<countNodes(root)<<endl;




    return 0;
}
