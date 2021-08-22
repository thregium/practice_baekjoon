#include <stdio.h>

/*
문제 : R * C(R, C <= 200) 크기의 격자에 폭탄과 빈 칸들이 있다. 이때, N(N <= 200)초 후 격자의 모습을 구한다.
폭탄은 3초 후 터지고, 폭탄이 터지면 상하좌우 4칸의 폭탄들도 같이 터진다. 연쇄 작용은 일어나지 않는다.
2초마다 폭탄이 없는 칸의 폭탄을 보충한다.

해결 방법 : 문제에 주어진대로 구현한다. 배열을 2개 두면 더 간단히 풀 수 있다.

주요 알고리즘 : 구현, 시뮬레이션
*/

char bombs[256][256], bombs2[256][256];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };

int main(void) {
    int r, c, n;
    char ch;
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            bombs[i][j] = -1;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &ch);
            if (ch == 'O') bombs[i][j] = 3;
            else bombs[i][j] = -1;
        }
    }
    for (int tm = 0; tm < n; tm++) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                bombs[i][j]--;
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                bombs2[i][j] = 0;
                for (int d = 0; d < 5; d++) {
                    if (bombs[i + dxy[d][0]][j + dxy[d][1]] == 0) bombs2[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (bombs2[i][j]) bombs[i][j] = -1;
            }
        }
        if (tm & 1) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (bombs[i][j] < 0) bombs[i][j] = 3;
                }
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%c", bombs[i][j] < 0 ? '.' : 'O');
        }
        printf("\n");
    }
    return 0;
}