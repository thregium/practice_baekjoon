#include <stdio.h>
#include <string.h>

/*
문제 : 60 * 60 크기의 판에 문자들을 추가하는 명령어들이 주어진다. 명령어가 끝나면 전체 판의 상태를 출력한다.

해결 방법 : 문제의 내용들을 구현한다. 크기 5의 문자들은 하드코딩해 두는 것이 좋다.

주요 알고리즘 : 구현, 파싱, 비트마스킹, 전처리

출처 : SCUSA 1995 4번
*/

const int c5[] = { 289797198, 256177231, 503583838, 256185423, 520384607, 17068127, 239439966, 289797201,
521158943, 103055900, 287601233, 520360001, 289756881, 291853521, 239408206, 17101903, 509940814,
287634511, 255909982, 235947359, 239408209, 69772369, 292377681, 287851153, 68174481, 520634911 };
//큰 알파벳들은 하드코딩해둔다.
char op[8], csz[8], str[128], res[64][64], toprint[8][512];

int main(void) {
    int row = -1, col = -1, pr, pc;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) res[i][j] = '.';
    }
    while (1) {
        if (scanf("%s", op) == EOF) break;
        if (!strcmp(op, ".EOP")) {
            //판을 출력하고 초기화한다
            for (int i = 0; i < 60; i++) {
                printf("%s\n", res[i]);
            }
            printf("\n");
            for (int i = 0; i < 60; i++) printf("-");
            printf("\n\n");
            for (int i = 0; i < 60; i++) {
                for (int j = 0; j < 60; j++) res[i][j] = '.';
            }
            continue;
        }
        scanf("%s %d ", csz, &row);
        row--;
        if (!strcmp(op, ".P")) {
            //절대 위치
            scanf("%d ", &col);
            col--;
        }
        if (!strcmp(op, ".L")) col = 0; //왼쪽 정렬
        fgets(str, 100, stdin);
        if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

        memset(toprint, 0, sizeof(toprint));
        pr = csz[1] - '0', pc = 0;
        if (csz[1] == '1') {
            //크기 1의 문자인 경우
            for (int i = 1; str[i] != '|'; i++) {
                toprint[0][i - 1] = str[i];
                if (str[i] == ' ') toprint[0][i - 1] = '.';
            }
            pc = strlen(str) - 2;
        }
        else {
            //크기 5의 문자인 경우
            for (int i = 1; str[i] != '|'; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 6; k++) {
                        //비트마스킹을 통해 값들을 추가해 나간다.
                        if (str[i] == ' ') toprint[j][(i - 1) * 6 + k] = '.';
                        else toprint[j][(i - 1) * 6 + k] =
                            ((c5[str[i] - 'A'] >> (j * 6 + k)) & 1) ? '*' : '.';
                    }
                }
            }
            pc = (strlen(str) - 2) * 6;
        }

        if (!strcmp(op, ".R")) col = 60 - pc; //우측 정렬
        if (!strcmp(op, ".C")) col = 30 - (pc >> 1); //가운데 정렬

        for (int i = 0; i < pr; i++) {
            for (int j = 0; j < pc; j++) {
                //문자들을 실제로 추가한다. 공백 또는 문자가 없는 칸은 추가하지 않도록 한다.
                if (i + row >= 60 || j + col >= 60 || i + row < 0 || j + col < 0) continue;
                if (toprint[i][j] != '.') res[i + row][j + col] = toprint[i][j];
            }
        }
    }
    return 0;
}