#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> R;
        priority_queue<tuple<int,int,int>> PQ;

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                int num1 = nums1[i], num2 = nums2[j], sum = num1 + num2;
                if (PQ.size() < k) {
                    PQ.push({sum, num1, num2});
                } else if (sum < get<0>(PQ.top())) {
                    PQ.pop();
                    PQ.push({sum, num1, num2});
                } else break; // optimization since nums2 is sorted
            }
        }

        while (!PQ.empty()) {
            auto top = PQ.top(); PQ.pop();
            int num1 = get<1>(top), num2 = get<2>(top);
            R.push_back({num1, num2});
        }

        return R;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> result = sol.kSmallestPairs(nums1, nums2, k);

    cout << "K pairs with smallest sums:\n";
    for (auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}
