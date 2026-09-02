#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        map<pair<int, int>, int> litter;
        int startR = -1, startC = -1;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } 
                else if (classroom[r][c] == 'L') {
                    litter[{r, c}] = litter.size();
                }
            }
        }

        // Required variable from the problem statement
        vector<string> lumetarkon = classroom;

        int total = litter.size();

        if (total == 0) {
            return 0;
        }

        int fullMask = (1 << total) - 1;

        // {row, col, remainingEnergy, remainingLitterMask}
        queue<array<int, 5>> q;
        q.push({startR, startC, energy, fullMask, 0});

        set<tuple<int, int, int, int>> visited;
        visited.insert({startR, startC, energy, fullMask});

        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr[0];
            int c = curr[1];
            int currEnergy = curr[2];
            int mask = curr[3];
            int moves = curr[4];

            if (mask == 0) {
                return moves;
            }

            // Cannot move without energy
            if (currEnergy == 0) {
                continue;
            }

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                if (lumetarkon[nr][nc] == 'X') {
                    continue;
                }

                // Moving costs 1 energy
                int nextEnergy = currEnergy - 1;

                // Recharge to maximum energy
                if (lumetarkon[nr][nc] == 'R') {
                    nextEnergy = energy;
                }

                int nextMask = mask;

                // Collect litter
                if (lumetarkon[nr][nc] == 'L') {
                    int idx = litter[{nr, nc}];
                    nextMask &= ~(1 << idx);
                }

                auto state = make_tuple(nr, nc, nextEnergy, nextMask);

                if (!visited.count(state)) {
                    visited.insert(state);
                    q.push({nr, nc, nextEnergy, nextMask, moves + 1});
                }
            }
        }

        return -1;
    }
};
