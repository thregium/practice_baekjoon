#include <stdio.h>

/*
문제 : "CHICKENS"로 시작하는 100자 이하의 문자열을 특정한 키를 이용해 XOR한 문자열이 주어진다. 이때, 원래 문자열을 구한다.
단, 원래 문자열과 XOR한 문자열은 모두 출력할 수 있는 경우만 주어진다.

해결 방법 : 원래 수와 특정한 값을 XOR한 결괏값을 안다면 결괏값에서 원래 수를 XOR하면 특정한 값을 알 수 있다.
따라서, 첫 글자를 통해 키값을 알아낼 수 있고, 알아낸 키값을 통해 원래 문자열을 구하면 된다.

주요 알고리즘 : 수학, 문자열

출처 : 경찰대 2019 C번
*/

char s[128];

int main(void) {
    char k = '\0';
    scanf("%s", s);
    k = s[0] ^ 'C';
    for (int i = 0; s[i]; i++) {
        printf("%c", s[i] ^ k);
    }
    return 0;
}