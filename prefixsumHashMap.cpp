#include <unordered_map>
#include <vector>
using namespace std;

int solveWithPrefixSum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixMap;
    prefixMap[0] = 1;

    int prefixSum = 0, result = 0;

    for (int num : nums) {
        prefixSum += num;

        // Example condition: sum == k
        if (prefixMap.count(prefixSum - k)) {
            result += prefixMap[prefixSum - k];
        }

        prefixMap[prefixSum]++;
    }

    return result;
}
x