#include <stdio.h>
int main() {
	int score[100][100] = {0};
	int student_sum[100] ={0};
	float student_avg[100] ={0};
	int study_sum[100] ={0};
	float study_avg[100] ={0};
	
	int study, student;
	printf("과목 수 입력: ");
	scanf("%d", &study);
	
	printf("학생 수 입력: ");
	scanf("%d", &student);
	
	for (int i=0; i<student; i++) {
		printf("[%d]번 학생의 점수 %d개를 차례대로 입력하세요: ", i+1, study);
		for (int j=0; j<study; j++) {
			scanf("%d", &score[i][j]);
			
			student_sum[i] += score[i][j];
			student_avg[i] = (float)student_sum[i]/3;
			
			study_sum[j] += score[j][i];
			study_avg[j] = (float)student_sum[j]/3;
		}
	}
	
	// 출력
	printf("\n");
	
	for (int i=0; i<student; i++) {
		printf("[%d]번 학생의 과목 총점은 %d, 평균은 %.1f 입니다.\n", i+1, student_sum[i], student_avg[i] );
	
	}
	
	printf("\n");
	
	// 출력 
	for (int j=0; j<study; j++) {
		printf("[%d]번 과목의 총점은 %d, 평균은 %.1f 입니다.\n", j+1, study_sum[j], study_avg[j]); 
	}
		
	return 0;	
}
