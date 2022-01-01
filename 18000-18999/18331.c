#include <stdio.h>

/*
���� : N(N <= 30)�ϰ��� Oshloob�� ����(1000 <=, <= 2000, �ڿ���)�� �־��� ��, ���� ������ C(0 <= C <= 3000, ����)��
Oshloob�� ��� �� ������ �ִ� �������� ���Ѵ�. ������� ����.

�ذ� ��� : ���� ���� ������ ��� �ִ��� Oshloob�� ���, ������ ��� �ִ��� �Ĵ� ���� �ݺ��ϸ� �ȴ�.
������ ������ ���� Oshloob�� ��� �ȵ��� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : Tehran 2019 B��
*/

int s[64];

int main(void) {
    int n;
    long long w, c = 0;
    scanf("%lld %d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] < s[i + 1]) {
            c += w / s[i];
            w -= w / s[i] * s[i];
        }
        else {
            w += c * s[i];
            c = 0;
        }
    }
    printf("%lld", w);
    return 0;
}