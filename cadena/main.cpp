#include <iostream>

using namespace std;
int tam(char *cad){
int cont = 0;
    while (*cad++ != '\0'){
        cont++;
    }
    return cont;
}
void invertir(char *cad,char *fin){
    int tama = tam(cad)/2;
    for(int i = 0; i != tama; i++){
        swap(*cad,*fin);
        cad++;
        fin--;
    }
}
void invertirR(char *cad,char *fin){
    //cout << fin - cad << endl;
    if (fin-cad <= 0 ){
        return;
    }
    swap(*cad, *fin);
    return invertirR( ++cad, --fin);
}
bool Palindrome(char *cad,char *fin){
    int i = tam(cad);
    while(i/2 != 0){
        if(*cad != *fin){
            return false;
        }
        else{
            cad++;
            fin--;
        }
    i--;
    }
    return true;

}
bool PalindromeR(char *cad,char *fin){
    char *i = fin+(fin-cad)/2;
    if(cad == i){
        return true;
    }
    if(*cad != *fin){
        return false;
    }
    return PalindromeR(++cad,--fin);
}

int main()
{
    char cad[]= "hola";
    char *fin = cad + tam(cad)-1;
    cout << cad << endl;
    invertir(cad, fin);
    cout << cad << endl;

    char num[]= "RECONOCER";
    char *fin2 = num + tam(num)-1;
    cout << PalindromeR(num,fin2)<< endl;
    return 0;
}
