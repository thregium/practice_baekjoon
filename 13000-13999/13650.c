#include <stdio.h>

/*
문제 : N(N <= 10000)개의 장화가 있다. 각 장화의 사이즈 M(30 <= M <= 60)과 어느 쪽 신발인지가 각각 주어질 때,
같은 사이즈로 맞출 수 있는 장화의 개수를 구한다.

해결 방법 : 각 사이즈와 방향마다 신발의 개수를 구한 다음, 적은 쪽의 개수를 전부 더하면 답이 된다.

주요 알고리즘 : 구현

출처 : Brasil 2011 B번
*/

int boot[64][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r;
    char l;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\botas.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %c", &m, &l);
            if (l == 'D') boot[m][0]++;
            else boot[m][1]++;
        }
        r = 0;
        for (int i = 30; i <= 60; i++) {
            r += small(boot[i][0], boot[i][1]);
            boot[i][0] = 0;
            boot[i][1] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}