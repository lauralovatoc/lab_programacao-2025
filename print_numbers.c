#include<stdio.h>

void putdig(int dig){
	if(dig>9){
	putdig(dig/10);
	}
	putchar('0'+dig%10);
}

void put2dig(int num){
	if(num>9){
	putdig(num/10);
	}
	putdig(num%10);
}

void put3dig(int num){
	if(num>9){
	put2dig(num/10);
	}
	putdig(num%10);
}

void put4dig(int num){
	if(num>9){
	put3dig(num/10);
	}
	putdig(num%10);
}

void put5dig(int num){
	if(num>9){
	put4dig(num/10);
	}
	putdig(num%10);
}

void put6dig(int num){
	if(num>9){
	put5dig(num/10);
	}

	putdig(num%10);
}

int main(){
	int n1, n2;
	n1=123456789;
	n2=5;
	put6dig(n1);
	putchar('\n');
	put6dig(n2);
	putchar('\n');
}

