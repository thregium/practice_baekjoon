#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 1000�� ������ ���ڿ��� �־��� ��, �빮�ڵ��� ��ȣȭ�Ͽ� ����Ѵ�. ��ȣȭ ����� ī�̻縣 ��ȣ�̸�,
�������� "LIVE"�� "CHIPMUNKS"�� ����ִ�. �빮�� �ܿ��� ���� �״�� ����Ѵ�.

�ذ� ��� : P���� 0���� 25���� �̵����Ѱ��� "CHIPMUNKS"�� "LIVE"�� ��� �����ϴ� ��츦 ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : NOIS 2007 3��
*/

char s[1024], ds[1024];

int main(void) {
    fgets(s, 1013, stdin);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; s[j]; j++) {
            if (isupper(s[j])) ds[j] = (s[j] - 'A' + i) % 26 + 'A';
            else ds[j] = s[j];
        }
        if (strstr(ds, "CHIPMUNKS") && strstr(ds, "LIVE")) {
            if (i == 0) return 2;
            printf("%s", ds);
            return 0;
        }
    }
    return 1;
}