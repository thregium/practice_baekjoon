#include <stdio.h>

/*
���� : [L, R](1 <= L <= R <= 10^9)(R - L <= 10^6) ������ �ڿ����� ��� ���μ��� ������ �Ҽ�����
���� ������ ���Ѵ�. ���� ���μ��� ������ �������� ��� ������ ������ ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �����Ѵ�. �켱 i * i �̳��� �Ҽ����� �����佺�׳׽��� ü�� ���� ��,
�� �Ҽ����� ���� �Ǵ� ������ [L, R] �������� ã�Ƽ� ������ �ش� ���μ� ������ ã�Ƴ� �� �տ� ���Ѵ�.
�׸��� ���� 1�� ���� ���� ������ ���μ� ������ 1�� �÷��ְ� �� ���� ���μ� ������ �Ҽ����� �� Ȯ���Ѵ�.
������ �Ҽ��� ã�� �� 32(2^32�� 10^9���� ũ�Ƿ�) ������ �Ҽ����� �̸� ���صθ�
ü���� �ٷ� �Ҽ� ���θ� Ȯ�� �����ϹǷ� ����.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : JAG 2017P C��
*/

char sieve[1048576];
int pcnt[1048576], rem[1048576], prime[103000];
int pp = 0;

int main(void) {
    int st, ed;
    long long res = 0;
    scanf("%d %d", &st, &ed);
    for (int i = st; i <= ed; i++) rem[i - st] = i;
    sieve[0] = 1, sieve[1] = 1;
    for (long long i = 2; i * i <= ed || i <= 100; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (long long j = i * 2; j * j <= ed || j <= 100; j += i) sieve[j] = 1;
    }
    for (int i = 0; i < pp; i++) {
        for (int j = st / prime[i] * prime[i]; j <= ed; j += prime[i]) {
            if (j < st) continue;
            while (rem[j - st] % prime[i] == 0) {
                pcnt[j - st]++;
                rem[j - st] /= prime[i];
            }
        }
    }
    for (int i = st; i <= ed; i++) {
        if (rem[i - st] > 1) pcnt[i - st]++;
        res += (!sieve[pcnt[i - st]]);
    }
    printf("%lld\n", res);
    return 0;
}