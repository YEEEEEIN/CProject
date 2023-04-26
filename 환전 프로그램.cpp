// <환전문제> 

#include <stdio.h>
#include <math.h>
 
int main()
{
	
	int currency;
	float moneyToExchange, exchangedMoney, exchange;
	int won1000, won500, won100, won50, won10; 
	
	// float exchange_rate
	float exchange_rate[20] = {0, 1194.50, 11.0148, 1392.33, 189.41, 1562.67, 872.14, 954.34, 815.64}; //1번부터 시작  
	
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%f", &moneyToExchange);
	
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP, 6:AUD, 7:CAD, 8:NZD) : ");
	scanf("%d", &currency);
	

	printf("기준 환율 : %.2f\n", exchange_rate[currency]);
			 
	exchangedMoney = floor(moneyToExchange/exchange_rate[currency]); //소수점이하 버림 floor => math 환경에서 사용 가능 
	exchange = 10*(floor((moneyToExchange - (exchangedMoney*exchange_rate[currency]))*0.1));
	
	printf("환전 결과\n");	
	printf("외화 : %.0f\n", exchangedMoney);
	printf("거스름돈 : %.0f원\n", exchange);

	
	// 거스름돈 상세 출력 
	exchange = (int)exchange; // %(나머지출력)함수 정수형에서 가능 => 형변환  
	 
	won1000 = exchange / 1000;
	exchange = (int)exchange % 1000;	// 또 형변환을 해줌,,,? 
	
	won500 = exchange / 500;
	exchange = (int)exchange % 500;
	
	won100 = (exchange / 100);
	exchange = (int)exchange % 100;
	
	won50 = exchange / 50;
	exchange = (int)exchange % 50;
	
	won10 = exchange / 10;
	exchange = (int)exchange % 10;
	
	
	printf("천원권 %d 장\n", won1000);
	printf("오백원 %d 개\n", won500);
	printf("백원  %d 개\n", won100);
	printf("오십원 %d 개\n", won50);
	printf("십원  %d 개\n", won10);
	
	return 0;
} 

