#include <stdio.h>

/*
���� : ���� N(N <= 100)�� ���ڿ��� ���� 1000 ������ ���ڿ� M(M <= 1000)���� �־��� ��, �� ���ڿ��� �κ� ������
���� N�� �ش� ���ڿ��� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ���ʺ��� ������ ���ڿ��� ���ڸ� ���ϴٰ� N ���ڿ��� ���ڰ� ������ ���� ���ڸ� �������� �ѱ��.
���ڿ��� ������ ���� ��, N ���ڿ��� ������ Ȯ���ߴٸ� �κ� ������ ���̰�, ���ߴٸ� �κ� ������ �ƴ� ���̴�.

�ֿ� �˰����� : �׸��� �˰�����, ���ڿ�

��ó : ���ϴ� 2018 G��
*/

char o[128], p[1024];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    scanf("%s", o);
    for (int i = 0; i < m; i++) {
        t = 0;
        scanf("%s", p);
        for (int j = 0; p[j]; j++) {
            if (p[j] == o[t]) t++;
        }
        printf("%s\n", t == n ? "true" : "false");
    }
    return 0;
}