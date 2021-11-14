#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� �׸��� �������� 90�� ȸ����Ų �׸��� ����Ѵ�. 90�� ������ ���� �Է°� �����
������ �־������ �Ѵ�. ������ �־��� ���ڵ鸸 �Է����� ���´�.

�ذ� ��� : �� ĭ�� �����ϴ� ���ڵ��� Ȯ���ϰ�, ����ؾ� �ϴ� �� ĭ���� �� ���ڿ� �����ϴ� ���ڸ� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : UCPC 2019�� B��
*/

char s[128][128];
const char* before = ".O-|/\\^<v>";
const char* after = ".O|-\\/<v>^";

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t = 1;
            for (int k = 0; k < 10; k++) {
                if (s[j][m - i - 1] == before[k]) {
                    printf("%c", after[k]);
                    t = 0;
                }
            }
            if (t) return 1;
        }
        printf("\n");
    }
    return 0;
}