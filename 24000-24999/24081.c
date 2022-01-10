#include <stdio.h>

/*
문제 : N(N <= 100)개의 상자가 열리는 열쇠 번호(<= 2000, 자연수)가 주어진다. M(M <= 100)개의 열쇠가 있고,
각각의 열쇠 번호(<= 2000, 자연수)가 주어지면, 열 수 있는 상자의 개수를 구한다.

해결 방법 : N과 M이 작기 때문에 각 열쇠마다 열 수 있는 상자를 하나씩 확인한다.
하나 이상의 열쇠로 열 수 있는 모든 상자를 체크한 다음, 체크된 상자의 개수를 세면 열 수 있는 상자의 개수와 같다.

주요 알고리즘 : 구현, 브루트 포스

출처 : JOI 2022예1 1-4번
*/

int chest[2048], opened[2048];

int main(void) {
    int n, m, x, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &chest[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        for (int j = 0; j < n; j++) {
            if (x == chest[j]) opened[j] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        res += opened[i];
    }
    printf("%d", res);
    return 0;
}