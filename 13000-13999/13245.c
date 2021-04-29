#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 10^16)�� �־����� ��, 1���� N���� ��� �ڸ����� ���� ���Ѵ�;.

�ذ� ��� : �� �� �ڸ����� ������� ���Ѵ�. �ش��ϴ� �ڸ��� ��ü ������ �� �� �������� Ȯ���� ��,
�ڸ����� ���� Ƚ��, 10^���� ��ġ�� ���� ���� ���Ѵ�. �׸���, ������ �ڸ��� �ƴ� ���, �ڿ� ���� �� �ִ� �ڸ����� ����
�ش��ϴ� �ڸ����� �����ش�. �̸� �ݺ��� ���� ���� �� �ִ�.

�ֿ� �˰����� : ����

��ó : AIPO 2016F 6��
*/

char n[32];
long long d10[32];

int main(void) {
    long long l = 0, t = 0, r = 0;
    scanf("%s", n);
    l = strlen(n);
    d10[0] = 1;
    for (int i = 1; i <= 18; i++) d10[i] = d10[i - 1] * 10; //10�� �ŵ������� �̸� ������ ���´�.
    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= 9; j++) {
            if (atoll(&n[i]) < d10[l - i - 1] * j) break; //�ش��ϴ� �ڸ����� ���ϰ��� �ϴ� ������ ���� ��� �Ѿ��.
            if (atoll(&n[i]) >= d10[l - i - 1] * (j + 1)) r += d10[l - i - 1] * j; //�ش��ϴ� �ڸ����� �� ū ��� 10^��ġ * �ڸ����� ���ؼ� ���Ѵ�.
            else r += (atoll(&n[i]) - (d10[l - i - 1] * j) + 1) * j; //���� ��� �ش��ϴ� ����ŭ�� �ڸ����� ���ؼ� ���Ѵ�.
        }
        if (i < l - 1) r += (45 * (l - i - 1) * d10[l - i - 2]) * (n[i] - '0'); //�ش��ϴ� ������ 1�ڸ� ���� ���� ���� ��� ���� ���Ѵ�. �� : 2000�� ��� 1 ~ 999 ���� 2�� �����ش�.
    }
    printf("%lld", r);
    return 0;
}