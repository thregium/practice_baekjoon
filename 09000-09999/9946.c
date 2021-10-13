#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : �ҹ��ڷ� �̷���� 1000�� ������ �� ���ڿ��� �־�����. ù ��° ���ڿ��� ��迭�ؼ�
�� ��° ���ڿ��� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ��� ������ �� ���ؼ� ���ٸ� ���� ���ڿ��� ���̰�, �ٸ��ٸ� �ٸ� ���ڿ��� ���̴�.

�ֿ� �˰��� : ����, ���ڿ�, ����

��ó : NCNA 2013 H��
*/

char s1[1024], s2[1024];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%s%s", s1, s2);
        if (!strcmp(s1, "END")) break;
        qsort(s1, strlen(s1), sizeof(char), cmp1);
        qsort(s2, strlen(s2), sizeof(char), cmp1);
        printf("Case %d: ", tt);
        if (strcmp(s1, s2)) printf("different\n");
        else printf("same\n");
    }
    return 0;
}