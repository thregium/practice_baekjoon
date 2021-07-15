#include <stdio.h>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 40)���� ���� ��� ���� M(M <= 10^18) ������ ������ ���� ���Ѵ�. �� ���� 10^16 �����̰�,
�����յ� �������� ����.

�ذ� ��� : N���� ���� �� �κ����� ������ ù ��° ������ ��� �κ����� ���� ���� �����Ѵ�.
�� ��° ���տ����� ��� �κ��տ� ���� ù ��° ������ �κ����� M - (2��° ������ �κ���) ������ ���� ������
�̺� Ž���� ���� ���� �� �ְ�, �� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �̺� Ž��, �� �� �� �̵�

��ó : CEOI 2015 4��
*/

long long ticket[64], msum[1280000];

int main(void) {
    long long n, m, s, r = 0, t;
    scanf("%lld %lld", &n, &m);
    s = (n >> 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ticket[i]);
    }
    for (int i = 0; i < (1 << s); i++) {
        for (int j = 0; j < s; j++) {
            if (i & (1 << j)) msum[i] += ticket[j];
        }
    }
    sort(msum, msum + (1 << s));
    for (int i = 0; i < (1 << (n - s)); i++) {
        t = 0;
        for (int j = 0; j < n - s; j++) {
            if (i & (1 << j)) t += ticket[j + s];
        }
        r += upper_bound(msum, msum + (1 << s), m - t) - msum;
    }
    printf("%lld", r);
    return 0;
}