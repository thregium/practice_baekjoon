#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 수평선상 (0, 0)에 두 개의 점이 있고, 각각의 길이 B(B <= 50000)인 이동 기록, 길이 E(E <= 50000)인 이동 기록이 주어진다.
이때, 두 점이 이동하며 만나게 되는 횟수를 구한다. 두 점은 같은 속도로 움직인다.

해결 방법 : 각 점의 이동을 시뮬레이션한다. 각 점의 좌표가 같아지는 순간의 개수를 세되, 직전 좌표도 같은 경우는 제외하고 센다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2012D B1번
*/

int bessie[51200], elsie[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("greetings.in", "r");
        fo = fopen("greetings.out", "w");
    }
    int b, e, t = 0, r = 0, bm = 0, em = 0, bp = 0, ep = 0, last = 1;
    char c;
    scanf("%d %d", &b, &e);
    for (int i = 0; i < b; i++) {
        scanf("%d %c", &bessie[i], &c);
        if (c == 'L') bessie[i] *= -1; //왼쪽 이동은 음수로 표현
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %c", &elsie[i], &c);
        if (c == 'L') elsie[i] *= -1; //왼쪽 이동은 음수로 표현
    }

    while (bm < b || em < e) {
        if (bessie[bm] == 0) bm++; //다음 이동으로 넘어감
        if (bm >= b); //이동이 끝난 경우
        else if (bessie[bm] < 0) {
            //왼쪽 이동
            bp--;
            bessie[bm]++;
        }
        else if (bessie[bm] > 0) {
            //오른쪽 이동
            bp++;
            bessie[bm]--;
        }
        else return 1;

        if (elsie[em] == 0) em++; //다음 이동으로 넘어감
        if (em >= e); //이동이 끝난 경우
        else if (elsie[em] < 0) {
            //왼쪽 이동
            ep--;
            elsie[em]++;
        }
        else if (elsie[em] > 0) {
            //오른쪽 이동
            ep++;
            elsie[em]--;
        }
        else return 1;

        t++;
        //printf("%d %d\n", bp, ep);
        if (bp == ep) {
            if (!last) r++;
            //printf("!%d\n", t);
            last = 1;
        }
        else last = 0;
    }
    printf("%d", r);
    return 0;
}