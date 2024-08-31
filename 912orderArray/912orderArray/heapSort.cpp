#include <vector>

using namespace std;

class Solution {
private:
    // the size of the heap;
    int size;

public:
    vector<int> sortArray(vector<int>& nums) {
        size = nums.size();
        heapSort(nums);
        return nums;
    }

    // 在位置i插入，向上调整大根堆
    void heapInsert(vector<int>& nums, int i) {
        while (nums[i] > nums[(i - 1) / 2]) {
            swap(nums, i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    // 在位置i插入，向下调整大根堆
    void heapify(vector<int>& nums, int i) {
        int l = i * 2 + 1;
        while (l < size) {
            int largest = l;
            // select the largest child;
            if (l + 1 < size && nums[l] < nums[l + 1]) {
                largest = l + 1;
            }
            if (nums[largest] <= nums[i]) {
                break;
            }
            swap(nums, largest, i);
            i = largest;
            l = i * 2 + 1;
        }
    }

    // swap nums[i] and nums[j]
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void buildHeap(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            heapify(nums, i);
        }
    }

    void heapSort(vector<int>& nums) {
        buildHeap(nums);
        while (size > 1) {
            swap(nums, 0, --size);
            heapify(nums, 0);
        }
    }
};