// 369 ����

#include <stdio.h>
#include <windows.h>

int main() {
    int num = 1; // ���� ����
    int i; // �ݺ��� �ε���
	int input_num;
	
	printf("���� �� ���� �ұ��? ");
	scanf("%d", &input_num);
	
    while (num <= input_num) { // 1���� 100���� �ݺ�
        int clap = 0; // �ڼ� ī����

        // ���ڿ� 3, 6, 9�� ����ִ��� �˻� -> ��, ��, ��, õ,,, ������ �˻� ���� 
        for (i = num; i > 0; i /= 10) {
            int digit = i % 10;
            if (digit == 3 || digit == 6 || digit == 9) {
                clap++;
            }
        }

        // �ڼ� ī���Ϳ� ���� ��� ��� 
        if (clap == 0) {
            printf("%d\n", num);
            Sleep(300); //������ ���  
        }
		else {
            for (i = 1; i <= clap; i++) {
                printf("¦\a"); // \a �Ҹ������� 
                Sleep(1000);
            }
            printf("\n");
        }

        num++; // ���� ���ڷ� �Ѿ
    }

    return 0;
}
