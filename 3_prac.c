#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int num_queries;
    printf("Enter the number of queries: ");
    scanf("%d", &num_queries);
    
    for (int query = 0; query < num_queries; query++) {
        char num[20];
        int decimal = 0;
        printf("Enter an integer constant (in decimal, octal, or hexadecimal format) for query %d: ", query + 1);
        scanf("%s", num);

        int is_negative = 0;
        int start_index = 0;

        if (num[0] == '-') {
            is_negative = 1;
            start_index = 1;
        } else if (num[0] == '+') {
            start_index = 1;
        }

        int base = 10;
        if (num[start_index] == '0') {
            if (num[start_index + 1] == 'x' || num[start_index + 1] == 'X') {
                base = 16;
                start_index += 2;
            } else {
                base = 8;
                start_index += 1;
            }
        }

        int i = start_index;
        while (num[i] != '\0') {
            int digit;
            if (isdigit(num[i])) {
                digit = num[i] - '0';
            } else if (isalpha(num[i])) {
                digit = toupper(num[i]) - 'A' + 10;
            } else {
                printf("Invalid character: %c\n", num[i]);
                return 1;
            }
            if (digit >= base) {
                printf("Invalid digit for base %d: %c\n", base, num[i]);
                return 1;
            }
            decimal = decimal * base + digit;
            i++;
        }

        if (is_negative) {
            decimal = -decimal;
        }
        printf("The decimal equivalent of %s is %d\n", num, decimal);
    }

    return 0;
}


/*

+15
-5
123
+0123
0117
-0777
0x1F
0x111

*/
