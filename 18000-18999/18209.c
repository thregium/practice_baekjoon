#include <stdio.h>
#include <ctype.h>

/*
문제 : 50만자 이하의 문자열이 주어질 때, 이 문자열을 해독한 문자열을 구한다.
'u'와 'm' 이외의 다른 영숫자가 없는 단어들을 골라 'u'와 'm'만 이어 붙인 후,
7자 단위로 잘라 'u'는 1, 'm'은 0으로 변환하고 이를 아스키 코드로 변환하여 출력하는 과정을 거친다.
변환 후 'u'와 'm'은 7 이상의 7의 배수의 개수만큼 있다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 문자열, 구현, 파싱

출처 : MidC 2019 L번
*/

char buff[524288], um[524288];

int main(void) {
    int m = 0, t;
    while (scanf("%s", buff) != EOF) {
        //if (buff[0] == '@') break;
        t = 1;
        for (int i = 0; buff[i]; i++) {
            if (islower(buff[i]) || isupper(buff[i]) || isdigit(buff[i])) {
                if (buff[i] == 'u' || buff[i] == 'm') continue;
                t = 0;
                break;
            }
        }
        if (!t) continue;
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == 'u' || buff[i] == 'm') um[m++] = buff[i];
        }
    }
    if (m % 7) return 1;
    for (int i = 0; i < m; i += 7) {
        t = 0;
        for (int j = 0; j < 7; j++) {
            if (um[i + j] == 'u') t += (1 << (6 - j));
        }
        printf("%c", t);
    }
    return 0;
}