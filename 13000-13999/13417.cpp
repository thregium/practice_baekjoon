#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : N(N <= 1000)개의 문자를 첫 번째 문자부터 보며 문자열의 앞 또는 뒤에 붙여가면 만들 수 있는 문자열 가운데
가장 사전순으로 빠른 것을 구한다.

해결 방법 : 문자들을 덱에 저장하며 맨 앞의 글자와 같거나 또는 그보다 사전순으로 빠른 글자가 오면 덱의 맨 앞에 넣고,
그 외에는 맨 뒤에 넣는다. 이를 반복한 후 덱의 내용을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 덱

출처 : 국민대 2016 E번
*/

deque<char> dq;

int main(void) {
    int t, n;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &c);
            if (dq.empty() || dq.front() >= c) dq.push_front(c);
            else dq.push_back(c);
        }
        for (char i : dq) {
            printf("%c", i);
        }
        printf("\n");
        dq.clear();
    }
    return 0;
}