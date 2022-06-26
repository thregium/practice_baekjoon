#include <stdio.h>

/*
문제 : 길이 100 이하의 대문자로 이루어진 두 문자열이 주어질 때, 커서가 맨 오른쪽에 있는 상태에서
첫 문자열을 두 번째 문자열로 바꾸기 위해 눌러야 하는 최소 키 횟수를 구한다.

해결 방법 : 가장 오른쪽의 서로 다른 문자까지는 이동해야 하고 그 문자를 지우거나 임의의 문자를 추가하는 데
1회에 키를 누를 수 있으므로 가장 오른쪽의 서로 다른 문자까지 이동했다가 돌아오는 사이에 있는
문자의 개수가 답이 된다.

주요 알고리즘 : 문자열, 그리디 알고리즘

출처 : KTH 2022 A번
*/

char s1[128], s2[128];

int main(void) {
    int same = 0, res = 0;
    scanf("%s%s", s1, s2);
    for (same = 0; s1[same] == s2[same] && s1[same]; same++);
    for (int i = same; s1[i]; i++) res++;
    for (int i = same; s2[i]; i++) res++;
    printf("%d", res);
    return 0;
}