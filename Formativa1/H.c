 /*#include <stdio.h>
int main()
{
    int D,A,S,M;
    int C, matriculados,aprovados;

    scanf("%d", &D);

    while(scanf("%d %d %d", &A, &S,&M ) == 3){
        int reprovados[1000] = {0}; //zera o vetor a cada semestre
        
        for(int i=0;i<M;i++){
            do{
                if(scanf("%d %d %d", &C, &matriculados, &aprovados) != 3){
                    return 1;
                }
            } while (C < 0 || C>=D);

            reprovados[C] += (matriculados-aprovados); //Soma os reprovados dessa disciplina C
        }

        int MaiorReprovacao = -1; //-1 Como base para calcular o maior
        for(int i=0;i<D;i++){
            if(reprovados[i]>MaiorReprovacao){
                MaiorReprovacao=reprovados[i];
            }
        }

        printf("%d/%d", A, S);

        // Imprime todos os códigos com o maior número de reprovações
        for (int i = 0; i < D; i++) {
            if (reprovados[i] == MaiorReprovacao) {
                printf("%d ", i);
            }
        }

        // Linha em branco após cada semestre
        printf("\n\n");
    }

    return 0;
} */

#include <stdio.h>

int main() {
    int D, A, S, M;
    int C, matriculados, aprovados;

    scanf("%d", &D); // Lê número de disciplinas

    while (scanf("%d %d %d", &A, &S, &M) == 3) {
        int reprovados[1000] = {0}; // Zera vetor

        // Lê M disciplinas e acumula reprovações
        for (int i = 0; i < M; i++) {
            do {
                if (scanf("%d %d %d", &C, &matriculados, &aprovados) != 3) {
                    return 1;
                }
            } while (C < 0 || C >= D);

            reprovados[C] += (matriculados - aprovados);
        }

        // Calcula maior número de reprovações
        int MaiorReprovacao = -1;
        for (int i = 0; i < D; i++) {
            if (reprovados[i] > MaiorReprovacao) {
                MaiorReprovacao = reprovados[i];
            }
        }

        // Imprime semestre
        printf("%d/%d\n", A, S);

        // Imprime todas as disciplinas com maior reprovação
        for (int i = 0; i < D; i++) {
            if (reprovados[i] == MaiorReprovacao) {
                printf("%d ", i); // espaço ao final é obrigatório
            }
        }

        // Linha em branco obrigatória após cada bloco
        printf("\n\n");
    }

    return 0;
}
