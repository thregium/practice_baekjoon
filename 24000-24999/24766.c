#include <stdio.h>

/*
문제 : 두 명이 굴린 주사위 2개씩의 값이 각각 주어지거나 주어지지 않을 때,
주어지지 않은 주사위의 값들을 임의로 결정하여 첫 번째 사람이 이길 확률을 구한다.
규칙은 문제에 주어진대로이다.

해결 방법 : 주사위 4개의 모든 경우를 세 보더라도 그리 많지 않기 때문에
모든 경우의 수에 대해 첫 번째 사람이 이기는 경우의 수를 각각 세고 그 둘의 비율을 구하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : VTH 2014 B번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int score(int a, int b) {
    if (a == 2 && b == 1) return 103000;
    else if (a == b) return 100 + a;
    else return a * 10 + b;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    char a, b, c, d;
    int res, tot, g, x, y, z, w;
    while (1) {
        scanf(" %c %c %c %c", &a, &b, &c, &d);
        if (a == '0') break;
        res = 0, tot = 0;
        for (int i = 1; i <= 6; i++) {
            if (a != '*' && a - '0' != i) continue;
            for (int j = 1; j <= 6; j++) {
                if (b != '*' && b - '0' != j) continue;
                for (int k = 1; k <= 6; k++) {
                    if (c != '*' && c - '0' != k) continue;
                    for (int l = 1; l <= 6; l++) {
                        if (d != '*' && d - '0' != l) continue;
                        tot++;
                        x = i, y = j, z = k, w = l;
                        if (x < y) swap(&x, &y);
                        if (z < w) swap(&z, &w);
                        if (score(x, y) > score(z, w)) res++;
                    }
                }
            }
        }
        if (res == 0) printf("0\n");
        else if (res == tot) printf("1\n");
        else {
            g = gcd(res, tot);
            res /= g, tot /= g;
            printf("%d/%d\n", res, tot);
        }
    }
    return 0;
}