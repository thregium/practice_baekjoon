#include <stdio.h>

/*
���� : 8�ڸ� �� 3���� �־��� ��, 3�� ������ ���� ���� �ڸ� ���� ���� ���� ���ӵ� ������ ���̸� ���Ѵ�.

�ذ� ��� : �� ������ ���ڿ��� �Է¹��� ���� ���� ���� �� ���ӱ����� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ���� 2009�� ��1/��1��
*/

char s[16];

int main(void) {
    int cnt = 0, longest = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%s", s);
        cnt = 1;
        longest = 1;
        for (int j = 1; j < 8; j++) {
            if (s[j] == s[j - 1]) {
                cnt++;
                if (cnt > longest) longest = cnt;
            }
            else cnt = 1;
        }
        printf("%d\n", longest);
    }
    return 0;
}