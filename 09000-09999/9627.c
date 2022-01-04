#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 20)개의 단어가 주어지고 이 단어들 사이 $인 단어에 1000 이하의 자연수를 나타내는 단어를 집어넣어
넣은 단어와 전체 알파벳 개수가 같은 문장을 찾는다. 답이 있는 경우만 주어진다.
답이 여러 개인 경우 가장 작은 수를 넣은 것을 출력한다.

해결 방법 : 1부터 1000까지의 모든 수를 하나씩 집어넣으며 답이 맞는 경우를 출력하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : COCI 13/14#3 3번
*/

char* ut[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
char* teen[] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char* tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

char wd[32][64];

int main(void) {
    int n, l = -1, tmp = 0;
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest3_testdata\\recenice\\recenice.in.10", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", wd[i]);
        l += strlen(wd[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(wd[i], "$")) {
            for (int j = 1; j <= 999; j++) {
                wd[i][0] = '\0';
                if (j >= 100) {
                    strcat(wd[i], ut[j / 100]);
                    strcat(wd[i], "hundred");
                }
                if (j % 100 >= 20) strcat(wd[i], tens[j / 10 % 10]);
                if (j % 100 < 20 && j % 100 >= 11) strcat(wd[i], teen[j % 100 - 10]);
                else if (j % 100 >= 20 && j % 10 > 0) strcat(wd[i], ut[j % 10]);
                else if (j % 100 <= 10 && j % 100 > 0) strcat(wd[i], ut[j % 100]);

                if (l + strlen(wd[i]) == j) {
                    tmp = 1;
                    break;
                }
            }
        }
    }
    if (tmp == 0) return 1;

    for (int i = 0; i < n; i++) {
        printf("%s ", wd[i]);
    }
    return 0;
}