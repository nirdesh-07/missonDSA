#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int nodes = 1; // start with one slot for the root

        while (getline(ss, curr, ',')) {
            nodes--; // one node takes one slot

            if (nodes < 0)
                return false;

            if (curr != "#")
                nodes += 2; // non-null node adds 2 child slots
        }

        return nodes == 0; // all slots should be exactly filled
    }
};

int main() {
    Solution sol;

    string test1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string test2 = "1,#";
    string test3 = "9,#,#,1";

    cout << "Test 1: " << (sol.isValidSerialization(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (sol.isValidSerialization(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (sol.isValidSerialization(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}
