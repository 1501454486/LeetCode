#include <vector>

const int MAXN = 50000;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) :val(x), next(next) {}
};
class Solution {
private:
    // create two arrays
    std::vector<int> arr;
    std::vector<int> helper;
public:
    ListNode* sortList(ListNode* head) {
        arr.resize(MAXN);
        helper.resize(MAXN);
        ListNode* ptr = head;
        int length = 0;
        // copy the value of the list to array;
        while (ptr) {
            arr[length++] = ptr->val;
            ptr = ptr->next;
        }
        // if length > 0
        if (length) {
            mergeSort1(0, length - 1);
        }

        ptr = head;
        for (int i = 0; i < length; i++) {
            ptr->val = arr[i];
            ptr = ptr->next;
        }

        return head;
    }

    void mergeSort1(int l, int rightEnd) {
        // base case
        if (l == rightEnd) {
            return;
        }
        int mid = l + ((rightEnd - l) >> 1);
        mergeSort1(l, mid);
        mergeSort1(mid + 1, rightEnd);
        merge(l, mid, rightEnd);
    }
    
    void merge(int l, int leftEnd, int rightEnd) {
        int i = l;
        int length = rightEnd - l + 1;
        int r = leftEnd + 1;
        while (l <= leftEnd && r <= rightEnd) {
            if (arr[l] <= arr[r]) {
                helper[i++] = arr[l++];
            }
            else {
                helper[i++] = arr[r++];
            }
        }
        while (l <= leftEnd) {
            helper[i++] = arr[l++];
        }
        while (r <= rightEnd) {
            helper[i++] = arr[r++];
        }

        for (i = 0; i < length; i++, rightEnd--) {
            arr[rightEnd] = helper[rightEnd];
        }
    }
};