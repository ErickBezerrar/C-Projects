#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno {
  long int matricula;
  char nome[81];
  char curso[51];
  char email[41];
  char login[21];
  char status;
};


void exibeAluno(Aluno*);


int main(void) {
  FILE *fp;
  Aluno* aluno;
  printf("Exemplo com Arquivo Binário\n");
  fp = fopen("arquivo.dat","rb");
  if (fp == NULL){
    printf("Erro na abertura do arquivo\n!");
    exit(1);
  }
  aluno = (Aluno*) malloc(sizeof(Aluno));
  while (fread(aluno, sizeof(Aluno), 1, fp)) {
    exibeAluno(aluno);
  }
  fclose(fp);
  free(aluno);
  return 0;
}


void exibeAluno(Aluno* al) {
  char situacao[20];
  if ((al == NULL) || (al->status == 'x')) {
    printf("\n= = = Aluno Inexistente = = =\n");
  } else {
    printf("\n= = = Aluno Cadastrado = = =\n");
    printf("Matrícula: %ld\n", al->matricula);
    printf("Nome do aluno: %s\n", al->nome);
    printf("E-mail: %s\n", al->email);
    printf("Login no SIGAA: %s\n", al->login);
    printf("Curso: %s\n", al->curso);
    if (al->status == 'm') {
      strcpy(situacao, "Matriculado");
    } else if (al->status == 't') {
      strcpy(situacao, "Trancado");
    } else {
      strcpy(situacao, "Não informada");
    }
    printf("Situação do aluno: %s\n", situacao);
  }
}