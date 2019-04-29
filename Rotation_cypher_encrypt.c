#include<stdio.h> //standard library
#include<string.h> //string library

char *encrypt(char[]); //declare function for encryption
void *decrypt(char []); //declare function for decryption

int main() {
	int i, key, choice, flag=0; //integers: for in functions( i for a counter along the letters and key is the shift in cipher), 
                                // choice is the user input , flag to indicate if an encryption has occured before.
	char msg[150]; //a string of 150 characters for a text to use
	char *c_text; //pointer to store  a set of encypted characters
	
	printf("Enter text to code : ");
	scanf("%[^\n]", msg); //scans an input of text
	printf("\n Your plain text is : %s", msg);
	
	do{
		printf("\n press 1 to enrypt \n press 2 to decrypt \n press '0' for exit \n"); // choice menu to make interface easier
		scanf("%d", &choice);
	switch(choice) {
		case 1: c_text = encrypt(msg);
			flag = 1; break;
		case 2: if(flag == 1) decrypt(c_text); //if encryption has occured it prints the decrypt function
				else(printf("First perform encryption")); // if an encryption has not happened, flag = 0, and user is told there is nothing to decrypt
			break;
		case 0: break;
		default: printf("\n please enter a valid choice"); //if user inputs a non useful input 
		}
	} while (choice !=0); //the code will not proceed if input is nothing
}

char *encrypt (char cipher_text[]){ //encryption function drawing from the pointer cipher_text
	int key, i; //variable key is the same as declared in main and is the shift of cipher, i is for the counter of letters
	
	printf("enter the key for encyption :"); //prompt for the user
	scanf("%d", &key); // user inputs any key to shift the cipher
	
    //counter of letters and the shift of the letters by the key i.e. a ceasar cipher
	for(i=0; i<strlen(cipher_text); i++){ //counter for the legnth of the text string
		if (cipher_text[i]>='0' && cipher_text[i]<='z'){ //for text which is more than a nothing input and for letters in the alphabet
		cipher_text[i] = cipher_text[i] + key;
			if (cipher_text[i]>'z') {cipher_text[i]-26;} //for letters or text outside of the alphabet in ascii will be adjusted into a letter
		}
		
	}
	
	printf("your encrypted message:	%s", cipher_text); // printing output of encryption
	return cipher_text;
}

void *decrypt(char cipher_text[]){
	int i, key;
	char cipher [300]; //a very large string to call on for a very large encrypted file
	strcpy (cipher, cipher_text); //copy of string last used
	printf("\n decryption process \n"); // to separate the dialogue from above in the text to the user
	
	for (key =1; key <=26; key++){ // counter for all possible keys used in a ceasar cipher rotation
		for (i=0; i<strlen(cipher_text);i++){ 
			if (cipher_text[i]>='a' && cipher_text[i]<='z') { 
			cipher[i] = cipher_text[i] -key; } // reversal of key for characters increased by the above
			if (cipher[i]<'a'){ //for characters outside of alpabet are adjusted back from the encryption above
			cipher[i] = cipher[i] +26; }
		printf("\n Decryption: %s", cipher); //will print each iteration of a ceasar cypher
		}
	}
}
