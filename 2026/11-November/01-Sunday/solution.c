
int minMoves(int* nums, int numsSize) {
    int minVal = nums[0];
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        sum += nums[i];
    }

    return sum - (numsSize * minVal);
}
