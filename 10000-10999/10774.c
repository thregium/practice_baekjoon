#include <stdio.h>

/*
���� : N(N <= 10^6)���� ������ A(A = 10^6)���� ������ �ִ�. �� ������ ��ȣ���� �� ���� �ְ�,
�������� �ڽ��� ���ϴ� ��ȣ�� ����� �ִ�. �ڽ��� ��ȣ�� �����鼭 �ڽ��� ������ �̻��� ������ �� ������ ���� ��,
������ ���� �� �ִ� �������� �ִ��� ����Ѵ�.

�ذ� ��� : �� ��ȣ���� �ּ� ����� ���� ����� ã�´�. �� ����, �� �����鸶���� ����� ���ϸ�
�� ������� �´� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : 

��ó : CCC 2015S 2��
*/

int js[1048576], best[1048576];

int main(void) {
    int n, a, x, r = 0;
    char c;
    scanf("%d%d", &n, &a);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &js[i]);
        if (js[i] == 'L') js[i] = 3;
        else if (js[i] == 'M') js[i] = 2;
        else if (js[i] == 'S') js[i] = 1;
        else return 1;
    }
    for (int i = 0; i < a; i++) {
        scanf(" %c %d", &c, &x);
        if (x <= 0 || x > n) continue;
        if (c == 'L' && (best[x] > 3 || best[x] == 0)) best[x] = 3;
        else if (c == 'M' && (best[x] > 2 || best[x] == 0)) best[x] = 2;
        else if (c == 'S' && (best[x] > 1 || best[x] == 0)) best[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (best[i] > 0 && best[i] <= js[i]) r++;
    }
    printf("%d", r);
    return 0;
}