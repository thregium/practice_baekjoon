#include <stdio.h>
#include <ctype.h>

/*
���� : ���� ǥ������� ǥ��� 100�� ������ ���� �־��� ��, �� ���� ����� ����� ���Ѵ�.
��, �� ���� ��� ���� ������ �־�����, �߰��� ���� ����� ��� 2^31���� ������ 0���� ������ ���� ����.

�ذ� ��� : ������ �̿��Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ����

��ó : ���ϴ� 2018 G��
*/

char s[128];
int stack[128];
int top = 0;

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            stack[top++] = s[i] - '0';
        }
        else {
            if (top < 2) return 1;
            if (s[i] == '+') stack[top - 2] = stack[top - 2] + stack[top - 1];
            else if (s[i] == '-') stack[top - 2] = stack[top - 2] - stack[top - 1];
            else if (s[i] == '*') stack[top - 2] = stack[top - 2] * stack[top - 1];
            else if (s[i] == '/') stack[top - 2] = stack[top - 2] / stack[top - 1];
            else return 2;
            top--;
        }
    }
    if (top != 1) return 3;
    printf("%d", stack[0]);
    return 0;
}