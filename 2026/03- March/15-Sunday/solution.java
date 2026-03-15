import java.util.*; 

class Fancy {

    private static final long MOD = 1_000_000_007;
    private List<Long> seq = new ArrayList<>();
    private long mul = 1;
    private long add = 0;

    public Fancy() {}

    public void append(int val) {
        long inv = modPow(mul, MOD-2);
        long v = (val - add) % MOD;
        if(v < 0) v += MOD;
        v = (v * inv) % MOD;
        seq.add(v);
    }

    public void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    public void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    public int getIndex(int idx) {
        if(idx >= seq.size()) return -1;
        long val = seq.get(idx);
        return (int)((val * mul + add) % MOD);
    }

    private long modPow(long base, long exp){
        long res = 1;
        base %= MOD;
        while(exp > 0){
            if((exp & 1) == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
}
