#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Random {
private:
    mt19937 engine;
public:
    Random() : engine(random_device{}()) {}

    int nextInt(int l, int r) {
        uniform_int_distribution<int> distribution(l, r);
        return distribution(engine);
    }
};

static int first, last;

class Solution {
private:
    Random randomGenerator;
    int target;
public:
    int findKthLargest(vector<int>& nums, int k) {
        target = nums.size() - k;
        return randomSelect(nums, 0, nums.size() - 1);
    }

    int randomSelect(vector<int>& nums, int l, int r) {
        // base case:
        if (l >= r) {
            return nums[l];
        }
        int x = nums[randomGenerator.nextInt(l, r)];
        partition(nums, l, r, x);
        int left = first;
        int right = last;
        if (target >= left && target <= right) {
            return x;
        }
        else if (target < left) {
            return randomSelect(nums, l, left - 1);
        }
        else {
            return randomSelect(nums, right + 1, r);
        }
    }

    void partition(vector<int>& nums, int l, int r, int x) {
        first = l;
        last = r;
        int i = l;
        while (i <= last) {
            if (nums[i] == x) {
                i++;
            }
            else if (nums[i] < x) {
                swap(nums[i++], nums[first++]);
            }
            else {
                swap(nums[i], nums[last--]);
            }
        }
    }
};