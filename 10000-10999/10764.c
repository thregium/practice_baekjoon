#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * M(N, M <= 50) 크기의 퍼즐이 있다. 이 퍼즐에서 각 문자들을 다른 문자들로 치환하고 "MOO"라는 문자열을
수평, 수직, 대각선으로 가능한 많이 찾으려고 할 때 찾을 수 있는 최대 개수를 구한다. 단, 여러 문자가
한 가지 문자로 치환되거나 문자가 치환되지 않는 경우는 불가능하다.

해결 방법 : 'M'과 'O'에 대응되는 글자들을 각각 확인해가며 퍼즐에서 찾을 수 있는 문자열의 개수를 구한다.
"MOO" 문자열의 개수는 방향 배열을 통해 간단히 구할 수 있다. 이 값들 중 가장 큰 것을 고르면 된다.
'M'에 대응되는 글자와 'O'에 대응되는 글자가 겹치거나 각각 'M', 'O'면 안 된다는 점에 유의한다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2015O B1번
*/

char puz[64][64];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("moocrypt.in", "r");
        fo = fopen("moocrypt.out", "w");
    }
    int n, m, r = 0, tr;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n + 1; i++) {
        scanf("%s", puz[i] + 2);
    }
    for (char cm = 'A'; cm <= 'Z'; cm++) {
        if (cm == 'M') continue;
        for (char co = 'A'; co <= 'Z'; co++) {
            if (cm == co || co == 'O') continue;
            tr = 0;
            for (int i = 2; i <= n + 1; i++) {
                for (int j = 2; j <= m + 1; j++) {
                    for (int d = 0; d < 8; d++) {
                        if (puz[i][j] == cm && puz[i + dxy[d][0]][j + dxy[d][1]] == co
                            && puz[i + dxy[d][0] * 2][j + dxy[d][1] * 2] == co) tr++;
                    }
                }
            }
            if (tr > r) r = tr;
        }
    }
    printf("%d", r);
    return 0;
}