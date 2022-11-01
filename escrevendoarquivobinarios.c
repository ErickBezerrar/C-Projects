#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno {
  long int matricula;
  char nome[81];
  char curso[51];
  char email[41];
  char login[21];
  char status;
};

Aluno* preencheAluno(void);

int main(void) {
  FILE* fp;
  Aluno* aluno;
  printf("Exemplo com Arquivo Binário\n");
  fp = fopen("arquivo.dat","ab");
  if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
  }
  aluno = preencheAluno();
  fwrite(aluno, sizeof(Aluno), 1, fp);
  fclose(fp);
  free(aluno);
  return 0;
}

Aluno* preencheAluno(void) {
  Aluno* aln;
  aln = (Aluno*) malloc(sizeof(Aluno));
  printf("\nInforme a matrícula do aluno: ");
  scanf("%ld", &aln->matricula);
  printf("Informe o nome do aluno: ");
  scanf(" %80[^\n]", aln->nome);
  printf("Informe o curso do aluno: ");
  scanf(" %50[^\n]", aln->curso);
  printf("Informe o login do aluno: ");
  scanf(" %20[^\n]", aln->login);
  printf("Informe o e-mail do aluno: ");
  scanf(" %40[^\n]", aln->email);
  aln->status = 'm';
  return aln;
}