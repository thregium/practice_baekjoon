#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� �빮�ڷ� �̷���� ���ڿ��� �־��� ��, ������ �����ϴ� "HONI" �κ� ������ �ִ� ������ ���Ѵ�.

�ذ� ��� : �տ������� H, O, N, I�� �ݺ��ϸ� ã���� �ȴ�. ó�� ������ ���� �߰��ϴ� ���� ������ �̵��̴�.
���ڿ��� ������ ã�� HONI�� ������ ����Ѵ�.

�ֿ� �˰����� : �׸��� �˰�����, ���ڿ�

��ó : COCI 18/19#3 1��
*/

char s[103000];
char* honi = "HONI";

int main(void) {
    int p = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == honi[p & 3]) p++;
    }
    printf("%d", p >> 2);
    return 0;
}