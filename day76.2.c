#include <stdio.h>

enum Color {
    RED,
    BLUE,
    GREEN,
    YELLOW,
    ORANGE,
    PURPLE,
    PINK,
    BLACK,
    WHITE,
    BROWN,
    GREY,
    CYAN
};

int main() {
    enum Color color;

    char *names[] = {
        "RED", "BLUE", "GREEN", "YELLOW",
        "ORANGE", "PURPLE", "PINK", "BLACK",
        "WHITE", "BROWN", "GREY", "CYAN"
    };

    for (color = RED; color <= CYAN; color++) {
        printf("%s=%d\n", names[color], color);
    }

    return 0;
}
