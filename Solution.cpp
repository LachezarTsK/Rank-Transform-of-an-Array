
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    
public:               //C++20: ...(span<const int> input) ...  
    vector<int> arrayRankTransform(const vector<int>& input) const {
        if (input.empty()) {
            return vector<int>();
        }
        vector<int> clonedInput(input.begin(), input.end());
        //C++20: std::ranges::sort(clonedInput);
        sort(clonedInput.begin(), clonedInput.end());

        int rank = 0;
        unordered_map<int, int> valueToRank;
        for (const auto& num : clonedInput) {
            //C++20: ...(!valueToRank.contains(num))...
            if (valueToRank.find(num) == valueToRank.end()) {
                valueToRank[num] = ++rank;
            }
        }

        vector<int> ranks(input.size());
        for (int i = 0; i < input.size(); ++i) {
            ranks[i] = valueToRank[input[i]];
        }

        return ranks;
    }
};
