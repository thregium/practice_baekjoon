#include <stdio.h>
#include <stdlib.h>

/*
문제 : L(L <= 1000)개의 문자와 K(K <= 1000)개의 키가 있다. 각 키에는 최대 P(P <= 1000, K * P >= L)개의
문자를 할당할 수 있을 때, 각 문자를 사용한 횟수(<= 10^6)가 주어지면 문자를 키에 최적의 방법으로
할당했을 때 자판을 누르는 횟수의 최솟값을 구한다.

해결 방법 : 많이 사용하는 문자부터 각 키의 앞쪽에 넣어나가면 된다. K * P가 L 이상이므로
이 방법으로 모든 문자를 할당할 수 있고, 이 방법이 최적의 방법이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : GCJ 2008C A2번
*/

int freq[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, p, k, l;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &p, &k, &l);
        res = 0;
        for (int i = 0; i < l; i++) {
            scanf("%d", &freq[i]);
        }
        qsort(freq, l, sizeof(int), cmp1);
        for (int i = 0; i < l; i++) {
            res += (i / k + 1) * freq[i];
        }
        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}