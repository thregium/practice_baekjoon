#include <stdio.h>
#include <string.h>

/*
���� : ���� 100 ������ �� ��� ���°� �־��� ��, �� ��ϸ� �¹����� �ϸ鼭 ��ģ ���� ���̸�
�ּ������� �ϴ� ��� �� ���̸� ���Ѵ�.

�ذ� ��� : �� ��ϸ� ���������� �¹����� ��� ��� ���� ª�� ��츦 ���ϸ� �ȴ�.
��� ��츦 ���� �� �ְ� �� �������� ������ ������ �ʵ��� �����ؾ� �Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : NEERC 2006 K��
*/

char s1[128], s2[128];

int main(void) {
    int l1, l2, best = 103000, lt, rt, good;
    scanf("%s%s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (int offset = -l2; offset <= l1; offset++) {
        lt = 103000, rt = -103000;
        for (int i = 0; i < l1; i++) {
            if (i < lt) lt = i;
            if (i > rt) rt = i;
        }
        good = 1;
        for (int i = offset; i < offset + l2; i++) {
            if (i >= 0 && i < l1) {
                if (s1[i] == s2[i - offset] && s1[i] == '2') good = 0;
            }
            if (i < lt) lt = i;
            if (i > rt) rt = i;
        }
        if (!good) continue;
        if (rt - lt + 1 < best) best = rt - lt + 1;
    }
    printf("%d", best);
    return 0;
}