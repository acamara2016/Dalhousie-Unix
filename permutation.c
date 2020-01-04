/* Adama Camara B00757321
   This program take argument from user, then 
   generate an intial int then convert it into an array of char.
   The program will use permutation and change function to perform the permutation*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change(char *left, char *right);//declaring method that will swap the element of the string 
void permute(char *num, int left, int right);//declaring method that will perform the permutation 

int digitCOunt(int  n); //method to retrieve the digital count of the string

int digitCOunt(int n){
	int count;
       while(n!=0){
		n/=10;
		count++;
	}
	return count;       
}
void change(char *left, char *right){//swap from left to right
	char keep=*left;
	*left=*right;
	*right=keep;
}

int main(int argc, char* argv[]){
	int input=atoi(argv[1]);//convert the input into integer
	int iter;
	int round=0;
	int x=0;
	char string[input];
	for(iter=1; iter<=111111111111 && round<input; iter=iter*10+1){//for loop that make the final integer
		x=x+iter; //add 1, 11, 111, 1111, .... to 1  until it get to the desired int
		round++; 
	}
//	printf("Digit count %d\n", digitCOunt(x));
	round=input-1;
	sprintf(string, "%d", x);//convert int t string
	permute(string, 0, round);//launch the permutation
}

void permute(char *num, int left, int right){
	int iter;
	if(left != right){//if the program is still passing through the array
		iter=left;//start from left
		do{
			change((num+left), (num+iter));
			permute(num, left+1, right);
			change((num+left), (num+iter));
			iter++;
		} while(iter<=right);
	}else{//print the string when the left indexe is equal to the right one
		for(iter=0; iter<strlen(num); iter++){
			printf("%c ", num[iter]);
		}
		printf("\n");
	}
}

//permutation method inspired by: https://www.sanfoundry.com/cpp-program-find-permutation-of-string-characters/
