#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 글에 대한 우선순위와 태그들(<= 100)이 주어질 때, 태그의 번호가 주어질 때 마다
그러한 태그가 있는 글의 번호를 우선순위 순으로 출력한다.

해결 방법 : 각 글들의 태그들과 우선순위, 번호를 배열에 넣고 우선순위 순으로 정렬한다.
그 후, 태그 번호가 주어질 때 마다 글들을 차례로 보면서 태그가 있는 글들을 찾아서 모두 출력하면 된다.

주요 알고리즘 : 구현, 정렬, 브루트 포스

출처 : 선린 4회 G번
*/

int kw[128][128];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 127);
    int bi = *((int*)b + 127);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, q, x, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &kw[i][127]);
        kw[i][126] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &kw[i][0]);
        for (int j = 1; j <= kw[i][0]; j++) {
            scanf("%d", &kw[i][j]);
        }
    }
    qsort(kw + 1, n, sizeof(int) * 128, cmp1);
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        c = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= kw[j][0]; k++) {
                if (kw[j][k] == x) {
                    printf("%d ", kw[j][126]);
                    c++;
                    break;
                }
            }
        }
        if (c == 0) printf("-1\n");
        else printf("\n");
    }
    return 0;
}