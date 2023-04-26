// 369 게임

#include <stdio.h>
#include <windows.h>

int main() {
    int num = 1; // 시작 숫자
    int i; // 반복문 인덱스
	int input_num;
	
	printf("숫자 몇 까지 할까요? ");
	scanf("%d", &input_num);
	
    while (num <= input_num) { // 1부터 100까지 반복
        int clap = 0; // 박수 카운터

        // 숫자에 3, 6, 9가 들어있는지 검사 -> 일, 십, 백, 천,,, 단위로 검사 진행 
        for (i = num; i > 0; i /= 10) {
            int digit = i % 10;
            if (digit == 3 || digit == 6 || digit == 9) {
                clap++;
            }
        }

        // 박수 카운터에 따라 결과 출력 
        if (clap == 0) {
            printf("%d\n", num);
            Sleep(300); //느리게 출력  
        }
		else {
            for (i = 1; i <= clap; i++) {
                printf("짝\a"); // \a 소리나오게 
                Sleep(1000);
            }
            printf("\n");
        }

        num++; // 다음 숫자로 넘어감
    }

    return 0;
}
