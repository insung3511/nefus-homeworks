#include <stdio.h>

int main() {
    int people[9] = { 4, 6, 11, 12, 9, 10, 5, 5, 3 };
    int whereami = 0;

    // 현재 유저의 지하철 위치를 받음
    printf("본인의 칸을 입력해주세요 (0 ~ 9칸) >> ");
    scanf("%d", &whereami);

    // 현재 유저가 잘못된 칸을 입력을 하였을 경우,
    if (0 > whereami || whereami >= 10) {
        printf("ㅇ? 어디갔어요.\n");
    }

    else {
         // 현재 지하철의 전체적인 혼잡도를 보여줌
        printf("=================================================================\n");
        for (int i = 0; i < 9; i++) { 
            printf("%d\t", people[i]);
        }   printf("\n");
        printf("=================================================================\n");

        printf("현재 %d번째 값의 혼잡도 : ", whereami);
        if(0 <= people[whereami] && people[whereami] <= 5) {
            printf("여유\n");
        }

        else if(6 <= people[whereami] && people[whereami] <= 10) {
            printf("보통\n");
        }

        else {
            printf("혼잡\n");
        }
    }

    return 0;
}
