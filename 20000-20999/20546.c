#include <stdio.h>

/*
문제 : 14일간의 주가(1 <=, <= 1000, 정수)가 주어질 때, 문제에 주어진 두 매매 전략 가운데 더 좋은 전략을 구한다.

해결 방법 : 문제에 주어진대로 두 전략을 시뮬레이션한다. 나눗셈과 나머지 연산을 잘 이용해야 한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 인하대 2020U H번
*/

int md[14];

int main(void) {
    int m, jhs = 0, jhm = 0, sms = 0, smm = 0;
    scanf("%d", &m);
    smm = m;
    jhm = m;
    for (int i = 0; i < 14; i++) {
        scanf("%d", &md[i]);
        if (jhm >= md[i]) {
            jhs += jhm / md[i];
            jhm %= md[i];
        }
        if (i >= 3 && md[i] < md[i - 1] && md[i - 1] < md[i - 2] && md[i - 2] < md[i - 3]) {
            sms += smm / md[i];
            smm %= md[i];
        }
        if (i >= 3 && md[i] > md[i - 1] && md[i - 1] > md[i - 2] && md[i - 2] > md[i - 3]) {
            smm += sms * md[i];
            sms = 0;
        }
    }
    if (jhs * md[13] + jhm > sms * md[13] + smm) printf("BNP");
    else if (jhs * md[13] + jhm == sms * md[13] + smm) printf("SAMESAME");
    else printf("TIMING");
    return 0;
}