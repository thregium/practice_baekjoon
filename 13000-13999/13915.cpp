#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : N(N <= 1000)개의 9자 이하의 숫자로 이루어진 문자열이 주어질 때, 각 문자열에서 나오는 문자의 종류의 가짓수를 구한다.

해결 방법 : 셋에 문자열의 각 문자들을 넣고, 그 셋을 넣는 셋을 만들어서 넣으면, 바깥쪽 셋의 크기가 답이 된다.

주요 알고리즘 : 자료 구조, 셋

출처 : CTU 2016 B번
*/

char buff[1024];
set<set<int>> st;

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        st.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            set<int> stp;
            for (int j = 0; buff[j]; j++) {
                if (stp.find(buff[j] - '0') != stp.end()) continue;
                stp.insert(buff[j] - '0');
            }
            if (st.find(stp) != st.end()) continue;
            else st.insert(stp);
        }
        printf("%d\n", st.size());
    }
    return 0;
}