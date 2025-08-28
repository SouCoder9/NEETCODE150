#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size(), 1); // Initialize with 1s
        int pre = 1, post = 1;

        // Forward pass: calculate prefix products
        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = result[i] * pre;
            pre = pre * nums[i];
        }

        // Backward pass: multiply with postfix products
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = result[i] * post;
            post = post * nums[i];
        }

        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    Solution solution;
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test Case 1:\n";
    cout << "Input:  ";
    printVector(nums1);
    cout << "\nOutput: ";
    vector<int> result1 = solution.productExceptSelf(nums1);
    printVector(result1);
    cout << "\nExpected: [24, 12, 8, 6]\n\n";

    // Test Case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Test Case 2:\n";
    cout << "Input:  ";
    printVector(nums2);
    cout << "\nOutput: ";
    vector<int> result2 = solution.productExceptSelf(nums2);
    printVector(result2);
    cout << "\nExpected: [0, 0, 9, 0, 0]\n\n";

    // Test Case 3
    vector<int> nums3 = {2, 3, 4, 5};
    cout << "Test Case 3:\n";
    cout << "Input:  ";
    printVector(nums3);
    cout << "\nOutput: ";
    vector<int> result3 = solution.productExceptSelf(nums3);
    printVector(result3);
    cout << "\nExpected: [60, 40, 30, 24]\n\n";
    return 0;
}