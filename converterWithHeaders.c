#include <stdio.h>
#include <string.h>  // only for using strlen

/* main functions */
void DecimalToBinary(int);
int BinaryToDecimal(char*);
int DecimalToOctal(int);
int OctalToDecimal(char*);
void DecimalToHexadecimal(int);
int HexadecimalToDecimal(char*);

/* These functions work using functions declaring above */
int BinaryToOctal(char*);
void OctalToBinary(char*);
void BinaryToHexadecimal(char*);
void HexadecimalToBinary(char*);
void OctalToHexadecimal(char*);
int HexadecimalToOctal(char*);

int main()
{
	printf("\n\t Hi, I can help you to convert numbers from one system to another! \n\n");
	int number = 0; // To enter a decimal(10) number
	char strNum[32]; // To enter a binary(2), an octal(8) or hexadecimal(16) number
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

/* Main functions */

void DecimalToBinary(int num) {
	int i = 0;
	int arr[32];

	while(num) {
		arr[i] = num % 2;
		num /= 2;
		++i;
	}

	for(int j = i - 1; j >= 0; --j) {
		printf("%d", arr[j]);
	}
	printf("\n");
}

int BinaryToDecimal(char* binary) {
	int decimal = 0;
	int length = strlen(binary);

	for(int i = 0; i < length; ++i) {
		if(binary[i] == '1') {
			decimal += 1 << (length - 1 - i);
		}
		else if(binary[i] != '0') {
			return -1;
		}	
	}
	return decimal;
}

int DecimalToOctal(int DecimalNum) {
	int octal = 0;
	int i = 1;

	while(DecimalNum) {
		octal += (DecimalNum % 8) * i;
		DecimalNum /= 8;
		i *= 10;
	}
	return octal;
}

int OctalToDecimal(char* octalNum) {
	int decimal = 0;
	int length = strlen(octalNum);

	for(int i = 0; i < length; ++i) {
		if(octalNum[i] < '0' || octalNum[i] > '7') {
			return -1;
		}

		decimal = decimal * 8 + (octalNum[i] - '0');
	}
	return decimal;
}


void DecimalToHexadecimal(int decimal) {
    char hex[100];
    int i = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;

        if (remainder < 10)
            hex[i++] = remainder + 48; // '0' = 48 in ASCII
        else
            hex[i++] = remainder + 55; // 'A' = 65 in ASCII

        decimal = decimal / 16;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

int HexadecimalToDecimal(char* hex) {
	int decimal = 0;
	int base = 1;
	int value = 0;
	int length = strlen(hex);
	for(int i = length - 1; i >= 0; --i) {
		if(hex[i] >= '0' && hex[i] <= '9') {
			value = hex[i] - '0';
		}
		else if(hex[i] >= 'A' && hex[i] <= 'F') {
			value = hex[i] - 'A' + 10;
		}
		else {
			return -1;
		}

		decimal += value * base;
		base *= 16;
	}
	return decimal;
}

/* Other functions that use main functions */

int BinaryToOctal(char* binNum) {
	int dec = BinaryToDecimal(binNum);
	int octal = DecimalToOctal(dec);
	return octal;
}

void OctalToBinary(char* octalNum) {
	int dec = OctalToDecimal(octalNum);
	DecimalToBinary(dec);
}

void BinaryToHexadecimal(char* binNum) {
	int dec = BinaryToDecimal(binNum);
	DecimalToHexadecimal(dec);
}

void HexadecimalToBinary(char* hexNum) {
	int dec = HexadecimalToDecimal(hexNum);
	DecimalToBinary(dec);
}

void OctalToHexadecimal(char* octalNum) {
	int dec = OctalToDecimal(octalNum);
	DecimalToHexadecimal(dec);
}

int HexadecimalToOctal(char* hexNum) {
	int dec = HexadecimalToDecimal(hexNum);
	int octal = DecimalToOctal(dec);
	return octal;
}

