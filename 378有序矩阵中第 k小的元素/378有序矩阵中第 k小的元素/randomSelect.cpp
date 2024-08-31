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
    vector<int> arr;
    Random randomGenerator;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        arr.resize(matrix.size() * matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                arr[i * matrix.size() + j] = matrix[i][j];
            }
        }
        return randomSelect(0, arr.size() - 1, k-1);
    }

    int randomSelect(int l, int r, int position) {
        // base case:
        if (l >= r) {
            return arr[l];
        }
        int x = arr[randomGenerator.nextInt(l, r)];
        partition(l, r, x);
        int left = first;
        int right = last;
        if (left <= position && right >= position) {
            return x;
        }
        else if (left > position) {
            return randomSelect(l, left - 1, position);
        }
        else {
            return randomSelect(right + 1, r, position);
        }
    }

    void partition(int l, int r, int  x) {
        first = l;
        last = r;
        int i = l;
        while (i <= last) {
            if (arr[i] == x) {
                i++;
            }
            else if (arr[i] < x) {
                swap(arr[i++], arr[first++]);
            }
            else {
                swap(arr[i], arr[last--]);
            }
        }
    }
};