#include <stdio.h>
#include <stdlib.h>

/*
���� : �ڿ��� N(N <= 100000)�� �־��� ��, 1�� ���ϰų� ���ϰų� �̾���̴� ���길�� ����Ͽ�
N�� ���� ��, N�� ����� ���� �ʿ��� 1�� ������ �ּڰ��� ���Ѵ�. (���ѽð� 15��)
��, �̾���̴� ��� ���� ���� 0���� ������ �� ����.

�ذ� ��� : ���̳��� ���α׷����� ���� ���� ���� �� �ִ�. N�� 1�� ��� ���� 1�� �ϰ�,
�׺��� ū ���� ��쿡�� ���ϰų� ���ϰų� �̾���̴� ��� ��츦 �õ��� ����
���� ã�Ƴ�����. ���ѽð��� ��� ������ ���ϴ� ������ ���� �õ��غ��� ��� ����.
�̾���̴� ��� ���� ���� 0���� �������� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : DP

��ó : ECNA 2021 A��
*/

int mem[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int getres(int x) {
    if (mem[x]) return mem[x];
    else if (x == 1) return mem[x] = 1;
    else if (x < 1) exit(1);

    int res = 103000, flag = 0;
    for (int i = x / 10, j = x % 10, k = 10; i;) {
        if (j > 0 && !flag) res = small(res, getres(i) + getres(j));
        j += k * (i % 10);
        if (i % 10) flag = 0;
        else flag = 1;
        i /= 10;
        k *= 10;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = small(res, getres(i) + getres(x / i));
        }
    }
    for (int i = 1; i <= x - i; i++) {
        res = small(res, getres(i) + getres(x - i));
    }
    return mem[x] = res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", getres(n));
    return 0;
}