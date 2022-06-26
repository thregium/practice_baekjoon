#include <stdio.h>

/*
���� : 1���� N(N <= 200000)���� ���� �ٸ� �ڿ������� M(M <= N)���� �������� �־�����.
�̶�, �� ������ �ڿ������� ������ �ϳ��� ������ 1���� N���� ���� ������ �� ���Ѵ�.

�ذ� ��� : �� ������ �������� ���� ����, �� ������ ��ġ�� ���� ��ȣ�� �Բ� �����Ѵ�.
�׸��� 1���� �� ������ ������ �� ������ ���ʷ� �� �ִ� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰����� : �ڷ� ����, ����?

��ó : ���� ��B C�� / ��E B��
*/

int book[204800][2], ht[204800];

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ht[i]);
        for (int j = 0; j < ht[i]; j++) {
            scanf("%d", &x);
            book[x][0] = i;
            book[x][1] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (book[i][1] != --ht[book[i][0]]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}