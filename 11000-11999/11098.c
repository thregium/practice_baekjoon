#include <stdio.h>
#include <string.h>

/*
���� : P(P <= 100)���� ���ݰ� �̸��� �־��� ��, ������ ���� ū ���� �̸��� ã�´�.

�ذ� ��� : ������ ���� ū ���� ���ݰ� �̸��� �����صΰ� �� ū���� ������ �װ͵��� ������Ʈ�Ѵ�.
�̸� �ݺ��ϸ� �������� ���� ū ���� �̸��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : IDI 2007 A��
*/

char buff[32], bestname[32];

int main(void) {
    int n, p, c, best;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        best = 0;
        for (int j = 0; j < p; j++) {
            scanf("%d %s", &c, buff);
            if (c > best) {
                best = c;
                strcpy(bestname, buff);
            }
        }
        printf("%s\n", bestname);
    }
    return 0;
}