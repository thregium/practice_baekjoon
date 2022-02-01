#include <stdio.h>

/*
문제 : N(N <= 10000)번의 주차장 출입 기록이 주어질 때, 전체 주차 요금을 구한다.
주차장의 크기는 C(C <= 1000)의 일직선형이며, 각 차의 길이에 맞추어 가장 가까운(수가 작은) 곳에 주차된다.
주차된 차들은 선불로 주차요금 10 헤알을 낸다. 주차가 불가능할 시 주차를 포기하고
주차요금을 내지 않는다. 출차시에는 별다른 요금 없이 해당 차가 나가는 것으로 끝난다.

해결 방법 : 주차장의 각 위치마다 주차되었는 지 여부와 각 주차된 차의 위치를 저장해두고,
각 차의 이동을 시뮬레이션하면 된다. 

주요 알고리즘 : 구현, 시뮬레이션

출처 : Brasil 2011 E번
*/

int park[1024], car[10240];

int main(void) {
    int c, n, p, q, r, t;
    char ch;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\estacionamento.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\estacionamento_t.out", "w", stdout);
    while (scanf("%d %d", &c, &n) != EOF) {
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c %d", &ch, &p);
            if (ch == 'S') {
                for (int j = car[p] + 1; park[j] == park[car[p]]; j++) park[j] = 0;
                park[car[p]] = 0;
            }
            else {
                scanf("%d", &q);
                t = 0;
                for (int j = 0; j < c; j++) {
                    if (park[j]) t = 0;
                    else t++;
                    if (t == q) {
                        for (int k = j - q + 1; k <= j; k++) park[k] = p;
                        car[p] = j - q + 1;
                        r += 10;
                        break;
                    }
                }
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < c; i++) park[i] = 0;
    }
    return 0;
}