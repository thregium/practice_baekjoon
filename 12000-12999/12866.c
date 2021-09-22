#include <stdio.h>
#define MOD 1000000007

/*
���� : ���� L(L <= 10^6)�� A, C, G, T�� �̷���� ���ڿ��� �־��� ��, A, C, G, T�� ���� ����� �������� ���Ѵ�.
�ٸ� ��ġ�� �ִ� ���� ���ڴ� �ٸ� ���̴�.

�ذ� ��� : A, C, G, T�� ������ ���� �� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���շ�
*/

char s[1048576];
long long cnt[4];

int main(void) {
    long long l, r;
    scanf("%lld", &l);
    scanf("%s", s);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'A') cnt[0]++;
        else if (s[i] == 'C') cnt[1]++;
        else if (s[i] == 'G') cnt[2]++;
        else cnt[3]++;
    }
    printf("%lld", cnt[0] * cnt[1] % MOD * cnt[2] % MOD * cnt[3] % MOD);
    return 0;
}