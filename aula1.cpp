#include <iostream>

using namespace std;

int main() {
  int i;
  float x;

  i = 7;
  x = 3.1415;
  int* p = &i; // Criamos um ponteiro para inteiro. Caso o valor de i não fosse inteiro, daria erro.
  // Poteiros são variaveis que armazena endereços de memoria, apenas (utiliza-se '*' após o tipo de dados especificado). 

  cout << "i: " << i << ", Tamanho: " << sizeof(i) << ", Endereco: " << &i << endl; //imprimimos o valor, o tamanho em bytes - ultilizando a função SIZEOF()-
  cout << "x: " << x << ", Tamanho: " << sizeof(x) << ", Endereco: " << &x << endl;// e por ultimo o endereço de memoria em hexadecimal (ultiliza-se '&' junto a variavel).
  cout << "p: " << p << " " << p+1 << ", Tamanho: " << sizeof(p) << ", Endereco: " << &p << endl; // P aponta para i, pois o ponteiro p contém o endereço de i (Se colocar * na hora de imprimir, p será desreferenciado).
  //ou seja 2**p = 14, pois é 2vezes a desreferencia de p que é o valor de i.
  // A unica aritimetica possivel com ponteiros, é somar um numero natural com o ponteiro. somar um ponteiro com um inteiro, mudara o lugar para onde o ponteiro aponta. p+1 = endereço mais 4 bytes...

  return 0;
}