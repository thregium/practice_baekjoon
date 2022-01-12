#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)대의 컴퓨터와 M(M <= 20000)개의 패킷 기록이 있다. 각 패킷은 데이터를 보낸 순서와 보낸 컴퓨터,
받은 컴퓨터로 이루어진다. 1번 컴퓨터가 바이러스에 감염되었고, 바이러스에 감염된 컴퓨터로부터 데이터를 받은 컴퓨터는
바이러스에 감염된다면 바이러스에 감염된 컴퓨터의 대수를 구한다.

해결 방법 : 각 패킷 기록을 시간 순으로 정렬한 다음, 하나씩 살펴보며 바이러스에 감염된 컴퓨터들을 확인한다.
각 컴퓨터의 감염 여부를 저장한 다음, 감염된 컴퓨터에서 데이터를 받은 컴퓨터들을 감염시켜 나가면 된다.
그리고 감염된 컴퓨터의 대수를 센 다음 출력한다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : JAG 2009S2 A번
*/

char vir[20480];
int packet[20480][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        vir[1] = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &packet[i][0], &packet[i][1], &packet[i][2]);
        }
        qsort(packet, m, sizeof(int) * 3, cmp1);
        for (int i = 0; i < m; i++) {
            if (vir[packet[i][1]]) vir[packet[i][2]] = 1;
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            r += vir[i];
            vir[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}