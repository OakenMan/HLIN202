#include <iostream>
#include <cstdlib>

using namespace std;

struct sTime{
  int h;
  int m;
  int s;
};

void saisieTime(sTime *time){
  char a, b;
  do{
    cin>>time->h>>a>>time->m>>b>>time->s;
  }while(((a!=':' || b!=':')||(time->h<0 || time->h>99))||((time->m<0 || time->m>59)||(time->s<0 || time->s>59)));
}

void displayTime(sTime t){
  cout<<t.h<<":"<<t.m<<":"<<t.s<<endl;
}

//================================================================================================

struct CD{
  int nbPistes;
  string albumName;
  string *songName;
  sTime *duree;
};

CD cree(){
  CD cd1;

  cout<<"Nom de l'album : ";
  cin>>cd1.albumName;

  cout<<"Nombre de pistes : ";
  cin>>cd1.nbPistes;

  cd1.duree = new sTime[cd1.nbPistes];
  cd1.songName = new string[cd1.nbPistes];

  for(int i=0;i<cd1.nbPistes;i++){
    cout<<"Nom Piste "<<i+1<<" : ";
    cin>>cd1.songName[i];
    cout<<"Duree Piste "<<i+1<<" : ";
    saisieTime(&cd1.duree[i]);
  }

  return cd1;
}

void displayCD(CD cd1){
  system("clear");
  cout<<"----- "<<cd1.albumName<<" -----"<<endl;
  for(int i=0;i<cd1.nbPistes;i++){
    cout<<i+1<<" - "<<cd1.songName[i]<<" - ";
    displayTime(cd1.duree[i]);
  }
}

int main(){
  CD staArc;
  staArc=cree();
  displayCD(staArc);
  return 0;
}






