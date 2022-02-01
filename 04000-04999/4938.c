#include <stdio.h>

/*
문제 : N(N <= 1000)개의 접속 로그가 있다. 각 접속 로그는 월/일 시:분 진입여부 id로 이루어져 있으며,
시간 순으로 정렬되어 있다. 모든 접속자는 진입 후 퇴장하며, 각 날의 0시 0분에는 접속자가 없다.
또한, 모든 로그는 0시 0분이 포함되지 않는다. id는 3자리 수로 구성되어 있으며 0으로 시작할 수 있다.
이때, 0번 접속자와 동시에 접속한 시간이 가장 긴 접속자의 동시 접속 시간을 구한다.

해결 방법 : 각 접속자의 동시 접속 시간과 접속 여부를 배열에 저장하고 로그마다 업데이트하며 푼다.
0번 접속자가 접속해 있었다면 그 시간동안 같이 접속해 있던 사람들의 동시 접속 시간을 추가한다.
추가하는 시간은 최근 로그의 시각에서 흐른 시간만큼이다. 0시를 지나지 않기 때문에
단순히 빼기만 하면 된다. 그 다음 각 접속자의 접속 여부를 갱신한다.
이를 모든 로그에 대해 반복한 다음 가장 동시 접속 시간이 긴 접속자의 동시 접속 시간을 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Fukuoka 2011 A번
*/

int bless[1024], presence[1024];

int main(void) {
    int n, mt, dy, h, m, id, last, goddess, endowed;
    char alt;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        last = 0, goddess = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d/%d %d:%d %c %d", &mt, &dy, &h, &m, &alt, &id);
            if (goddess) {
                for (int j = 0; j < 1000; j++) bless[j] += presence[j] * (h * 60 + m - last);
            }
            if (alt == 'I') presence[id] = 1;
            else presence[id] = 0;
            if (id == 0) goddess = (alt == 'I');
            last = h * 60 + m;
        }

        endowed = 0;
        for (int i = 1; i < 1000; i++) {
            if (bless[i] > endowed) endowed = bless[i];
            bless[i] = 0;
        }
        printf("%d\n", endowed);
    }
    return 0;
}