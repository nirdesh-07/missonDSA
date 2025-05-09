#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26, 0);

        for (char i : tasks) {
            mp[i - 'A']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (mp[i])
                pq.push(mp[i]);
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> remain;
            int cycle = n + 1;

            while (cycle && !pq.empty()) {
                int max_freq = pq.top();
                pq.pop();
                if (max_freq > 1) {
                    remain.push_back(max_freq - 1);
                }
                ++time;
                --cycle;
            }

            for (int count : remain) {
                pq.push(count);
            }

            if (pq.empty()) break;
            time += cycle;
        }

        return time;
    }
};

int main() {
    Solution sol;

    // Example: Tasks = ['A','A','A','B','B','B'], cooldown n = 2
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    int result = sol.leastInterval(tasks, n);
    cout << "Minimum intervals needed: " << result << endl;

    return 0;
}
