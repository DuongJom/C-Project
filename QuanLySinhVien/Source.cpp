#include<stdio.h>
#include<string.h>
#define fo "danhsach.txt"

struct SinhVien {
	char ID[15];
	char ten[50];
	char diem;
};

void nhapTT1SV(SinhVien& s) {
	printf("Nhap ID: ");
	scanf("%s", &s.ID); fflush(stdin);
	printf("Nhap ten: ");
	gets(s.ten); fflush(stdin);
	printf("Nhap diem: ");
	scanf("%c", &s.diem);fflush(stdin);
}

void themSV(SinhVien a[], int& n, SinhVien x) {
	a[n++] = x;
}

void capNhatTT(SinhVien a[], int n, char ID[]){
	printf("Nhap ID sinh vien can cap nhat thong tin: ");
	gets(ID); fflush(stdin);
	bool flag=false;
	for(int i=0;i<n;i++){
		if(strcmp(a[i].ID,ID)==0){
			printf("Ban muon cap nhat thong tin gi?\n");
			printf("1. Ho ten\t2. Diem\n");
			printf("==> Moi ban chon: ");
			int chon;
			scanf("%d",&chon); fflush(stdin);
			switch(chon)
			{
			case 1:
				char tenMoi[50];
				printf("Nhap ten moi: ");
				strcpy(a[i].ten,gets(tenMoi));
				break;
			case 2:
				char diemMoi;
				printf("Nhap diem moi: ");
				scanf("%c",&diemMoi); fflush(stdin);
				a[i].diem=diemMoi;
				break;
			}
			flag=true;
			break;
		}
	}
	if(flag==false)
		printf("Sinh vien co ID \"%s\" khong ton tai!",ID);
}
void xuatSV(SinhVien s){
	printf("ID: %s\nTen: %s\nDiem: %c\n", s.ID,s.ten,s.diem);
}
void thongKe(SinhVien a[], int n){
	int diemA=0,diemB=0,diemC=0,diemD=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].diem=='A') diemA++;
		if(a[i].diem=='B') diemB++;
		if(a[i].diem=='C') diemC++;
		if(a[i].diem=='D') diemD++;
	}
	printf("Co %d sinh vien dat diem A. Chiem %.2f%%.\n",diemA,diemA*100*1.0/n);
	printf("Co %d sinh vien dat diem B. Chiem %.2f%%.\n",diemB,diemB*100*1.0/n);
	printf("Co %d sinh vien dat diem C. Chiem %.2f%%.\n",diemC,diemC*100*1.0/n);
	printf("Co %d sinh vien dat diem D. Chiem %.2f%%.\n",diemD,diemD*100*1.0/n);
}
void xoaTT(SinhVien a[], int &n, int pos)
{
	if (n <= 0) {
		return;
	}
	if (pos < 0) {
		pos = 0;
	}
	else if (pos >= n) {
		pos = n - 1;
	}
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	--n;
}
void xoaSV(SinhVien a[], int &n, char ID[]){
	printf("Nhap ID sinh vien can xoa: ");
	gets(ID);
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].ID,ID)==0){
			xoaTT(a,n,i);
			flag=true;
			break;
		}
	}
	if(flag==false)
		printf("Sinh vien co ID \"%s\" khong ton tai!",ID);
}

void timKiem(SinhVien a[], int n)
{
	printf("\nBan muon tim theo ten hay ID?\n");
	printf("1. Ten\t2. ID\n");
	int chon;
	printf("==> Moi ban chon: ");
	scanf("%d",&chon); fflush(stdin);
	if(chon==1){
		char ten[50];
		gets(ten);
		for(int i=0;i<n;i++){
			if(strcmp(a[i].ten,ten)==0){ 
				xuatSV(a[i]);
			}
		}
	}else{
		printf("Nhap ID can tim: ");
		char ID[15];
		gets(ID);
		for(int i=0;i<n;i++){
			if(strcmp(a[i].ID,ID)==0) xuatSV(a[i]);
		}
	}
}

void sapXep(SinhVien a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].diem>a[j].diem)
			{
				SinhVien tmp = a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
void hienThiDS(SinhVien a[], int n){
	for(int i=0;i<n;i++)
	{
		printf("Sinh vien thu %d:\n",i+1);
		xuatSV(a[i]);
	}
}

void ghiFile(SinhVien a[], int n)
{
	FILE* f = fopen(fo,"w");
	for(int i=0;i<n;i++)
	{
		fprintf(f,"Sinh vien thu %d:\n",i+1);
		fprintf(f,"\tID: %s\n",a[i].ID);
		fprintf(f,"\tHo ten: %s\n",a[i].ten);
		fprintf(f,"\tDiem: %c\n",a[i].diem);
	}
	fclose(f);
}
void menu(){
	printf("1. Them sinh vien\n");
	printf("2. Cap nhat thong tin sinh vien theo ID\n");
	printf("3. Thong ke diem\n");
	printf("4. Xoa sinh vien\n");
	printf("5. Tim kiem theo Ten, ID\n");
	printf("6. Sap xep diem giam dan\n");
	printf("7. Hien thi danh sach\n");
	printf("8. Ghi danh sach ra file\n");
}
int main() {
	SinhVien a[100];
	int n = 0;
	bool flag=true;
	while(flag==true){
		menu();
		printf("Moi ban chon chuc nang(1-8): ");
		int chon;
		scanf("%d",&chon); fflush(stdin);
		switch(chon){
		case 1: 
			printf("\n=========================================");
			printf("\nBan da chon chuc nang THEM SINH VIEN\n");
			SinhVien x;
			nhapTT1SV(x);
			themSV(a,n,x);
			printf("\n==> HOAN TAT THEM!\n");
			printf("\n=========================================\n");
			break;
		case 2:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang CAP NHAT THONG TIN SINH VIEN\n");
			char ID[15];
			capNhatTT(a,n,ID);
			printf("\n==> HOAN TAT CAP NHAT!\n");
			printf("\n=========================================\n");
			break;
		case 3:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang THONG KE\n");
			thongKe(a,n);
			printf("\n=========================================\n");
			break;
		case 4:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang XOA THONG TIN SINH VIEN\n");
			char Id[15];
			xoaSV(a,n,Id);
			printf("\n==> HOAN TAT XOA!\n");
			printf("\n=========================================\n");
			break;
		case 5:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang TIM KIEM\n");
			timKiem(a,n);
			printf("\n=========================================\n");
			break;
		case 6:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang SAP XEP\n");
			sapXep(a,n);
			printf("\n==> HOAN TAT SAP XEP!\n");
			printf("\n=========================================\n");
			break;
		case 7:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang HIEN THI DANH SACH\n");
			hienThiDS(a,n);
			printf("\n=========================================\n");
			break;
		case 8:
			printf("\n=========================================");
			printf("\nBan da chon chuc nang GHI DANH SACH RA FILE\n");
			ghiFile(a,n);
			printf("\nHOAN TAT GHI!\n");
			printf("\n=========================================\n");
			break;
		default:
			flag=false;
			break;
		}
	}
	return 0;
}