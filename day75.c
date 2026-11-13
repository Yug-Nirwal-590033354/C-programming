#include <stdio.h>

enum Values {
    A = 10,
    B,
    C
};

int main()
{
    printf("A=%d, B=%d, C=%d", A, B, C);

    return 0;
}
