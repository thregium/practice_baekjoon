#include <stdio.h>

/*
문제 : 길이 N의 배열이 주어지고, 그 다음 길이 M(2 <= N <= M <= 1000)의 배열이 주어질 때, 길이 M의 배열에서
길이 N의 해당 배열 또는 해당 배열의 X배된 배열(X칸마다 N의 원소가 있는 배열)이 있는지 구하고,
있다면 X - 1의 가장 작은 값과 가장 큰 값을 구한다.

해결 방법 : 최댓값과 최숫값을 나올 수 없는 값으로 초기화한 다음, 모든 X(1 <= X <= M)에 대해 가능한 모든 시작점에서
원래의 배열과 비교한다. 정확히 일치하는 때가 나오면 최댓값과 최솟값을 X와 비교해서 그 값으로 갱신한다.
모든 경우의 탐색이 끝나면 가장 작은 값과 가장 큰 값을 출력하면 된다. 단, 처음 값 그대로라면 가능한 경우가 없는 것이다.

주요 알고리즘 : 브루트 포스

출처 : 서강대 2015M C번
*/

int real[1024], dream[1024];

int main(void) {
    int n, m, t, l = 3331, h = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &real[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &dream[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < m - (n - 1) * i; j++) {
            //가능한 시작점: 0 이상 M - (N - 1) * i 이하
            t = 1;
            for (int k = 0; k < n; k++) {
                if (dream[j + k * i] != real[k]) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                if (i < l) l = i - 1;
                if (i > h) h = i - 1;
            }
        }
    }
    if (h < 0) printf("-1");
    else printf("%d %d", l, h);
    return 0;
}