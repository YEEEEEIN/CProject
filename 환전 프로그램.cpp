// <ȯ������> 

#include <stdio.h>
#include <math.h>
 
int main()
{
	
	int currency;
	float moneyToExchange, exchangedMoney, exchange;
	int won1000, won500, won100, won50, won10; 
	
	// float exchange_rate
	float exchange_rate[20] = {0, 1194.50, 11.0148, 1392.33, 189.41, 1562.67, 872.14, 954.34, 815.64}; //1������ ����  
	
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%f", &moneyToExchange);
	
	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP, 6:AUD, 7:CAD, 8:NZD) : ");
	scanf("%d", &currency);
	

	printf("���� ȯ�� : %.2f\n", exchange_rate[currency]);
			 
	exchangedMoney = floor(moneyToExchange/exchange_rate[currency]); //�Ҽ������� ���� floor => math ȯ�濡�� ��� ���� 
	exchange = 10*(floor((moneyToExchange - (exchangedMoney*exchange_rate[currency]))*0.1));
	
	printf("ȯ�� ���\n");	
	printf("��ȭ : %.0f\n", exchangedMoney);
	printf("�Ž����� : %.0f��\n", exchange);

	
	// �Ž����� �� ��� 
	exchange = (int)exchange; // %(���������)�Լ� ���������� ���� => ����ȯ  
	 
	won1000 = exchange / 1000;
	exchange = (int)exchange % 1000;	// �� ����ȯ�� ����,,,? 
	
	won500 = exchange / 500;
	exchange = (int)exchange % 500;
	
	won100 = (exchange / 100);
	exchange = (int)exchange % 100;
	
	won50 = exchange / 50;
	exchange = (int)exchange % 50;
	
	won10 = exchange / 10;
	exchange = (int)exchange % 10;
	
	
	printf("õ���� %d ��\n", won1000);
	printf("����� %d ��\n", won500);
	printf("���  %d ��\n", won100);
	printf("���ʿ� %d ��\n", won50);
	printf("�ʿ�  %d ��\n", won10);
	
	return 0;
} 

