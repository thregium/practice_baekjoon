#include <stdio.h>

/*
문제 : 3개의 직사각형의 양쪽 변의 길이(<= 40)가 주어진다. 세 직사각형을 붙여 하나의 직사각형으로
만드는 방법이 반드시 있다고 할 때, 그 방법을 출력한다.

해결 방법 : 붙여서 하나의 직사각형을 만드는 방법은 크게 2가지이다. 두 경우를 모든 방향과 조합에 대해
시도해 보면서 가능한 경우를 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스, 케이스 워크, 구성적

출처 : IATI 2015 D2번
*/

char res[256][256];
int rect[3][2];

void printhor(int x) {
    for (int y = 0; y <= x * 2; y++) printf("%c", (~y & 1) ? '.' : ' ');
    printf("\n");
}

void printver1(int x, int y) {
    for (int i = 0; i < x; i++) {
        printf(".");
        for (int j = 1; j < y * 2; j++) printf(" ");
        printf(".\n");
    }
}

void printver2(int x, int y1, int y2) {
    for (int i = 0; i < x; i++) {
        printf(".");
        for (int j = 1; j < y1 * 2; j++) printf(" ");
        printf(".");
        for (int j = 1; j < y2 * 2; j++) printf(" ");
        printf(".\n");
    }
}

int main(void) {
    int r = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &rect[i][0], &rect[i][1]);
    }
    for (int i = 0; i < 8; i++) {
        if (rect[0][i & 1] + rect[1][(i >> 1) & 1] == rect[2][(i >> 2) & 1]) {
            if (rect[0][~i & 1] == rect[1][(~i >> 1) & 1]) {
                printhor(rect[2][(i >> 2) & 1]);
                printver1(rect[2][(~i >> 2) & 1] - 1, rect[2][(i >> 2) & 1]);
                printhor(rect[2][(i >> 2) & 1]);
                printver2(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1], rect[1][(i >> 1) & 1]);
                printhor(rect[2][(i >> 2) & 1]);
                return 0;
            }
        }

        if (rect[0][i & 1] + rect[2][(i >> 2) & 1] == rect[1][(i >> 1) & 1]) {
            if (rect[0][~i & 1] == rect[2][(~i >> 2) & 1]) {
                printhor(rect[1][(i >> 1) & 1]);
                printver1(rect[1][(~i >> 1) & 1] - 1, rect[1][(i >> 1) & 1]);
                printhor(rect[1][(i >> 1) & 1]);
                printver2(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1], rect[2][(i >> 2) & 1]);
                printhor(rect[1][(i >> 1) & 1]);
                return 0;
            }
        }

        if (rect[1][(i >> 1) & 1] + rect[2][(i >> 2) & 1] == rect[0][i & 1]) {
            if (rect[1][(~i >> 1) & 1] == rect[2][(~i >> 2) & 1]) {
                printhor(rect[0][(i >> 0) & 1]);
                printver1(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1]);
                printhor(rect[0][(i >> 0) & 1]);
                printver2(rect[1][(~i >> 1) & 1] - 1, rect[1][(i >> 1) & 1], rect[2][(i >> 2) & 1]);
                printhor(rect[0][(i >> 0) & 1]);
                return 0;
            }
        }

        if (rect[0][i & 1] == rect[1][(i >> 1) & 1] && rect[0][i & 1] == rect[2][(i >> 2) & 1]) {
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[1][(~i >> 1) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[2][(~i >> 2) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            return 0;
        }
    }
    return 1;
}