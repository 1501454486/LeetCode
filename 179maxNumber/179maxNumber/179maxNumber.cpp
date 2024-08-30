#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> helper;
public:
    string largestNumber(vector<int>& nums) {
        helper.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return arrayToString(nums);
    }

    void mergeSort(vector<int>& nums, int l, int rightEnd) {
        // base case
        if (l == rightEnd) {
            return;
        }
        // mid = (rightEnd + l) / 2
        int mid = l + ((rightEnd - l) >> 1);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, rightEnd);
        merge(nums, l, mid, rightEnd);
    }

    void merge(vector<int>& nums, int l, int leftEnd, int rightEnd) {
        int length = rightEnd - l + 1;
        int r = leftEnd + 1;
        int i = l;
        while (l <= leftEnd && r <= rightEnd) {
            if (nums[l] >= nums[r]) {
                helper[i++] = nums[l++];
            }
            else {
                helper[i++] = nums[r++];
            }
        }
        while (l <= leftEnd) {
            helper[i++] = nums[l++];
        }
        while (r <= rightEnd) {
            helper[i++] = nums[r++];
        }

        for (i = 0; i < length; i++, rightEnd--) {
            nums[rightEnd] = helper[rightEnd];
        }
    }

    string arrayToString(const vector<int>& nums) {
        string result;
        for (int num : nums) {
            result += to_string(num);
        }
        return result;
    }
};