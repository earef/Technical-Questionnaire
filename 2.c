#include <stdio.h>

int New_strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int main() {
    char input_string[1000]

    printf("please enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    int length = New_strlen(input_string);

    printf("The length of your string is: %d\n", length);

    return 0;
}
