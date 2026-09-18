#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void backtrack(int index, vector<int>& candidates,
                   int target, vector<int>& current,
                   vector<vector<int>>& result) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Target exceeded
        if (target < 0) {
            return;
        }

        // Try every candidate
        for (int i = index; i < candidates.size(); i++) {

            // Choose
            current.push_back(candidates[i]);

            // Same number can be used again
            backtrack(i, candidates,
                      target - candidates[i],
                      current, result);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, candidates, target, current, result);

        return result;
    }
};

int main() {

    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result =
        obj.combinationSum(candidates, target);

    cout << "Combinations whose sum is " << target << ":\n";

    for (vector<int> combination : result) {

        cout << "[";

        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];

            if (i < combination.size() - 1)
                cout << ", ";
        }

        cout << "]\n";
    }

    return 0;
}