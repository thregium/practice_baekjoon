#include <stdio.h>

/*
문제 : A장의 카드 가운데 B장의 폭탄이 있다. 폭탄이 아닌 카드를 뽑을 때 까지 카드를 뽑아야 하고,
폭탄을 뽑으면 체력이 5 감소한다. 체력 C(A, B, C <= 30)가 주어질 때, HP가 0 이하가 되지 않고 카드 뽑기를 멈출 확률을 구한다.
단, 폭탄이 아닌 카드는 최소 1개는 존재한다.

해결 방법 : 매번 폭탄을 뽑을 확률과 폭탄이 아닌 것을 뽑을 확률을 재귀적으로 구하여 확률을 구한다.
폭탄이 없는 경우 확률은 그 상황의 확률과 같고, 체력이 0 이하가 되었을 때의 확률은 0임을 이용한다.

주요 알고리즘 : 수학, 확률론, 재귀

출처 : KAIST 2020F B번
*/

double getres(int a, int b, int c, double p) {
    if (c <= 0) return 0.0;
    if (b == 0) return p;
    else return p * ((double)a - b) / a + getres(a - 1, b - 1, c - 5, p * b / (double)a);
}

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.9f", getres(a, b, c, 1.0));
    return 0;
}