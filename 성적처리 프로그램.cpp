#include <stdio.h>
int main() {
	int score[100][100] = {0};
	int student_sum[100] ={0};
	float student_avg[100] ={0};
	int study_sum[100] ={0};
	float study_avg[100] ={0};
	
	int study, student;
	printf("���� �� �Է�: ");
	scanf("%d", &study);
	
	printf("�л� �� �Է�: ");
	scanf("%d", &student);
	
	for (int i=0; i<student; i++) {
		printf("[%d]�� �л��� ���� %d���� ���ʴ�� �Է��ϼ���: ", i+1, study);
		for (int j=0; j<study; j++) {
			scanf("%d", &score[i][j]);
			
			student_sum[i] += score[i][j];
			student_avg[i] = (float)student_sum[i]/3;
			
			study_sum[j] += score[j][i];
			study_avg[j] = (float)student_sum[j]/3;
		}
	}
	
	// ���
	printf("\n");
	
	for (int i=0; i<student; i++) {
		printf("[%d]�� �л��� ���� ������ %d, ����� %.1f �Դϴ�.\n", i+1, student_sum[i], student_avg[i] );
	
	}
	
	printf("\n");
	
	// ��� 
	for (int j=0; j<study; j++) {
		printf("[%d]�� ������ ������ %d, ����� %.1f �Դϴ�.\n", j+1, study_sum[j], study_avg[j]); 
	}
		
	return 0;	
}
