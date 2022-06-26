#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : N(N <= 50)���� �빮�ڷ� �̷���� ���ڿ�(<= 100��)��� �빮�ڷ� �̷���� ���ڿ��� �־��� ��,
�ٸ� �־��� ���ڿ��� ����� ���� �������� �־��� ���ڿ��� ���� ���ڰ� �� �� �ִ� ������ ����� ����Ѵ�.

�ذ� ��� : �� ���ڿ����� Ȯ���ϸ鼭 ������ ���ڿ��� ���λ��� ��� ���� ���ڸ� ��Ͽ� �߰��Ѵ�.
�׸��� ����� ��Ŀ� �°� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : COCI 16/17#4 2��
*/

char s[64][128], t[128];
char res[64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%s", t);
    for (int i = 0; i < 32; i++) res[i] = '*';
    for (int i = 0; i < n; i++) {
        if (strstr(s[i], t) == s[i] && isupper(s[i][strlen(t)])) {
            res[s[i][strlen(t)] - 'A' + 3] = s[i][strlen(t)];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", res[i * 8 + j]);
        }
        printf("\n");
    }
    return 0;
}