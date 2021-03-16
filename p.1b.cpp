#include <iostream>

using namespace std;

class Ponto{
private:
  double x;
  double y;

public:
  inline Ponto(): x(0.0) , y(0.0) {}
  friend ostream &operator<<(ostream &O, const Ponto &P);
  friend istream &operator>>(istream &I, Ponto &P);
};

ostream &operator<<(ostream &O, const Ponto &P){
  O << "[" << P.x << ";" << P.y << "]";
  return O;
}

istream &operator>>(istream &I, Ponto &P){
  I >> P.x >> P.y;
  return I;
}

class Linha{
private:
unsigned tam;
  Ponto *ptr_linha;

public:
  Linha(): tam(0.0), ptr_linha(NULL) {}
  Linha(const Linha &L);
  ~Linha(void);
  friend ostream &operator<<(ostream &O, const Linha &L);
  void adcionar(const Ponto &P);
  Linha operator+(const Linha &L);
  void operator=(const Linha &L);
};

Linha::Linha(const Linha &L){
  int N = L.tam;
  if (N>0){
    ptr_linha = new Ponto[N];
  }
  else{
    ptr_linha = NULL;
    }
}

Linha::~Linha(void){
  delete[] ptr_linha;
}

ostream &operator<<(ostream &O, const Linha &L)
{
  for (unsigned i=0; i<L.tam; i++){
  O << L.ptr_linha[i];
  }
  return O;
}

void Linha::adcionar(const Ponto &P){
  Ponto *prov = new Ponto[tam+1];
  prov[tam] = P;
  delete[] ptr_linha;
  tam++;
  ptr_linha = prov;
}

Linha Linha::operator+(const Linha &L){
  Linha prov;
  prov.tam = tam+L.tam;
  for(unsigned i = 0; i < tam; i++){
    prov.ptr_linha[i] = ptr_linha[i];
  }
    for(unsigned i = 0; i < L.tam; i++){
    prov.ptr_linha[i+tam] = L.ptr_linha[i];
  }
  return prov;
}
void Linha::operator=(const Linha &L)
{
  if (this != &L)
  {
    // Soh faz alguma coisa se as duas variaveis sendo atribuidas forem diferentes
    if (tam != L.tam)
    {
      // Soh desaloca a area antiga e aloca nova area se as dimensoes forem diferentes
      // Senao, reutiliza a mesma area e soh copia o valor dos elementos
      if (tam>0) delete[] ptr_linha;
      tam = L.tam;
      if (tam>0) ptr_linha = new Ponto[tam];
      else ptr_linha = NULL;
    }
    // Copia os valores dos pontos
    for (unsigned i=0; i<tam; i++) ptr_linha[i]=L.ptr_linha[i];
  }
}
int main(void)
{
  Linha L1,L2,L3;
  Ponto P;
  unsigned NPt, NPtAdic, i;

  do
  {
    cout << "Numero de pontos da 1a linha (>0): ";
    cin >> NPt;
  } while (NPt<=0);
  for (i=0; i<NPt; i++)
  {
    cout << "Digite o ponto indice " << i << ": ";
    cin >> P;
    L1.adcionar(P);
  }
  L2 = L1;
  do
  {
    cout << "Numero de pontos adicionais da 2a linha (>0): ";
    cin >> NPtAdic;
  } while (NPtAdic<=0);
  for (i=0; i<NPtAdic; i++)
  {
    cout << "Digite o ponto indice " << i+NPt << ": ";
    cin >> P;
    L2.adcionar(P);
  }
  L3 = L1+L2;
  cout << "1a linha: " << L1 << endl;
  cout << "2a linha: " << L2 << endl;
  cout << "3a linha: " << L3 << endl;

  return 0;
}