#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 수를 가진 수열 A가 주어질 때, Ai + 1 == A(i + 1)이 되는 경우가 없도록 하는 수열 가운데 가장 사전순으로 빠른 것을 구한다.

해결 방법 : 사전 순으로 수들을 출력하되, 남은 수가 현재 수와 그보다 1 큰 수만 남은 경우에는 큰 수부터 처리한다.
또한, 다음 수가 현재 수보다 1 큰 경우에는 그보다 더 큰 수 가운데 가장 작은 수를 출력한 후 다음 수를 출력한다.

주요 알고리즘 : 그리디 알고리즘
*/

int a[64], r[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, lar, sel;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        lar = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > lar) lar = a[j]; //최댓값 구하기
        }
        if (a[0] + 1 == lar) {
			//최댓값이 남은 값들 중 최솟값보다 1 큰 경우
            sel = -1;
            for (int j = 1; j < n - i; j++) {
                if (a[j] == a[0] + 1) {
                    sel = j;
                    break;
                }
            }
            if (sel < 0) return 1;
            r[i] = a[sel];
            for (int j = sel; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
        else if (lar > a[0] + 1 && i > 0 && a[0] == r[i - 1] + 1) {
			//다음 수가 남은 값들 중 최솟값보다 1 큰 경우
            sel = -1;
            for (int j = 1; j < n - i; j++) {
                if (a[j] > r[i - 1] + 1) {
                    sel = j;
                    break;
                }
            }
            if (sel < 0) return 1;
            r[i] = a[sel];
            for (int j = sel; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
        else {
            r[i] = a[0];
            for (int j = 0; j < n - i - 1; j++) {
                a[j] = a[j + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    return 0;
}