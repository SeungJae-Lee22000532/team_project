typedef struct{
	char name[30];
	int price;
	int star;
	double weight;
}Instrument;

int SelectNumber(); //메뉴 고르기 함수
int addInstrument(Instrument *i); //제품을 추가하는 함수
void showInstrument(Instrument *i); //제품 하나를 보여주는 함수
int updateInstrument(Instrument *i); //수정함수
int deleteInstrument(Instrument *i); //삭제함수
