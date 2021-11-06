#include <stdio.h>

/*
문제 : N(N <= 3402)개의 구슬에 대해 각각의 무게(<= 400)와 가치(<= 100)가 주어질 때, 전체 무게 M(M <= 12880) 이하에서
해당 구슬들로 만들 수 있는 가장 가치 합이 큰 팔찌의 가치를 구한다. 실의 무게는 무시한다. (메모리 128MB)

해결 방법 : 일반적인 냅색과 같은 형태이므로 비슷한 방식으로 해결 가능하다, 단, 메모리가 부족하기 때문에
한 줄을 업데이트 한 후 다시 원래 줄에 붙여넣기 하는 방식을 사용해야 한다.

주요 알고리즘 : DP, 냅색, 슬라이딩 윈도우

출처 : USACO 2007D S1번
*/

int bra[4096][2], mem[2][13312];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, r = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bra[i][0], &bra[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) mem[1][j] = big(mem[0][j], j >= bra[i][0] ? mem[0][j - bra[i][0]] + bra[i][1] : 0);
        for (int j = 0; j <= m; j++) mem[0][j] = mem[1][j];
    }
    for (int i = 0; i <= m; i++) r = big(mem[0][i], r);
    printf("%d", r);
    return 0;
}