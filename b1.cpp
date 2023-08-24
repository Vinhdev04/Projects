#include"stdio.h"
#include"math.h"

void nhapN(int &n){
	do{
		printf("Nhap so phan tu cau mang : ");
		scanf("%d",&n);
	}while(n<=0);
}

void nhapMang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}

void xuatMang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%4d",a[i]);
	}
}

int tinhTong(int a[],int n){
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	return sum;
}

float trungBinhCong(int a[],int n){
	int count=0;
	float tbc,sum=0;
	for(int i=0; i<n; i++){
		sum += a[i];
		count++;
	}
	return tbc = sum/count;
	
}


void timX(int a[],int n){
	int x;
	printf("Nhap x can tim : ");
	scanf("%d",&x);
	printf("\nVi tri x trong mang :");
	for(int i=0; i<n; i++){
		if(a[i]==x){
			printf("%d",i);
	    }
	}
}

int timTuyenTinh(int a[],int n,int x){
	for(int i=0; i<n;i++){
		if(a[i]==x)
			return i;
	}
	return -1;
}

int binarySearch(int a[],int n,int k){
	int left = 0;
	int right = n-1;
	int mid;
	while(left <= right){
		mid = (left+right)/2;
		if(a[mid]==k)
			return a[mid];
		else if(a[mid]<k)
			left = mid + 1; // tim ben phai mang
		else
			right = mid - 1;	// tim ben trai mang
	}
}

void insertionSort(int a[],int n){
	int temp;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){      // sap xep tang
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main(){
	int n;
	int a[100];
	nhapN(n);
	nhapMang(a,n);
	printf("\nMang vua nhap la :\n");
	xuatMang(a,n);
	
// Tinh tong va Trung Binh Cong	
	printf("\nTong = %d\n",tinhTong(a,n));
	printf("\nTrung Binh Cong = %.2f\n",trungBinhCong(a,n));
	
// Tim kiem tuyen tinh	
	timX(a,n);
	
// Tim X Cuoi Trong Mang
	int x;
	printf("\nNhap x =");
	scanf("%d",&x);
	int kq = timTuyenTinh(a,n,x);
	printf("Vi tri cua %d trong mang la %d",x,kq);

// 	Sap Xep Tang Theo Insertion Sort

	printf("\nMang sau khi sort : ");
	insertionSort(a,n);
	xuatMang(a,n);

// Tim kiem BinarySearch (sap xep truoc khi dung)	
	int k;
	printf("\nNhap k =");
	scanf("%d",&k);
	int ketqua = binarySearch(a,n,k);
	if(ketqua )
		printf("\nTim thay %d trong mang !",k);
	else
		printf("\nKhong tim thay %d trong mang !",k);
		

	return 0;
}

