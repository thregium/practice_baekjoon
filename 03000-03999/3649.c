#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6)개의 나노미터 단위의 조각 크기(<= 10^7)가 주어진다. 이때, X(X <= 20, 센티미터) 크기의
구멍을 정확히 2개의 조각으로 막을 수 있는 지 구하고 있다면 그러한 방법 가운데 조각 크기의 차이가
가장 큰 것을 구한다.

해결 방법 : 각 조각들을 크기 순으로 정렬한 다음, 양 끝에서부터 범위를 좁혀오며 서로 다른 두 조각의
합이 X(* 10^7)가 되는 경우가 있는 지 구하면 된다. 테스트 케이스의 개수가 여러 개일 수 있음에 유의한다.

주요 알고리즘 : 정렬, 투 포인터

출처 : NWERC 2012 J번
*/

int leg[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int x, n, s, e, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2012\\J\\joint-venture.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2012\\J\\joint-venture_t.out", "w", stdout);
    while (scanf("%d", &x) != EOF) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &leg[i]);
        }
        qsort(leg, n, sizeof(int), cmp1);
        r = 0, s = 0, e = n - 1;
        while (s < e) {
            if (leg[s] + leg[e] < x * 10000000) s++;
            else if (leg[s] + leg[e] > x * 10000000) e--;
            else {
                printf("yes %d %d\n", leg[s], leg[e]);
                r = 1;
                break;
            }
        }
        if (!r) printf("danger\n");
    }
    return 0;
}