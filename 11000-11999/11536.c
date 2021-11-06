#include <stdio.h>
#include <string.h>

/*
���� : N(2 <= N <= 20)���� �빮�ڷ� �̷���� ���� 12 ������ ���ڿ��� �־��� ��, �� ���ڿ��� �����ϴ� ��������
�����ϴ� �������� �� �� �ƴ��� ���Ѵ�. ���ڿ��� �ߺ����� �ʴ´�.

�ذ� ��� : ���ڿ��� ���� �Է¹��� ���� strcmp�Լ��� �̿��� (2��° ������) �� ���ڿ��� ���� ���ڿ��� ����
ū�� ������ Ȯ���Ѵ�. �� ũ�ٸ�(���������� ��) �����ϴ� ���� �ƴϰ�, �� �۴ٸ�(���������� ��) �����ϴ� ���� �ƴϴ�.
������� �� ū�� �� ������ �� �� �ƴ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : MidC 2015 F��
*/

char s[32][32];

int main(void) {
    int n, ic = 1, dc = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i < n; i++) {
        if (strcmp(s[i], s[i - 1]) < 0) ic = 0;
        else if (strcmp(s[i], s[i - 1]) > 0) dc = 0;
        else return 1;
    }
    if (dc && ic) return 2;
    if (ic) printf("INCREASING");
    else if (dc) printf("DECREASING");
    else printf("NEITHER");
    return 0;
}