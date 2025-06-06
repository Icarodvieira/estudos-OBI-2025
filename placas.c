#include <stdio.h>
#include <string.h>

int main() {
   
    // 1, se a placa está no antigo padrão Brasileiro; OBI-2024
    // 2, se a placa está no novo padrão Mercosul; OBI2P24
    // 0, se a placa é falsificada OBI-24

    char placa[10];

    scanf("%s", placa);

    if(strlen(placa) == 8){
        if(placa[3] != 45){
            printf("0");
            return 0;
        }
        for (int i = 0; i < 3; i++){
            if(placa[i] < 65 || placa[i] > 90){
                printf("0");
                return 0;
            }
        }
        for(int i = 4; i < 8; i++){
                if(placa[i] < 48 || placa[i] > 57){
                    printf("0");
                    return 0;
                }
        }    
        printf("1");
        return 0;
    }
    if(strlen(placa) == 7){

        if(placa[3] < 48 || placa[3] > 57){
            printf("0");
            return 0;
        }

        if(placa[4] < 65 || placa[4] > 90){
            printf("0");
            return 0;
        }

        if((placa[5] < 48 || placa[5] > 57) || (placa[6] < 48 || placa[6] > 57)){
            printf("0");
            return 0;
        }

        for (int i = 0; i < 3; i++){
            if(placa[i] < 65 || placa[i] > 90){
                printf("0");
                return 0;
            }
        }
        printf("2");
        return 0;
    }
    
    printf("0");
    return 0;
}