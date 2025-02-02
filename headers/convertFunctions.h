
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

