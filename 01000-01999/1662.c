#include <stdio.h>
#include <string.h>

/*
���� : 50�� ������ ���ڿ� ��ȣ�� �̷���� ���ڿ��� �־��� ��, �ش� ���ڿ��� ������ Ǯ�� ��� ���� �������� ���Ѵ�.
�߸� ����� ���� ������ ���� �־����� �ʴ´�.

�ذ� ��� : ��������� ���� ���Ѵ�. ���� ���� ���ڰ� '('�� ��� �ش� ��ȣ�� ������ ���������� ã�Ƴ� ����,
�ش� ������ �ش� ������ ���� ���� ���� �信 ���Ѵ�. �� ���� ����(����)�� ������ �ᱣ���� 1�� ���Ѵ�.

�ֿ� �˰��� : ����, ���
*/

char s[64];

int getres(int st, int ed) {
    int r = 0, p = 0, schk, num;
    for (int i = st; i <= ed; i++) {
        if (s[i + 1] == '(') {
            p = 1;
            num = s[i] - '0';
            i++;
            schk = i + 1;
            while (p) {
                i++;
                if (s[i] == '(') p++;
                else if (s[i] == ')') p--;
            }
            r += num * getres(schk, i - 1);
        }
        else r++;
    }
    return r;
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    printf("%d", getres(0, l - 1));
    return 0;
}