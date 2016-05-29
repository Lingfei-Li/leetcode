// 36ms
// hashtable
// heap (priority queue)

#include"mytest.h"


class RadixSort{
    static int getmax(vector<int>& v) {
        int ans = (1<<31);
        for(int i = 0; i < v.size(); i ++) ans = max(ans, v[i]);
        return ans;
    }

    static void countSort(vector<int>& v, int mask) {
        int cnt[10] = {0};
        for(int i = 0; i < v.size(); i ++) {
            int digit = (v[i]/mask)%10;
            cnt[digit] ++;
        }
        for(int i = 1; i < 10; i ++) {
            cnt[i] += cnt[i-1];
        }
        vector<int> tmp;
        tmp.resize(v.size());
        for(int i = v.size()-1; i >= 0; i --) {
            int digit = (v[i]/mask)%10;
            tmp[--cnt[digit]] = v[i];
        }
        v = tmp;
    }
    public:
    static void sort(vector<int>& v) {
        int mask = 1;
        int maxNum = getmax(v);
        while(maxNum/mask) {
            countSort(v, mask);
            mask *= 10;
        }
    }

};



vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    if(!nums.size()) return ans;
    unordered_map<int,int> cnt;
    for(int i = 0; i < nums.size(); i ++) {
        cnt[nums[i]] ++;
    }

    priority_queue<pair<int,int> > q;
    for(auto ptr = cnt.begin(); ptr != cnt.end(); ptr ++) {
        q.push(pair<int,int>(ptr->second, ptr->first));
    }

    while(k--){
        if(q.empty()) break;
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
                
}



int main() {
	srand(time(NULL));


    vector<int> v;
    read(v);
//    gen(v,10);
    print(v);
    print(topKFrequent(v, 2));
    RadixSort::sort(v);
    print(v);




    return 0;
}
