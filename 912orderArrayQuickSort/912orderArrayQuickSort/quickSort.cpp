#include <vector>
// random library
#include <random>

using namespace std;

static int first, last;

class Random {
private:
    mt19937 engine;
public:
    Random() : engine(random_device{}()) {}

    int nextInt(int l, int r) {
        // generate a random number between l and r;
        uniform_int_distribution<int> distribution(l, r);
        return distribution(engine);
    }
};

class Solution {
private:
    Random randomGenerator;
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        // base case:
        if (l >= r) {
            return;
        }
        
        // generate a random number between l and r;
        int x = nums[randomGenerator.nextInt(l, r)];
        partition(nums, l, r, x);
        // in case the bottom recursion rewrite first and last
        // use two local variable to store them
        int left = first;
        int right = last;
        quickSort(nums, l, left - 1);
        quickSort(nums, right + 1, r);
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
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};