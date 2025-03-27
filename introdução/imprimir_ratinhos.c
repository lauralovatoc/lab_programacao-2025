#include<stdio.h>

void ratinhos(int n){
	if(n>0){
	   puts("<:3)~~~");
	   ratinhos(n-1);
	}
}

int get2dig(){
	int dig1, dig2, n;
	dig1 = getchar() - '0';
	dig2 =  getchar() - '0';
	n = 10*dig1 + dig2;
	return n;
}

int get3dig(){
        int two_digits, dig3, n;
        two_digits = get2dig();
        dig3 =  getchar() - '0';
        n = 10*two_digits + dig3;
        return n;
}

int main(){
	puts("Impressor de ratinhos");
	puts("Quantos ratinhos?");
	int n;
	n=get3dig();
	ratinhos(n);
}
