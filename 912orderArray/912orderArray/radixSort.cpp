#include <vector>
#include <algorithm>

using namespace std;

static int BASE = 10;

class Solution {
private:
    vector<int> helper;
    vector<int> cnts;
public:
    vector<int> sortArray(vector<int>& nums) {
        // n是数组中元素个数
        int n = nums.size();
        helper.resize(n);

        int min = 0;
        // 找到nums中的最小数
        for (int i = 0; i < n; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }

        int max = 0;
        // 找到nums中的最大数，同时将其全变为非负数；
        for (int i = 0; i < n; i++) {
            nums[i] -= min;
            if (nums[i] > max) {
                max = nums[i];
            }
         }

        radixSort(nums, n, bits(max));

        // 最后还原；
        for (int i = 0; i < n; i++) {
            nums[i] += min;
        }
        return nums;
    }

    // return bits of the number
    int bits(int number) {
        int ans = 0;
        while (number > 0) {
            ans++;
            number /= BASE;
        }
        return ans;
    }

    void radixSort(vector<int>& nums, int n, int bits) {
        cnts.resize(BASE);
        for (int offset = 1; bits > 0; offset *= BASE, bits--) {
            fill(cnts.begin(), cnts.end(), 0);
            for (int i = 0; i < n; i++) {
                cnts[(nums[i] / offset) % BASE]++;
            }

            for (int i = 1; i < BASE; i++) {
                cnts[i] += cnts[i - 1];
            }

            for (int i = n - 1; i >= 0; i--) {
                helper[--cnts[(nums[i] / offset) % BASE]] = nums[i];
            }

            for (int i = 0; i < n; i++) {
                nums[i] = helper[i];
            }
        }
    }
};