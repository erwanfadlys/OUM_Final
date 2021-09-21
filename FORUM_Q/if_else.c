#include <stdio.h>

float water_temp = 0;
int main(){ 
    
    printf("Captain Obviouse Ver 1.0\n\n");
    printf("Please enter the water temperature value\n");
    scanf("%f", &water_temp);

    if (water_temp <= 10){
        printf("%.01f celcius?! Thats cold water!\n", water_temp);
    }
    else if (water_temp >= 11 && water_temp <= 25){
        printf("That water is tepid!, at %.01f celcius, lukewarm at most.\n", water_temp);
    }
    else if (water_temp >= 26){
        printf("At %.01f celcius, this water can be considered hot.\n", water_temp);
    }
 
    return 0;
}