#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 18)개의 라운드로 풀 토너먼트를 하려고 한다. 각 팀의 전력(<= 10^9)이 주어지면
각 라운드마다 전력이 상위 절반인 팀들만 올라가도록 할 때, 실력 차이가 K(K <= 10^9) 이하인
대진의 최대 개수를 구한다. 모든 팀의 전력은 전부 다르다.

해결 방법 : 각 팀들을 전력 순서로 정렬한다. 그 다음, 각 라운드마다 진출 팀을 내림차순으로 살펴보고,
탈락 팀도 내림차순으로 살펴보면서 아직 매치되지 않은 첫 팀과의 실력 차이가 K 이하인지 확인한다.
그러한 경우 결괏값에 1을 더하고 다음 탈락 팀으로 시작점을 옮긴다. 이를 모든 진출 팀에 매치시킨 다음,
남은 팀들은 매치시킬 수 없으므로 적당히 매치된다고 생각하고 다음 라운드로 넘어가는 것을 반복한다.
최종적으로 나온 결과가 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 투 포인터

출처 : PacNW 2021 K/X번 // SCUSA 2021D1 I / 2021D2 J번
*/

int a[262144];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, e, res = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, 1 << n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        e = (1 << i);
        for (int j = 0; j < (1 << i); j++) {
            if (a[j] - a[e] <= k) {
                res++;
                e++;
            }
        }
    }
    printf("%d", res);
    return 0;
}