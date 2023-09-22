/*
 * EX3.c
 *
 *  Created on: 21 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
void reverse(char str[]);
int main(){
	char str[100];
	printf("Enter a sentence : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	reverse(str);
	printf("%s",str);
	return 0;
}
void reverse(char str[]){
	int i,len,temp;
	len=strlen(str);
	for(i=0;i<len/2;i++){
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;

	}

}
