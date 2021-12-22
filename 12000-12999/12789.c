#include <stdio.h>

/*
���� : 1���� N(N <= 1000)������ �ڿ����� �̷���� ������ �־��� ��, �ϳ��� ���ø��� �̿��� �� ������ ������ �� �ִ��� ���Ѵ�.

�ذ� ��� : �־��� ������ ���� ���� ���;� �� ���� �ƴ϶�� ���ÿ� ���� �ִ´�. ���;� �� �����
�� ���� ������ ���;� �� ���� ���� ���� �ٲ۴�. �Ź� ���� �� �� ���� ������ �� ���� �ִ� ����
���� ���;� �� ����� �� ���� ���� ���� ���� �Ѿ�� ���� �ݺ��Ѵ�.

�� ������ N���� ���� ���� ������ �� ���ÿ� ���� �����ִٸ� ������ �� ���� ���̰�,
������ ����ٸ� ������ �Ϸ�� ���̴�.

�ֿ� �˰����� : �ڷ� ����, ����

��ó : ���ϴ� 2016 L��
*/

int stack[1024];
int top = 0;

int main(void) {
    int n, x, p = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == p) p++;
        else stack[top++] = x;
        while (top > 0 && stack[top - 1] == p) {
            stack[top--];
            p++;
        }
    }
    if (p > n) printf("Nice");
    else printf("Sad");
    return 0;
}