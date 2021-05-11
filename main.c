#include "project.h"

int main(){
	Instrument ilist[100];
	int menu, count;
	int index = 0;

	count = loadData(ilist);
	index = count;	

	while(1){
                menu = SelectNumber();
                if(menu == 0){
                        break;
                }
                if(menu == 1){
			if(count > 0)
				listInstrument(ilist, index);
                	else{
				printf("데이터가 없습니다!\n");
				printf("\n");
				continue;
			}
			printf("\n");
		}
                if(menu == 2){
                        count += addInstrument(&ilist[index++]);
			if(count > 0) printf("=> 추가됨!\n");
                }
                else if(menu == 3){
                        int no = selectInstrument(ilist, index);
                        if(no == 0){
                                printf("=>취소되었습니다.\n");
				printf("\n");
                                continue;
                        }
                        updateInstrument(&ilist[no-1]);
			printf("=> 수정됨!\n");
                }
                else if(menu == 4){
                        int no = selectInstrument(ilist, index);
                        if(no == 0){
                                printf("=> 취소되었습니다.\n");
                        }
                        else{
                                int delete;
                                delete = deleteInstrument(&ilist[no-1]);
                                if(delete == 1){
                                        printf("=> 삭제되었습니다.\n");
                                        count--;
                                        }
                                else
                                        printf("=> 취소되었습니다.\n");
                        }
                }
                else if(menu == 5){
                        saveData(ilist, index);
                }
		else if(menu == 6) {
			searchName(ilist, index);
		}
		else if(menu == 7) {
			searchPrice(ilist, index);
		}
		else if(menu == 8) {
			searchStar(ilist, index);
		}
		else if(menu == 9) {
			searchWeight(ilist, index);
		}
		printf("\n");
        }
        printf("=> 종료\n");
        return 0;
}

