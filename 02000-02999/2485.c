#include <stdio.h>
#include <stdlib.h>

/*
���� : N(3 <= N <= 100000)���� �ڿ���(<= 10^9)�� �־��� ��, �� �ڿ������� ������ ��� ���� ����� ����
�߰��ؾ� �ϴ� ���� ������ ���Ѵ�.

�ذ� ��� : ������ �� ������ ������ ������ �ִ������� ��� ���� ���� �� �ִ� �ּ� �����̴�.
����, �ִ������� ���� ���� �ִ��������� ���̰� ũ�ٸ� �ִ������� ���� �� - 1���� �ᱣ���� �߰��ϴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ����

��ó : ���� 2010�� ��2��
*/

int tre[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, g, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tre[i]);
    }
    qsort(tre, n, sizeof(int), cmp1);
    g = tre[1] - tre[0];
    for (int i = 2; i < n; i++) {
        g = gcd(g, tre[i] - tre[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        r += (tre[i] - tre[i - 1]) / g - 1;
    }
    printf("%d", r);
    return 0;
}