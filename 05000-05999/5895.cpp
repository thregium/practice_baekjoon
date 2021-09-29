#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : 길이 N(N <= 100000)의 F, L, R로 이루어진 문자열이 주어진다. 문자 F는 앞쪽으로 1만큼 이동, L은 왼쪽으로 90도 이동,
R은 오른쪽으로 90도 이동이라 할 때, 원래 문자열에서 한 글자를 바꾸어 도달 가능한 모든 위치의 가짓수를 구한다.

해결 방법 : 앞쪽부터 i개의 명령을 수행했을 때 (0, 0)에서 출발해서 도착하는 위치를 먼저 구한다. 그 다음으로,
뒤쪽부터 i개의 명령을 앞쪽부터 차례로 수행했을 때의 결과도 마찬가지로 저장해둔다.
그러면 각 위치에서 방향을 바꾸었을 때 도달하는 위치를 바로 구할 수 있다. 따라서 이제 N개의 모든 문자에 대해서
각 문자를 다른 문자로 바꾸어 보며 도달하는 위치들을 맵에 저장한다.
각 문자를 바꾸었을 때 도달하는 위치는 해당 위치 전까지의 누적 합 + 해당 위치를 바꾼 명령을 수행한 후 +
(해당 위치 이후의 누적 합을 해당 위치의 방향으로 돌린 것)과 같다.
모든 문자에 대해 바꾸어본 다음 맵의 크기를 구하면 위치의 가짓수와 같으므로 답이 된다.

주요 알고리즘 : 기하학, 누적 합, 맵

출처 : USACO 2012M B3번
*/

const char* flr = "FLR";
char trac[103000]; //원래 문자열
int lsum[103000][3], rsum[103000][2]; //앞쪽 누적합(x, y, 방향), 오른쪽 누적합(x, y)
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //각 방향 별 이동 좌표
set<pair<int, int>> res; //도달하는 위치 저장

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_03\\wrongdir\\10.in", "r", stdin);
    int l = 0, x = 0, y = 0, d = 0, t; //l : 전체 길이, x, y : 좌표, d : 현재 방향
    scanf("%s", trac);
    //앞쪽 누적합
    for (int i = 0; trac[i]; i++) {
        lsum[i][0] = x;
        lsum[i][1] = y;
        lsum[i][2] = d;
        if (trac[i] == 'F') {
            x += dxy[d][0];
            y += dxy[d][1];
        }
        else if (trac[i] == 'R') d = ((d + 1) & 3);
        else d = ((d + 3) & 3);
        l++;
    }
    lsum[l][0] = x;
    lsum[l][1] = y;
    lsum[l][2] = d;

    //뒤쪽 누적합
    d = 0, x = 0, y = 0;
    for (int i = l; i > 0; i--) {
        rsum[i][0] = x;
        rsum[i][1] = y;
        if (trac[i - 1] == 'F') {
            x += dxy[d][0];
            y += dxy[d][1];
        }
        else if (trac[i - 1] == 'R') {
            //d = ((d + 1) & 3); 오른쪽 회전 (이후의 값들을 돌릴 뿐 현재 방향은 바뀌지 않는다)
            t = y;
            y = -x;
            x = t;
        }
        else {
            //d = ((d + 3) & 3); 왼쪽 회전 (오른쪽 회전과 마찬가지)
            t = x;
            x = -y;
            y = t;
        }
    }
    rsum[0][0] = x;
    rsum[0][1] = y;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 3; j++) {
            if (trac[i] == flr[j]) continue;
            d = lsum[i][2];
            x = lsum[i][0];
            y = lsum[i][1];
            if (j == 0) {
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else if (j == 1) d = ((d + 3) & 3); //왼쪽 회전
            else d = ((d + 1) & 3); //오른쪽 회전

            //이후의 누적합을 한번에 계산해 추가한다
            if (d == 0) {
                //직진
                x += rsum[i + 1][0];
                y += rsum[i + 1][1];
            }
            else if (d == 1) {
                //오른쪽 90도
                x += rsum[i + 1][1];
                y -= rsum[i + 1][0];
            }
            else if (d == 2) {
                //180도
                x -= rsum[i + 1][0];
                y -= rsum[i + 1][1];
            }
            else {
                //왼쪽 90도
                x -= rsum[i + 1][1];
                y += rsum[i + 1][0];
            }

            if (res.find(pair<int, int>(x, y)) == res.end()) {
                //아직 없는 도착지가 나오면 맵에 저장한다
                res.insert(pair<int, int>(x, y));
            }
        }
    }
    printf("%d", res.size()); //맵의 크기가 답이 된다.
    return 0;
}