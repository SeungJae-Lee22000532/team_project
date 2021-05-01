#include <stdio.h>
#include <string.h>
#include "project.h"

int SelectNumber(){
	int select;
	printf("메뉴****************\n");
	printf("0. 종료\n");
	printf("1. 제품조회\n");
	printf("2. 제품추가\n");
	printf("3. 제품수정\n");
	printf("4. 제품삭제\n");
	printf("5. 파일에 저장\n");
	printf("\n");
	printf("원하는 메뉴는? ");
	scanf("%d", &select);
	
	return select;
}

int addInstrument(Instrument *i){
	getchar();
	printf("악기 이름은? ");
	scanf("%[^\n]s", i->name);
	getchar();
	printf("악기 가격은? ");
	scanf("%d", &i->price);
	printf("악기 별점은?(1~5개) ");
	scanf("%d", &i->star);
	printf("악기 중량은?(kg) ");
	scanf("%lf", &i->weight);

	return 1;
}

void showInstrument(Instrument i){
	printf("%s\t%d\t%d\t%.1lf\n", i.name, i.price, i.star, i.weight);
}

int updateInstrument(Instrument *i){
	getchar();
	printf("새 악기 이름은? ");
	scanf("%[^\n]s", i->name);
	getchar();
	printf("새 악기 가격은? ");
	scanf("%d", &i->price);
	printf("새 악기 별점은?(1~5개) ");
	scanf("%d", &i->star);
	printf("새 악기 중량은?(kg) ");
	scanf("%lf", &i->weight);

	return 1;
}

int deleteInstrument(Instrument *i){
	int check;
	printf("정말로 삭제하시겠습니까? (취소: 0) ");
	scanf("%d", &check);
	if(check == 1){
		strcpy(i->name, "NULL");
		i->price = -1;
		i->star = -1;
		i->weight = -1;
	}

	return check;
}

void listInstrument(Instrument *i, int count){
	printf("번호\t악기이름\t악기가격\t악기 별점\t악기중량\n");
	for(int x=0; x<count; x++){
		printf("%2d\t", x+1);
		showInstrument(i[x]);
	}
}

int selectInstrument(Instrument *i, int count){
	int no;
	listInstrument(i, count);
	printf("수정하고 싶은 악기 번호는? (취소: 0) ");
	scanf("%d", &no);

	return no;
}

void saveData(Instrument *i, int count){
	FILE *fp = fopen("instrument.txt", "wt");

	for(int x=0; x<count; x++){
		if(i[x].price == -1)
			continue;
		fprintf(fp, "%s %d %d %.1lf", i[x].name, i[x].price, i[x].star, i[x].weight);
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}
