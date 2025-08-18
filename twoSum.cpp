#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int, int> TwoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (map.find(complement) != map.end())
        {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {-1, -1};
}
int main()
{
    // Test cases
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> nums3 = {3, 3};
    int target3 = 6;

    cout << "Two Sum Solution:\n";

    // Test case 1
    pair<int, int> result1 = TwoSum(nums1, target1);
    cout << "Array: [2, 7, 11, 15], Target: 9\n";
    cout << "Indices: [" << result1.first << ", " << result1.second << "]\n";
    cout << "Values: [" << nums1[result1.first] << ", " << nums1[result1.second] << "]\n\n";

    // Test case 2
    pair<int, int> result2 = TwoSum(nums2, target2);
    cout << "Array: [3, 2, 4], Target: 6\n";
    cout << "Indices: [" << result2.first << ", " << result2.second << "]\n";
    cout << "Values: [" << nums2[result2.first] << ", " << nums2[result2.second] << "]\n\n";

    // Test case 3
    pair<int, int> result3 = TwoSum(nums3, target3);
    cout << "Array: [3, 3], Target: 6\n";
    cout << "Indices: [" << result3.first << ", " << result3.second << "]\n";
    cout << "Values: [" << nums3[result3.first] << ", " << nums3[result3.second] << "]\n\n";

    return 0;
}