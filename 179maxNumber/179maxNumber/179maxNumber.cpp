#include <vector>
#include <string>
#include <iostream>

using namespace std;

class comparor {
public:
    // if a is prior to b, return -1;
    // else if a is inferior to b, return 1;
    // else return 0
    int compare(int a, int b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        if (s1 > s2) {
            return -1;
        }
        else if(s1 < s2) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int compare(string a, string b) {
        string s1 = a + b;
        string s2 = b + a;
        if (s1 > s2) {
            return -1;
        }
        else if (s1 < s2) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

class Solution {
private:
    vector<int> helper;
    comparor numComparor;
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
            // if left number is prior
            if (numComparor.compare(nums[l], nums[r]) <= 0) {
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
        if (numComparor.compare(result, "0") == 0) {
            // if result == 0
            result = "0";
        }
        return result;
    }
};