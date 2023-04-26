//현대의 달력은 그레고리력이라고 불리는 날짜시스템입니다.
//그레고리력은 1900년 1월 1일이 월요일로 시작합니다.

#include <stdio.h>

int main() {
	
	int year=0, month=0, days=0, start_day=0;
	
	printf("년도 입력 : ");
  		scanf("%d", &year);

	
	while (year != 0){
	
			printf("월 입력 : ");
		scanf("%d", &month);
		
	 
		// 입력 받은 년도와 월의 유효성 검사
    	while (year < 1) {
	   		printf("유효하지 않은 입력입니다.\n");
   			scanf("%d", &year);
  	 	}
   	
   		while (month < 1 || month > 12) {
   	 	    printf("유효하지 않은 입력입니다.\n");
   	    	 scanf("%d", &month);
   		 	}
	
		// 윤년 평년 계산 
		if (month == 2) {
   	 	    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        	    days =  29; // 윤년인 경우 29일
      	  	} 
			else {
      	      days = 28; // 평년인 경우 28일
      	 	}
  		} 
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
   	    	days = 30; // 30일인 경우
   		}
		else {
        days = 31; // 31일인 경우
    	}	
	
		// 해당 월의 첫 번째 날의 요일 계산
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
	
		// 달력 출력
    	printf("======= %d년 %d월=======\n", year, month);
    	printf(" 일 월 화 수 목 금 토\n");
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
    	
		printf("\n년도 입력 : ");
		scanf("%d", &year);
		
		
	}
	
	printf("종료합니다.");
	


	
	return 0;
} 
