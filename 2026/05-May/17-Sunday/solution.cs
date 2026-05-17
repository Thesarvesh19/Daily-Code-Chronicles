public class Solution {
    public bool CanReach(int[] arr, int start) {

        if(start < 0 || start >= arr.Length || arr[start] < 0)
            return false;

        if(arr[start] == 0)
            return true;

        int jump = arr[start];
        arr[start] *= -1;

        return CanReach(arr, start + jump) ||
               CanReach(arr, start - jump);
    }
}
