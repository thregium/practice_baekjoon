#include <stdio.h>
#include <string.h>

/*
���� : ���� L(L <= 10^6)�� ��ȣ�� �̷���� ���ڿ��� �־����� �� ���ڿ��� ����� �Ǿ��� �� Ȯ���ϰ�,
����� �� ��� �ְ� ��ȣ ���̸� ���Ѵ�.

�ذ� ��� ; ������ �̿��� ��ȣ�� �˻��ϸ鼭 �ְ� top ���̸� ã�´�.
��ȣ�� ����� �Ǿ��ٸ� �ְ� ���̸�, �ƴ϶�� NIE�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ����

��ó : JPOI 2010 1-2��
*/

char p[1048576], stack[1048576];
int top = 0;

int main(void) {
    int l, r1 = 1, r2 = 0;
    scanf("%d", &l);
    scanf("%s", p);
    top = 0;
    for (int j = 0; j < l; j++) {
        if (p[j] == '(' || p[j] == '[' || p[j] == '{') {
            stack[top] = p[j];
            top++;
            if (top > r2) r2 = top;
        }
        else if (p[j] == ')' || p[j] == ']' || p[j] == '}') {
            if (top <= 0) {
                r1 = 0;
                break;
            }
            if ((p[j] == ')' && stack[top - 1] != '(') || (p[j] == ']' && stack[top - 1] != '[')
                || (p[j] == '}' && stack[top - 1] != '{')) {
                r1 = 0;
                break;
            }
            else top--;
        }
    }
    if (top) r1 = 0;
    if (!r1) printf("NIE");
    else printf("%d", r2);
    return 0;
}