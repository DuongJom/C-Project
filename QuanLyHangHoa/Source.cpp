#include<stdio.h>
#include<string.h>
#define file "PRODUCT.BNR"
#define sortedFile "SORTED.BNR"

typedef struct PRODUCT
{
	char ma[20];
	char ten[50];
	int soLuong;
	float donGia;
} P;

int n=0;
P a[100];

void nhapTT(P& p) {
	fflush(stdin);
	printf("Nhap ma: ");
	gets(p.ma); fflush(stdin);
	printf("Nhap ten: ");
	gets(p.ten); fflush(stdin);
	printf("Nhap so luong: ");
	scanf("%d", &p.soLuong); fflush(stdin);
	printf("Nhap don gia: ");
	scanf("%f", &p.donGia); fflush(stdin);
}

void nhapDS(P a[], int& n)
{
	printf("Nhap so luong hang hoa: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap thong tin hang hoa thu %d:\n", i + 1);
		nhapTT(a[i]);
	}
}

void ghiFile(char fileName[])
{
	FILE* data;

	if ((data = fopen(fileName, "wb")) == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	fwrite(a, sizeof(P) * n, 1, data);
	fclose(data);
}

void docFile(char fileName[])
{
	FILE* data;
	if ((data = fopen(fileName, "rb")) == NULL)
	{
		printf("Error opening file\n");
		return;
	}
	fread(a, sizeof(P) * n, 1, data);
	fclose(data);
}
void hienThiThanhTien(P a[], int n)
{
	float tongTien = 0;
	printf("\nMa\tTen\t\tSo luong\tDon gia\t\tThanh tien\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%s\t%d\t\t%2.f\t\t%.2f\n", a[i].ma, a[i].ten, a[i].soLuong, a[i].donGia, a[i].soLuong * a[i].donGia);
		tongTien += a[i].soLuong * a[i].donGia;
	}
	printf("\nTong tien: %.2f\n", tongTien);
}
void sapXep(P a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].soLuong * a[i].donGia < a[j].soLuong * a[j].donGia) {
				P tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
int main() {
	P a[100];
	int n;
	nhapDS(a, n);
	ghiFile(file);
	docFile(file);

	printf("\nDanh sach chua sap xep:\n");
	hienThiThanhTien(a, n);

	printf("\nDanh sach sau sap xep:\n");
	sapXep(a, n);
	hienThiThanhTien(a,n);

	ghiFile(sortedFile);
	return 0;
}