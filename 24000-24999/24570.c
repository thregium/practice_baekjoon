#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : ������ �־��� ������ ���ڿ��� �־��� ��, ���ڿ����� ��¿� �ʿ��� ���·� ��ȯ�Ͽ� ����Ѵ�.

�ذ� ��� : ������ �־������ ���ڿ��� ��ȯ�Ѵ�. �Ľ� �������� �� ��� ���ڿ��� ���� �� �����Ͽ�
����ϵ��� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : CCC 2022 J3��
*/

char s[1024], inst[64];

int main(void) {
    int st = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) inst[i - st] = s[i];
        else {
            inst[i - st] = '\0';
            printf("%s %s %lld\n", inst, s[i] == '+' ? "tighten" : "loosen", strtoll(&s[i + 1], NULL, 10));
            i++;
            while (isdigit(s[i])) i++;
            st = i;
            i--;
        }
    }
    return 0;
}