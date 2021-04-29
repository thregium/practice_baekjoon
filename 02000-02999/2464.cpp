#include <stdio.h>
#include <algorithm>
using namespace std;

/*
���� : �ڿ��� N(N <= 10^18)�� �־����� ��, �������� ��Ÿ���� �� N�� 1�� ������ ���� �� ��� N���� ũ�� ���� ���� ���� ������ ���� ū ���� ã�´�.
�׷��� ���� ���� ��� 0�� ����Ѵ�.

�ذ� ��� : �������� ��Ÿ���� �� N�� 1�� ������ ���ٴ� ���� N�� �������� ǥ���� ���� ������ �� �� N�� ���� �����̶�� �� �� �ִ�.
����, next_permutation�̳� prev_permutation �Լ��� �̿��� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���շ�

��ó : ���� 2011���� ��2��
*/

long long ab[64];

int main(void) {
    long long a, t, x = 0, y = 0;
    scanf("%lld", &a);
    for (int i = 0; i < 64; i++) {
        ab[63 - i] = ((a >> i) & 1);
    }
    t = prev_permutation(ab, ab + 64);
    for (int i = 0; i < 64; i++) {
        x += (ab[63 - i] << i);
    }
    if (!t) x = 0;
    next_permutation(ab, ab + 64);
    t = next_permutation(ab, ab + 64);
    for (int i = 0; i < 64; i++) {
        y += (ab[63 - i] << i);
    }
    if (!t) y = 0;

    printf("%lld %lld", x, y);
    return 0;
}