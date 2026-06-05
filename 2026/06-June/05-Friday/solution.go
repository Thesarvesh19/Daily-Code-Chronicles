package main

import (
	"strconv"
)

type State struct {
	pos   int
	prev  int
	prev2 int
	lead  bool
}

type Pair struct {
	cnt int64
	wav int64
}

func solve(x int64) int64 {
	if x <= 0 {
		return 0
	}

	s := strconv.FormatInt(x, 10)
	memo := make(map[State]Pair)

	var dfs func(int, int, int, bool, bool) Pair

	dfs = func(pos, prev, prev2 int, lead, tight bool) Pair {
		if pos == len(s) {
			return Pair{1, 0}
		}

		key := State{pos, prev, prev2, lead}

		if !tight {
			if val, ok := memo[key]; ok {
				return val
			}
		}

		limit := 9
		if tight {
			limit = int(s[pos] - '0')
		}

		var cnt int64
		var wav int64

		for d := 0; d <= limit; d++ {
			ntight := tight && d == limit
			nlead := lead && d == 0

			nprev := d
			if nlead {
				nprev = -1
			}

			res := dfs(
				pos+1,
				nprev,
				prev,
				nlead,
				ntight,
			)

			cnt += res.cnt

			if !lead &&
				prev2 != -1 &&
				((prev2 < prev && prev > d) ||
					(prev2 > prev && prev < d)) {
				wav += res.cnt
			}

			wav += res.wav
		}

		ans := Pair{cnt, wav}

		if !tight {
			memo[key] = ans
		}

		return ans
	}

	return dfs(0, -1, -1, true, true).wav
}

type Solution struct{}

func (Solution) totalWaviness(num1 int64, num2 int64) int64 {
	return solve(num2) - solve(num1-1)
}
