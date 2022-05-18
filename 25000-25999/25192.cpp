#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 100000)개의 문자열이 주어진다. "ENTER"가 주어진 후 각 문자열이 처음으로 등장한 횟수를 구한다.
첫 문자열은 반드시 "ENTER"이다.

해결 방법 : 입력받은 문자열이 "ENTER"인 경우 해시셋을 초기화하고, 그 외 경우에는 그 문자열이 해시셋에
있다면 넘어가고 없는 경우 결괏값에 1을 더한 후 해시셋에 그 문자열을 추가한다.
이를 반복한 후 결괏값을 출력하면 된다.

주요 알고리즘 : 자료 구조, 해시셋, 문자열

출처 : 곰곰컵 1회 B번
*/

unordered_set<string> st;
char buff[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "ENTER")) st.clear();
        else if (st.find(buff) == st.end()) {
            st.insert(buff);
            r++;
        }
    }
    printf("%d", r);
    return 0;
}