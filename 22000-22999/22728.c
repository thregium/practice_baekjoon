#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 세로줄과 M(M <= 1000)개의 가로줄로 이루어진 사다리타기에서 A번 줄이 어디로 이어지는 지 구한다.
단, 같은 높이에서 하나의 가로줄에 여러 개의 선이 연결되는 경우는 없다.

해결 방법 : 각 가로줄을 높이순(위에서 아래로)으로 정렬한 다음, A번 줄에 연결되는 가로선이 나오면,
해당 세로선으로 옮기는 행동을 반복한다. 모두 완료된 다음 옮겨간 마지막 줄이 답이 된다.

주요 알고리즘 : 구현, 정렬

출처 : JAG 2006D B번
*/

int hor[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, a;
    while (1) {
        scanf("%d %d %d", &n, &m, &a);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &hor[i][0], &hor[i][1], &hor[i][2]);
        }
        qsort(hor, m, sizeof(int) * 3, cmp1);
        for (int i = 0; i < m; i++) {
            if (hor[i][1] == a) a = hor[i][2];
            else if (hor[i][2] == a) a = hor[i][1];
        }
        printf("%d\n", a);
    }
    return 0;
}