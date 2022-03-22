#include <stdio.h>
#include <string.h>

/*
���� : �� ���ĺ� �빮�ڸ��� �ٸ� 5�� ������ �빮�� ���ڿ��� �ٲٴ� ���谡 N(N <= 26)�� �־�����.
ó���� �빮�ڷ� �̷���� 30�� ������ ���ڿ��� �־��� ��, M(M <= 5)ȸ ���� ���ڿ��� ���Ѵ�.
���谡 �־����� ���� ��� �״�� �θ� �ȴ�.

�ذ� ��� : ������ �־������ �� ���ڸ��� �ٲ� ���ڿ����� ������ ����,
�� ���ڿ��� ���ڿ����� �߰��� ������ �ȴ�. ���� ���ڿ��� ��� ���ڸ� �ٲ� ���� �ٲ�� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �ùķ��̼�

��ó : VTH 2016 B��
*/

char buff[32], seq[26][32], res[103000], tmp[103000];

int main(void) {
    int n, m;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 26; i++) seq[i][0] = 'A' + i;
    for (int i = 0; i < n; i++) {
        scanf(" %c -> %s", &c, buff);
        strcpy(seq[c - 'A'], buff);
    }
    scanf("%s", res);
    for (int i = 0; i < m; i++) {
        for (int j = 0; res[j]; j++) {
            strcat(tmp, seq[res[j] - 'A']);
        }
        strcpy(res, tmp);
        tmp[0] = '\0';
    }
    printf("%s", res);
    return 0;
}