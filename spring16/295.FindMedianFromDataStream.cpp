// 42.09% med
// binary search tree
// median

#include"mytest.h"


struct Node{
    int val;
    Node *left, *right;
    int size, leftsize, rightsize;
    Node(int v): val(v){
        size = 1;
        leftsize = rightsize = 0;
        left = right = NULL;
    }
};



class MedianFinder {
public:
    Node* root;
    MedianFinder() {
        root = 0;
    }

    Node* add(Node* u, int v) {
        if(!u) {
            u = new Node(v);
            return u;
        }
        if(v < u->val) {
            u->leftsize ++;
            u->left = add(u->left, v);
        }
        else if(v > u->val) {
            u->rightsize ++;
            u->right = add(u->right, v);
        }
        else {
            u->size ++;
        }

        return u;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        root = add(root, num);
    }

    int findMin(Node* u) {
        if(!u) return 1<<31;
        if(u->left) return findMin(u->left);
        return u->val;
    }
    int findMax(Node* u) {
        if(!u) return 1<<31;
        if(u->right) return findMax(u->right);
        return u->val;
    }

    // Returns the median of current data stream
    double findMedian() {
        Node* u = root;
        if(!u) return 0;
        int leftcnt = u->leftsize;
        int rightcnt = u->rightsize;
        while(1){
            assert(u != 0);

            if(leftcnt == rightcnt)break;

            // can cover
            if((leftcnt < rightcnt && leftcnt + u->size > rightcnt) ||
               (rightcnt < leftcnt && rightcnt + u->size > leftcnt)) {
                return (double)u->val;
            }

            if((leftcnt < rightcnt && leftcnt + u->size > rightcnt) ||
               (rightcnt < leftcnt && rightcnt + u->size > leftcnt)) {
                return (double)u->val;
            }

            //share
            if(leftcnt + u->size == rightcnt) {
                assert(u->right);
                return ((double)u->val + (double)findMin(u->right)) / 2;
            }
            if(rightcnt + u->size == leftcnt) {
                assert(u->left);
                return ((double)u->val + (double)findMax(u->left)) / 2;
            }

            //cannot cover
            if(leftcnt > rightcnt) {
                rightcnt += u->size;
                u = u->left;
                rightcnt += u->rightsize;
                leftcnt = leftcnt - u->size - u->rightsize;
            }
            else{
                leftcnt += u->size;
                u = u->right;
                leftcnt += u->leftsize;
                rightcnt = rightcnt - u->size - u->leftsize;
            }
        }
        return (double)u->val;
    }
};

int main() {
	srand(time(NULL));


    vector<int> v;
    vector<int> tmp;
    int n = 10;
    gen(v,n);
    print(v);
    MedianFinder mf;
    for(int i = 0; i < v.size(); i ++) {
        tmp.push_back(v[i]);
        sort(tmp.begin(), tmp.end());
        print(tmp);
        mf.addNum(v[i]);
        cout<<"Median: "<<mf.findMedian()<<endl;
    }

    return 0;
}
