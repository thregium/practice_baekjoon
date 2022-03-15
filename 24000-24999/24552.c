#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100000 이하의 괄호로 이루어진 문자열이 주어질 때, 이 문자열에서 한 개의 괄호를 뒤집어
만들 수 있는 괄호 문자열의 개수를 구한다. 답은 1 이상이다.

해결 방법 : 답이 1 이상이므로 (와 )의 차이는 1이다. 우선 (이 많은 경우를 생각해 보면
괄호의 누적 값을 왼쪽부터 센 다음, 어떤 (를 지우고 그 이전과 이후에 음수가 나오지 않아야 한다.
그러기 위해서는 최솟값을 오른쪽부터 확인하면서 0보다 클 때의 (들 개수만 세면 된다.
)이 많은 경우는 문자열을 뒤집은 다음 똑같이 하면 된다.

주요 알고리즘 : 누적 합?

출처 : 신촌 2020 K번
*/

char s[103000];
int lv[103000];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int res = 0, lt = 0, rt = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') lt++;
        else rt++;
        lv[i] = lt - rt;
    }
    if (lt == rt + 1);
    else if (rt == lt + 1) {
        for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
            swap(&s[i], &s[j]);
        }
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        lt = 0, rt = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') lt++;
            else rt++;
            lv[i] = lt - rt;
        }
    }
    else return 1;

    for (int i = strlen(s) - 2; i >= 0; i--) {
        if (lv[i + 1] < lv[i]) lv[i] = lv[i + 1];
        if (lv[i] < 0) res = -103000;
    }
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' && lv[i] > 0) res++;
    }
    printf("%d", res < 0 ? 0 : res);
    return 0;
}