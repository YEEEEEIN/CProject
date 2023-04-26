#include<stdio.h>
#include<time.h>
#include<math.h>

const int BABY_PRICE = 0,
             ADULT_DAY_PRICE = 56000, ADULT_NIGHT_PRICE = 46000,
             TEEN_DAY_PRICE = 47000, TEEN_NIGHT_PRICE = 40000,
             CHILD_DAY_PRICE = 44000, CHILD_NIGHT_PRICE = 37000,
             OLD_DAY_PRICE = 44000, OLD_NIGHT_PRICE = 37000;

int ticketList[10], ageList[10], countList[10], firstList[10], totalList[10], totalordercount =0;
             
int get_ticket(){

	int ticket;

   		printf("������ �����ϼ���.\n");
   		printf("1. �ְ���\n");
   		printf("2. �߰���\n");  		

  			while(true)
   			{
	   		scanf("%d", &ticket);
	   			if(ticket == 1 || ticket == 2)
	   			{

	   			break;
	   			}
	   			else{
	   			printf("�ٽ� �Է����ּ���.\n");
	   			}
	   
   			}
   			ticketList[totalordercount] = ticket;
   			return ticket; 
		}
	
int get_age(){

	long long  idNum;
   	int num;
   	long long birthYear, birthMonth, birthDay;
   	long long todayYear, todayMonth, todayDay;
   	int age;
   	int flag;
   	  	printf("�ֹι�ȣ�� �Է��ϼ���.(-���� �Է�)\n");
   		while (true) {
      		scanf("%lld", &idNum);
        	
			// ���� ��¥ ���� ����
      		time_t t = time(NULL);
      		struct tm *now = localtime(&t);
      		todayYear = now->tm_year + 1900;
      		todayMonth = now->tm_mon + 1;
      		todayDay = now->tm_mday;
			
			// ������� ����
      		birthYear = idNum / 100000000000; // 11��������
      		birthMonth = (idNum / 1000000000) % 100; // 9�� ������
      		birthDay = (idNum / 10000000) % 100; //7
      		flag = (idNum / 1000000) % 10;

			// flag �˻�
			if(birthYear >= 0 &&  birthYear < todayYear % 100){
				if (flag != 3 && flag != 4) {
			            printf("�ٽ� �Է��ϼ���. �ֹι�ȣ ���ڸ��� 3,4�� �����մϴ�.\n");
			            continue;
			        }
			}else{
				if (flag != 1 && flag != 2) {
			            printf("�ٽ� �Է��ϼ���. �ֹι�ȣ ���ڸ��� 1,2�� �����մϴ�.\n");
			            continue;
			        }
			} 
			        
      		//���� ����ϱ�
			switch (flag) {
         		case 1:
         		case 2:
            		birthYear += 1900;
            		
            	break;
         		case 3:
         		case 4:
            		birthYear += 2000;
            	break;
         		default:
            		printf("�ٽ� �Է��ϼ���.flag�� 1,2,3,4�� ����\n");
            	continue;
      		}
      		
       			age = todayYear - birthYear;
       			
       			
       			if(birthMonth > todayMonth) 
   				{
      			// ������ ������ ����
      			age--;
   				} else if(birthMonth == todayMonth && birthDay > todayDay)
   				{
     			 // ������ ������ ����
      			age--;
   				}

     			if ((birthYear % 4 == 0 && birthYear % 100 != 0) || birthYear % 400 == 0) {
        		 // ������ ��� 2������ 29�� ����
         			if (birthMonth == 2 && birthDay > 29) {
            			printf("�ٽ� �Է��ϼ���. 29�ϱ����Դϴ�.\n");
            			continue;
         			}
      			} 
				else {
         		// ����� ��� 2������ 28�� ����
         			if (birthMonth == 2 && birthDay > 28) {
            		printf("�ٽ� �Է��ϼ���. 28�ϱ����Դϴ�.\n");
            		continue;
         			}
      			}		
				if (birthMonth == 4 || birthMonth == 6 || birthMonth == 9 || birthMonth == 11) {
        		 	if (birthDay > 30) {
            			printf("�ٽ� �Է��ϼ���. 30�ϱ����Դϴ�.\n");
           				continue;
         			}
      			}
      			if (birthMonth == 1 || birthMonth == 3 || birthMonth == 5 || birthMonth == 7 || birthMonth == 8 || birthMonth == 10 || birthMonth == 12) {
         			if (birthDay > 31) {
           				printf("�ٽ� �Է��ϼ���. 31�ϱ����Դϴ�.\n");
            			continue;
         			}
      			}if(birthMonth == 0 || birthMonth > 12){
      					printf("�ٽ� �Է��ϼ���. �ش� ���� �����ϴ�.\n");
            			continue;
				  }
      			break;
  		}
  		return age;
}

int get_count(){
		int count;
		  	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
   
   			while(true)
   			{
	   			scanf("%d", &count);
	   			if(count >=1 && count<=10)
	   			{
	   			break;
	   			}
	   			else{
	   			printf("�ٽ� �Է����ּ���.\n");
	   			}
	   
   			}
   			countList[totalordercount]= count;
   			return count;
	
}

