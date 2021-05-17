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
	printf("6. 이름검색\n");
	printf("7. 가격검색\n");
	printf("8. 별점검색\n");
	printf("9. 중량검색\n");
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
	printf("%s\t\t%d\t\t%d\t\t%.1lf\n", i.name, i.price, i.star, i.weight);
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
	printf("정말로 삭제하시겠습니까? (선택: 1, 취소: 0) ");
	while(1) {
		scanf("%d", &check);
		if(check == 1 || check == 0) break;
	}
	if(check == 1){
		strcpy(i->name, "NULL");
		i->price = -1;
		i->star = -1;
		i->weight = -1;
	}

	return check;
}

void listInstrument(Instrument *i, int count){
	printf("번호\t악기이름\t악기가격\t악기별점\t악기중량\n");
	for(int x=0; x<count; x++){
		if(i[x].price == -1) continue;
		printf("%2d\t", x+1);
		showInstrument(i[x]);
	}
}

int selectInstrument(Instrument *i, int count){
	int no;
	listInstrument(i, count);
	printf("수정하고 싶은 악기 번호는? (취소: 0) ");
	while(no < 0 || no > count) {
		scanf("%d", &no);
	}

	return no;
}

void saveData(Instrument *i, int count){
	FILE *fp = fopen("instrument.txt", "wt");

	for(int x=0; x<count; x++){
		if(i[x].price == -1) continue;
		fprintf(fp, "%s %d %d %.1lf\n", i[x].name, i[x].price, i[x].star, i[x].weight);
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}

int loadData(Instrument *i) {
	int count = 0;
	FILE *fp = fopen("instrument.txt", "rt");
	if(fp == NULL) {
		printf("저장된 데이터가 없습니다!\n\n");
		return 0;
	}
	else {
		while(!(feof(fp))) {
			fscanf(fp, "%s %d %d %lf", i[count].name, &i[count].price, &i[count].star, &i[count].weight);
			count++;
		}
		count--;
	}
	fclose(fp);
	printf("불러오기 성공!\n\n");
	return count;
}

void searchName(Instrument *i, int count) {
	char i_name[30];
	printf("검색할 이름? ");
	scanf("%s", i_name);
	int x;
	for(x = 0; x < count; x++) {
		if(i[x].price == -1) continue;
		if(strcmp(i[x].name, i_name) == 0) {
			printf("번호\t악기이름\t악기가격\t악기 별점\t악기중량\n");
		       	printf("%2d\t", x + 1);
		       	showInstrument(i[x]);
		}
	}
}

void searchPrice(Instrument *i, int count) {
	int i_price;
	printf("검색할 가격은? ");
	scanf("%d", &i_price);
	int x;
	for(x = 0; x < count; x++) {
		if(i[x].price == -1) continue;
		if(i[x].price >= i_price) {
			printf("번호\t악기이름\t악기가격\t악기 별점\t악기중량\n");
		       	printf("%2d\t", x + 1);
		       	showInstrument(i[x]);
		}
	}
}
void searchStar(Instrument *i, int count) {
	int i_star;
	printf("검색할 별점은? ");
	scanf("%d", &i_star);
	int x;
	for(x = 0; x < count; x++) {
		if(i[x].price == -1) continue;
		if(i[x].star == i_star) {
			printf("번호\t악기이름\t악기가격\t악기 별점\t악기중량\n");
		       	printf("%2d\t", x + 1);
		       	showInstrument(i[x]);
		}
	}
}
void searchWeight(Instrument *i, int count) {
	double i_weight;
	printf("검색할 중량은? ");
	scanf("%lf", &i_weight);
	int x;
	for(x = 0; x < count; x++) {
		if(i[x].price == -1) continue;
		if(i[x].weight - i_weight > 0.0) {
			printf("번호\t악기이름\t악기가격\t악기 별점\t악기중량\n");
		       	printf("%2d\t", x + 1);
		       	showInstrument(i[x]);
		}
	}
}
