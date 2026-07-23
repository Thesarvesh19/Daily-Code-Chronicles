int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize <= 2)
        return numsSize;

    int bits = 0;
    int temp = numsSize;

    while (temp > 0) {
        bits++;
        temp >>= 1;
    }

    return 1 << bits;
}
