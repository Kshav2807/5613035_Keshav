#include <stdio.h>

char* counterGame(long num) {
    static char louise[] = "Louise";
    static char richard[] = "Richard";
    int turn = 0; 

    while (num > 1) {
       
        if ((num & (num - 1)) == 0) {
            num = num / 2;
        } else {
            
            long a = 1;
            while (a * 2 < num) {
                a = a * 2;
            }
            num = num - a;
        }
        turn = 1 - turn; 
    }

    if (turn == 1) {
        return louise;
    } else {
        return richard;
    }
}

int main() {
    int x;
    long num;
    scanf("%d", &x);
    while (x--) {
        scanf("%ld", &num);
        printf("%s\n", counterGame(num));
    }
    return 0;
}
