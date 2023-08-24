#include"stdio.h"
int fibo(int n){
	if(n==1 || n==2)
		return 1;
	return fibo(n-1) + fibo(n-2);	
}

int main(){
	int n;
	printf("nhap n =");
	scanf("%d",&n);
	printf("fibo thu %d = %d",n,fibo(n));

}
