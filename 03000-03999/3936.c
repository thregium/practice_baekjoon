#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : ���� ��ȣ���� ���ڷ���� ȭ�нĵ��� �־��� ��, ȭ�нĵ��� ȭ�нķ��� ���� ���Ѵ�.

�ذ� ��� : ������� ������� �ذ��Ѵ�. �Է��� ���� ������ ���ұ�ȣ�� �̸� �ؽ��صδ� ���� ���ϴ�.
���� ���ұ�ȣ�� ���� ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���

��ó : Aizu 2003 E��
*/

char buff[128];
int awt[1024];

int parse(char* form, int st, int ed) {
    int res = 0, level = 0, llast = -1, inner;
    for (int i = st; i <= ed; i++) {
        if (form[i] == '(') {
            level++;
            if (level == 1) llast = i;
        }
        if (form[i] == ')') {
            level--;
            if (level == 0) {
                inner = parse(form, llast + 1, i - 1) * strtoll(form + i + 1, NULL, 10);
                if (inner < 0) return -1;
                else res += inner;
            }
        }
        if (level > 0) continue;
        if (isupper(form[i])) {
            if (islower(form[i + 1])) {
                if (awt[(form[i] - 'A' + 1) * 26 + (form[i + 1] - 'a')] == 0) return -1;
                if (isdigit(form[i + 2])) {
                    res += awt[(form[i] - 'A' + 1) * 26 + (form[i + 1] - 'a')] *
                        strtoll(form + i + 2, NULL, 10);
                }
                else res += awt[(form[i] - 'A' + 1) * 26 + (form[i + 1] - 'a')];
            }
            else if (isdigit(form[i + 1])) res += awt[form[i] - 'A'] * strtoll(form + i + 1, NULL, 10);
            else res += awt[form[i] - 'A'];
            if (!islower(form[i + 1]) && awt[form[i] - 'A'] == 0) return -1;
        }
    }
    return res;
}

int main(void) {
    int wt, res;
    for (int i = 0;; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "END_OF_FIRST_PART")) break;
        if (strlen(buff) > 2) return 1;
        scanf("%d", &wt);
        if (strlen(buff) == 1) awt[buff[0] - 'A'] = wt;
        else awt[(buff[0] - 'A' + 1) * 26 + (buff[1] - 'a')] = wt;
    }
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "0")) break;
        res = parse(buff, 0, strlen(buff) - 1);
        if (res < 0) printf("UNKNOWN\n");
        else printf("%d\n", res);
    }
    return 0;
}