#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 10^6)개의 소문자(글자수 합 <= 10^6)로 이루어진 비행기 이름들이 주어진다.
원래 이름과 ROT13 관계인 이름의 비행기도 있어야만 유효한 이름이라 할 때, 서로 다른 유효한 이름의
개수를 구한다.

해결 방법 : 각 비행기의 이름을 입력받을 때 마다 입력받은 이름의 ROT13된 문자열이 해시셋에 있다면
그 쌍은 유효한 이름이 되므로 결괏값에 2를 추가한다. 단, 이미 그 이름도 해시셋에 있다면
중복되는 이름이므로 추가하지 않는다. 그 후 그 문자열을 해시셋에 더해나간다.
최종적으로 나오는 결괏값을 출력한다.

주요 알고리즘 : 문자열, 자료 구조, 해시셋

출처 : PA 2007 7-0번
*/

char buff[1048576];
unordered_set<string> u;

string rot13(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (s[i] - 'a' + 13) % 26 + 'a';
    }
    return s;
}

int main(void) {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (u.find(rot13(buff)) != u.end()) {
            if (u.find(buff) != u.end()) continue;
            else res += 2;
        }
        u.insert(buff);
    }
    printf("%d", res);
    return 0;
}