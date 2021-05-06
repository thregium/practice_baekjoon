#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 주어진 길이 100 이하의 문자열에서 문자 하나를 삭제하거나, 주어진 문자 중 하나를 더하거나 문자열의 문자 중 하나를 주어진 문자로 바꾸는 것이 가능하다.
이 모든 경우의 수 중 원래 문자열과 다른 것을 중복 없이 사전순으로 출력한다.

해결 방법 : 먼저, 원래 문자열의 각 글자 중 하나를 고르고 그 글자를 뺀 것과 다른 글자로 바꾼 것들을 목록에 집어넣는다.
중복인지는 일단 신경쓰지 않는다. 그 다음, 각 글자 사이 위치를 고르고, 글자를 삽입한 것들도 목록에 집어넣는다.
모든 목록의 길이는 100개의 문자열에서 하나를 삭제하거나(100), 하나를 바꾸거나(100 * 26), 하나를 더하거나((100 + 1) * 26) 증 하나이므로
최대 약 6000개 정도로 만들면 된다. 이후 모든 문자열들을 사전순으로 정렬한 뒤 출력하되, 현재 문자열이 원래 문자열이거나
이전 문자열이 현재 문자열과 같다면 출력하지 않으면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : PacNW 2019 V번 // SEUSA 2019D2 I번 // SEUSA 2019D1 H번
*/

char use[128], s[128], ans[16384][128];
int ap = 0;

int main(void) {
    scanf("%s%s", use, s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = 0; use[j]; j++) {
            strcpy(ans[ap], s);
            ans[ap][i] = use[j];
            ap++;
        }
        for (int j = 0; j < len - 1; j++) {
            if (j >= i) ans[ap][j] = s[j + 1];
            else ans[ap][j] = s[j];
        }
        ap++;
    }
    for (int i = 0; i <= len; i++) {
        for (int j = 0; use[j]; j++) {
            for (int k = 0; k < i; k++) {
                ans[ap][k] = s[k];
            }
            ans[ap][i] = use[j];
            for (int k = i; k < len; k++) {
                ans[ap][k + 1] = s[k];
            }
            ap++;
        }
    }
    qsort(ans, ap, sizeof(char) * 128, strcmp);
    for (int i = 0; i < ap; i++) {
        if (i > 0 && !strcmp(ans[i], ans[i - 1])) continue;
        if (!strcmp(ans[i], s)) continue;
        printf("%s\n", ans[i]);
    }
    return 0;
}