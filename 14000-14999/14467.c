#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 소 10마리의 등장 기록이 N(N <= 100)회 주어진다. 이때, 등장 위치는 0 또는 1뿐이라면 소들이 위치를 바꾼 최소 횟수를 구한다.

해결 방법 : 소들이 처음 나오지 않았다면 마지막으로 등장한 장소와 같은 곳에서 등장했는지 확인하고 아니라면
반드시 장소를 이동한 것이다. 이러한 경우의 횟수를 세면 된다.

주요 알고리즘 : 구현

출처 : USACO 2017F B1번
*/

int cows[16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crossroad.in", "r");
        fo = fopen("crossroad.out", "w");
    }
    int n, r = 0, c, p;
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) cows[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &p);
        if (cows[c] < 0) cows[c] = p;
        else if (cows[c] != p) {
            r++;
            cows[c] = p;
        }
    }
    printf("%d", r);
    return 0;
}