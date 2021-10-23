#include <stdio.h>
#include <stdlib.h>

/*
문제 : 한 개의 강의실에 N(N <= 10000)개의 강의가 들어올 수 있다. 각 강의 시간은 30000 이하의 음이 아닌 정수 구간이라 할 때,
강의 시간을 최대가 되도록 배정하는 방법을 구한다.

해결 방법 : 강의를 시작 시각 기준으로 정렬한 다음, 순서대로 강의를 확인하며 강의가 끝나는 시각에 가장 오래 강의한
시간을 저장해가며 다이나믹 프로그래밍을 진행한다. 이때, 이전 시각보다 현재 시각의 값이 작다면
이전 시각의 값으로 수를 바꿔줘야 한다.

주요 알고리즘 : DP, 정렬

출처 : POI 1996/1997S3 6번
*/

int lec[10240][2], mem[32768];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lec[i][0], &lec[i][1]);
    }
    lec[n][0] = 32767;
    qsort(lec, n + 1, sizeof(int) * 2, cmp1);

    for (int i = 0; i <= n; i++) {
        while (p < lec[i][0]) {
            p++;
            if (mem[p] < mem[p - 1]) mem[p] = mem[p - 1];
        }
        if (i == n) break;
        if (mem[p] + (lec[i][1] - lec[i][0]) > mem[lec[i][1]]) mem[lec[i][1]] = mem[p] + (lec[i][1] - lec[i][0]);
    }
    printf("%d", mem[32767]);
    return 0;
}