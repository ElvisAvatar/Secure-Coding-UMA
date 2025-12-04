#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPwOK(void){
char pw[12];
	gets(pw);
	return (0==strcmp(pw,"passbueno"));
}
int main(void){
	bool pwStatus;
	puts("Enter Password: ");
	pwStatus=isPwOK();
	if (!pwStatus){
	puts("Acceso Denegado"); return -1;
	}
	else puts("Acceso correcto");
}
