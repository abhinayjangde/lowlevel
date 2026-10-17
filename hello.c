#include <stdio.h>

int main(){
	int actual_number = 0x23;
	int input_number;

	printf("guess the number? ");
	scanf("%d", &input_number);

	if (actual_number == input_number){
		printf("You got this\n");
	}else{
		printf("bad luck\n");
	}

	return 0;
}
