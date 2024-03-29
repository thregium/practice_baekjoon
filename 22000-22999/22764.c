#include <stdio.h>

/*
문제 : 휴대전화 문자판을 누른 순서가 주어질 때, 화면에 출력되는 문자열을 출력한다.
모든 문자는 확인 버튼을 눌러야 출력된다. 또한, 같은 문자판을 계속 누르면 앞에서부터 같은 문자가 반복된다.
아무것도 누르지 않고 확인 버튼을 누르면 아무것도 나오지 않는다. 문자판은 최대 1000번만 누른다.

해결 방법 : 각 문자판을 누를 때 마다 출력되는 문자들을 미리 저장해둔 다음, 문자판을 누를 때 마다
해당 문자판과 연속해서 누른 횟수를 갱신해 나간다. 그러다가 0을 누르면 이전에 누른 문자판이 0이 아닌 경우
그 문자의 그 누른 횟수에 해당하는 문자를 출력한다. 이를 반복해 나가면 된다.

주요 알고리즘 : 구현, 문자열

출처 : JDC 2005 A번
*/

char s[1024];
char* but[] = { "", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
int bcnt[] = { 0, 5, 3, 3, 3, 3, 3, 4, 3, 4 };

int main(void) {
    int n, cnt, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        cnt = 0;
        b = -1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == '0') {
                if (b > 0) printf("%c", but[b][(cnt - 1) % bcnt[b]]);
                b = 0;
            }
            else {
                if (b == s[j] - '0') cnt++;
                else {
                    b = s[j] - '0';
                    cnt = 1;
                }
            }
        }
        printf("\n");
    }
    return 0;
}