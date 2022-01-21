#include <stdio.h>
#include <stdlib.h>

/*
문제 : W * D(W, D <= 100) 크기의 케잌을 N(N <= 100)번 잘랐다. 매번 자를 때마다 P_i번 조각을 왼쪽 위
꼭짓점에서 S_i만큼 시계방향으로 이동한 곳에서 수직으로 자른다. 그곳의 위치는 꼭짓점이 아니다.
각 조각은 만들어진 순서대로 번호가 갱신되며, 새로운 조각들 중에는 더 작은 것이 앞 번호를 받는다.
이때, N번 자르는 행동이 끝난 후 각 조각의 크기를 오름차순으로 출력한다.

해결 방법 : 각 조각의 번호를 차례로 확인하면서 조각들을 잘라나간다. 자를 위치는 나머지 연산을
통해 알 수 있고, 각 조각의 크기는 각 조각의 크기에서 뺀 값과 비교해서 확인 가능하다.
매번 자를 때 마다 자른 블록의 번호부터 그 뒤의 번호들은 하나씩 당겨와야 한다.
모든 자르는 행동이 끝나고 각 조각들의 번호들을 차례로 확인하며 넓이를 구하고 넓이를 정렬한 다음
그 넓이들을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2007 C번
*/

int rect[128][2], area[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, w, d, p, s;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2007\\INPUT\\C4", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2007\\OUTPUT\\C4_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &n, &w, &d);
        if (w == 0) break;
        rect[1][0] = w, rect[1][1] = d;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p, &s);
            w = rect[p][0], d = rect[p][1];
            for (int j = p; j <= i; j++) {
                rect[j][0] = rect[j + 1][0];
                rect[j][1] = rect[j + 1][1];
            }
            if (s % (w + d) < w) {
                rect[i + 1][0] = small(s % (w + d), w - s % (w + d));
                rect[i + 1][1] = d;
                rect[i + 2][0] = big(s % (w + d), w - s % (w + d));
                rect[i + 2][1] = d;
            }
            else {
                rect[i + 1][0] = w;
                rect[i + 1][1] = small(s % (w + d) - w, d - (s % (w + d) - w));
                rect[i + 2][0] = w;
                rect[i + 2][1] = big(s % (w + d) - w, d - (s % (w + d) - w));
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            area[i - 1] = rect[i][0] * rect[i][1];
        }
        qsort(area, n + 1, sizeof(int), cmp1);
        for (int i = 0; i <= n; i++) {
            printf("%d%c", area[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}