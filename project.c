#include <stdio.h>
#include <string.h>
#include "project.h"

int SelectNumber(){
	int select;
	printf("메뉴****************");
	printf("0. 종료\n");
	printf("1. 제품조회\n");
	printf("2. 제품추가\n");
	printf("3. 제품수정");
	printf("4. 제품삭제");
	printf("5. 파일에 저장");
	printf("원하는 메뉴는? ");
	scanf("%d", &select);
	
	return select;
}

int addInstrument(Instrument *i){
	printf("악기 이름은? ");
	scanf("%[^\n]s", i->name);
	getchar();
	printf("악기 가격은? ");
	scanf("%d", i->price);
	printf("악기 별점은? ");
	scanf("%d", i->star);
	printf("악기 중량은? ");
	scanf("%lf", i->weight);

	return 1;
}

void showInstrument(Instrument *i){
	printf("%s\t%d\t%d\t%.1lf\n", i.name, i.price, i.star, i.weight);
}

int updateInstrument(Instrument *i){
	printf("새 악기 이름은? ");
	scanf("%[^\n]s", i->name);
	getchar();
	printf("새 악기 가격은? ");
	scanf("%d", &i->price);
	printf("새 악기 별점은? ");
	scanf("%d", &i->star);
	printf("새 악기 중량은? ");
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
