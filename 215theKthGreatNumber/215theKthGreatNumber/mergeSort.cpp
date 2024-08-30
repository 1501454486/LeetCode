#include <vector>

using namespace std;

class Solution {
private:
    vector<int> helper;
public:
    int findKthLargest(vector<int>& nums, int k) {
        helper.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

    void mergeSort(vector<int>& nums, int l, int rightEnd) {
        // base case:
        if (l == rightEnd) {
            return;
        }
        int mid = l + ((rightEnd - l) >> 1);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, rightEnd);
        merge(nums, l, mid, rightEnd);
    }

    void merge(vector<int>& nums, int l, int leftEnd, int rightEnd) {
        int r = leftEnd + 1;
        int length = rightEnd - l + 1;
        int i = l;
        while (l <= leftEnd && r <= rightEnd) {
            if (nums[l] <= nums[r]) {
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
};