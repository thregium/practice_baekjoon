#include <stdio.h>
#include <ctype.h>

/*
문제 : 100자 이하의 문자열이 주어질 때, 이 문자열을 자모음별로 ROT13한 결과를 출력한다. 단, 자모음 순서는 문제에 주어진대로
원래 자모음과는 다른 순서이다. 자음을 3칸씩 돌리고 모음을 10칸씩 돌려야 하며, 대소문자는 유지되어야 한다.
그 외 문자는 그대로 출력한다.

해결 방법 : 문자열을 입력 받고 문자열에서 각 문자를 살핀다. 대문자가 나오면 체크해두고, 대문자와 소문자가 모두 아닌
다른 문자가 나오면 그 문자를 출력하고 다음 문자를 본다. 그 다음으로는 자음인지 모음인지 확인하고,
등장 위치에서 해당 길이만큼 돌린 문자를 출력한다. 출력할 때 대문자 여부를 체크해 두었으므로 그를 이용해 대소문자를 유지한다.
문자열로 여러 줄이 들어올 수 있다는 점에 주의한다.

주요 알고리즘 : 구현, 문자열

출처 : PacNW 2012 L번
*/

char* vow = "aiyeou";
char* con = "bkxznhdcwgpvjqtsrlmf";
char s[128];

int main(void) {
    int u = -1;
    while (fgets(s, 120, stdin)) {
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) u = 1;
            else if (islower(s[i])) u = 0;
            else {
                printf("%c", s[i]);
                continue;
            }
            s[i] = tolower(s[i]);
            for (int j = 0; j < 6; j++) {
                if (vow[j] == s[i]) printf("%c", u ? toupper(vow[(j + 3) % 6]) : vow[(j + 3) % 6]);
            }
            for (int j = 0; j < 20; j++) {
                if (con[j] == s[i]) printf("%c", u ? toupper(con[(j + 10) % 20]) : con[(j + 10) % 20]);
            }
        }
    }
    return 0;
}