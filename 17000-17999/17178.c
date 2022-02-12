#include <stdio.h>

/*
문제 : N * 5(N <= 100)명이 티켓을 들고 줄을 서있다. 각 사람이 들고 있는 티켓은 서로 다르며,
각 티켓의 번호는 대문자-수(< 1000)로 이루어져 있다. 티켓의 번호는 대문자가 빠른 순 -
수가 작은 순으로 빠른 번호이다. 이때, 현재 서있는 줄의 상태에서 티켓이 빠른 순으로 사람들이
들어올 수 있는 지 구한다. 입구의 옆에는 대기 줄이 있고, 들어온 순의 역순으로 나가게 된다.
대기 줄에서 나갈 때에는 입구로만 나올 수 있고 줄로 돌아갈 수는 없다.

해결 방법 : 우선 각 사람의 티켓 번호를 들어가야 하는 순서로 바꾼다. 그 다음으로는
1번째부터 차례로 해당 티켓인 사람을 들여보낸다. 그 티켓이 아닌 경우 대기 줄로 보낸다.
해당 티켓인 경우 대기 줄에서 다음 티켓인 사람들을 최대한 들여보낸다.
이를 반복하다가 모든 사람이 대기 줄에 있으면 마지막으로 사람들을 최대한 들여보낸다.
대기 줄에 사람이 없다면 모든 사람을 들여보낸 것이고, 남았다면 들여보내지 못한 것이다.

주요 알고리즘 : 자료 구조, 스택, 시뮬레이션, 값 압축

출처 : 충남대 3회 F번
*/

int line[512], wait[512];

int main(void) {
    int n, x, wp = 0, lo, lon;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n * 5; i++) {
        scanf(" %c-%d", &c, &x);
        line[i] = (c - 'A' + 1) * 1000 + x;
    }
    for (int i = 1; i <= n * 5; i++) {
        lo = 103000, lon = -1;
        for (int j = 0; j < n * 5; j++) {
            if (line[j] >= 1000 && line[j] < lo) {
                lo = line[j];
                lon = j;
            }
        }
        line[lon] = i;
    }
    lo = 1;
    for (int i = 0; i < n * 5; i++) {
        if (line[i] == lo) {
            lo++;
            while (wp > 0 && wait[wp - 1] == lo) {
                wp--;
                lo++;
            }
        }
        else wait[wp++] = line[i];
    }
    while (wp > 0 && wait[wp - 1] == lo) {
        wp--;
        lo++;
    }
    if (lo > n * 5) printf("GOOD");
    else printf("BAD");
    return 0;
}