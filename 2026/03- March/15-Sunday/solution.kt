class Fancy {

    private val MOD = 1_000_000_007L
    private val seq = ArrayList<Long>()
    private var mul = 1L
    private var add = 0L

    fun append(value: Int) {
        val inv = modPow(mul, MOD-2) 
        var v = (value - add) % MOD
        if (v < 0) v += MOD
        v = (v * inv) % MOD
        seq.add(v)
    }

    fun addAll(inc: Int) {
        add = (add + inc) % MOD
    }

    fun multAll(m: Int) {
        mul = (mul * m) % MOD
        add = (add * m) % MOD
    }

    fun getIndex(idx: Int): Int {
        if (idx >= seq.size) return -1
        val v = seq[idx]
        return ((v * mul + add) % MOD).toInt()
    }

    private fun modPow(base: Long, exp: Long): Long {
        var b = base % MOD
        var e = exp
        var res = 1L
        while (e > 0) {
            if (e and 1L == 1L) res = (res * b) % MOD
            b = (b * b) % MOD
            e = e shr 1
        }
        return res
    }
}
