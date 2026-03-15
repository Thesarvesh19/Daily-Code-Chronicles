#include <stdlib.h>

#define MOD 1000000007
typedef long long ll;

typedef struct {
    ll *seq;
    int size;
    ll mul;
    ll add;
} Fancy;

ll modPow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

Fancy* fancyCreate() {
    Fancy* obj = malloc(sizeof(Fancy));
    obj->seq = malloc(sizeof(ll) * 100000);
    obj->size = 0;
    obj->mul = 1;
    obj->add = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    ll inv = modInv(obj->mul);
    ll x = (val - obj->add) % MOD;
    if (x < 0) x += MOD;
    x = (x * inv) % MOD;
    obj->seq[obj->size++] = x;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->add = (obj->add + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->mul = (obj->mul * m) % MOD;
    obj->add = (obj->add * m) % MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx >= obj->size) return -1;
    ll val = obj->seq[idx];
    return (val * obj->mul + obj->add) % MOD;
}

void fancyFree(Fancy* obj) {
    free(obj->seq);
    free(obj);
}
