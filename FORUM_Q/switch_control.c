#include <stdio.h>

int main(){
    int water_temp;

    printf("Captain Obvious Ver 1.1\n");
    printf("Please enter the water temperature value\n");
    scanf("%d", &water_temp);
    switch (water_temp) {
        case 0 ... 11: //... can be use for range
            printf("%d celcius?! Thats cold water!\n", water_temp);
            break;
        case 12 ... 25:
            printf("That water is tepid!, at %d celcius, lukewarm at most.\n", water_temp);
            break;
        case 26 ... 99:
            printf("At %d celcius, this water can be considered hot.\n", water_temp);
            break;
        case 100:
            printf("That water is boiling, be extra careful\n");
        default:
            printf("Please insert the water temperature value below boiling point\n");
    }
    return 0;
}