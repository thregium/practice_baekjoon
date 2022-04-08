#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 문자열을 RLE 형태로 인코딩한 문자열을 출력한다. 2에서 9 사이의 숫자를 이용하며,
1인 구간은 앞뒤에 1을 넣고 그 사이에는 숫자를 추가하지 않는다. 1이 쓰인다면 1을 2개 연속으로 쓴다.

해결 방법 : 현재 구간의 정보를 확인해 나가면서 문자열들을 만들어 나가면 된다. 조건이 복잡하므로 유의한다.

주요 알고리즘 : 구현, 문자열, 파싱

출처 : Ulm 2004 E번
*/

char s[103000];

int main(void) {
    int l, one;
    char c;
    //freopen("E:\\PS\\Contest\\Ulm\\2004\\encoding.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Ulm\\2004\\encoding _t.out", "w", stdout);
    while (fgets(s, 103000, stdin)) {
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        l = 0, c = '\0', one = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] != c || l == 9) {
                if (l == 1) {
                    if (one) printf("%c", c);
                    else printf("1%c", c);
                    if (c == '1') printf("1");
                    one = 1;
                }
                else {
                    if (one) printf("1");
                    if (c) printf("%d%c", l, c);
                    one = 0;
                }
                l = 1, c = s[i];
            }
            else l++;
        }
        if (l == 1) {
            if (one) printf("%c", c);
            else printf("1%c", c);
            if (c == '1') printf("1");
            one = 1;
        }
        else {
            if (one) printf("1");
            if (c) printf("%d%c", l, c);
            one = 0;
        }
        if (one) printf("1");
        printf("\n");
    }
    return 0;
}