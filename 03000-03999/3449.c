#include <stdio.h>

/*
���� : �� ���̰� ���� ������ ���ڿ�(100�� ����)�� �־��� ��, ���� �ٸ� �ڸ��� ������ ���Ѵ�.

�ذ� ��� : ���ڿ��� ���ۺ��� ������ ���鼭 ���� �ٸ� �ڸ��� ������ ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : CERC 2007 PD��
*/

char s1[128], s2[128];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        scanf("%s%s", s1, s2);
        for (int i = 0; s1[i]; i++) {
            if (s1[i] != s2[i]) r++;
        }
        printf("Hamming distance is %d.\n", r);
    }
    return 0;
}