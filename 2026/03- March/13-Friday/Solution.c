#include <math.h>
#include <stdbool.h>

bool canFinish(long long time, int mountainHeight, int* workerTimes, int workers) {
    long long total = 0;

    for (int i = 0; i < workers; i++) {
        long long w = workerTimes[i];
 
        long long val = (2 * time) / w;
        long long x = (long long)((sqrt(1.0 + 4.0 * val) - 1) / 2);

        total += x;

        if (total >= mountainHeight)
            return true;
    }

    return false;
}

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    
    long long left = 0;
    long long right = (long long)workerTimes[0] * mountainHeight * (mountainHeight + 1) / 2;

    for (int i = 1; i < workerTimesSize; i++) {
        long long candidate = (long long)workerTimes[i] * mountainHeight * (mountainHeight + 1) / 2;
        if (candidate < right)
            right = candidate;
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canFinish(mid, mountainHeight, workerTimes, workerTimesSize))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
