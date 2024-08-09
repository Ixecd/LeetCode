#include <bits/stdc++.h>
using namespace std;

// 下面是快排
int partition(vector<int> &ary, int low, int high) {
    int pivot = ary[low];
    while (low < high) {
        while (low < high && ary[high] >= pivot) {
            --high;
        }
        ary[low] = ary[high];
        while (low < high && ary[low <= pivot]) {
            ++low;
        }
        ary[high] = ary[low];
    }
    ary[low] = pivot;
    return low;
}

void qsort(vector<int> &ary, int low, int high) {
    if (low < high) {
        int pivot = partition(ary, low, high);
        qsort(ary, low, pivot - 1);
        qsort(ary, pivot + 1, high);
    }
}

int charge(vector<int> &coins, int target) {
    // 先对coins排序
    qsort(coins, 0, coins.size() - 1);
    int i = coins.size() - 1;
    int count = 0;
    while (target > 0) {
        while (i > 0 && coins[i] > target) {
            --i;
        }
        target -= coins[i];
        count++;
    }
    return target == 0 ? count : -1;
}

int getMaxCap(vector<int> const &ht) {
    int left = 0, right = ht.size() - 1;
    int cap = 0;
    while (left < right) {
        cap = max(cap, (right - left) * min(ht[left], ht[right]));
        if (ht[left] > ht[right]) {
            right--;
        } else {
            ++left;
        }
    }
    return cap;
}

int main() {
    // vector<int> coins{5,1,2};
    // std::cout << charge(coins, 11);

    vector<int> ht{3, 8, 5, 2, 7, 7, 3, 4};
    std::cout << getMaxCap(ht);

    return 0;
}
