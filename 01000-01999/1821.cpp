#include <stdio.h>
#include <algorithm>
using namespace std;

/*
���� : ���� N(N <= 10)�� ������ ���� ���� ��, ����� F(F <= 10^6)�� ���� ��� ���� ������
���� ���� ������ ã�´�.

�ذ� ��� : N�� �۱� ������ ��� ������ ���� N�� ������ ���� �õ��غ��鼭 ó�� ������ ���� F��
������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

long long a[16], b[16][16];

long long getres(int n) {
    for (int i = 0; i < n; i++) b[0][i] = a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) b[i][j] = b[i - 1][j] + b[i - 1][j + 1];
    }
    return b[n - 1][0];
}

int main(void) {
    int n;
    long long f;
    scanf("%d %lld", &n, &f);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    while (1) {
        if (getres(n) == f) {
            for (int i = 0; i < n; i++) printf("%lld ", a[i]);
            return 0;
        }
        next_permutation(a, a + n);
    }
    return 1;
}