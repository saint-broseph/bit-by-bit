// You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.


public class searchinsertposition {

    // Function to find the insert position of x in sorted array
    public int searchInsert(int[] arr, int x) {
        int n = arr.length;
        int low = 0, high = n - 1;
        int ans = n; // Default to end if x is greater than all elements

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] >= x) {
                // Potential answer found, try to go left
                ans = mid;
                high = mid - 1;
            } else {
                // Go right
                low = mid + 1;
            }
        }

        return ans;
    }
}
