#include <stdio.h>

/*
문제 : 원을 N(N <= 100)개의 칸으로 나누어 놓고, 각 칸에 0에서 9 사이의 숫자를 써넣었다. 이때, M(M <= 9)자리 자연수
X <= Y가 주어질 때, 시계방향으로 연속해서 M칸을 읽은 수가 X와 Y 사이인 것의 개수를 구한다.

해결 방법 : 각 칸에 대해서 M칸을 연속해서 나오는 수들을 기록한다. 그리고, 각 자릿수를 담은 배열을 X, Y와 각각 비교한다.
배열이 X 이상이고 Y 이하인 경우 조건을 만족하는 것이므로 세면 된다. 자릿수는 항상 같으므로 생각할 필요가 없다.

주요 알고리즘 : 브루트 포스, 구현

출처 : Daejeon 2015 L번
*/

int x[16], y[16], tmp[16], rot[128];

int cmp(int* a, int* b, int n) {
    //배열 비교 함수
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) return -1;
        else if (a[i] > b[i]) return 1;
    }
    return 0;
}

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &y[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &rot[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[j] = rot[(i + j) % n];
            }
            if (cmp(x, tmp, m) <= 0 && cmp(tmp, y, m) <= 0) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}