#include <stdio.h>

/*
문제 : 문제에서 앨범들이 주어질 때, S년과 E년 사이 나온 앨범들과 발매 연도를 순서대로 출력한다.

해결 방법 : 앨범의 이름과 발매 연도를 오름차순으로 하드코딩하고 그 사이 있는 앨범들을 확인해서 출력하면 된다.

주요 알고리즘 : 구현, 전처리

출처 : CoderH 2016O B번
*/

char* album[] = { "DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory",
"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", "AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans",
"StationToStation", "Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight",
"NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar" };

int albumy[] = { 1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974, 1975, 1976, 1977, 1977, 1979, 1980,
1983, 1984, 1987, 1993, 1995, 1997, 1999, 2002, 2003, 2013, 2016 };

int main(void) {
    int q, s, e, r;
    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d", &s, &e);
        r = 0;
        for (int j = 0; j < 25; j++) {
            if (albumy[j] <= e && albumy[j] >= s) r++;
        }
        printf("%d\n", r);
        for (int i = 0; i < 25; i++) {
            if (albumy[i] <= e && albumy[i] >= s) {
                printf("%d %s\n", albumy[i], album[i]);
            }
        }
    }
    return 0;
}