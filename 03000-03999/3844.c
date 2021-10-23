#include <stdio.h>
#define MOD 1000000007

/*
���� : N(N <= 10^7) ������ ���� �ٸ� �ڿ����� ������ �̷���� �� ��� ���� ū �������� 10^9+7�� ���� �������� ���Ѵ�.

�ذ� ��� : ���� N!�� ���μ����� �غ���. �� ���μ����� Ȧ���� �Ǵ� ¦���� ���� ���̴�.
¦���� ������ ���μ��� �Ű� �� �ʿ䰡 ����.(�̹� �������� ������ �����ϹǷ�) Ȧ���� ������ ���μ��� �ش� ���μ���
���� ���� ������ �ش� ���μ��� ���� Ƚ���� 1ȸ �پ��Ƿ� ¦�������� �ٰ�, ���� �������� ������ ������ �� �ְ� �ȴ�.

�׷���, 10^9+7�� ���� �������� ���� ���ķδ� ������ �������� ������Ű�� ���� �Ұ���������.
����, �� ���μ��� ���� �����佺�׳׽��� ü�� �̿��� ã�� ����, �� ���μ����� ���� Ƚ���� ���ϰ�,
���μ��� ���� �ش��ϴ� ���� Ƚ�� ��ŭ �ŵ������� ���� ���� ������ �̿��� �ŵ��������� ���ؼ� �ᱣ���� ���ϴ� ����
�ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, ���� �ŵ�����

��ó : SWERC 2011 J��
*/

char sieve[10485760];
int prime[1048576];
int pp = 0;

int sqrm(int a) {
    return (long long)a * a % MOD;
}

int mul(int n, int m) {
    //�ŵ����� ���ϱ�
    if (m == 0) return 1;
    else if (m & 1) return (long long)sqrm(mul(n, m >> 1)) * n % MOD;
    else return sqrm(mul(n, m >> 1));
}

int main(void) {
    int n, m, cnt, r;
    //freopen("E:\\PS\\ICPC\\Europe\\SWERC\\2011\\TestCasesAndSolutions-1\\J\\J.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\SWERC\\2011\\TestCasesAndSolutions-1\\J\\J_t.out", "w", stdout);
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i; //�Ҽ� ���ϱ�
        for (int j = i * 2; j <= 10000000; j += i) {
            sieve[j] = 1;
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < pp; i++) {
            if (n < prime[i]) break;
            cnt = 0;
            m = n;
            while (m) {
                cnt += m / prime[i]; //�� ���μ��� ���� Ƚ�� ���ϱ�
                m /= prime[i];
            }
            if (cnt & 1) cnt--;
            r = (long long)r * mul(prime[i], cnt) % MOD; //����� ����
        }
        printf("%d\n", r);
    }
    return 0;
}