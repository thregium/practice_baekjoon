#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 연도에 대한 연호와 해당 연호의 연도가 주어진다. Q(Q <= 1000)개의 연도에 대해
연호를 알 수 있는 지 확인하고 그러하다면 그때의 연호와 그 연호의 연도를 출력한다. 알 수 없다면 Unknown을 출력한다.
같은 연호의 연도는 하나씩만 주어진다.

해결 방법 : 우선 각 연호의 정보를 서력 기준으로 정렬한다. 그리고 Q개의 연도가 각각 주어질 때 마다
연호의 목록을 앞쪽부터 살펴나간다. 만약 현재 연도가 지금 보는 연호의 기준년 이전인 경우 해당 연호에 들어가는 지
확인한다. 들어간다면 그 연호와 연호의 연도를 계산하고, 들어가지 않는다면 이미 그 해를 지나쳤으므로 Unknown을 출력한다.
끝까지 그러한 연호가 없었더라도 알 수 없는 경우이므로 Unknown을 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : JAG 2010P A번
*/

typedef struct era {
    char s[32];
    int by;
    int wy;
} era;

era e[1024];

int cmp1(const void* a, const void* b) {
    era ai = *(era*)a;
    era bi = *(era*)b;
    return ai.wy > bi.wy ? 1 : ai.wy == bi.wy ? 0 : -1;
}

int main(void) {
    int n, q, y, r;
    while (1) {
        scanf("%d %d", &n, &q);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", e[i].s, &e[i].by, &e[i].wy);
        }
        qsort(e, n, sizeof(era), cmp1);
        for (int i = 0; i < q; i++) {
            scanf("%d", &y);
            r = 0;
            for (int j = 0; j < n; j++) {
                if (y <= e[j].wy) {
                    if (y > e[j].wy - e[j].by) printf("%s %d\n", e[j].s, e[j].by - (e[j].wy - y));
                    else printf("Unknown\n");
                    r = 1;
                    break;
                }
            }
            if (!r) printf("Unknown\n");
        }
    }
    return 0;
}