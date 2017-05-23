#include <iostream>

#include "fonctions.h"

using namespace std;

struct complexe{
  float re;
  float im;
};

complexe saisie(){
  float re, im;
  cout<<"Re = ";
  cin>>re;
  cout<<"Im = ";
  cin>>im;
  complexe c = {re,im};
  return c;
}

void affiche(complexe c){
  cout<<"("<<c.re<<" + "<<c.im<<"i)";
}

complexe somme(complexe c1, complexe c2){
  complexe c3;
  c3.re=c1.re+c2.re;
  c3.im=c1.im+c2.im;
  return c3;
}

int main(){
  complexe c1, c2, c3;
  c1=saisie();
  c2=saisie();
  c3=somme(c1,c2);
  affiche(c1);
  cout<<" + ";
  affiche(c2);
  cout<<" = ";
  affiche(c3);
  return 0;
}
  
  
