/*H3. "Dots teksta fails. Saskaitit teksta vardus (garuma vismaz 2) pec to pirmajiem diviem burtiem,
neskirojot registru (""ab"", ""ac"", ""ad"" utt.). Programmai statistika pa vardu garumiem jasaliek tabula,
kas realizeta ka vardnica (STL map). Programmas rezultata iegut failu,
kas katrai teksta sastopamajai 2 burtu virknei (ar ko sakas vārds)
izdrukats parstaveto vardu skaits (piemeram, ab 7, ac 3, ad 5 utt.).
Par vardu tiek uzskatita latinu alfabeta burtu virkne."

Autors:Paula Beatrise Valtere
*/

#include<iostream>
#include<list>
#include<map>
#include <fstream>

using namespace std;

bool ischar(char b){                                    //Funkcija vertibas parbaudei

if((b>='A' && b<='Z')||(b>='a' && b<='z')) return true;
else return false;

}

int main(){

fstream fin ("in.txt", ios::in);                  //Funkcijas faila atversanai
//fstream fin ("in2.txt", ios::in);
//fstream fin ("in3.txt", ios::in);
fstream fout ("out.txt", ios::out);             //Funkcija rakstisanai faila

map<string,int> st;
string c;
string v;

while (!fin.eof())                              //Funkcija .txt faila satura iegusanai
    {
         getline (fin,c);
         v+=c;
    }

if(v==""){ fout<<"Izveletais fails ir tukss! Statistiku nevar izveidot."; return 0;}

list<string>tt;
tt.push_back(v);                        //Faila satura virknes ievietosana ieks list

//  for(auto &a:tt){cout<<a;}


string vard;
int gar=v.length();

for (auto &a: tt) {                             //Funkcija list satura parskatisanai

if(ischar(a[0]) && ischar(a[1])){           //Parbaude gadijuma, ja teksts list objekta sakas ar vardu

        vard.push_back(a[0]);               //Varda sakumburtu iegusana
        vard.push_back(a[1]);
        st[vard]+=1;                        //Sakumburtu ievietosana map
        vard.clear();

}

for (int i = 1; i <= gar; i++) {            //Funkcija ta objekta caurskatisanai, kas ir ieks list

vard.clear();

if(a[i-1]==' ' && ischar(a[i]) && ischar(a[i+1])){      //Parbaude uz vardu sakumiem teksta

        vard.push_back(a[i]);
        vard.push_back(a[i+1]);
        st[vard]+=1;
        }

    }
}

if (st.empty()) {                           //Parbaude, vai map nav tukss

    fout<< "Faila nav neviens vards, kas satur vismaz 2 simbolus.";

    }

    else{

    fout<<"Varda sakums | Atkartosanas biezums"<<endl;
    fout<<endl;
        for(auto &s:st){

        //cout<<s.first<<" "<<s.second<<endl;
        fout<<"          "<<s.first<<"                           "<<s.second<<endl;      //Map izprintesana .txt faila

            }
        }
fin.close ();                       //Funkcija faila aizversanai
fout.close ();                  //Funkcija rakstisanas iespejas partrauksanai

return 0;
}
