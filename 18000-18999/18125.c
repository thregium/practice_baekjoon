#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 배열과 C * R 크기의 배열이 주어질 때, 첫 번째 배열을
오른쪽으로 90도 돌리면 두 번째 배열이 되는 지 확인하고, 결과에 따라 그림을 각각 출력한다.

해결 방법 : 첫 번째 배열을 90도 돌린 후 결과를 비교한다. 출력이 복잡하므로 실수하지 않도록 주의한다.

주요 알고리즘 : 구현

출처 : 가톨릭대 1회D2 2번
*/

int food1[128][128], food2[128][128], food1r[128][128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotr(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[(*h - j - 1) * lsz + i];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

int main(void) {
    int r, c, res = 1;
    scanf("%d %d", &c, &r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &food1[i][j]);
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &food2[i][j]);
        }
    }
    rotr(food1, food1r, &r, &c, 128);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (food1r[i][j] != food2[i][j]) res = 0;
        }
    }
    if (res) {
        printf("|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|");
    }
    else {
        printf("|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|");
    }
    return 0;
}