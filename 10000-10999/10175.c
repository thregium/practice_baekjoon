#include <stdio.h>

/*
문제 : 문자열로 각 종들의 분포가 주어질 때, 우점종을 찾는다. 각 종들은 특정한 비중을 갖고, 비중 * 개체수가 해당 개체의 점유율이다.

해결 방법 : 문자열의 각 문자마다 어떤 종인지 찾은 다음, 모든 개체의 점유율을 계산한다.
그 다음 가장 점유율이 높은 종을 찾아서 구하면 된다.

주요 알고리즘 : 구현

출처 : PLU 2014N 6번
*/

char loc[128], spe[128];

int main(void) {
    int n, b, c, m, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", loc, spe);
        b = 0, c = 0, m = 0, w = 0;
        for (int j = 0; spe[j]; j++) {
            if (spe[j] == 'B') b += 2;
            else if (spe[j] == 'C') c++;
            else if (spe[j] == 'M') m += 4;
            else if (spe[j] == 'W') w += 3;
            else return 1;
        }
        printf("%s: ", loc);
        if (b > c && b > m && b > w) printf("The Bobcat is the dominant species\n");
        else if (c > b && c > m && c > w) printf("The Coyote is the dominant species\n");
        else if (m > b && m > c && m > w) printf("The Mountain Lion is the dominant species\n");
        else if (w > b && w > c && w > m) printf("The Wolf is the dominant species\n");
        else printf("There is no dominant species\n");
    }
    return 0;
}