#include <stdio.h>
	
	int yearMonthDay = 20220414;
	
	// 종합이용권 가격
	const int ALL_1D_ADULT = 62000, ALL_1D_TEEN = 54000 ,ALL_1D_KID = 47000 ,ALL_1D_BABY = 15000;	
	const int ALL_A4_ADULT = 50000, ALL_A4_TEEN = 43000, ALL_A4_KID = 36000, ALL_A4_BABY = 15000;
	
	// 파크이용권 가격
	const int PARK_1D_ADULT = 59000, PARK_1D_TEEN = 52000, PARK_1D_KID = 46000, PARK_1D_BABY = 15000;
	const int PARK_A4_ADULT = 47000, PARK_A4_TEEN = 41000, PARK_A4_KID = 35000, PARK_A4_BABY = 15000;
	
	// 주민등록번호 분석
	const int PROTECT_CITIZEN_NUM = 10000000;
	const int OLD_GENERATION = 18000000, NEW_GENERATION = 19000000;
	
	// 나이에 따른 범위
	const int MIN_BABY = 1, MIN_KID = 3, MIN_TEEN = 12, MIN_ADULT = 18, MIN_OLD = 65; 
	
	// 할인율
	const double DISABLED = 0.5, NATIONAL_MERIT = 0.5, SOLDIER = 0.49, PREGNANT = 0.5, MANY_CHILDREN = 0.3;

	
void errorMessagePrint(){
	
}

int orderTicketClass(int ticketClass){
	
	while(ticketClass != 1 && ticketClass != 2){ // ticketClass 1,2가 아니라면 반복  
	printf("이용권 종류를 선택하세요 : \n");
	printf("1. 종합이용권 (롯데월드 + 민속박물관)\n");
	printf("2. 파크이용권 (롯데월드)\n");
	scanf("%d", &ticketClass);
	}
	return ticketClass;
}

int orderTicketType(int ticketType){
	
	while(ticketType != 1 && ticketType != 2){ // 1, 2가 아니라면 반복 
	printf("권종을 선택하세요 : \n");
	printf("1. 1Day\n");
	printf("2. After4 (오후 4시부터 입장)\n");
	scanf("%d", &ticketType);
	}
	return ticketType;
}

int orderCitizenNum(int citizenNum){
	printf("주민번호를 뒷자리 첫째자리까지 입력하세요 (ex:9304081) : \n");
	scanf("%d", &citizenNum);
	citizenNum += PROTECT_CITIZEN_NUM;
}

int orderTicketCount(int ticketCount){
	printf("몇개를 주문하시겠습니까?(최대 10개)\n");
	scanf("%d", &ticketCount);
	return ticketCount;
}

int orderPreferClass(int preferClass){
	
	while(preferClass < 1 || preferClass > 6){
	printf("우대사항을 선택하세요.\n");
	printf("1. 없음 (나이 우대는 자동처리)\n");
	printf("2. 장애인 우대\n"); //동반1인 
	printf("3. 국가유공자 우대\n"); //동반1인 
	printf("4. 휴가장병 우대\n"); //동반1인 
	printf("5. 임산부 우대\n");
	printf("6. 다둥이 행복카드 우대\n");
	scanf("%d", &preferClass);
	}
	return preferClass;	
}


int calcAge(int citizenNum){
	int today = yearMonthDay; // 오늘 날짜 
	int gender = citizenNum % 10; // 주민번호 뒷자리 1, 2, 3, 4 
	int birthDay = citizenNum / 10;
	if (gender >= 3){
		birthDay += NEW_GENERATION;
	} else {
		birthDay += OLD_GENERATION;
	}
	int age = (today - birthDay) / 10000;
	return age;
}

int calcAgeGroup(int manAge){
	int ageGroup;
	if(manAge < MIN_BABY){
		ageGroup = 0; //영유아 
	} else if(manAge >= MIN_BABY && manAge < MIN_KID){
		ageGroup = 1; // 유아  
	} else if (manAge >= MIN_KID && manAge <= MIN_TEEN){
		ageGroup = 2; // 어린이
	} else if (manAge > MIN_TEEN && manAge <= MIN_ADULT){
		ageGroup = 3; // 청소년 
	} else if (manAge > MIN_ADULT && manAge < MIN_OLD){
		ageGroup = 4; // 어른 
	} else if (manAge >= MIN_OLD){
		ageGroup = 5;// 노인 
	} else {
		printf("ERROR");
	}
	return ageGroup;
}	

