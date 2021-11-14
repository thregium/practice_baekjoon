#include <stdio.h>
#include <stdlib.h>

/*
문제 : 십자 모양으로 4개의 숫자(1 ~ 9)가 적혀 있을 때, 시계방향으로 4개의 수를 붙인 것 중 가장 작은 것을 시계 수라 한다면
주어진 수로 만들어진 시계 수는 몇 번째로 작은 시계 수인지 구한다.

해결 방법 : 4개의 수로 가능한 모든 조합에 대해 시계 수를 만들어 본다.
그 다음, 만들어진 시계 수를 정렬하고 중복을 제한 것을 새로 만든다. 이 배열에서 주어진 수로 만든 시계 수가
몇 번째인지 찾으면 된다.

주요 알고리즘 : 구현, 브루트 포스, 정렬

출처 : 정올 1997 초2번
*/

int clock[10240], nclock[10240], arr[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int p = 0, best = 103000, t;
    for (arr[0] = 1; arr[0] <= 9; arr[0]++) {
        for (arr[1] = 1; arr[1] <= 9; arr[1]++) {
            for (arr[2] = 1; arr[2] <= 9; arr[2]++) {
                for (arr[3] = 1; arr[3] <= 9; arr[3]++) {
                    best = 103000;
                    for (int i = 0; i < 4; i++) {
                        t = 0;
                        for (int j = 0; j < 4; j++) {
                            t *= 10;
                            t += arr[(j + i) % 4];
                        }
                        if (t < best) best = t;
                    }
                    clock[(arr[0] - 1) * 729 + (arr[1] - 1) * 81 + (arr[2] - 1) * 9 + (arr[3] - 1)] = best;
                }
            }
        }
    }
    qsort(clock, 6561, sizeof(int), cmp1);
    for (int i = 0; i < 6561; i++) {
        if (i > 0 && clock[i] == clock[i - 1]) continue;
        else nclock[p++] = clock[i];
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++) {
        t = 0;
        for (int j = 0; j < 4; j++) {
            t *= 10;
            t += arr[(j + i) % 4];
        }
        if (t < best) best = t;
    }
    for (int i = 0; i < p; i++) {
        if (best == nclock[i]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 1;
}