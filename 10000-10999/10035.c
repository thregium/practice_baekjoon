#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 두 자연수 X, Y(X, Y <= 10^16)가 주어질 때, X와 Y 사이에 있는 흥미로운 수의 개수를 구한다.
흥미로운 수는 자연수 가운데 한 자리를 제외한 모든 자릿수가 같은 수를 의미한다. 모든 자릿수가 같다면 흥미로운 수가 아니다.

해결 방법 : 10^16 이하에 흥미로운 수가 많지 않음을 알 수 있다. 따라서, 범위 내의 흥미로운 수들을 전부 만든 다음,
X와 Y 사이에 있는 흥미로운 수를 세면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2014O B1번
*/

char odo[32];
long long inter[103000];
int ip = 0;

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("odometer.in", "r");
        fo = fopen("odometer.out", "w");
    }
    for (int i = 2; i < 18; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k < i; k++) odo[k] = '0' + j;
            for (int k = 0; k < i; k++) {
                for (int l = 0; l <= 9; l++) {
                    if (j == l || (l == 0 && k == 0) || (i == 2 && l < j)) continue;
                    odo[k] = '0' + l;
                    inter[ip++] = strtoll(odo, NULL, 10);
                    odo[k] = '0' + j;
                }
            }
        }
    }
    for (int i = 0; i < 32; i++) odo[i] = '\0';
    for (int i = 2; i < 18; i++) {
        for (int j = 1; j < i; j++) odo[j] = '0';
        for (int j = 1; j <= 9; j++) {
            odo[0] = '0' + j;
            inter[ip++] = strtoll(odo, NULL, 10);
        }
    }
    long long x, y, r = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = 0; i < ip; i++) {
        if (inter[i] >= x && inter[i] <= y) r++;
    }
    printf("%d", r);
    return 0;
}