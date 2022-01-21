#include <stdio.h>

/*
문제 : N + 1(N <= 50)개의 여러 선분으로 이루어진 도형이 주어진다. 이때, 처음 주어진 도형과
같은 도형의 번호를 모두 출력한다. 같은 도형은 90도 단위로 돌려서 원래 도형과 완전히 겹치는 경우이다.
순서를 뒤집어서 겹쳐지는 경우도 포함한다. 그러나 대칭인 경우는 포함하지 않는다.

해결 방법 : 원래 도형과 주어진 도형의 시작점을 (0, 0)으로 맞추어 둔다. 그리고 90도씩 돌려가며
4개의 방향에 대해 원래 도형과 일치하는 지 확인한다. 90도를 돌릴 때에는 원래 도형의 방향에서
X좌표와 Y좌표를 교환하되 둘 중 하나의 방향을 뒤집으면 된다. 각 방향을 확인한 다음에는
주어진 도형의 순서를 뒤집고 시작점을 다시 (0, 0)으로 맞춘 다음 다시 90도씩 4방향을 확인한다.
중간에 완전히 일치하는 것이 나왔다면 같은 도형이고, 끝까지 나오지 않았다면 다른 도형이다.
같은 도형인 경우 그 도형의 번호를 모두 출력하면 된다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : JDC 2005 B번
*/

int tpl[16][2], lin[16][2], tmp[16][2];

void rot90(int m) {
    int t;
    for (int i = 1; i < m; i++) {
        t = lin[i][0];
        lin[i][0] = -lin[i][1];
        lin[i][1] = t;
    }
}

void revlin(int m) {
    for (int i = 0; i < m; i++) {
        tmp[m - i - 1][0] = lin[i][0];
        tmp[m - i - 1][1] = lin[i][1];
    }
    for (int i = 0; i < m; i++) {
        lin[i][0] = tmp[i][0] - tmp[0][0];
        lin[i][1] = tmp[i][1] - tmp[0][1];
    }
}

int arrcmp(int m) {
    for (int i = 0; i < m; i++) {
        if (tpl[i][0] - lin[i][0] || tpl[i][1] - lin[i][1]) return 1;
    }
    return 0;
}

int linecmp(int m) {
    for (int i = m - 1; i >= 0; i--) {
        tpl[i][0] -= tpl[0][0], tpl[i][1] -= tpl[0][1];
        lin[i][0] -= lin[0][0], lin[i][1] -= lin[0][1];
    }
    for (int i = 0; i < 4; i++) {
        if (!arrcmp(m)) return 1;
        rot90(m);
    }
    revlin(m);
    for (int i = 0; i < 4; i++) {
        if (!arrcmp(m)) return 1;
        rot90(m);
    }
    return 0;
}

int main(void) {
    int n, m, l;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &tpl[i][0], &tpl[i][1]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &l);
            for (int j = 0; j < l; j++) {
                scanf("%d %d", &lin[j][0], &lin[j][1]);
            }
            if (l != m) continue;
            if (linecmp(m)) printf("%d\n", i);
        }
        printf("+++++\n");
    }
    return 0;
}