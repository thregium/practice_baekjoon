#include <stdio.h>

/*
���� : ���� 30 ������ ���ĺ� �빮�ڿ� �������� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ������ ���Ѵ�.
���ڿ��� ������ ������ ������ �� ���ڵ鿡 A�� 1��, B�� 2�� .. Z�� 26������ ������ �ű�� ��� ������ ������ ���� ���̴�.
������ 100���� ��쿡�� ���� ��� PERFECT LIFE�� ����Ѵ�.

�ذ� ��� : �� ������ ������ c - 'A' + 1�� ���� �� �ִ�. ��, �̶� ������ ���� �̸� ������� �ʰ� �Ѿ�� �Ѵ�.
�̸� ��� ���ڿ� ���� ���ؼ� ������ ���� �� 100���̸� PERFECT LIFE�� ����ϰ�, �� �ܿ��� ������ ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, ���ڿ�
*/

char s[48];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 40, stdin);
        r = 0;
        for (int j = 0; s[j]; j++) {
            if (s[j] == ' ' || s[j] == '\n') continue;
            r += s[j] - 'A' + 1;
        }
        if (r == 100) printf("PERFECT LIFE\n");
        else printf("%d\n", r);
    }
    return 0;
}