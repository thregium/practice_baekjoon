#include <stdio.h>
#include <string.h>

/*
���� : 8�ڸ� ������ ¦�� �ڸ� �� N�� �־��� ��, �� ���� ���� ���� �ڸ����� �հ� ���� ���� �ڸ����� ���� ������ Ȯ���Ѵ�.

�ذ� ��� : �ڸ����� Ȯ���ϰ� ���� �ڸ����� �հ� ���� �ڸ����� ���� ���� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����
*/

char n[16];

int main(void) {
    int l, sl = 0, sr = 0;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l / 2; i++) sl += n[i] - '0';
    for (int i = l / 2; i < l; i++) sr += n[i] - '0';
    if (sl == sr) printf("LUCKY");
    else printf("READY");
    return 0;
}