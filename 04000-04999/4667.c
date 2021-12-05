#include <stdio.h>

/*
문제 : 대출 기간과 일시금, 대출액이 주어질 때, 담보 대상의 가치가 대출액 이상이 되는 시점을 구한다.
감가상각은 특정 시점과 감소율로 주어지며, 해당 시점의 감가상각 기준은 해당 시점 이전의 가장 마지막 감가상각을 적용한다.
대출 기간은 100개월 이하, 일시금 + 대출액은 75000$ 이하로 주어진다. 반드시 0개월때의 감가상각액이 주어진다.

해결 방법 : 처음의 담보 대상의 가치는 일시금 + 대출액이다. 매달 갚아야 할 돈은 대출액 / 기간이다.
이제 매달 감가상각을 적용하고, 대출을 상환해 나가며 두 값이 역전하게 되는 순간의 개월수를 구하면 된다.
반드시 이 값은 대출 기간 내로 나오게 된다.(담보 가치는 양수이지만 잔액은 0이므로)

주요 알고리즘 : 수학, 구현, 시뮬레이션

출처 : MidC 1999 D번
*/

typedef struct deprication {
    int month;
    double drop;
} deprication;

deprication depr[128];

int main(void) {
    int duration, n, p;
    double payment, loan, car;
    while (1) {
        scanf("%d %lf %lf %d", &duration, &payment, &loan, &n);
        if (duration < 0) break;
        car = loan + payment;
        for (int i = 0; i < n; i++) {
            scanf("%d %lf", &depr[i].month, &depr[i].drop);
        }
        depr[n].month = -1;
        p = 0;
        payment = loan / duration;
        for (int i = 0; i <= duration; i++) {
            if (i == depr[p + 1].month) p++;
            car *= (1.0 - depr[p].drop);
            if (loan < car) {
                if (i == 1) printf("1 month\n");
                else printf("%d months\n", i);
                break;
            }
            loan -= payment;
        }
    }
    return 0;
}