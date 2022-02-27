#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 200)개의 램프가 K(K <= 20)가지 색상으로 존재한다.
이때, 각 램프의 색을 원하는대로 바꿀 수 있고, 램프의 색을 바꾸면 인접한 같은 색의 램프들도
색이 바뀐다면 모든 램프의 색을 같게 만들기 위해 램프 색을 최소 몇 회 바꿔야 하는 지 구한다.

해결 방법 : 색이 같은 구간을 넓혀가면서 다이나믹 프로그래밍을 진행한다.
변수를 [L, R] 범위을 모두 같게 하기 위해 램프의 색을 바꾸는 횟수로 정의한다.
두 램프의 범위를 합치는 과정에서 항상 램프의 색을 왼쪽 기준으로 합치더라도
최소 횟수가 보장된다는 성질을 이용한다.

주요 알고리즘 : DP, 그리디 알고리즘

출처 : 정올 2011 초4번
*/

int lamp[256], mem[256][256];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lamp[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            mem[j][i + j] = INF;
            for (int k = j + 1; k <= i + j; k++) {
                mem[j][i + j] = small(mem[j][i + j], mem[j][k - 1] + mem[k][i + j] + (lamp[j] != lamp[k]));
            }
        }
    }
    printf("%d", mem[0][n - 1]);
    return 0;
}