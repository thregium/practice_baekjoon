#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 원소 기호들의 원자량들과 화학식들이 주어질 때, 화학식들의 화학식량을 각각 구한다.

해결 방법 : 재귀적인 방법으로 해결한다. 입력이 적기 때문에 원소기호는 미리 해싱해두는 것이 편하다.
없는 원소기호가 나올 때의 처리에 유의한다.

주요 알고리즘 : 문자열, 파싱, 재귀

출처 : Aizu 2003 E번
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