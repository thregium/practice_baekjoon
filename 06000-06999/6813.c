#include <stdio.h>

/*
문제 : "WELCOME TO CCC GOOD LUCK TODAY"라는 문장을 각 줄의 길이(>= 7)가 주어질 때
문제에 주어진 양식대로 출력한다. 각 줄에는 최대한의 단어가 들어가되 공백으로 각 단어가 구분되면서
단어 단위로 줄에 들어가야 하며, 첫 단어는 맨 앞에, 첫 단어가 아닌 마지막 단어는 맨 뒤에 온다.
사이 공백은 균일하게 맞추되 나누어 떨어지지 않는 경우 앞쪽에 1개씩 더 많이 둔다.

해결 방법 : 각 줄에 들어갈 단어들을 미리 고른 다음 남는 칸 수를 센다. 그 후 남는 칸수에 맞게
공백을 배치하면서 출력하면 된다.

주요 알고리즘 : 구현, 문자열, 수학

출처 : CCC 2009J 4번
*/

const int wlen[6] = { 7, 2, 3, 4, 4, 5 };
const char* words[6] = { "WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY" };

int main(void) {
    int n, printed = 0, last = 0, rem = 0;
    scanf("%d", &n);
    while (printed < 6) {
        rem = n - wlen[printed++];
        while (printed < 6 && wlen[printed] + 1 <= rem) {
            rem -= wlen[printed] + 1;
            printed++;
        }
        if (printed == last + 1) {
            printf("%s", words[last]);
            for (int i = 0; i < rem; i++) printf(".");
            printf("\n");
            last = printed;
            continue;
        }

        for (int i = last; i < printed; i++) {
            printf("%s", words[i]);
            if (i == printed - 1) break;
            for (int j = -1; j < rem / (printed - last - 1); j++) printf(".");
            if (i - last < rem % (printed - last - 1)) printf(".");
        }
        printf("\n");
        last = printed;
    }
    return 0;
}