#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 L * L(L <= 400) 크기의 정사각형 범위의 값(<= 255)들이 주어질 때,
두 번째 정사각형을 뒤집거나 회전시켜 비슷한 값(차이가 100 이하)의 비율을 최대로 하는 경우의
그 비율을 출력한다.

해결 방법 : 정사각형 범위들을 뒤집거나 회전시키는 모든 경우를 직접 비교해 가며
비슷한 값이 가장 많을 때의 비슷한 값 개수를 구하고 그를 통해 비율을 계산하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : SARC 2002 G번
*/

int img[512][512], scanned[512][512], tmpimg[512][512];

int big(int a, int b) {
    return a > b ? a : b;
}

int imgcmp(int l) {
    int c = 0, x;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (abs(scanned[i][j] - img[i][j]) <= 100) c++;
        }
    }
    return c;
}

void rotimg(int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) tmpimg[i][j] = scanned[l - j - 1][i];
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) scanned[i][j] = tmpimg[i][j];
    }
}

void flipimg(int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) tmpimg[i][j] = scanned[i][l - j - 1];
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) scanned[i][j] = tmpimg[i][j];
    }
}

int main(void) {
    int l, x, r;
    while (1) {
        scanf("%d", &l);
        if (l == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%d", &img[i][j]);
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%d", &scanned[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < 8; i++) {
            r = big(r, imgcmp(l));
            if (i & 1) rotimg(l);
            flipimg(l);
        }
        printf("%.2f\n", (double)r / (l * l) * 100.0 + 1E-9);
    }
    return 0;
}