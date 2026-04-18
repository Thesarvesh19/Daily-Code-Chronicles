// 3783. Mirror Distance of an Integer

#include <stdlib.h>

int mirrorDistance(int n) {
    int temp = n, rev = 0;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return abs(n - rev);
}
