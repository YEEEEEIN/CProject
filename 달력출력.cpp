//������ �޷��� �׷������̶�� �Ҹ��� ��¥�ý����Դϴ�.
//�׷������� 1900�� 1�� 1���� �����Ϸ� �����մϴ�.

#include <stdio.h>

int main() {
	
	int year=0, month=0, days=0, start_day=0;
	
	printf("�⵵ �Է� : ");
  		scanf("%d", &year);

	
	while (year != 0){
	
			printf("�� �Է� : ");
		scanf("%d", &month);
		
	 
		// �Է� ���� �⵵�� ���� ��ȿ�� �˻�
    	while (year < 1) {
	   		printf("��ȿ���� ���� �Է��Դϴ�.\n");
   			scanf("%d", &year);
  	 	}
   	
   		while (month < 1 || month > 12) {
   	 	    printf("��ȿ���� ���� �Է��Դϴ�.\n");
   	    	 scanf("%d", &month);
   		 	}
	
		// ���� ��� ��� 
		if (month == 2) {
   	 	    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        	    days =  29; // ������ ��� 29��
      	  	} 
			else {
      	      days = 28; // ����� ��� 28��
      	 	}
  		} 
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
   	    	days = 30; // 30���� ���
   		}
		else {
        days = 31; // 31���� ���
    	}	
	
		// �ش� ���� ù ��° ���� ���� ���
    	start_day = ( year  +  (year - 1)/4  -  (year - 1)/100  +  (year - 1)/400 ) % 7;
    
    	for (int i = 1; i < month; i++) {
        	switch (i) {
            	case 2:
                	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    	start_day = (start_day + 29) % 7;
                	} else {
                    	start_day = (start_day + 28) % 7;
                	}
                	break;
            	case 4:
            	case 6:
            	case 9:
            	case 11:
                	start_day = (start_day + 30) % 7;
                	break;
            	default:
                	start_day = (start_day + 31) % 7;
                	break;
        	}	
    	}
	
		// �޷� ���
    	printf("======= %d�� %d��=======\n", year, month);
    	printf(" �� �� ȭ �� �� �� ��\n");
    	for (int i = 0; i < start_day; i++) {
        	printf("   ");
    	}
    	for (int i = 1; i <= days; i++) {
        	printf("%3d", i);
        	if ((start_day + i -1) % 7 == 6) {
            	printf("\n");
        	}
    	}
    	if ((start_day + days - 1) % 7 != 6) {
        	printf("\n");
    	}
    	
		printf("\n�⵵ �Է� : ");
		scanf("%d", &year);
		
		
	}
	
	printf("�����մϴ�.");
	


	
	return 0;
} 
