#include <stdio.h>

/*
���� : 0���� N - 1(N <= 10)������ ������ �̷���� ������ ����(<= 50)�� �־�����.
�ڱ� M(M <= 50)���� ���� �� �ִ� ���� ū ���� ���Ѵ�. ��, ���� 0�� �ƴ϶�� 0���� �����ؼ��� �� �ȴ�.
�ϳ� �̻��� ���ڸ� �� �� �ִ� ��츸 �־�����.

�ذ� ��� : ���� ���� �� ���� ��� ���� ū ���� �ִ��� �缭 ���� �� ���� ���� ä���д�.
�̶�, �� ���ڰ� 0�� ��쿡�� �� ��°�� �� ���ڸ� ã�Ƽ� ù ���ڷ� ���� �������� 0���� ä���.
ù ���ڸ� ���� �� ���ٸ� ���� 0�� �ȴ�.
�ڸ������� ä���ٸ� ���ڸ����� �ٲ� �� �ִ� ���� ū ���ڷ� �ٲپ� ���� ���� ���س����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : SRM 311 D2B
*/

int price[16];
char res[64];

int main(void) {
    int n, m, best, bnz;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    scanf("%d", &m);

    best = n - 1, bnz = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] < price[best]) best = i;
    }
    for (int i = n - 2; i > 0; i--) {
        if (price[i] < price[bnz]) bnz = i;
    }

    if (best == 0) {
        if (m < price[0]) return 1;
        if (m < price[bnz]) {
            printf("0");
            return 0;
        }
        else {
            m -= price[bnz];
            res[0] = bnz + '0';
            for (int i = 1; m >= price[0]; i++) {
                m -= price[0];
                res[i] = '0';
            }
        }
    }
    else {
        for (int i = 0; m >= price[best]; i++) {
            m -= price[best];
            res[i] = best + '0';
        }
    }

    for (int i = 0; res[i]; i++) {
        for (int j = n - 1; j > res[i] - '0'; j--) {
            if (m >= price[j] - price[res[i] - '0']) {
                m -= price[j] - price[res[i] - '0'];
                res[i] = j + '0';
                break;
            }
        }
    }
    printf("%s", res);
    return 0;
}