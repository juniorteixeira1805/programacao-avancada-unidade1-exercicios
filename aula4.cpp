#include <iostream>
using namespace std;

int main() {

  int* p; // crio-se o ponteiro ´para inteiros
  p = new int[4]; //fez-se o ponteiro apontar para um espaço na memoria que cabe 4 inteiros.


  int* *q; // criou-se um ponteiros para ponteiros.
  q = new int* [4]; // fez-se o ponteiro apontar para 4 ponteiros

  q[0] = new int[3]; // fez-se cada ponteiro "secundario apontar para um espaço de memoria de 3 inteiros"
  q[1] = new int[3]; // agora podemos utilizar o metodo que ultilizamos para array bi-dimensionais
  q[2] = new int[3]; // para liberar a memoria tem que ser o caminho contrario que foi alocado
  q[3] = new int[3]; //


  return 0;
}