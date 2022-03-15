#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ��ʸ�Ʈ�� ������ ���ڿ� ���·� �־��� ��, �� ���� �¸� Ƚ���� �־��� ���¿� ���� �� ���� �� ���Ѵ�.

�ذ� ��� : ��������� �� ���� ���и� ���糪�� ���� �¸� Ƚ���� ���� �� Ȯ���ϸ� �ȴ�.
�¸� ���� ���� �¸� Ƚ���� ���� ������ �Ѵ�. ������ ���ٸ� (�翬�� ������ ������ �� ������)
�ƹ� ���̳� �¸���Ű���� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���, �׸��� �˰���

��ó : JAG 2017P B��
*/

int win[26];
char s[1024];

int tour(int st, int ed) {
    int lt = -1, rt = -1, dep = 0;
    if (st == ed) return s[st] - 'a';
    if (s[st] == '[') st++;
    if (s[ed] == ']') ed--;
    for (int i = st; i <= ed; i++) {
        if (s[i] == '[') dep++;
        else if (s[i] == ']') dep--;
        else if (dep == 0 && s[i] == '-') {
            lt = tour(st, i - 1);
            rt = tour(i + 1, ed);
        }
    }

    if (win[lt] >= win[rt]) {
        win[lt]--;
        return lt;
    }
    else {
        win[rt]--;
        return rt;
    }
}

int main(void) {
    int a = 0, w, r = 1;
    char c;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) a++;
    }
    for (int i = 0; i < a; i++) {
        scanf(" %c %d", &c, &w);
        win[c - 'a'] = w;
    }

    tour(0, strlen(s) - 1);
    for (int i = 0; i < 26; i++) {
        if (win[i]) r = 0;
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}