
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



A Bulls and Cows game, wherer your friend selects a positive integer 
number and you need to guess it.

Here,
 Bulls = The right digit in the right position from you firend's number.
 cows = The correct digit but not necessarily in right place. 

@Author Vishwanath Gulabal
Still in improvement



++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include<iostream>
#include<stdlib.h>
#define MAX 1000

using namespace std;

int num,bulls,cows;
int arr[MAX];

//To print the total number of cows and bulls based on guessed number  
void BullsAndCows(int b,int c){

	cout <<"Bulls " << b << endl;
	cout <<"Cows " << c << endl;

}

//check whether the guessed number if correct or not
void CheckNumber(int number) {
	int guessed_number = 0,temp1 = 0,temp2 = number,length = 0, count =0;
	int j_index = 0;
	char ch;
	//To count cows , storing digits in an array
		while(temp2 !=0 ){
			arr[j_index] = temp2 % 10;
			temp2 = temp2 / 10;
			length = length + 1;//length of the number
			j_index = j_index + 1;
		}
	
	while(1) {
		
		count = count + 1;//if user wants to give up after trying six or seven times.
		cout << "Now guess the number " << endl;
		cin >> guessed_number;
		if(number == guessed_number) {
			cout << "You guessed it right "<< endl;
			BullsAndCows(4,0);
			cout << "You won " << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			break;		
		} 
		else {
			temp1 = guessed_number;
			temp2 = number;
			while(temp1 != 0 && temp2 != 0){
				int n = temp1 % 10;
				int m = temp2 % 10;
				if(n == m)
					bulls++;
				else{
					//to count cows,
					for(int i_index = 0;i_index < length;i_index++){
						
						if(n == arr[i_index]) 
							cows = cows + 1;
					}
				}
				
				temp1 = temp1 / 10;
				temp2 = temp2 / 10;				
			}
		}
		BullsAndCows(bulls,cows);	
		bulls = 0;
		cows = 0;
		l1:if(count%6 == 0 ) {
			cout << "Tiered of guessing, want to QUIT (y or n)?" << endl;
			cin >> ch;
			if( ch == 'y' || ch == 'Y'){
					cout << "The number is " << num << endl;
					cout << "Well played " << endl;
					break; 
			}
			else if(ch == 'n' || ch == 'N')
	      				cout << "Then, continue " << endl;
	 		else{
					cout << "Enter 'y' or 'n'" << endl;
					goto l1;			
				}
			}
		}
}

int main(void) {
	
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	srand( time(NULL));
	num = rand() % 9000 + 1000; // formula is rand() % (b - a + 1) + a
	
//	cout << num << endl;

	cout << "Computer already recorded a number " << endl;

	CheckNumber(num);

	return 0;
}
