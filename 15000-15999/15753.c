#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 마지막으로 사건이 일어난지 X일 지났다는 N(N <= 100)일간의 기록이 있다고 한다. 이때, 일부 기록은 유실되었다고 하면,
사건이 일어날 수 있는 가장 적은 일 수와 가장 많은 일 수를 출력한다. 그러한 것이 불가능하다면 -1만 출력한다.

해결 방법 : 기록의 맨 뒤부터 순서대로 앞으로 가면서 현재의 기록이 가능한지 본다. 그 다음, 사건이 일어난 날부터 그 기록의 날까지
마지막 사건이 일어난 날을 기록해둔다. 새로 기록한 경우 카운터 값을 1 올린다. 이를 기록의 맨 앞까지 반복한다.
중간에 불가능한 경우가 나온 경우 -1을 출력하고, 끝까지 가능했을 경우 가장 적은 일 수는 카운터의 값과 같다.
가장 많은 일 수는 카운터 값에 마지막 사건이 일어난 날을 모르는 날의 수를 더한 값과 같다.

주요 알고리즘 : 구현

출처 : USACO 2018F B3번
*/

int log[128], last[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("taming.in", "r");
        fo = fopen("taming.out", "w");
    }
    int n, r = 1, c1 = 1, c2 = 0;
    scanf("%d", &n);
    last[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &log[i]);
    }
    for (int i = n; i > 0; i--) {
        if (log[i] >= 0) {
            if (last[i] && last[i] != i - log[i]) {
                r = 0;
            }
            else if (!last[i]) {
                if (!last[i - log[i]]) c1++;
                for (int j = i - log[i]; j <= i; j++) {
                    last[j] = i - log[i];
                }
            }
        }
    }
    if (!r) {
        printf("%d", -1);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!last[i]) c2++;
    }
    printf("%d %d", c1, c1 + c2);
    return 0;
}