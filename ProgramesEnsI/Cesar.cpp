#include<iostream>
#include <string>
//#include <math.h>
//#include <vector>
//#include <list>
//#include <iomanip>
#include <sstream>
using namespace std;

bool isCharacter (char l) {
	//Comproba si el valor ASCII d'un caracter és una lletra per a estalviar calculs
	if((64 < l) && (l < 91)) {
		return true;
	} else if((96 < l) && (l < 123)) {
		return true;
	} else {
		return false;
	}
}

char cycle(char lletra, int c) {
	//Mira si una lletra és majuscula, minúscula o altres i li suma el valor corresponent
	char o = lletra;
	if (isCharacter(lletra)){
		if(int(lletra)<91){
			//Si és majúscula
			o = lletra + c;
			if (90 < o) {
				o = o - 26;
			}
			if (o < 65) {
				o = o + 26;
			}

		} else {
			//Si és minúscula
			o = lletra + c;
			if (122 < o) {
				o = o - 26;
			}
			if (o < 97) {
				o = o + 26;
			}
		}
		return o;
	} else {
		return lletra;
	}

}

int main() {
	bool ask;
	int c;
	string s;
	cout << "Vol encriptar (0) o desencriptar (1)?" << endl;
	cin >> ask;
	cout << "Quantes posicions voleu desplaçar el text?" << endl;
		if (ask){
			cin >> c;
			c = c*(-1);
		} else {
			cin >> c;
		}	

	cout << "Pot escriure el text ara, per a sortir premi Control + Z:" << endl;
	while ( getline (cin, s) ) {
		for (int i = 0; i < s.size(); i++){
			cout << cycle(s[i], c);
		}
		cout << endl;

		
	}
	


}

