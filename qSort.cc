#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int Partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= pivot) {
            --right;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot) {
            ++left;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void qSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        int pivot = Partition(nums, left, right);
        qSort(nums, left, pivot - 1);
        qSort(nums, pivot + 1, right);
    }
}

int main() {
    vector<int> nums{7, 5, 3, 2, 10};
    qSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
