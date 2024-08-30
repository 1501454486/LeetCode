#include <vector>

using namespace std;

class Solution {
private:
    vector<int> helper;
public:
    int reversePairs(vector<int>& nums) {
        helper.resize(nums.size());
        return (numOfPair(nums, 0, nums.size() - 1));
    }

    // return the number of reversePair between l and rightEnd;
    int numOfPair(vector<int>& nums, int l, int rightEnd) {
        // base case
        if (l == rightEnd) {
            return 0;
        }
        int mid = l + ((rightEnd - l) >> 1);
        return (numOfPair(nums, l, mid) + numOfPair(nums, mid + 1, rightEnd) + merge(nums, l, mid, rightEnd));
    }

    // return the number of reversePair across left and right, then order
    int merge(vector<int>& nums, int l, int leftEnd, int rightEnd) {
        int r = leftEnd + 1;
        int length = rightEnd - l + 1;

        int i = l;
        int j = r;
        int sum = 0;
        int ans = 0;

        for (i = l; i <= leftEnd; i++) {
            while (j <= rightEnd && nums[i] > (long long) 2 * nums[j]) {
                j++;
                sum++;
            }
            ans += sum;
        }

        // mergeSort
        i = l;
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

        return ans;
    }
};