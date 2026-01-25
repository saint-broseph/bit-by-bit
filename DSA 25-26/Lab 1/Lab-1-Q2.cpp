class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> index(n);

        for (int i = 0; i < n; i++)
            index[i] = i;

        mergeSort(nums, index, counts, 0, n - 1);
        return counts;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& index,
                   vector<int>& counts, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, index, counts, left, mid);
        mergeSort(nums, index, counts, mid + 1, right);
        merge(nums, index, counts, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& index,
               vector<int>& counts, int left, int mid, int right) {

        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[index[i]] <= nums[index[j]]) {
                temp[k++] = index[j++];
            } else {
                counts[index[i]] += (right - j + 1);
                temp[k++] = index[i++];
            }
        }

        while (i <= mid) temp[k++] = index[i++];
        while (j <= right) temp[k++] = index[j++];

        for (int p = 0; p < temp.size(); p++)
            index[left + p] = temp[p];
    }
};
