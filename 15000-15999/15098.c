#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 80�� ������ ���ڿ�(�빮��, ����)�� �־��� ��, �� ���ڿ��� �ܾ� ��� ���� �ܾ �ִ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ��� �ܾ� ������ �ڸ� ����, �ܾ���� �����ϰ�, ������ �ܾ� ��� ���� ���� �ִ��� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : MidC 2017 D��
*/

char buff[128], word[128][128];

int main(void) {
    int wc = 0, r = 1;
    char* c;
    fgets(buff, 100, stdin);
    buff[strlen(buff) - 1] = '\0';
    c = strtok(buff, " ");
    while (c) {
        strcpy(word[wc], c);
        wc++;
        c = strtok(NULL, " ");
    }
    qsort(word, wc, sizeof(char) * 128, strcmp);
    for (int i = 1; i < wc; i++) {
        if (!strcmp(word[i], word[i - 1])) r = 0;
    }
    printf("%s", r ? "yes" : "no");
    return 0;
}