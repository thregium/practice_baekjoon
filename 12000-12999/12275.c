#include <stdio.h>
#include <string.h>

/*
���� : 100KB ������ ���ڿ��� �־��� ��, �ּ��� ������ �־��� ��Ĵ�� ���� ����� ����Ѵ�.

�ذ� ��� : �ּ��� ��ȣ�� �����ϰ� 0�ܰ� �ּ��� ������ ���ڵ鸸 ����ϸ� �ȴ�.
�̶�, 0�ܰ迡�� �ݴ� �ּ��� �����Կ� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : GKS 2013B B2��
*/

char s[103000], buff[103000];

int main(void) {
    int len, level = 0;
    while (fgets(buff, 102500, stdin)) {
        strcat(s, buff);
    }
    len = strlen(s);
    printf("Case #1:\n");
    for (int i = 0; i < len; i++) {
        if (s[i] == '/' && s[i + 1] == '*') {
            level++;
            i++;
            continue;
        }
        if (s[i] == '*' && s[i + 1] == '/' && level > 0) {
            level--;
            i++;
            continue;
        }
        if (level == 0) printf("%c", s[i]);
    }
    return 0;
}