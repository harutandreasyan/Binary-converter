#include <stdio.h>
#include <string.h>  // only for using strlen
#include "./headers/convertFunctions.h"

int main()
{
	printf("\n\t Hi, I can help you to convert numbers from one system to another! \n\n");
	int number = 0; // To enter a decimal(10) number
	char strNum[40]; // To enter a binary(2), an octal(8) or hexadecimal(16) number
	int inputSystem = 0;
	do {
		printf("Enter the input system (2,8,10 or 16): ");
		scanf("%d", &inputSystem);
	} while(inputSystem != 2 && inputSystem != 8 && inputSystem != 10 && inputSystem != 16);
	printf("\n");
	if(inputSystem == 10) {
		printf("Enter the number in chosen (%d) system: ", inputSystem);
		scanf("%d", &number);
		printf("\n");
	}
	else {
		printf("Enter the number in chosen (%d) system: ", inputSystem);
		scanf("%s", strNum);
		printf("\n");
	}
	
	/* Since some functions receive an array of chars as an argument, it is necessary to convert the value
	   entered in "number" to an array of chars and use as needed.
	   That's why we use <sprintf> method. */

/*	char numberToString[40]; 
	sprintf(numberToString, "%d", number); 
*/	
	int outputSystem = 0;
	do {
		printf("Enter the output system (2,8,10 or 16): ");
		scanf("%d", &outputSystem);
	} while(outputSystem != 2 && outputSystem != 8 && outputSystem != 10 && outputSystem != 16);
	printf("\n");
	
	/* Using switch, for each input and output system,
	   we call the corresponding functions and print the corresponding messages. */

	switch(inputSystem) {
		case 2:
			if(outputSystem == 2) {
				printf("Output and input are the same. \n");
				break;
			}
			else if(outputSystem == 8) {
				int octal = BinaryToOctal(strNum);
				if(octal != -1) {
					printf("Octal of given number = %d \n", octal);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 10) {
				int decimal = BinaryToDecimal(strNum);
				if(decimal != -1) {
					printf("Decimal of given number = %d \n", decimal);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 16) {
				int dec = BinaryToDecimal(strNum);
				if(dec != -1) {
					printf("Hexadecimal of given number = ");
					BinaryToHexadecimal(strNum);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
		case 8:
			if(outputSystem == 8) {
				printf("Output and input are the same. \n");
				break;
			}
			else if(outputSystem == 2) {
				int dec = OctalToDecimal(strNum);
				if(dec != -1) {
					printf("Binary of given number = ");
					OctalToBinary(strNum);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 10) {
				int octToDec = OctalToDecimal(strNum);
				if(octToDec != -1) {
					printf("Decimal of given number = %d \n", octToDec);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 16) {
				int dec = OctalToDecimal(strNum);
				if(dec != -1) {
					printf("Hexadecimal of given number = ");
					OctalToHexadecimal(strNum);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
		case 10:
			if(outputSystem == 10) {
				printf("Output and input are the same. \n");
				break;
			}
			else if(outputSystem == 2) {
				printf("Binary of given number = ");
				DecimalToBinary(number);
				break;
			}
			else if(outputSystem == 8) {
				int decToOct = DecimalToOctal(number);
				printf("Octal of given number = %d \n", decToOct);
				break;
			}
			else if(outputSystem == 16) {
				printf("Hexadecimal of given number = ");
				DecimalToHexadecimal(number);
				break;
			}
		case 16:
			if(outputSystem == 16) {
				printf("Output and input are the same. \n");
				break;
			}
			else if(outputSystem == 2) {
				int dec = HexadecimalToDecimal(strNum);
				if(dec != -1) {
					printf("Binary of given number = ");
					HexadecimalToBinary(strNum);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 8) {
				int dec = HexadecimalToDecimal(strNum);
				if(dec != -1) {
					int hexToOct = HexadecimalToOctal(strNum);
					printf("Octal of given number = %d \n", hexToOct);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}
			else if(outputSystem == 10) {
				int hexToDec = HexadecimalToDecimal(strNum);
				if(hexToDec != -1) {
					printf("Decimal of given number = %d \n", hexToDec);
				} else printf("Imported is inappropriate for input system! \n");
				break;
			}

	}
}

