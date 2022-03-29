#include <stdio.h>

/*
문제 : N(N <= 1000)개의 패킷이 오는 시점(<= 10^9)이 주어진다. 이때, 패킷들을 순서대로 확인하는 동안
생기는 지연 시간을 구한다. 패킷은 단위 시간당 1개씩 본다.

해결 방법 : 각 패킷들을 1개씩 확인하면서 해당 순서에 필요한 패킷이 제때 도착했는 지 확인한다.
그 경우 다음 확인 시간을 1 늘린다. 제때 도착하지 않았다면 늦은 만큼 결과에 더하고,
다음 확인 시간은 도착 시간 + 1로 한다. 이를 반복한 후 총 지연 시간을 출력하면 된다.

주요 알고리즘 : 구현

출처 : MidAtl 2021 M번 // NCNA 2021 J번
*/

int packet[1024][2], chk[1024];

int main(void) {
    int n, l = 1, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &packet[i][0], &packet[i][1]);
    }
    for (int p = 1; p <= n; p++) {
        for (int i = 0; i < n; i++) {
            if (packet[i][1] == p) {
                if (packet[i][0] <= l) l++;
                else {
                    r += packet[i][0] - l;
                    l = packet[i][0] + 1;
                }
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}