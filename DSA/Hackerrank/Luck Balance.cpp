#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> contests(n);
    for (int i = 0; i < n; ++i) {
        cin >> contests[i].first >> contests[i].second;
    }

    int luck = 0;
    vector<int> important_contests;

    for (const auto& contest : contests) {
        if (contest.second == 0) {
            luck += contest.first;
        } else {
            important_contests.push_back(contest.first);
        }
    }

    sort(important_contests.rbegin(), important_contests.rend());

    for (size_t i = 0; i < important_contests.size(); ++i) {
        if (i < k) {
            luck += important_contests[i];
        } else {
            luck -= important_contests[i];
        }
    }

    cout << luck << endl;

    return 0;
}