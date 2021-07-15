#include <stdio.h>
#define MOD 987654321

/*
���� : N(N <= 10000, N�� ¦��)���� ������� ��Ź�� ���� ��, �� ����� �Ǽ��� �������� �ʰ� �ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : ��ȭ���� īŻ�� ���� �ȴ�. ����, �̿� �°� īŻ�� ���� �����ָ� �ȴ�.

�ֿ� �˰��� : ����, ���̳��� ���α׷���
*/

int mem[5120];

int main(void) {
    mem[0] = 1;
    mem[1] = 2;
    for (int i = 2; i <= 5000; i++) {
        mem[i] = (mem[i - 1] * 2) % MOD;
        for (int j = 1; j < i; j++) {
            mem[i] = (mem[i] + (long long)mem[j - 1] * mem[i - j - 1]) % MOD;
        }
    }
    int n;
    scanf("%d", &n);
    printf("%d", mem[(n >> 1) - 1]);
    return 0;
}