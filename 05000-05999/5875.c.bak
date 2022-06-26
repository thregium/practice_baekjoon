#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 길이 N(N <= 100000)의 '('와 ')'로 이루어진 문자열이 주어질 때, 한 글자를 바꾸어
괄호 문자열이 되는 경우의 수를 구한다. 괄호 문자열은 모든 '('와 ')'를 짝지을 수 있는 문자열이다.

해결 방법 : 처음부터 끝까지 여는 괄호와 닫는 괄호의 수를 먼저 세 준다.
여는 괄호와 닫는 괄호의 수 차이가 2가 아니라면 한 글자를 바꾸었을 때 괄호의 개수를 맞출 수 없으므로 경우의 수는 0이다.

여는 괄호가 더 많다면 여는 괄호 가운데 하나를 닫는 괄호로 바꾸면 괄호 문자열이 될 수도 있다.
그 조건으로는 해당 문자 또는 그 이전에 괄호 문자열이 깨지거나 이후로 닫는 괄호가 2개 이상 많아지는 경우가 아니면 된다.
이를 찾기 위해서는 여는 괄호와 닫는 괄호의 개수 차이를 세 준 다음,
왼쪽부터의 최솟값과 오른쪽부터의 최솟값을 미리 누적 합과 비슷한 방식으로 계산해둔다.
그 다음에는 모든 '('에 대해서 왼쪽부터의 최솟값이 0 이상이며 오른쪽부터의 최솟값이 2 이상인 지점의 개수를 세 주면
여는 괄호가 2개 더 많을 때의 답이 된다.

닫는 괄호가 더 많은 경우에는 닫는 괄호 하나를 여는 괄호로 바꾸면 된다.
이때는 해당 문자에서 닫는 괄호가 1개 더 많다고 해도 여는 괄호로 바꾸면 괄호 문자열이 될 수도 있음에 유의한다.
그 외에는 그 왼쪽 문자까지의 왼쪽부터의 최솟값이 0 이상이고 다음 문자부터 오른쪽부터의 최솟값이 -2 이상인 지점의
개수를 세 주면 닫는 괄호가 2개 더 많을 때의 답이 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2012N B2번
*/

char s[103000];
int left[103000], sml[103000], smr[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("typo.in", "r");
        fo = fopen("typo.out", "w");
    }
    int l, r = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == '(') left[i] = (i ? left[i - 1] : 0) + 1;
        else left[i] = (i ? left[i - 1] : 0) - 1;

        if (i == 0) sml[i] = left[i];
        else if (left[i] < sml[i - 1]) sml[i] = left[i];
        else sml[i] = sml[i - 1];
    }
    smr[l - 1] = left[l - 1];
    for (int i = l - 2; i >= 0; i--) {
        if (left[i] < smr[i + 1]) smr[i] = left[i];
        else smr[i] = smr[i + 1];
    }
    if (left[l - 1] == -2) {
        for (int i = l - 1; i >= 0; i--) {
            if (s[i] == ')' && sml[i] >= -1 && smr[i] >= -2) r++;
        }
        printf("%d", r);
    }
    else if (left[l - 1] == 2) {
        for (int i = 0; i < l; i++) {
            if (s[i] == '(' && sml[i] >= 0 && smr[i] >= 2) r++;
        }
        printf("%d", r);
    }
    //else if (left[l - 1] == 0 && smr[0] == 0) printf("%d", 1);
    else printf("%d", 0);
    return 0;
}