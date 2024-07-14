#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>


int atoi(char s[], int *result)
{
    int i, n, sign;
    sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    for (n = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 10 * n + (s[i] - '0');
        } else if (isspace(s[i])) {
            errno = EINVAL;
            return -2;  
        } else {
            errno = EINVAL;
            return -1;  
        }
    }
    
    *result = sign * n;
    return 0;
}

int main() {
    char input_string[100];
    int num;
    
    printf("llease enter your string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = 0;

    int status = atoi(input_string, &num);
    if (status == 0) {
        printf("The converted int number is: %d\n", num);
    } else if (status == -2) {
        printf("Error: Invalid input. Contains space, please reenter your string.\n");
    } else {
        printf("Error: Invalid input. Contains nonnumeric characters, please reenter your string.\n");
    }

    return 0;
}
