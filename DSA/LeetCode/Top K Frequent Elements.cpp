#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<pair<int, int>> pairVec;
        for (auto it : mpp) {
            pairVec.push_back({it.second, it.first});
        }

        sort(pairVec.rbegin(), pairVec.rend()); // Sort descending by frequency

        for (int i = 0; i < k; i++) {
            ans.push_back(pairVec[i].second);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
