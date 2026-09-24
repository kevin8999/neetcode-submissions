#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashMap;

        for (int& num : nums) {
            if (hashMap.find(num) != hashMap.end())
                hashMap[num] += 1;
            else
                hashMap.insert({num, 1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> minHeap;

        for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            minHeap.push(make_pair(it->second, it->first));
        }

        int i = 0;
        vector<int> output(k);
        while (i < k) {
            output[i] = minHeap.top().second;
            minHeap.pop();
            ++i;
        }

        return output;
    }
};
