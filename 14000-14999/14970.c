#include <stdio.h>
#include <string.h>

/*
문제 : 두 길이 200 이하의 알파벳 대소문자, 숫자, '.', '"', ';'로 이루어진 문자열이 주어진다.
이때, 두 문자열이 동일한지 유사한지 다른지 검사한다.
동일한 경우는 모든 글자가 같은 경우이고, 유사한 경우는 한 리터럴만 다른 경우이다. 리터럴은 "으로 홀수 번 싸여진 구간이다.

해결 방법 : 먼저 동일한지 여부는 strcmp 함수로 간단히 알 수 있다. 유사한 경우는 먼저 strtok을 사용하기 위해
문자열을 1개씩 떨어뜨린다. 그리고 strtok을 사용하여 각 " 사이에 있는 문자열들을 각각 나누어 둔다.
만약 문자열의 개수가 다르다면("의 개수가 다르다면) 서로 다른 것이다.
같다면 본격적으로 문자열들을 하나씩 확인한다. 만약 홀수번째("의 밖에 있는) 문자열이
서로 다르다면 이는 다른 문자열인 것이다. 짝수번째("의 안에 있는)문자열은 리터럴이므로
정확히 1개만 다르다면 유사한 문자열, 2개 이상 다르다면 다른 문자열이다. 같지 않은 문자열이 모두 같을 수는 없다.

주요 알고리즘 : 문자열, 파싱

출처 : JDC 2017 B번
*/

char s1[256], s2[256], s1_1[512], s2_1[512], stk1[256][512], stk2[256][512];

int main(void) {
    int w1, w2, cnt;
    char* c;
    while (1) {
        scanf("%s", s1);
        if (!strcmp(s1, ".")) break;
        scanf("%s", s2);
        if (!strcmp(s1, s2)) {
            printf("IDENTICAL\n");
            continue;
        }
        for (int i = 0; i < 250; i++) {
            s1_1[i * 2] = ' ';
            s2_1[i * 2] = ' ';
            s1_1[i * 2 + 1] = s1[i];
            s2_1[i * 2 + 1] = s2[i];
        }

        cnt = 0, w1 = 0, w2 = 0;
        c = strtok(s1_1, "\"");
        while (c) {
            strcpy(stk1[w1++], c);
            c = strtok(NULL, "\"");
        }
        c = strtok(s2_1, "\"");
        while (c) {
            strcpy(stk2[w2++], c);
            c = strtok(NULL, "\"");
        }
        if (w1 != w2) {
            printf("DIFFERENT\n");
            continue;
        }

        for (int i = 0; i < w1; i++) {
            if (strcmp(stk1[i], stk2[i])) {
                if (i & 1) {
                    if (cnt >= 0) cnt++;
                }
                else cnt = -1;
            }
        }

        if (cnt == 0) return 1;
        else if (cnt == 1) printf("CLOSE\n");
        else printf("DIFFERENT\n");
    }
    return 0;
}