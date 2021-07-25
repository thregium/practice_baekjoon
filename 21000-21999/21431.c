#include <stdio.h>

/*
문제 : 최대 길이 K(K <= 10^8)까지의 선분을 사용할 수 있을 때, 선분들을 이용해 평각이 없는 N(N <= 10)각형을
만들 수 없는 최대 크기의 선분 집합을 구한다.

해결 방법 : 일단 N - 1개의 선분은 길이가 몇이든 상관 없다. 작을 수록 좋으므로 전부 1로 설정해둔다.
그 이후로는 가장 긴 N - 1개의 선분 이상의 길이가 나와야 한다. 따라서 이후 값들은 DP를 통해 구하다가
K를 넘어서면 그때까지의 값들을 출력하면 된다.

주요 알고리즘 : 기하학, DP

출처 : ROI 2005H C번
*/

int mem[1024];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    n--;
    for (int i = 0; i < n; i++) {
        mem[i] = 1;
    }
    for (int i = n;; i++) {
        for (int j = i - 1; j >= i - n; j--) {
            mem[i] += mem[j];
        }
        if (mem[i] > k) {
            printf("%d\n", i);
            for (int j = 0; j < i; j++) {
                printf("%d ", mem[j]);
            }
            break;
        }
    }
    return 0;
}