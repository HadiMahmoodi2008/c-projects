#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

for(int i = 1; i < argc; i++)
{
    char *found = strpbrk(argv[i], "+-*/");
    if (found != NULL) 
    {
        size_t len_left = found - argv[i];
        char left_part[12];
        strncpy(left_part, argv[i], len_left);
        left_part[len_left] = '\0';

        char op = *found;

        char right_part[12];
        strncpy(right_part, found + 1, sizeof(right_part) - 1);
        right_part[sizeof(right_part) - 1] = '\0';

        int left_num = atoi(left_part);
        int right_num = atoi(right_part);
        int result = 0;
        int valid = 1;

        switch(op) {
            case '+': result = left_num + right_num; break;
            case '-': result = left_num - right_num; break;
            case '*': result = left_num * right_num; break;
            case '/': 
                if (right_num != 0) result = left_num / right_num;
                else { printf("Error: vivision by zero\n"); valid = 0; }
                break;
            default: valid = 0; break;
        }
        if (valid) {
            printf("%d\n", result);
        }
    }
    else 
    {
        printf("%s", argv[i]);
    }
}

    return 0;
}
