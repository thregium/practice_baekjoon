#include <stdio.h>
#include <string.h>

/*
���� : ���� 10000 ������ �빮�ڷ� �̷���� ���ڿ��� �ٸ��� �־�����. �� �ٸ��� ù ���ں��� (�ش� ���� ��ȣ)�� ���ڸ�ŭ
���� ���� ����� ����Ѵ�.

�ذ� ��� : �ݺ����� �̿��� �� ���� ��ȣ�� ����, �� �ٿ����� ù ���ڿ��� �� ��ȣ + 1ĭ�� ���ڿ� ������ ��� ���� ������ �ȴ�.

�ֿ� �˰����� : ����

��ó : �Ѿ��E 2019Z H��
*/

char s[10240];

int main(void) {
    int l;
    for (int i = 2;; i++) {
        scanf("%s", s);
        if (s[1] == 'a') break;
        l = strlen(s);
        for (int j = 0; j < l; j += i) {
            printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}