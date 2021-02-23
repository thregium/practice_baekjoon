#include <stdio.h>
#define INF 1234567890

int rol[1024][1024];

int main(void) {
    int r, c, mn = INF;
    int dont[2] = { 0, 0 };
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &rol[i][j]);
            if ((i + j) % 2 && rol[i][j] < mn) {
                mn = rol[i][j];
                dont[0] = i;
                dont[1] = j;
            }
        }
    }
    int x = 0, y = 0;
    if (r % 2) {
        while (x < r - 1 || y < c - 1) {
            if (x % 2) {
                if (y == 0) {
                    printf("D");
                    x++;
                }
                else {
                    printf("L");
                    y--;
                }
            }
            else {
                if (y == c - 1) {
                    printf("D");
                    x++;
                }
                else {
                    printf("R");
                    y++;
                }
            }
        }
    }
    else if (c % 2) {
        while (x < r - 1 || y < c - 1) {
            if (y % 2) {
                if (x == 0) {
                    printf("R");
                    y++;
                }
                else {
                    printf("U");
                    x--;
                }
            }
            else {
                if (x == r - 1) {
                    printf("R");
                    y++;
                }
                else {
                    printf("D");
                    x++;
                }
            }
        }
    }
    else {
        while (x < r - 1 || y < c - 1) {
            if (x / 2 < dont[0] / 2) {
                if (x % 2) {
                    if (y == 0) {
                        printf("D");
                        x++;
                    }
                    else {
                        printf("L");
                        y--;
                    }
                }
                else {
                    if (y == c - 1) {
                        printf("D");
                        x++;
                    }
                    else {
                        printf("R");
                        y++;
                    }
                }
            }
            else if (x / 2 == dont[0] / 2) {
                if (y < dont[1]) {
                    if (y % 2) {
                        if (x % 2) {
                            printf("U");
                            x--;
                        }
                        else {
                            printf("R");
                            y++;
                        }
                    }
                    else {
                        if (x % 2) {
                            printf("R");
                            y++;
                        }
                        else {
                            printf("D");
                            x++;
                        }
                    }
                }
                else if (y == dont[1]) {
                    if (dont[1] == c - 1) {
                        printf("D");
                        x++;
                    }
                    else {
                        printf("R");
                        y++;
                    }
                }
                else {
                    if (y % 2) {
                        if (x % 2 && (y != c - 1)) {
                            printf("R");
                            y++;
                        }
                        else {
                            printf("D");
                            x++;
                        }
                    }
                    else {
                        if (x % 2) {
                            printf("U");
                            x--;
                        }
                        else {
                            printf("R");
                            y++;
                        }
                    }
                }
            }
            else {
                if (x % 2) {
                    if (y == c - 1) {
                        printf("D");
                        x++;
                    }
                    else {
                        printf("R");
                        y++;
                    }
                }
                else {
                    if (y == 0) {
                        printf("D");
                        x++;
                    }
                    else {
                        printf("L");
                        y--;
                    }
                }
            }
        }
    }
    return 0;
}
