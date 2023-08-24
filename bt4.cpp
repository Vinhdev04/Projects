#include"stdio.h"

int UCLN(int a,int b){
	if(a==b)
		return a;
	if(a>b)
		return UCLN(a-b,b);
	else
		return UCLN(a,b-a);
}

int main(){
	int a;
	int b;
	printf("Nhap a va b ");
	scanf("%d%d",&a,&b);
	printf("UCLN(%d %d) = %d",a,b,UCLN(a,b));
}
