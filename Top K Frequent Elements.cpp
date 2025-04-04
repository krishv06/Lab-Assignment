class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Bucket sort: index = frequency, value = list of numbers with that frequency
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        // Traverse buckets from high to low frequency
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
