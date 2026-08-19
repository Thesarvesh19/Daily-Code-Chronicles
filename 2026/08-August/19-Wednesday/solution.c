#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int row;
    int mask;
} Row;

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize,
                        int* reservedSeatsColSize) {

    Row* rows = (Row*)calloc(reservedSeatsSize, sizeof(Row));
    int rowCount = 0;

    for (int i = 0; i < reservedSeatsSize; i++) {
        int r = reservedSeats[i][0];
        int c = reservedSeats[i][1];

        int index = -1;

        for (int j = 0; j < rowCount; j++) {
            if (rows[j].row == r) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            index = rowCount++;
            rows[index].row = r;
            rows[index].mask = 0;
        }

        rows[index].mask |= (1 << c);
    }

    int ans = (n - rowCount) * 2;

    for (int i = 0; i < rowCount; i++) {
        int mask = rows[i].mask;

        bool left =
            !(mask & (1 << 2)) &&
            !(mask & (1 << 3)) &&
            !(mask & (1 << 4)) &&
            !(mask & (1 << 5));

        bool middle =
            !(mask & (1 << 4)) &&
            !(mask & (1 << 5)) &&
            !(mask & (1 << 6)) &&
            !(mask & (1 << 7));

        bool right =
            !(mask & (1 << 6)) &&
            !(mask & (1 << 7)) &&
            !(mask & (1 << 8)) &&
            !(mask & (1 << 9));

        if (left && right)
            ans += 2;
        else if (left || middle || right)
            ans += 1;
    }

    free(rows);
    return ans;
}
