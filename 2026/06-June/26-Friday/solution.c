typedef struct {
    int *tree;
    int n;
} BIT;

void update(BIT *bit, int idx, int val) {
    while (idx <= bit->n) {
        bit->tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(BIT *bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit->tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int size = 2 * numsSize + 1;

    BIT bit;
    bit.n = size;
    bit.tree = (int *)calloc(size + 1, sizeof(int));

    int prefix = numsSize + 1;
    update(&bit, prefix, 1);

    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target)
            prefix++;
        else
            prefix--;

        ans += query(&bit, prefix - 1);
        update(&bit, prefix, 1);
    }

    free(bit.tree);
    return ans;
}
