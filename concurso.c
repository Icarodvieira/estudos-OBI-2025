#include <stdio.h>

int main() {
    
    int nParticipantes,minAprovados, notaCorte, aux; 

    //n = número de participantes 
    //k = número mínimo de candidatos que devem ser aprovados
    //c = nota de corte

    scanf("%d%d",&nParticipantes, &minAprovados);

    int notas [nParticipantes];

    for (int i = 0; i < nParticipantes; i++)
    {
         scanf("%d", &notas[i]);
    }
    
    for(int i=0; i < nParticipantes; i++){
        for(int j=0; j<nParticipantes - 1; j++){
            if(notas[j] < notas[j+1]){
                aux = notas[j+1];
                notas[j+1] = notas [j];
                notas[j] = aux;
            }
        }
    }

    notaCorte = notas [minAprovados-1];

    
    // for (int i = 0; i < nParticipantes; i++)
    // {
    //     printf("%d", notas[i]);
    // }

    printf("%d", notaCorte);

    return 0;
}