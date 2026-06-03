#include <stdlib.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    ll start;
    ll dur;
} Ride;

int cmp(const void* a, const void* b) {
    Ride* x = (Ride*)a;
    Ride* y = (Ride*)b;

    if (x->start < y->start) return -1;
    if (x->start > y->start) return 1;
    return 0;
}

int lowerBound(ll* arr, int n, ll target) {
    int l = 0, r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

ll solve(int* s1, int s1Size,
         int* d1,
         int* s2, int s2Size,
         int* d2) {

    int m = s2Size;

    Ride* rides = (Ride*)malloc(sizeof(Ride) * m);

    for (int i = 0; i < m; i++) {
        rides[i].start = s2[i];
        rides[i].dur = d2[i];
    }

    qsort(rides, m, sizeof(Ride), cmp);

    ll* start = (ll*)malloc(sizeof(ll) * m);
    ll* prefDur = (ll*)malloc(sizeof(ll) * m);
    ll* sufFinish = (ll*)malloc(sizeof(ll) * m);

    for (int i = 0; i < m; i++)
        start[i] = rides[i].start;

    prefDur[0] = rides[0].dur;

    for (int i = 1; i < m; i++)
        prefDur[i] = prefDur[i - 1] < rides[i].dur
                     ? prefDur[i - 1]
                     : rides[i].dur;

    sufFinish[m - 1] =
        rides[m - 1].start + rides[m - 1].dur;

    for (int i = m - 2; i >= 0; i--) {

        ll cur = rides[i].start + rides[i].dur;

        sufFinish[i] =
            sufFinish[i + 1] < cur
            ? sufFinish[i + 1]
            : cur;
    }

    ll ans = LLONG_MAX;

    for (int i = 0; i < s1Size; i++) {

        ll finish1 = (ll)s1[i] + d1[i];

        int pos = lowerBound(start, m, finish1);

        if (pos > 0) {
            ll candidate = finish1 + prefDur[pos - 1];
            if (candidate < ans)
                ans = candidate;
        }

        if (pos < m) {
            if (sufFinish[pos] < ans)
                ans = sufFinish[pos];
        }
    }

    free(rides);
    free(start);
    free(prefDur);
    free(sufFinish);

    return ans;
}

long long earliestFinishTime(int* landStartTime,
                             int landStartTimeSize,
                             int* landDuration,
                             int landDurationSize,
                             int* waterStartTime,
                             int waterStartTimeSize,
                             int* waterDuration,
                             int waterDurationSize) {

    ll ans1 = solve(
        landStartTime,
        landStartTimeSize,
        landDuration,
        waterStartTime,
        waterStartTimeSize,
        waterDuration
    );

    ll ans2 = solve(
        waterStartTime,
        waterStartTimeSize,
        waterDuration,
        landStartTime,
        landStartTimeSize,
        landDuration
    );

    return ans1 < ans2 ? ans1 : ans2;
}
