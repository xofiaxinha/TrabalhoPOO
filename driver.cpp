#include "../classes/DVD.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  string ar = "Melanie", tit = "Crybaby", al = "Cry Baby", gen = "alt";
  string audForm = "MP3", vidForm = "1080 x 720";
  int an = 2015;

  vector<string> legenda;
  legenda.push_back(al);
  DVD *novo = new DVD(ar, tit, an, gen, audForm, vidForm, legenda);

  return 0;
}