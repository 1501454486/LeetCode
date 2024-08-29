#include <vector>

using namespace std;

class Solution {
private:
    vector<int> helpArray;
public:
    vector<int> sortArray(vector<int>& nums) {
        helpArray.resize(nums.size());
        //mergeSort1(nums, 0, nums.size() - 1);
        mergeSort2(nums);
        return nums;
    }

    void mergeSort1(vector<int>& nums, int l, int rightEnd) {
        if (l == rightEnd) {
            // base case:
            return;
        }
        int mid = l + ((rightEnd - l) >> 1);
        mergeSort1(nums, l, mid);
        mergeSort1(nums, mid + 1, rightEnd);
        merge(nums, l, mid, rightEnd);
    }

    void mergeSort2(vector<int>& nums) {
        for (int l, m, r, step = 1; step < nums.size(); step <<= 1) {
            l = 0;
            while (l < nums.size()) {
                m = l + step - 1;
                if (m + 1 >= nums.size()) {
                    // if nothing on the right
                    break;
                }
                r = ((l + (step << 1) - 1) < nums.size() - 1) ? (l + (step << 1) - 1) : (nums.size() - 1);
                merge(nums, l, m, r);
                l = r + 1;
            }
        }
    }

    void merge(vector<int>& nums, int l, int leftEnd, int rightEnd) {
        int i = l;
        int r = leftEnd + 1;
        int length = rightEnd - l + 1;
        while (l <= leftEnd && r <= rightEnd) {
            if (nums[l] <= nums[r]) {
                helpArray[i++] = nums[l++];
            }
            else {
                helpArray[i++] = nums[r++];
            }
        }
        while (l <= leftEnd) {
            helpArray[i++] = nums[l++];
        }
        while (r <= rightEnd) {
            helpArray[i++] = nums[r++];
        }
        for (i = 0; i < length; i++, rightEnd--) {
            nums[rightEnd] = helpArray[rightEnd];
        }
    }
};