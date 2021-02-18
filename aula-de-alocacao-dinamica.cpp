#include <iostream>

using namespace std;

int main() {
  
  int *arr; //Criando um apontador
  int i, tam;

  do{
    cout << "Informe o tamanho do vetor" << endl;
    cin >> tam; // recebendo a variavel do input
  }while(tam < 1);
  
  arr = new int[tam]; //Reservando um espaço de memoria de acordo com o tamanho recebido no input

  for(i = 0; i < tam; i++){//Percorrendo o espaço de memoria reservado anteriormente
    arr[i] = i+1; //adicionando a cada espaço de memoria que foi reservado um inteiro i+1
  }

  for(i = 0; i < tam; i++){//Percorrendo o espaço de memoria reservado anteriormente
    cout << arr[i] << " ";// imprimindo os valores
  }

  delete[] arr;//liberando a memoria
  arr = NULL;// apontando o array para um valor nullo
  
  return 0;
}