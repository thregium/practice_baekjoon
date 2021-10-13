#include <stdio.h>

/*
문제 : M * N(M, N <= 100) 크기의 공간에 박스들이 놓인 형태가 주어진다. 박스들이 떨어진 거리의 합을 구한다.

해결 방법 : 각 열의 박스들을 아래쪽부터 보면서 떨어질 위치와의 거리 차를 결괏값에 더해나간다.
그 다음, 떨어질 위치를 1칸 위로 옮긴다. 이를 모든 열에 대해 반복하면 답을 구할 수 있다.

주요 알고리즘 : 구현

출처 : Daejeon 2013 A번
*/

int box[128][128];

int main(void) {
    int t, m, n, r, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &box[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            cnt = 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[j][i]) r += (m - cnt++) - j;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}