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
int menu_principal(void);
void gravaAluno(Aluno*);

int main(void) {
  Aluno* fulano;
  int opcao;
  printf("Programa Cadastro de Alunos\n\n");
  opcao = menuPrincipal();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  fulano = preencheAluno();
                gravaAluno(fulano);
                free(fulano);
                break;
      case 2 :  fulano = buscaAluno();
                exibeAluno(fulano);
                free(fulano);
                break;
      case 3 :  // Tente implementar esta função ;)
                //;
                break;
      case 4 :  fulano = buscaAluno();
                excluiAluno(fulano);
                free(fulano);
                break;
      case 5 :  listaAlunos();
                break;
      case 6 :  listaAlunosPorCurso();
                break;
    }
    opcao = menuPrincipal();
  }
  return 0;
}

int menuPrincipal(void) {
  int op;
  printf("\nMenu Principal\n");
  printf("1 - Cadastrar aluno\n");
  printf("2 - Pesquisar aluno\n");
  printf("3 - Alterar aluno\n");
  printf("4 - Excluir aluno\n");
  printf("5 - Listar alunos\n");
  printf("6 - Listar alunos por curso\n");
  printf("0 - Encerrar programa\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  return op;
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

void gravaAluno(Aluno* aln) {
  FILE* fp;
  fp = fopen("alunos.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(aln, sizeof(Aluno), 1, fp);
  fclose(fp);
}