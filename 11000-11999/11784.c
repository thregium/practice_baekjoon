#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� 250�� ������ 16������ �̷���� ���ڿ��� �� �ھ� ���� �ƽ�Ű �ڵ�� �ٲ� ���� ���ڷ� ���� ����Ѵ�.

�ذ� ��� : �� �ڸ��� ���ڿ��� ���� ����, strtoll �Լ��� �̿��Ͽ� ������ �ٲٰ� ������ ���� ���ڷ� �ٲٸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : Phuket 2015 A��
*/

char s[256], s2[4];

int main(void) {
    int x;
    while (scanf("%s", s) != EOF) {
        for (int i = 0; s[i]; i += 2) {
            s2[0] = s[i];
            s2[1] = s[i + 1];
            x = strtoll(s2, NULL, 16);
            printf("%c", (char)x);
        }
        printf("\n");
    }
    return 0;
}