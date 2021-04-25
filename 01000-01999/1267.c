#include <stdio.h>

/*
문제 : 통화 횟수와 시간이 주어질 때, 통화시 30초마다 10원씩 청구되는 요금제와 60초마다 15원씩 청구되는 요금제 가운데
어느 것이 더 저렴한지, 그때의 요금은 얼마인지 출력한다.

해결 방법 : 각각의 통화에 대해 요금을 계산하고, 더 저렴한 것을 찾는다.

주요 알고리즘 : 수학
*/

int main(void) {
    int n, t, y = 0, m = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if(t == 0) {
            y += 10;
            m += 15;
            continue;
        }
        y += (t / 30 + 1) * 10;
        m += (t / 60 + 1) * 15;
    }
    if(y < m) printf("Y %d\n", y);
    else if(y == m) printf("Y M %d\n", y);
    else printf("M %d\n", m);
    return 0;
}