int calcPriceProcess(int ageGroup, int ticketClass, int ticketType){
	if(ticketClass == 1){ // ALL
		if(ticketType == 1){ // 1D
			if(ageGroup == 4){
				return ALL_1D_ADULT;
			} else if(ageGroup == 3){
				return ALL_1D_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return ALL_1D_KID;
			} else if(ageGroup == 1){
				return ALL_1D_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else if(ticketType == 2){ //A4
			if(ageGroup == 4){
				return ALL_A4_ADULT;
			} else if(ageGroup == 3){
				return ALL_A4_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return ALL_A4_KID;
			} else if(ageGroup == 1){
				return ALL_A4_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}		
		} else {
			printf("ERROR");
		}
		
	} else if(ticketClass == 2){ // PARK
		if(ticketType == 1){ // 1D
			if(ageGroup == 4){
				return PARK_1D_ADULT;
			} else if(ageGroup == 3){
				return PARK_1D_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return PARK_1D_KID;
			} else if(ageGroup == 1){
				return PARK_1D_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else if(ticketType == 2){ //A4
			if(ageGroup == 4){
				return PARK_A4_ADULT;
			} else if(ageGroup == 3){
				return PARK_A4_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return PARK_A4_KID;
			} else if(ageGroup == 1){
				return PARK_A4_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else {
			printf("ERROR");
		}
	}
}

int calcTicketCount(int ticketCount, int price){
	price *= ticketCount;
	return price;
} 

int calcDiscount(int price, int preferClass, int ticketClass){
	if(preferClass == 2){
		price *= DISABLED;
	} else if(preferClass == 3){
		price *= NATIONAL_MERIT;
	} else if(preferClass == 4 && ticketClass == 1){
		price *= SOLDIER;
	} else if(preferClass == 5 && ticketClass == 1){
		price *= PREGNANT;
	} else if(preferClass == 6 && ticketClass == 1){
		price *= MANY_CHILDREN;
	}
	return price;
}



int *savedInforms (int ticketClass, int ticketType, int ageGroup, int ticketCount, int price, int preferClass, int position, 
					int inputList [][6]){
	
	inputList[position][0] = ticketClass;
	inputList[position][1] = ticketType;
	inputList[position][2] = ageGroup;
	inputList[position][3] = ticketCount;
	inputList[position][4] = price;
	inputList[position][5] = preferClass;

}


void inputData(int position, int inputList[][6]){
	int ticketClass = 0;
	int ticketType = 0;
	int citizenNum = 0;
	int manAge = 0;
	int ageGroup = 0;
	int price = 0;
	int ticketCount = 0;
	int preferClass = 0;
	
	ticketClass = orderTicketClass(0);
	ticketType = orderTicketType(0);
	citizenNum = orderCitizenNum(0);
	manAge = calcAge(citizenNum);
	ageGroup = calcAgeGroup(manAge);
	price = calcPriceProcess(ageGroup, ticketClass, ticketType);
	ticketCount = orderTicketCount(0);
	price = calcTicketCount(ticketCount, price);
	preferClass = orderPreferClass(0);
	if(preferClass != 1){
		price = calcDiscount(price, preferClass, ticketClass); 
	}
	
	savedInforms(ticketClass, ticketType, ageGroup, ticketCount, price, preferClass, position, inputList);
	
}




char* convertTicketClass(int input){
	char* ticketClass;
	if(input == 1){
		ticketClass = "종합이용권"; 
	} else if(input == 2){
		ticketClass = "파크이용권";
	} 
	return ticketClass;
}

char* convertTicketType(int input){
	char* ticketType;
	if(input == 1){
		ticketType = "1Day";
	} else if(input == 2){
		ticketType = "After4";
	}
	return ticketType;
}

char* convertAgeGroup(int input){
	char* ageGroup;
	if (input == 0){
		ageGroup = "영유아";
	} else if (input == 1){
		ageGroup = "유아";
	} else if (input == 2){
		ageGroup = "어린이";
	} else if (input == 3){
		ageGroup = "청소년";
	} else if (input == 4){
		ageGroup = "어른";
	} else if (input == 5){
		ageGroup = "노인";
	}
	return ageGroup;
}

char* convertPreferClass(int input){
	char* preferClass;
	if(input == 1){
		preferClass = "없음";
	} else if(input == 2){
		preferClass = "장애인";
	} else if (input == 3){
		preferClass = "국가유공자";
	} else if (input == 4){
		preferClass = "휴가장병";
	} else if (input == 5){
		preferClass = "임산부";
	} else if (input == 6){
		preferClass = "다둥이";
	}
	return preferClass;
}


void csvPrint(){
	FILE *fp;
	fp = fopen("C:\\test\\lotteworldreport\\report.csv", "w");
	fprintf(fp, "날짜, 이용권, 권종, 연령구분, 수량, 가격, 우대사항\n");
}


void entrancePrint(int inputList[][6], int position){
	
	FILE *fp;
	fp = fopen("C:\\test\\lotteworldreport\\report.csv", "a");
	int totalPrice = 0;
	printf("티켓 발권을 종료합니다. 감사합니다.\n");
	printf("---------------------롯데월드-----------------------------\n");
	for(int column = 0; column <= position; column++){
		
		char* ticketClass = convertTicketClass(inputList[column][0]);
		char* ticketType = convertTicketType(inputList[column][1]);
		char* ageGroup = convertAgeGroup(inputList[column][2]);
		char* preferClass = convertPreferClass(inputList[column][5]);
		//ticketClass ticketType ageGroup ticketCount price preferClass 
		printf("%s %5s %5s %2d장 %8d원 *%s\n", ticketClass, ticketType, ageGroup, inputList[column][3], 
						inputList[column][4], preferClass);
		totalPrice += inputList[column][4];
		
		fprintf(fp, "%d,%s,%s,%s,%d,%d,%s\n", yearMonthDay, ticketClass, ticketType, ageGroup, inputList[column][3], 
						inputList[column][4], preferClass);	
		    
	}
	printf("입장료 총액은 %d원 입니다.\n", totalPrice);
	
	fclose(fp); 
}



int main() {
	
	csvPrint();
	
	int totalPrice = 0; // 주문 총액 
	int position = 0; // inputList 행 추가시 사용  
	int filePosition = 0; // 파일 출력 첫줄 구분 
	int inputList [100][6] = {0}; // 주문내역 저장 
	int exitIndex = 0;

	while(true){
		inputData(position, inputList);	
		//고객정보 저장  
		int continueSelect;
		printf("계속 발권 하시겠습니까?\n");
		printf("1. 티켓 발권\n");
		printf("2. 종료\n");
		scanf("%d", &continueSelect);
		if(continueSelect == 1){
			exitIndex++;
		} else if(continueSelect == 2){
			entrancePrint(inputList, position);	
			break;
		}	
		
		position++; // 배열위치 변경 
	}

}



