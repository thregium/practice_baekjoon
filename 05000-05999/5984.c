#include <stdio.h>

/*
���� : N(N <= 250)���� ������� �������� �ɾ��ִ�. 1�� ������� �����ؼ� �ڽ��� ��ȣ��ŭ �ð�������� �̵��ϰ�
�װ��� �ɾ��ִ� ����� �ٽ� �ڽ��� ��ȣ��ŭ �̵��ϴ� ���� �ݺ��Ͽ� � �ڸ��� �ִ� ����� 2�� �̵��ؾ� �� �� ���� �ݺ��Ѵ�.
�̶�, 2�� �̵��ؾ� �ϴ� ����� �ڸ��� �� ������ ����� �������� ���Ѵ�.

�ذ� ��� : �� ����� �ִ� ��ġ�� ��ȣ�� ���� �ش� ��ġ���� ����� ����� ���� �� ��ȣ�� �ش� ��ȣ�� 2���� ���̴�.
���� �׷��� ���� ���ٸ� N��ŭ�� �� ��ȣ�� �ȴ�. �̸� ���� ������ ��ȣ�� ã�� �� �����Ƿ� �������� �̹� �̵��ߴ��� ���θ�
�����ϴ� �迭�� �����ؼ� �̹� �̵��� ����� ������ �� ������ ��� ��ȣ�� ����ϸ� ������.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : USACO 2011O B1��
*/

int vis[256];

int main(void) {
    int n, x = 1, y;
    scanf("%d", &n);
    while (1) {
        vis[x] = 1;
        y = (x * 2 - 1) % n + 1;
        if (vis[y]) {
            printf("%d", x);
            break;
        }
        else x = y;
    }
    return 0;
}