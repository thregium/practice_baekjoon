#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10000 이하의 대문자로 이루어진 문자열이 줄마다 주어진다. 각 줄마다 첫 글자부터 (해당 줄의 번호)개 문자만큼
띄어가며 읽은 결과를 출력한다.

해결 방법 : 반복문을 이용해 각 줄의 번호를 세고, 각 줄에서는 첫 글자에서 줄 번호 + 1칸씩 문자열 끝까지 띄어 가며 읽으면 된다.

주요 알고리즘 : 구현

출처 : 한양대E 2019Z H번
*/

char s[10240];

int main(void) {
    int l;
    for (int i = 2;; i++) {
        scanf("%s", s);
        if (s[1] == 'a') break;
        l = strlen(s);
        for (int j = 0; j < l; j += i) {
            printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}