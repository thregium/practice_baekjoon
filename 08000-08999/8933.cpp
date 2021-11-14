#include <stdio.h>
#include <map>
#include <tuple>
using namespace std;

/*
문제 : 길이 60000 이하의 DNA 문자열과 자연수 K(K <= 600)가 주어질 때, 연속한 K개의 문자열에 대해
구성이 같은 수를 묶었을 때 가장 큰 집합의 크기를 구한다.

해결 방법 : 맵에 4가지 문자의 개수를 키값으로 하고 개수를 값으로 하여 각 문자 구성에 대한 개수를 구해나간다.
처음에는 K개 문자에 대해 합을 구하고, 그 뒤로는 문자를 추가하고 K개 전의 문자를 1개씩 빼내면서
각 문자의 개수를 센다. 문자의 개수를 셀 때 마다 맵에 값을 넣거나 값을 업데이트한다.
모든 문자를 확인했으면 각 집합을 찾아서 크기가 가장 큰 것을 구하면 된다.

주요 알고리즘 : 자료 구조, 맵, 슬라이딩 윈도우

출처 : Seoul 2008 B번
*/

char w[65536];
int cnt[4];
map<tuple<int, int, int, int>, int> mp;

int main(void) {
    int t, k, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %s", &k, w);
        for (int i = 0; i < k; i++) {
            if (w[i] == 'A') cnt[0]++;
            else if (w[i] == 'C') cnt[1]++;
            else if (w[i] == 'G') cnt[2]++;
            else cnt[3]++;
        }
        mp.insert(pair<tuple<int, int, int, int>, int>(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]), 1));
        for (int i = k; w[i]; i++) {
            if (w[i] == 'A') cnt[0]++;
            else if (w[i] == 'C') cnt[1]++;
            else if (w[i] == 'G') cnt[2]++;
            else cnt[3]++;
            if (w[i - k] == 'A') cnt[0]--;
            else if (w[i - k] == 'C') cnt[1]--;
            else if (w[i - k] == 'G') cnt[2]--;
            else cnt[3]--;
            if (mp.find(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3])) != mp.end()) {
                (mp.find(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]))->second)++;
            }
            else {
                mp.insert(pair<tuple<int, int, int, int>, int>(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]), 1));
            }
        }
        r = -1;
        for (auto i : mp) {
            if (i.second > r) r = i.second;
        }
        printf("%d\n", r);

        for (int i = 0; i < 4; i++) cnt[i] = 0;
        mp.clear();
    }
    return 0;
}