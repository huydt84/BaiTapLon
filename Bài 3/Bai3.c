#include"student.h"
int xemds();
void nhapthem();
void timSV();
int main(){
	do {
	    int sl; //Con so lua chon
	    printf("\n----------------------------------------\n");
        printf("| Chuong trinh quan ly sinh vien       |\n");
        printf("----------------------------------------\n");
        printf("| 1. Xem danh sach sinh vien           |\n");
        printf("| 2. Nhap them sinh vien               |\n");
        printf("| 3. Tim sinh vien theo ten            |\n");
        printf("| 4. Thoat                             |\n");
        printf("----------------------------------------\n");
        printf("Xin moi nhap lua chon: ");
	    scanf("%d",&sl);
	    switch (sl)     //Lua chon theo so dua vao
	    {
	    case 1 :
	        xemds();    //xem danh sach ten sinh vien va diem 
	        break;
	    case 2 :    
	        nhapthem();         // Nhap them ten sinh vien va diem cua sinh vien
	        break;
	    case 3 :
	        timSV();        //Tim sinh vien theo ten
	        break;  
	    case 4 :
	        return 0;   //Thoat
	        break;
	    default:
	        printf("Ban dinh hack he thong ha ?!!???\n");
	        break;
	    }
	} while(1);
}
int xemds(){
    student SinhVien;
    int i=1;  
    FILE *data = fopen("SV2021.dat","r");   //mo file luu du lieu
    printf("   ***Danh sach sinh vien***\n");
    while (fscanf(data,"%[^\t]\t%f\n",SinhVien.name,&SinhVien.score)!=EOF){  //Quet du lieu theo dong, ten va
        printf("%d.%.30s\t\t%3.1f\n",i,SinhVien.name,SinhVien.score);    // diem ngan cach nhau boi dau Tab 
        ++i;
    }
}
void nhapthem(){
    student svmoi;
    FILE *data = fopen("SV2021.dat","a"); // Mo file luu du lieu
    printf("Nhap ten sinh vien: ");
    getchar();
    scanf("%[^\n]",svmoi.name);
    printf("Nhap so diem: ");
    scanf("%f",&svmoi.score);
    fprintf(data,"\n%s\t%.1f",svmoi.name,svmoi.score); //Luu du lieu moi vao file
    fclose(data);
}
void timSV(){
    student SVoi;
    int count = 0;
    FILE *data = fopen("SV2021.dat","r");
    FILE *out  = fopen("output.txt","a");
    char trace[30]; //chuoi su dung de tim kiem
    printf("Nhap ten Sinh Vien ma ban muon tim di: ");
    getchar();
    scanf("%[^\n]",trace); // Nhap chuoi tim kiem
    while (fscanf(data,"%[^\t]\t%f\n",SVoi.name,&SVoi.score)!=EOF){ //Quet theo tung dong
        if (strstr(SVoi.name,trace)!=NULL){         // Neu tim thay chuoi thi in ra
            printf("%s\t%0.1f\n",SVoi.name,SVoi.score);
            fprintf(out,"%s\t%0.1f\n",SVoi.name,SVoi.score);
            ++count;
        }
    }
    if (count ==0){
        printf("Khong tim thay ten Sinh Vien, chac bi duoi hoc roi!\n");
    }
    fclose(data);
    fclose(out);
}
