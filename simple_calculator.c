#include <stdio.h>
int main()
{
    float x, y;
    printf("Enter X:");
    scanf("%f", &x);
    printf("Enter Y:");
    scanf("%f", &y);

    printf("Choose the operation to perform:\n");
    printf("1 -> add\n");
    printf("2 -> subtract\n");
    printf("3 -> multiply\n");
    printf("4 -> divide\n");
    printf("Enter your option:");
    int status;
    scanf("%d", &status);

    switch (status)
    {
    case 1:
        printf("%f + %f = %f", x, y, x + y);
        break;
    case 2:
        printf("%f - %f = %f", x, y, x - y);
        break;
    case 3:
        printf("%f * %f = %f", x, y, x * y);
        break;
    case 4:
        printf("%f / %f = %f", x, y, x / y);
        break;
    default:
        printf("Enter a valid option");
        break;
    }
}