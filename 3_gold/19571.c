#include <stdio.h>

int arr[128][128];

int main(void) {
    int a = 1, x = 1, y = 1, n = 100, p = 0;
    while (a <= n * n) {
        arr[y][x] = a++;
        if (p == 0) {
            if (x < n - y - 2) {
                x++;
            }
            else if (x == n - y - 2) {
                if (y == 1) x += 2;
                else if (y == n - 3) y += 2;
                else x++;
            }
            else if (x == n - y - 1) {
                if (y == n - 3) x--;
                else if (y == n - 2) x++;
                else y++;
            }
            else if (x == n - y) {
                if (y == 1 || y == n - 3) x--;
                else if (y == n - 2) {
                    p = 1;
                    y += 2;
                }
                else if (y == n - 1) {
                    y--;
                }
                else x = 1;
            }
        }
        else if (p == 1) {
            if (x == n - y + 2) {
                if (y == 2) {
                    p = 2;
                    y--;
                }
                else x = n;
            }
            else if (x == n - y + 3) {
                y--;
            }
            else {
                x--;
            }
        }
        else if (p == 2) {
            x--;
            y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}