#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int dec_to_bin(int decimal) {
	if (decimal == 0) {
		printf("0\n");
		return 0;
	}

	int po2 = 1;	//po2 = power of 2
	while (po2 <= decimal) {
		po2 = po2*2;
	}

	po2 = po2 / 2;
	while (po2 > 0) {
		if (decimal >= po2) {
			printf("1");
			decimal = decimal - po2;
		} else {
			printf("0");
		}

		po2 = po2 / 2;
	}

	printf("\n");
	return 0;
}


int bin_to_dec(int binary) {
	int decimal = 0;
	int position_counter = 0, remainder;
	while (binary != 0) {
		remainder = binary % 10;
		decimal += remainder << position_counter;
		binary /= 10;
		++position_counter;
	}
	
	printf("%d\n", decimal);
	return 0;
}


int dec_to_hex(int decimal) {
	char* hex_digits = "0123456789ABCDEF";
	int remainder;
	char output[17];
	int index = 0;

	if (decimal == 0) {
		printf("0\n");
		return 0;
	}

	while (decimal != 0) {
		remainder = decimal % 16;
		output[index++] = hex_digits[remainder];
		decimal /= 16;
	}

	for (int i = index - 1; i >= 0; --i) {
		printf("%c", output[i]);
	}

	printf("\n");
	return 0;
}


int hex_to_dec(const char *hex) {
	int len = strlen(hex);
	int base = 1;
	int decimal = 0;

	for (int i = len - 1; i >= 0; i--) {
		char c = toupper(hex[i]);

		if (c >= '0' && c <= '9') {
			decimal = decimal + (c - '0') * base;
		} else if (c >= 'A' && c <= 'F') {
			decimal = decimal + (c - 'A' + 10) * base;
		} else {
			printf("Invalid hex digit: %c\n", c);
			return -1;
		}

		base = base * 16;
	}

	printf("%d\n", decimal);
	return decimal;
}


int main(int argc, char *argv[]) {
	int decimal = atoi(argv[1]);
	bool reverse = false;
	for (int rev_i = 0; rev_i < argc; rev_i++) {
		if (strcmp(argv[rev_i], "--rev") == 0) {
			reverse = true;
		}
	}

	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--help") == 0) {
			printf("Usage: NSCT [decimal number] [flags]\n");
			printf("Example: NSCT 1001 --bin --rev\n");
			printf("Options:\n");
			printf("  --help                   Display this information.\n");
			printf("   -h                      Display this information.\n");
			printf("  --bin                    Tells the programm to convert decimal to binary.\n");
			printf("  --hex                    Tells the programm to convert decimal to hexadecimal.\n");
			printf("  --rev                    Tells the programm to convert from hexadecimal or binary to decimal. (must be used with '--bin' or '--hex' in combination)\n");

			return 0;
		}

		if (strcmp(argv[i], "--bin") == 0) {
			if (reverse == true) {
				bin_to_dec(decimal);
			} else {
				dec_to_bin(decimal);
			}
			return 0;
		}

		if (strcmp(argv[i], "--hex") == 0) {
			if (reverse == true) {
				hex_to_dec(argv[1]);
			} else {
				dec_to_hex(decimal);
			}
			return 0;
		}
	}
	dec_to_bin(decimal);
	return 0;
}
