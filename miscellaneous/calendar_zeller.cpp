//Print calendar of any year using Zeller's formula
#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int y) {
    return (!(y % 4) && y % 100) || !(y % 400);
}

int getDow(int q, int m, int y) {
    if (m == 1) { m = 13; y--; }
    if (m == 2) { m = 14; y--; }
    int k = y % 100;
    int j = y / 100;
    int h = q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    return h == 0 ? 6 : h - 1;
}

int main()
{
    char months[12][10] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    char daysow[7][4] = {"S", "M", "T", "W", "T", "F", "S"};
    
    int y;
    printf("Input year: ");
    scanf("%d", &y);
    
    putchar('\n');
    
    for (int m = 1; m <= 12; m++, printf("\n")) {
        printf("%s\n", months[m - 1]);
        
        int top;
        switch(m) {
            case 2: top = isLeapYear(y) ? 29 : 28; break;
            case 4: case 6: case 9: case 11: top = 30; break;
            default: top = 31; break;
        }
        
        int dow = getDow(1, m, y);

        int days[6][7] = {0};
        int* d = days[0];
        for (int i = 0; i < dow; i++) d++;
        for (int i = 0; i < top; i++) *(d++) = i + 1;
        for (int i = 0; i < 7; i++) printf("%3s", daysow[i]);
        printf("\n");
        int row = dow + top > 35 ? 6 : 5;
        for (int i = 0; i < row; i++, putchar('\n'))
            for (int j = 0; j < 7; j++)
                days[i][j] == 0 ? printf("%3s", " ") : printf("%3d", days[i][j]);
            
    }
    
    return 0;
}
