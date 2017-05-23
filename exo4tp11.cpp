#include <iostream>
#include <cstdlib>

using namespace std;

struct sTime{
  int h;
  int m;
  int s;
};

sTime conversion(int secondes){
  sTime c;
  c.h=secondes/3600;
  c.m=(secondes%3600)/60;
  c.s=secondes-3600*c.h-60*c.m;
  return c;
}

void saisie(sTime *time){
  char a, b;
  do{
        cin>>time->h>>a>>time->m>>b>>time->s;
  }while(((a!=':' || b!=':')||(time->h<0 || time->h>99))||((time->m<0 || time->m>59)||(time->s<0 || time->s>59)));
}

void addTime(sTime *t1, sTime *t2, sTime *tFinal){
  tFinal->s = (t1->s + t2->s)%60;
  tFinal->m = (t1->m + t2->m)%60 + (t1->s + t2->s)/60;
  tFinal->h = (t1->h + t2->h) + (t1->m + t2->m)/60;
}

void affiche(sTime t){
  cout<<t.h<<":"<<t.m<<":"<<t.s<<endl;
}

int main(){
  sTime t1;
  sTime t2;
  sTime tSum;
  saisie(&t1);
  saisie(&t2);
  addTime(&t1,&t2,&tSum);
  affiche(tSum);
  return 0;
}

