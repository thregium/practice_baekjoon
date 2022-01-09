#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 30)명의 사람들이 0번부터 N - 1번까지 번호로 원형으로 있다. 오른쪽 또는 왼쪽으로 x번째 사람에게 전달하다가 undo x가 나오면
최근 x개 전의 위치로 돌아가는 행동을 K(K <= 100)번 반복할 때, 마지막으로 도착하는 위치를 구한다.

해결 방법 : 스택 자료구조를 이용하여 스택에 각 번째의 위치를 쌓아둔다. undo가 나올 때 마다 x만큼 스택의 높이를 낮추면 된다.

주요 알고리즘 : 자료 구조, 스택, 시뮬레이션, 파싱

출처 : ECRC 2017 D번
*/

char buff[16];
int st[128];
int stt = 1;

int main(void) {
    int n, k, x, r = 0;
    //freopen("E:\\PS\\ICPC\\North America\\East Central\\2017\\throwns\\throwns\\data\\secret\\02.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "undo")) {
            scanf("%d", &x);
            stt -= x;
            if (stt <= 0) return 1;
            r = st[stt - 1];
        }
        else {
            r = (((r + strtoll(buff, NULL, 10)) % n) + n) % n;
            st[stt++] = r;
        }
    }
    printf("%d", r);
    return 0;
}