#include<stdio.h>

void putdig(int dig){
	if(dig>9){
	putdig(dig/10);
	}
	putchar('0'+dig%10);
}

int main(){
	int n1, n2;
	n1=123456789;
	n2=5;
	putdig(n1);
	putchar('\n');
	putdig(n2);
	putchar('\n');
}

