#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 N * 2(N <= 4)의 수열이 주어질 때, 이 수열에서 4의 배수인 N개의 수와 해당 수의 3 / 4인 N개의 수들이
섞여 있다고 한다. 이 수열에서 3 / 4인 수들을 오름차순으로 모두 구한다. 같은 수가 여러 번 나올 수 있다.
답이 유일하다는 것이 보장된다.

해결 방법 : 각 수들을 확인하며 원래 수와 3 / 4인 수의 쌍을 찾으면 재귀적으로 다음 수를 찾아 나간다.
이를 N개의 쌍을 찾을 때 까지 반복해 나가면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : GCJ 2016W A1번
*/

int price[8], chk[8], collect[4];
int fin = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int tt) {
    if (n == x) {
        fin = 1;
        qsort(collect, n, sizeof(int), cmp1);
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%d ", collect[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n * 2; i++) {
        if (chk[i]) continue;
        for (int j = 0; j < n * 2; j++) {
            if (i == j) continue;
            if (chk[j]) continue;
            if (price[i] * 4 == price[j] * 3) {
                chk[i] = 1;
                chk[j] = 1;
                collect[x] = price[i];
                track(n, x + 1, tt);
                chk[i] = 0;
                chk[j] = 0;
                if (fin) return;
                break;
            }
        }
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n * 2; i++) {
            scanf("%d", &price[i]);
        }
        track(n, 0, tt);
    }
    return 0;
}