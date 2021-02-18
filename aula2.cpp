#include <iostream>

using namespace std;

int main() {
  int a[10];

  cout << a << "\t" << &a[1] << " " << a+1 << endl; // usar só o nome do array é o mesmo que acessar seu endereço.
  //Concomitantemente, imprimir a = imprimir a[0] (&a[1] = a+1)
  // Todo Array é ponteiros. Ou seja,  *p = p[0], *(p+3) = p[3]

  return 0;
}