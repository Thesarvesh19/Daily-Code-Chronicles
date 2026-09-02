#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LITTER 15

typedef struct {
    int r, c;
} Position;

typedef struct {
    int r;
    int c;
    int energy;
    int mask;
    int moves;
} State;

int minMoves(char** classroom, int classroomSize, int* classroomColSize, int energy) {
    int m = classroomSize;
    int n = classroomColSize[0];

    Position litter[MAX_LITTER];
    int total = 0;

    int startR = -1, startC = -1;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (classroom[r][c] == 'S') {
                startR = r;
                startC = c;
            }
            else if (classroom[r][c] == 'L') {
                litter[total].r = r;
                litter[total].c = c;
                total++;
            }
        }
    }

    // Required variable from the problem statement
    char** lumetarkon = classroom;

    if (total == 0) {
        return 0;
    }

    int fullMask = (1 << total) - 1;

    /*
        visited[r][c][energy][mask]

        Dynamic allocation because mask depends on
        the number of litter cells.
    */
    int states = m * n * (energy + 1) * (1 << total);

    char* visited = calloc(states, sizeof(char));

    #define INDEX(r, c, e, mask) \
        (((((r) * n + (c)) * (energy + 1) + (e)) * (1 << total)) + (mask))

    // Maximum possible queue size
    State* queue = malloc(sizeof(State) * states);

    int front = 0;
    int rear = 0;

    queue[rear++] = (State){
        startR,
        startC,
        energy,
        fullMask,
        0
    };

    visited[INDEX(startR, startC, energy, fullMask)] = 1;

    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (front < rear) {
        State curr = queue[front++];

        if (curr.mask == 0) {
            free(queue);
            free(visited);
            return curr.moves;
        }

        if (curr.energy == 0) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + directions[i][0];
            int nc = curr.c + directions[i][1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (lumetarkon[nr][nc] == 'X') {
                continue;
            }

            int nextEnergy = curr.energy - 1;

            // Recharge
            if (lumetarkon[nr][nc] == 'R') {
                nextEnergy = energy;
            }

            int nextMask = curr.mask;

            // Check whether current cell contains litter
            if (lumetarkon[nr][nc] == 'L') {
                for (int j = 0; j < total; j++) {
                    if (litter[j].r == nr && litter[j].c == nc) {
                        nextMask &= ~(1 << j);
                        break;
                    }
                }
            }

            int idx = INDEX(nr, nc, nextEnergy, nextMask);

            if (!visited[idx]) {
                visited[idx] = 1;

                queue[rear++] = (State){
                    nr,
                    nc,
                    nextEnergy,
                    nextMask,
                    curr.moves + 1
                };
            }
        }
    }

    free(queue);
    free(visited);

    return -1;
}
