#include <stdio.h>

/*
���� : N(N <= 100)���� �ܼ�Ʈ�� K(K <= 100)���� ��Ƽ�ǿ� ������ �Ѵ�. ������ ĭ�� ���� �� ����,
��Ƽ�ǿ��� �ܼ�Ʈ�� ���� �� �ִٸ�, �� ��Ƽ���� �� ���� �־��� �� ��� �ܼ�Ʈ�� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ��Ƽ�ǿ� ���� �� �ִ� �ܼ�Ʈ�� ���� A(�� ��)�� ¦���� ��� A / 2���̰�, Ȧ���� ���
(A + 1) / 2���̴�. �̸� ���� K���� ��Ƽ�ǿ� ���� ���� ���ϸ� ��ü ���� �� �ִ� �ܼ�Ʈ�� ���̰�,
�� ���� N�� ���ؼ� N �̻��̸� ���� �� �ְ�, �̸��̸� ���� �� ������ �� �� �ִ�.

�ֿ� �˰����� : ����, ��Ģ����

��ó : ���ϴ� 2018 A��
*/

int main(void) {
    int n, k, a, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        r += ((a + 1) >> 1);
    }
    printf("%s", r >= n ? "YES" : "NO");
    return 0;
}