int get_first(){
	int first;
		printf("�������� �����ϼ���.\n");
	   	printf("1. ���� (���� ���� �ڵ�ó��)\n");
	   	printf("2. �����\n");
	   	printf("3. ����������\n");
	   	printf("4. ���ڳ�\n");
	   	printf("5. �ӻ��\n");
	      	while(true)
	   		{
		   		scanf("%d", &first);
		   		if(first >=1 && first<=5)
		   		{
					break;
		   		}
		   		else{
		   			printf("�ٽ� �Է����ּ���.\n");
		   		}
		   
	   		}
	   		firstList[totalordercount]= first;
	   		return first;
	
} 

int get_price(int ticket, int age){
	int price;
	int tickettype;
   			if(ticket ==1){
      			if (age >= 19 && age <=64)
    			{
    			tickettype=1;
       			price =   ADULT_DAY_PRICE;
    			}
    			else if(age >=13 && age <=18)
    			{
       			price =   TEEN_DAY_PRICE;
       			tickettype=2; 
   				}
    			else if(age >=3 && age <=12)
    			{
       			price =   CHILD_DAY_PRICE;
       			tickettype=3;
    			}
    			else if( age >= 65)
    			{
	      	 	price =   OLD_DAY_PRICE;
	       		tickettype=4;
	    		}
	    		else
	    		{
	       		price = BABY_PRICE;
	       		tickettype=5;
	    		}
	   		}
    
	    	if(ticket == 2){
	       		if (age >= 19 && age <=64 )
	    		{
	       			price =   ADULT_NIGHT_PRICE;
	       			tickettype=1;
	    		}
	    		else if( age >=13 && age <=18)
	    		{
	      			price =   TEEN_NIGHT_PRICE;
	       			tickettype=2;
	         
	    		}
	    		else if(age >=3 && age <=12)
	    		{
	       			price =   CHILD_NIGHT_PRICE;
	       			tickettype=3;
	    		}
	    		else if( age >= 65)
	    		{
	       			price =   OLD_NIGHT_PRICE;
	       			tickettype=4;
	       
	    		}
	    		else 
	    		{
	       			price =   BABY_PRICE;
	       			tickettype=5;
	       
	    		}
    		}				
    		ageList[totalordercount]= tickettype;
			return(price);
}

float get_discount(int first){
	float discount;
		switch(first)
	   		{
	      	case 1:
	      		discount = 1;
	      	break;
	      
	      	case 2:
	      		discount = 0.6;
	      	break;
	      
	      	case 3:
	      		discount = 0.5;
	      	break;
	            
	      	case 4:
	      		discount = 0.8;
	      	break;
	      
	      	case 5:
	      		discount = 0.85;
	      	break;
	
	   		}
	   		return discount;
}

int printTotalList(int totalordercount){
	int sum = 0;
	printf("==================== �������� ====================\n");
	for(int index = 0; index <= totalordercount; index++){
				switch(ticketList[index]){
	   				case 1 : printf("�ְ��� ");
	   				break;
	   				case 2: printf("�߰��� ");
	   				break;
			   }
				switch(ageList[index]){
	   				case 1 : printf("���� X ");
	   				break;
	   				case 2: printf("û�ҳ� X");
	   				break;
	   				case 3: printf("���� X");
	   				break;
	   				case 4: printf("��� X");
	   				break;
	   				case 5: printf("���� X");
	   				break;
			   }
				if(countList[index] != 0){
				
					printf("%d", countList[index]);
				}
			
				if(totalList[index] >= 0){
					printf(" %d", totalList[index]);
				}
				switch(firstList[index]){
	   				case 1 : printf(" * ������� ����\n");
	   				break;
	   				case 2: printf(" * ����� �������\n");
	   				break;
	   				case 3: printf(" * ���������� �������\n");
	   				break;
	            	case 4 :  printf(" *���ڳ� �������\n");
	                break;
	           		case 5 :  printf(" * �ӻ�� �������\n");
	                break;
				}
			sum += totalList[index];
		}
		printf("������� �Ѿ��� %d�Դϴ�.\n",sum);
}



	
int main(){
	
    int sum=0;

   	while(true){
   		while(true){
		   
	   	int ticket;
   		ticket = get_ticket();
    	
   		int age;
   		age = get_age();
   	
   		int price;
   		price = get_price(ticket, age);
   		
		int count;
	 	count = get_count();
	           
		int first; 
	   	first = get_first();
	   	 
	   	float discount;
	   	discount = get_discount(first);
	   
	   	float total;	
	   	total = ((float)price * (float)count * (float)discount);
	   	printf("������ %.0f �� �Դϴ�.\n", total);
	
	   	totalList[totalordercount]= total;
	   
	   	printf("�����մϴ�.\n", total);
	
	   	int end;
	  
	   	printf("��� �߱��Ͻðڽ��ϱ�?\n");
	   	printf("1. Ƽ�� �߱�\n");
	   	printf("2. ����\n"); 
	   	scanf("%d", &end);
	   
				if(end == 2) {
					break;
				} 
			totalordercount++;
		}

	   	printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n\n");
	  
	   	printTotalList(totalordercount);
	   
			int ing; 
			printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����):");
			scanf("%d",&ing);
			if(ing == 2){
				break;
			}
		ticketList[10]=0, ageList[10]=0, countList[10]=0, firstList[10]=0, totalList[10]=0, totalordercount =0 ;
	}
}
