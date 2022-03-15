#include <stdio.h>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/*
문제 : 비어 있는 10^9개의 공간이 있을 때, N(N <= 10000)개의 쿼리에 응답한다.
W. 맨 앞에서부터 B개만큼의 빈 공간을 A에 할당한다.
D. A에 할당된 공간을 해제한다.
R. A번 위치에 할당된 것이 무엇인 지 구한다. 없다면 -1을 출력한다.
할당되는 가장 높은 번호의 공간은 10^9보다 작다.

해결 방법 : 맵과 이분 탐색을 이용한다. 맵 하나에는 구간의 시작점마다의 끝점과 할당된 번호를 저장하고,
다른 맵에는 번호마다의 시작점 목록을 저장한다.
공간을 할당할 때에는 0번부터 다음 위치로 이동을 반복하며 빈 공간들을 양쪽 맵에 추가해 나간다.
찾을 위치는 이분 탐색을 통해 확인하고, 빈 공간들의 남은 크기를 확인해가며 남은 것이 없을 때 까지 반복한다.
다음 찾을 칸은 현재 구간의 다음 구간이다. 또한, 빈 칸이 없다면 바로 다음 칸으로 넘어간다.
해제할 때에는 번호마다의 저장된 시작점 목록의 모든 값들을 다른 맵에서 삭제한다.
그리고 이 맵의 번호도 삭제한다.
할당을 확인할 때에는 역시 이분 탐색을 통해 위치를 찾아 범위에 맞는 지 확인하고,
범위에 맞는 경우만 그 번호를, 그 외에는 -1을 출력한다.

주요 알고리즘 : 자료 구조, 맵, 해시맵, 이분 탐색

출처 : JDC 2009 D번
*/

map<int, pair<int, int>> space; //st, ed, file
unordered_map<int, vector<int>> file;

int main(void) {
    int n, a, b, s;
    char o;
    pair<int, pair<int, int>> node;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2009D\\D\\D1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2009D\\D\\D1_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &o);
            if (o == 'W') {
                scanf("%d %d", &a, &b);
                s = 0;
                while (b > 0) {
                    if (space.lower_bound(s) == space.end()) {
                        space.insert({ s, {s + b - 1, a} });
                        if (file.find(a) != file.end()) file[a].push_back(s);
                        else file.insert({ a, {s} });
                        break;
                    }
                    node = *space.lower_bound(s);
                    if (node.first > s) {
                        if (node.first - s > b) {
                            space.insert({ s, {s + b - 1, a} });
                            b = 0;
                        }
                        else {
                            space.insert({ s, {node.first - 1, a} });
                            b -= node.first - s;
                        }
                        if (file.find(a) != file.end()) file[a].push_back(s);
                        else file.insert({ a, {s} });
                    }
                    s = node.second.first + 1;
                }
            }
            if (o == 'D') {
                scanf("%d", &a);
                for (int i : file[a]) {
                    space.erase(i);
                }
                file.erase(a);
            }
            if (o == 'R') {
                scanf("%d", &a);
                if (space.size() == 0) {
                    printf("-1\n");
                    continue;
                }
                if (space.upper_bound(a) != space.begin() &&
                    a <= (space.upper_bound(a).operator--())->second.first) {
                    printf("%d\n", (space.upper_bound(a).operator--())->second.second);
                }
                else printf("-1\n");
            }
        }
        printf("\n");
        space.clear();
        file.clear();
    }
    return 0;
}