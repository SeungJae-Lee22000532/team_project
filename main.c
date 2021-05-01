#include <stdio.h>
#include <string.h>
#include "project.h"

int main(){
	Instrument ilist[100];
	int menu, count =0;
	int index = 0;

	while(1){
                int x = 0;
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
                        x++;
			printf("\n");
                }
                else if(menu == 3){
                        int no = selectInstrument(ilist, index);
                        if(no == 0){
                                printf("=>취소되었습니다.\n");
				printf("\n");
                                continue;
                        }
                        updateInstrument(&ilist[no-1]);
			printf("\n");
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
		printf("\n");
        }
        printf("=> 종료\n");
        return 0;
}

