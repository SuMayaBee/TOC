#include <stdio.h>
#include <stdbool.h>

void generate_combinations(int length, char* bit_string, int index) {
    if (index == length) {
        printf("%s\n", bit_string);
        return;
    }

    bit_string[index] = '0';
    generate_combinations(length, bit_string, index + 1);

    bit_string[index] = '1';
    generate_combinations(length, bit_string, index + 1);
}

int main() {
    int length; // Specify the desired length of the bit string
    printf("enter length: ");  
    scanf("%d",&length);
    char bit_string[length + 1]; // +1 for the null terminator
    bit_string[length] = '\0'; // Null terminator for the string

    generate_combinations(length, bit_string, 0);

    return 0;
}

