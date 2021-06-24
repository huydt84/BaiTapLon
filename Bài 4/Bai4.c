#include<stdio.h>
// #include<stdlib.h>
//#include<time.h>
//#include<windows.h>

void GoiTen(int n){
	int m = n / 4;
	switch(m){
	case 0:	
	    printf("Ace ");
	    break;
	case 1:	
		printf("2 ");
		break;
	case 2:
	    printf("3 ");
	    break;
	case 3:	
		printf("4 ");
		break;
	case 4:	
		printf("5 ");
		break;
	case 5:
		printf("6 ");
		break;
	case 6:
		printf("7 ");
		break;
	case 7:
		printf("8 ");
		break;
	case 8:
		printf("9 ");
		break;
	case 9:
		printf("10 ");
		break;
    case 10:
		printf("J ");
		break; 
	case 11:
		printf("Q ");
		break;
    case 12:
		printf("K ");
		break;
    }
    int l = n % 4;
	switch(l){
	case 0:
		printf("Co ");
		break;
	case 1:
		printf("Ro ");
		break;
	case 2:
		printf("Bich ");
		break;
	case 3:
		printf("Tep ");
		break;
    }
}

void XuLy(int nv[13][4]){
	int i = 0;
	for(i = 0 ; i < 52 ; i++){
		if(nv[i/4][i%4] == 1){
			GoiTen(i);
			printf("  ");
			}
	}
}

int TuQuy(int nv[13][4]){
	int i, j;
	int c_tuquy=0;
	for (i=0;i<13;i++){
		int count = 0;
		for (j=0;j<4;j++){
			if (nv[i][j]==1){
				count += 1;
			}else {
				break;
			}
		}
		if (count == 4){
			c_tuquy += 1;
			if (i==0){
				printf("\nCo tu quy A\n");
			}else if (i==10){
				printf("\nCo tu quy J\n");
			}else if (i==11){
				printf("\nCo tu quy Q\n");
			}else if (i==12){
				printf("\nCo tu quy K\n");
			}else{
				printf("\nCo tu quy %d\n",i+1);
			}
		}
	}
	if (c_tuquy==0){
		printf("\nKhong co tu quy den ghe ban oi");
	}
}

int main(){
	int i = 0, j = 0; 
	int nv1[13][4] = {0}; 
	int nv2[13][4]=  {0}; 
	int nv3[13][4] = {0};  
	int nv4[13][4] = {0}; 
	srand(time(NULL));
	int card[13][4] ;
	for(i = 0 ; i < 13 ; i++){
		for (j = 0; j < 4 ; j++)
		{
			card[i][j] = 1;
		}
	}
	for(i = 0 ; i < 13 ; i++){
		int n = rand() % 52;
		if(card[n/4][n%4] == 0){
			i--;
			continue;
		}
		nv1[n/4][n%4] = 1;
		card[n/4][n%4] = 0;
	}
	for(i = 0 ; i < 13 ; i++){
		int n = rand() % 52;
		if(card[n/4][n%4] == 0){
			i--;
			continue;
		}
		nv2[n/4][n%4] = 1;
		card[n/4][n%4] = 0;}
	for(i = 0 ; i < 13 ; i++){
		int n = rand() % 52;
		if(card[n/4][n%4] == 0){
			i--;
			continue;
		}
		nv3[n/4][n%4] = 1;
		card[n/4][n%4] = 0;}
	for(i = 0; i < 13 ; i++){
		int n = rand() % 52;
		if(card[n/4][n%4] == 0){
			i--;
			continue;
		}
		nv4[n/4][n%4] = 1;
		card[n/4][n%4] = 0;}
	printf("Nguoi choi 1: \n");
	XuLy(nv1); TuQuy(nv1);
	printf("\nNguoi choi 2: \n");
	XuLy(nv2); TuQuy(nv2);
	printf("\nNguoi choi 3: \n");
	XuLy(nv3); TuQuy(nv3);
	printf("\nNguoi choi 4: \n");
	XuLy(nv4); TuQuy(nv4);
	printf("\n");
}
