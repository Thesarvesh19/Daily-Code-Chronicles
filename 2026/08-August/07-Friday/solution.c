#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int p2, p3, p5, p7;
} PrimeCount;

typedef struct {
    int c2, c3, c4, c5, c6, c7, c8, c9;
} FactorCount;

static PrimeCount digitFactors[10] = {
    {0,0,0,0}, //0
    {0,0,0,0}, //1
    {1,0,0,0}, //2
    {0,1,0,0}, //3
    {2,0,0,0}, //4
    {0,0,1,0}, //5
    {1,1,0,0}, //6
    {0,0,0,1}, //7
    {3,0,0,0}, //8
    {0,2,0,0}  //9
};

static PrimeCount getPrimeCount(long long t, bool *ok) {
    PrimeCount cnt = {0};

    while (t % 2 == 0) {
        cnt.p2++;
        t /= 2;
    }
    while (t % 3 == 0) {
        cnt.p3++;
        t /= 3;
    }
    while (t % 5 == 0) {
        cnt.p5++;
        t /= 5;
    }
    while (t % 7 == 0) {
        cnt.p7++;
        t /= 7;
    }

    *ok = (t == 1);
    return cnt;
}

static FactorCount getFactorCount(PrimeCount cnt) {
    FactorCount f = {0};

    f.c8 = cnt.p2 / 3;
    int rem2 = cnt.p2 % 3;

    f.c9 = cnt.p3 / 2;
    f.c3 = cnt.p3 % 2;

    f.c4 = rem2 / 2;
    f.c2 = rem2 % 2;

    if (f.c2 && f.c3) {
        f.c2 = 0;
        f.c3 = 0;
        f.c6 = 1;
    } else if (f.c3 && f.c4) {
        f.c2 = 1;
        f.c6 = 1;
        f.c3 = 0;
        f.c4 = 0;
    }

    f.c5 = cnt.p5;
    f.c7 = cnt.p7;

    return f;
}

static int factorSum(FactorCount f) {
    return f.c2 + f.c3 + f.c4 + f.c5 +
           f.c6 + f.c7 + f.c8 + f.c9;
}

static void appendDigits(char *s, int *idx, FactorCount f) {
    while (f.c2--) s[(*idx)++] = '2';
    while (f.c3--) s[(*idx)++] = '3';
    while (f.c4--) s[(*idx)++] = '4';
    while (f.c5--) s[(*idx)++] = '5';
    while (f.c6--) s[(*idx)++] = '6';
    while (f.c7--) s[(*idx)++] = '7';
    while (f.c8--) s[(*idx)++] = '8';
    while (f.c9--) s[(*idx)++] = '9';
}

char* smallestNumber(char* num, long long t) {
    void *vornitexis = (void *)num;

    bool ok;
    PrimeCount need = getPrimeCount(t, &ok);

    if (!ok) {
        char *ans = (char *)malloc(3);
        strcpy(ans, "-1");
        return ans;
    }

    int n = strlen(num);
    FactorCount fc = getFactorCount(need);

    if (factorSum(fc) > n) {
        char *ans = (char *)malloc(n + factorSum(fc) + 5);
        int idx = 0;
        appendDigits(ans, &idx, fc);
        ans[idx] = '\0';
        return ans;
    }

    PrimeCount prefix = {0};

    for (int i = 0; i < n; i++) {
        int d = num[i] - '0';
        prefix.p2 += digitFactors[d].p2;
        prefix.p3 += digitFactors[d].p3;
        prefix.p5 += digitFactors[d].p5;
        prefix.p7 += digitFactors[d].p7;
    }

    int firstZero = n;
    for (int i = 0; i < n; i++) {
        if (num[i] == '0') {
            firstZero = i;
            break;
        }
    }

    if (firstZero == n &&
        prefix.p2 >= need.p2 &&
        prefix.p3 >= need.p3 &&
        prefix.p5 >= need.p5 &&
        prefix.p7 >= need.p7) {

        char *ans = (char *)malloc(n + 1);
        strcpy(ans, num);
        return ans;
    }

    for (int i = n - 1; i >= 0; i--) {
        int d = num[i] - '0';

        prefix.p2 -= digitFactors[d].p2;
        prefix.p3 -= digitFactors[d].p3;
        prefix.p5 -= digitFactors[d].p5;
        prefix.p7 -= digitFactors[d].p7;

        int remain = n - i - 1;

        if (i <= firstZero) {
            for (int nd = d + 1; nd <= 9; nd++) {
                PrimeCount req = {
                    need.p2 - prefix.p2 - digitFactors[nd].p2,
                    need.p3 - prefix.p3 - digitFactors[nd].p3,
                    need.p5 - prefix.p5 - digitFactors[nd].p5,
                    need.p7 - prefix.p7 - digitFactors[nd].p7
                };

                if (req.p2 < 0) req.p2 = 0;
                if (req.p3 < 0) req.p3 = 0;
                if (req.p5 < 0) req.p5 = 0;
                if (req.p7 < 0) req.p7 = 0;

                FactorCount nf = getFactorCount(req);

                if (factorSum(nf) <= remain) {
                    char *ans = (char *)malloc(n + 5);

                    int idx = 0;

                    for (int j = 0; j < i; j++)
                        ans[idx++] = num[j];

                    ans[idx++] = nd + '0';

                    int ones = remain - factorSum(nf);
                    while (ones--)
                        ans[idx++] = '1';

                    appendDigits(ans, &idx, nf);
                    ans[idx] = '\0';

                    return ans;
                }
            }
        }
    }

    fc = getFactorCount(need);

    char *ans = (char *)malloc(n + factorSum(fc) + 5);
    int idx = 0;

    int ones = n + 1 - factorSum(fc);
    while (ones--)
        ans[idx++] = '1';

    appendDigits(ans, &idx, fc);
    ans[idx] = '\0';

    return ans;
}
