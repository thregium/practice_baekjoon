#include <stdio.h>
#include <string.h>

/*
���� : �� �ٿ� �ҹ��ڿ� �������� �̷���� ���ڿ�(100�� ����)�� �־��� ��, �� ���ڿ����� ù �ܾ "god"�� �ٲٰ�
������ ���ڿ��� ���ʷ� ���� ���ڿ��� ����Ѵ�.

�ذ� ��� : strtok() �Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : UCPC 2016 E��
*/

char s[128], res[128];

int main(void) {
    int n;
    char* c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        c = strtok(s, " ");
        strcpy(res, "god");
        while (c) {
            c = strtok(NULL, " ");
            if (c == NULL) break;
            strcat(res, c);
        }
        printf("%s\n", res);
    }
    return 0;
}