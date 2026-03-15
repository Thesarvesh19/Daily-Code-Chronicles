#include <vector>
using namespace std;

class Fancy {
    const long long MOD = 1000000007;
    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while(exp){
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long x){
        return modPow(x, MOD-2);
    }

public:
    Fancy(){}

    void append(int val){
        long long inv = modInv(mul);
        long long v = (val - add) % MOD;
        if(v < 0) v += MOD;
        v = (v * inv) % MOD;
        seq.push_back(v);
    }

    void addAll(int inc){
        add = (add + inc) % MOD;
    }

    void multAll(int m){
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx){
        if(idx >= seq.size()) return -1;
        long long val = seq[idx];
        return (val * mul + add) % MOD;
    }
};
