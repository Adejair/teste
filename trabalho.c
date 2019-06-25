#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define cls system("cls");
#define pause system("pause");

using namespace std;

int rnd(int low,int high) { return low+(double)rand()/((double)RAND_MAX+1)*(high-low+1); }

int main() {
  srand((unsigned)time(NULL)); int n=rnd(0,4);
  while(1) {
    cls
    int total=0;
    char palavra[100][100]={
      "melancia","sorvete","pudim","gelatina","manga","goiaba","uva","banana","espinafre","nabo","repolho",
      "beringela","ovo","salsicha","salame","biscoito","bolacha","croquete","hamburguer","esfirra",
      "pastel","coxinha","sanduiche","feijoada","macarronada","rocambole","pizza","empada","kibe","arroz",
      "carne","frango","peixe","presunto","queijo","tomate","cenoura","alface","couve","beterraba",
      "azeitona","fim"
      },descoberto[100]="",resposta[100]="",jafoi[100]="",letra='\0';
    for(int n=0;;n++) {
      char p[100]="";
      for(int n2=0;;n2++) { p[n2]=palavra[n][n2]; if(palavra[n][n2]=='\0') break; }
      if(strcmp(p,"fim")) total++;
      else break;
    }
    int escolha=rnd(0,total),vidas=5,ok=1,ja=0;
    cout << "Selecione uma opcao:\n\n[1] Jogar sozinho\n[2] Jogar com um amigo\n[3] Sair\n";
    char opcao=getch();
    for(int n=0;palavra[escolha][n];n++) resposta[n]=palavra[escolha][n];
    if(opcao=='2') {
      cout << "\nDigite a palavra para seu amigo tentar descobrir ... ";
      cin >> resposta;
    }
    else if(opcao=='3') return 0;
    for(int n=0;;n++) { descoberto[n]=resposta[n]=='\0'?'\0':'-'; if(resposta[n]=='\0') break; }
    while(vidas && stricmp(descoberto,resposta)) {
      cls
      cout << "Palavra: ";
      for(int n=0;descoberto[n]!='\0';n++) cout << descoberto[n];
      cout << "\nLetras usadas: ";
      for(int n=0;jafoi[n]!='\0';n++) cout << jafoi[n];
      if(letra!='\0') {
        if(!ok) {
          vidas--;
          if (vidas>0) printf("\n\nErrou!!! Voce ainda tem %d tentativa%s\n",vidas,vidas>1?"s":"");
          else cout << "\n\nErrou!!! Voce perdeu, pois acabaram suas tentativas!!!\n\nA palavra era: " << resposta << endl;
        }
        else if(ja) cout << "\n\nA letra '" << letra << "' ja foi usada!!!\n";
        else cout << "\n\nAcertou!!!\n";
      }
      if(vidas) {
        ja=0; cout << "\nDigite uma letra... "; letra=getch();
        for(int n=0;!ja;n++) {
          if(jafoi[n]==letra) ja=1;
          else if(jafoi[n]=='\0') { jafoi[n]=letra,jafoi[++n]='\0'; break; }
        }
        ok=!ja?0:1;
        for(int n=0;resposta[n]!='\0' && !ja;n++) { if(resposta[n] == letra) descoberto[n]=letra,ok=1; }
      }
    }
    cls
    if(vidas) cout << "Parabens!!! Voce descobriu a palavra (" << resposta << ")\n\n";
    cout << "Pressione qualquer tecla para reiniciar...";
    getch();
  }
}
