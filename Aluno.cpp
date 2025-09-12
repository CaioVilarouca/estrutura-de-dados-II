#include <stdio.h>
#include <stdbool.h> 
#include <ctype.h>
#include <iostream>
#include <stdexcept>

#define MAX_PROVAS 10 // Limites max de provas 

int qtdAlunos=0, qtdProvas, totalMasc=0, totalFem=0, aprovMasc=0, aprovFem=0, reprovMasc=0, reprovFem=0, Opcao=0; 
float MediaAprovacao;
char Resposta, Barra[] = "\u2588";  // Unicode, substitui ASCII 219 a barra = 219;

// Definicao da estrutura Aluno, que agrupa os dados de cada aluno
struct Aluno { 
    char Nome[30];  // Esse campo so permite 30 caractere    
    float Notas[MAX_PROVAS];   
    float NotaObtida; // Media final do aluno
    char Sexo;         
    bool Resultado;      
};

int main() {
        Aluno Turma[100]; // Vetor de limite max de 100 alunos por turma

        // Regra de negocio
        do {
            // Quantas provas vao ser aplicado para todos os alunos
            printf("\nInforme a quantidade de provas: (Limite max de 10 provas.): ");
            scanf("%i", &qtdProvas);

            // Quantidade provas a ser aplicado o MAX 10 provas
            // || Se a primeira condicao ja for true, nao avalia a segunda
            if(qtdProvas < 1 || qtdProvas > MAX_PROVAS){
                printf("\n Atencao! Entre 1 e 10 Provas.");
            }

            // || Se a primeira condicao ja for true, nao avalia a segunda
        }while(qtdProvas < 1 || qtdProvas > MAX_PROVAS);// Operador OU e ||

        do {
        // Media de aprovacao
        printf("\nInforme a media de para aprovacao: (Media entre 05 e 08): ");
        scanf("%f", &MediaAprovacao);
        } while ( MediaAprovacao < 5 || MediaAprovacao > 8);

        do {
            // Leia Nome do aluno e guarda o nome na posicao qtdAlunos no vetor Turma
            printf("\nInforme o nome do %i. aluno: ", qtdAlunos + 1);
            scanf(" %29[^\n]", Turma[qtdAlunos].Nome); // 29 caractere nesse campo

            //  Entrada do sexo com validacao (aceita M ou F)
            do {
                printf("Informe o sexo (M/F): ");
                scanf(" %c", &Turma[qtdAlunos].Sexo);
                Turma[qtdAlunos].Sexo = toupper(Turma[qtdAlunos].Sexo); // forca a letra maiuscula

                if (Turma[qtdAlunos].Sexo != 'M' && Turma[qtdAlunos].Sexo != 'F'){
                    printf("Esse campo so aceita M ou F \n");
                }
            } while (Turma[qtdAlunos].Sexo != 'M' && Turma[qtdAlunos].Sexo != 'F');

            // Pecorrendo o vetor na linha 21
            Turma[qtdAlunos].Notas[0] = 0;// Essa intrucao nao eh opcional! por causa da linha 74
            for (int i = 1; i <= qtdProvas; i++){

                // Leia uma nota e guarde na posicao I das notas do aluno de numero qtdAlunos
                printf("Informe a %i. nota: ", i);
                scanf("%f", &Turma[qtdAlunos].Notas[i]);// Um agregador container

                // Acomulando a soma das notas na posicao 0 do vetor
                Turma[qtdAlunos].Notas[0] += Turma[qtdAlunos].Notas[i]; 
            }

            // Resultado recebe o True ou False | Evita HARD CODED com a var MediaAprovacao
            Turma[qtdAlunos].Resultado = Turma[qtdAlunos].Notas[0] / qtdProvas >= MediaAprovacao; // Resultado da media do aluno
            // Ternario para var NotaObtida inicializar sempre 
            Turma[qtdAlunos].NotaObtida = (Turma[qtdAlunos].Notas[0] > 0) ? Turma[qtdAlunos].Notas[0] / qtdProvas : 0.0f; // Soma final

            // Codigo antigo
            //Turma[qtdAlunos].NotaObtida = Turma[qtdAlunos].Notas[0] / qtdProvas;

            //  Atualiza as estatisticas de acordo com o sexo e se foi aprovado ou nao
            if (Turma[qtdAlunos].Sexo == 'M') {
                totalMasc++;
                (Turma[qtdAlunos].Resultado) ? aprovMasc++ : reprovMasc++;
            } else {
                totalFem++;
                (Turma[qtdAlunos].Resultado) ? aprovFem++ : reprovFem++;
            }

            /* codigo antigo
            if (Turma[qtdAlunos].Sexo == 'M') {
                totalMasc++;
                if (Turma[qtdAlunos].Resultado)
                    aprovMasc++;   
                else
                    reprovMasc++;
            } else {
                totalFem++;
                if (Turma[qtdAlunos].Resultado)
                    aprovFem++;
                else
                    reprovFem++;
            }*/

            // Saida do loop principal        
            printf("Deseja cadastrar outro aluno? (S/N): ");
            scanf(" %c", &Resposta); // espaço antes do %c ignora enter anterior
            Resposta = toupper(Resposta);

            // Eu so comeco esse while si a respota for diferente de S ou N
            while (Resposta != 'S' && Resposta != 'N') {
                printf("Esse campo só aceita (S/N): ");
                scanf(" %c", &Resposta);
                Resposta = toupper(Resposta);
            }
            qtdAlunos++; 
        } while (Resposta == 'S');
        // Fim do loop 

        do {
            // Menu de registro aluno
            printf ("\n[1] Registro de Aprovados\n[2] Registro de Reprovados\n[3] Estatistica\n[4] Grafico\n[0] Sair\nInforme: ");
            scanf("%d", &Opcao);

            // Menu
            switch (Opcao){
            case 1:
                printf("\nRegistro de alunos Aprovados | quantidade de alunos: %i\n", aprovMasc + aprovFem);
            for (int i = 0; i < qtdAlunos; i++) {
            // true ou false
                if (Turma[i].Resultado) {
                    printf("Nome: %-10s \nSexo: %c \nStatus: APROVADO\nMedia solicitada: %.2f \nMedia obtida: %.2f \n---------\n", Turma[i].Nome, Turma[i].Sexo, MediaAprovacao, Turma[i].NotaObtida);
                }
            }  
                break;
            case 2:
                printf("\nRegistro de alunos Reprovados | quantidade de alunos: %i\n", reprovFem + reprovMasc);
                for (int i = 0; i < qtdAlunos; i++) {
                    // resultado for diferente de true 
                    if (!Turma[i].Resultado) {
                    printf("Nome: %-10s \nSexo: %c \nStatus: REPROVADO\nMedia solicitada: %.2f \nMedia obtida: %.2f \n---------\n", Turma[i].Nome, Turma[i].Sexo, MediaAprovacao, Turma[i].NotaObtida);
                    }
                }
                break;
            case 3:  
                printf("Quantidade total de alunos %i \n", qtdAlunos);     // Cast
                printf("Porcetagem de alunos Masc APROVADOS   %.2f \n", ((float)aprovMasc / totalMasc) * 100);
                printf("Porcetagem de alunos Fem APROVADOS    %.2f \n", ((float)aprovFem / totalFem) * 100);
                printf("Porcetagem dda turma APROVADOS  %.2f \n", ((float)(aprovMasc + aprovFem) / qtdAlunos) * 100);
                printf("---------------------------------\n");
                printf("Porcetagem de alunos Masc REPROVADOS   %.2f \n", ((float)reprovMasc / totalMasc) * 100);
                printf("Porcetagem de alunos Fem REPROVADOS    %.2f \n", ((float)reprovFem / totalFem) * 100);
                printf("Porcetagem da turma REPROVADOS  %.2f \n", ((float)(reprovMasc + reprovFem) / qtdAlunos) * 100);
                break;
            case 4:
                printf("\nGrafico da turma de APROVADOS\n");
                for (int i = 0; i < (aprovMasc + aprovFem); i++){
                    printf("%s", Barra);
                }
                printf("\nGrafico da turma de REPROVADOS\n");
                for (int i = 0; i < (reprovMasc + reprovFem); i++){
                    printf("%s", Barra);
                }
                break;
            default:
                while (Opcao != 1 && Opcao != 2 && Opcao != 3 && Opcao != 0){
                    printf ("Esse campo so aceita esses valores!\n[1] Registro de Aprovados\n[3] Registro de Reprovados\n[4] Grafico\n[0] Sair\nInforme: ");
                    scanf("%d", &Opcao);
                }
                break;
            }    
        } while (Opcao != 0);
    printf("\n Encerramento de registro");
}