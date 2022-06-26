#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 H * W(H, W <= 75) 크기의 판 안에 주어진 명령어를 실행한대로 내용물을 출력한다.
각 명령어에서 좌표 범위는 모두 판 안에 들어가지만 시작점과 끝점의 상대적인 위치는 바뀔 수 있다.

해결 방법 : 점은 그대로 출력, 텍스트는 범위를 넘지 않도록만 하면서 출력, 삭제는 시작과 끝점을 조정
(순서가 바뀐 경우를 방지)한 다음 출력하고, 선의 경우 방향에 따라 경우를 나누어 출력하면 된다.

주요 알고리즘 : 구현

출처 : CTU 2004 J번
*/

char s[16], txt[1024];
char plot[96][96];

int swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int h, w, x1, y1, x2, y2;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) plot[i][j] = ' ';
        }
        while (1) {
            scanf("%s", s);
            if (!strcmp(s, "PRINT")) break;
            if (!strcmp(s, "POINT")) {
                scanf("%d %d", &y1, &x1);
                if (plot[x1][y1] == ' ' || plot[x1][y1] == 'o') plot[x1][y1] = 'o';
                else plot[x1][y1] = '*';
            }
            else if (!strcmp(s, "TEXT")) {
                scanf("%d %d %s", &y1, &x1, txt);
                for (int i = 0; y1 + i <= w && txt[i]; i++) {
                    if (plot[x1][y1 + i] == ' ' || plot[x1][y1 + i] == txt[i]) plot[x1][y1 + i] = txt[i];
                    else plot[x1][y1 + i] = '*';
                }
            }
            else if (!strcmp(s, "LINE")) {
                scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
                if (x1 > x2 || (x1 == x2 && y1 > y2)) {
                    swap(&x1, &x2);
                    swap(&y1, &y2);
                }
                if (x1 < x2) {
                    for (int i = x1; i <= x2; i++) {
                        if (y1 < y2) {
                            if (plot[i][y1 + i - x1] == ' ' || plot[i][y1 + i - x1] == '\\') {
                                plot[i][y1 + i - x1] = '\\';
                            }
                            else if (plot[i][y1 + i - x1] == 'x' || plot[i][y1 + i - x1] == '/') {
                                plot[i][y1 + i - x1] = 'x';
                            }
                            else plot[i][y1 + i - x1] = '*';
                        }
                        else if (y1 == y2) {
                            if (plot[i][y1] == ' ' || plot[i][y1] == '|') plot[i][y1] = '|';
                            else if (plot[i][y1] == '+' || plot[i][y1] == '-') plot[i][y1] = '+';
                            else plot[i][y1] = '*';
                        }
                        else {
                            if (plot[i][y1 - i + x1] == ' ' || plot[i][y1 - i + x1] == '/') {
                                plot[i][y1 - i + x1] = '/';
                            }
                            else if (plot[i][y1 - i + x1] == 'x' || plot[i][y1 - i + x1] == '\\') {
                                plot[i][y1 - i + x1] = 'x';
                            }
                            else plot[i][y1 - i + x1] = '*';
                        }
                    }
                }
                else {
                    for (int i = y1; i <= y2; i++) {
                        if (plot[x1][i] == ' ' || plot[x1][i] == '-') plot[x1][i] = '-';
                        else if (plot[x1][i] == '+' || plot[x1][i] == '|') plot[x1][i] = '+';
                        else plot[x1][i] = '*';
                    }
                }
            }
            else if (!strcmp(s, "CLEAR")) {
                scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
                if (x1 > x2) swap(&x1, &x2);
                if (y1 > y2) swap(&y1, &y2);
                for (int i = x1; i <= x2; i++) {
                    for (int j = y1; j <= y2; j++) {
                        plot[i][j] = ' ';
                    }
                }
            }
            else return 1;
        }

        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if ((i == 0 || i == h + 1) && (j == 0 || j == w + 1)) printf("+");
                else if (j == 0 || j == w + 1) printf("|");
                else if (i == 0 || i == h + 1) printf("-");
                else printf("%c", plot[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}