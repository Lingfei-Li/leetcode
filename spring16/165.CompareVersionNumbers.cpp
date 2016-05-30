// 7.65% good
// comprehensive alanysis of corner cases

#include"mytest.h"


int compareVersion(string v1, string v2) {
    int p1 = 0, p2 = 0, l1 = v1.length(), l2 = v2.length();
    int s1 = 0, s2 = 0;

    for(int i = l1-1; i >= 0; i --) {
        if(v1[i] == '.') {
            if(atoi(v1.substr(i+1, l1-i-1).c_str()) == 0) 
                v1.resize(i);
            else 
                break;
        }
    }
    for(int i = l2-1; i >= 0; i --) {
        if(v2[i] == '.') {
            if(atoi(v2.substr(i+1, l2-i-1).c_str()) == 0) 
                v2.resize(i);
            else 
                break;
        }
    }
//    cout<<v1<<endl<<v2<<endl;

    l1 = v1.length();
    l2 = v2.length();


    while(p1<l1 && p2<l2) {
//        printf("%d %d\n", p1, p2);
        while(p1<l1 && v1[p1] != '.') {
            p1 ++;
        }
        while(p2<l2 && v2[p2] != '.') {
            p2 ++;
        }
        int t1 = atoi(v1.substr(s1, p1-s1).c_str());
        int t2 = atoi(v2.substr(s2, p2-s2).c_str());
        if(t1!=t2) {
            return (t1<t2)?-1:1;
        }
        s1 = ++p1;
        s2 = ++p2;
    }
//        printf("%d %d\n", p1, p2);
    if(p1 >= l1 && p2<l2) return -1;
    if(p1 < l1 && p2>=l2) return 1;

    return 0;
}


int main() {
	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2){
        cout<<compareVersion(s1, s2)<<endl;
    }




    return 0;
}
