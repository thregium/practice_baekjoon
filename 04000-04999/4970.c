#include <stdio.h>
#include <string.h>

/*
���� : ���� 80 ������ ������ �־��� ��, P, Q, R ������ 0���� 2������ ���� �����Ͽ�
������ ���� 2�� �ǰ� ����� ����� �������� ���Ѵ�. �׻� ����� �� ���ĸ� �־�����.

�ذ� ��� : P, Q, R�� �������� �� �� �ִ� �ĺ��� �ִ� 27���� �Ұ��ϹǷ� ��� ��츦 �õ��غ���.
�� ������ ����� ġȯ�� �� ���� 2�� �Ǵ� ���� ���� ���ϸ� �ȴ�.
�� ������ ���� ������ ��������� ���鼭 ������ ���� ���س�����.
���� 0���� �����̳� ������ �־����� ��� ������ ��ȣ�� ���ְ� ������ �� �Ǵ� ���� ����,
�׷��� ���� ���ٸ� ������ ������ �� ���� ������ ���� Ȯ���Ѵ�.
����� ������ ��� �� ����� ���� ��ȯ�Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���Ʈ ����, ���

��ó : JDC 2008 C��
*/

char orig[128], s[128];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int getres(int st, int ed) {
    int lv = 0, cnt = 0;
    if (st == ed) return s[st] - '0';
    for (int i = st; i <= ed; i++) {
        if (s[i] == '(') lv++;
        else if (s[i] == ')') lv--;

        if (s[i] == '+' && lv == 0) {
            return big(getres(st + (s[st] == '('), i - 1 - (s[i - 1] == ')')),
                getres(i + 1 + (s[i + 1] == '('), ed - (s[ed] == ')')));
        }
        else if (s[i] == '*' && lv == 0) {
            return small(getres(st + (s[st] == '('), i - 1 - (s[i - 1] == ')')),
                getres(i + 1 + (s[i + 1] == '('), ed - (s[ed] == ')')));
        }
    }
    for (int i = st; i <= ed; i++) {
        if (s[i] == '-') cnt++;
        else {
            if (cnt & 1) return 2 - (getres(i + (s[i] == '('), ed - (s[i] == ')')));
            else return getres(i + (s[i] == '('), ed - (s[i] == ')'));
        }
    }
    return 0;
}

int main(void) {
    int l, r;
    while (1) {
        scanf("%s", orig);
        if (!strcmp(orig, ".")) break;
        l = strlen(orig);
        r = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    strcpy(s, orig);
                    for (int ii = 0; ii < l; ii++) {
                        if (s[ii] == 'P') s[ii] = i + '0';
                        else if (s[ii] == 'Q') s[ii] = j + '0';
                        else if (s[ii] == 'R') s[ii] = k + '0';
                    }
                    if (getres(0 + (s[0] == '('), l - 1 - (s[l - 1] == ')')) == 2) r++;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}