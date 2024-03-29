#include <stdio.h>
#define INF 1012345678

/*
문제 : N(0 <= N <= 50)권의 책이 있고, 용량이 M(<= 1000)인 박스가 주어지면, 책을 순서대로 담을 때 필요한 박스의 수를 구한다.
책의 무게는 M 이하의 자연수이다.

해결 방법 : 현재 박스에 담긴 책의 무게와 지금까지 담은 박스의 개수를 저장하며 값을 구해나간다.
매번 현재 책을 담으면 박스가 넘치는지 살피고 넘친다면 새 박스를 들여놓는 방식이다.
시작할 때에는 책 0개에 대응하기 위해 박스의 수를 0, 담은 용량을 무한대로 초기화해야 한다.

주요 알고리즘 : 구현, 그리디 알고리즘
*/

int book[64];

int main(void) {
    int n, m, r = 0, u = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &book[i]);
        if (u + book[i] > m) {
            r++;
            u = 0;
        }
        u += book[i];
    }
    printf("%d", r);
    return 0;
}