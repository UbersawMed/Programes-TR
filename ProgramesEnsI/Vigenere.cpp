#include<iostream>
#include<string>
#include<vector>

using namespace std;

int valorNum (char c) {
	if(int(c)<91){
        	//Si és majúscula
        	return (c-65);

    	} else {
        	//Si és minúscula
        	return (c-97);
    	}
}

bool isCharacter (char l) {
	//Comproba si el valor ASCII d'un caracter és una lletra per a estalviar calculs
	if((64 < l)&&(l < 91)) {
    	return true;
	} else if((96 < l)&&(l < 123)) {
    	return true;
	} else {
    	return false;
	}
}

char cycle(char car, int c) {
	//Mira si una lletra és majuscula, minúscula o altres i li suma el valor corresponent
	int o = car;
	if (isCharacter(o)){
		
    	if(int(o)<92){
        	//Si és majúscula
        	o = o + c;
        	while (90 < o) {
            	o = o - 26;
        	}
        	while (o < 65) {
            	o = o + 26;
        	}

    	} else {
        	//Si és minúscula
        	o = o + c;
        	while (122 < o) {
            	o = o - 26;
        	}
        	while (o < 97) {
            	o = o + 26;
        	}
    	}
    	return char(o);
	} else {
    	return car;
	}

}

int main() {
	bool ask;
	string buf;
	string s;
	int ctemp;
	vector <int>c;
     
	cout << "Vol encriptar (0) o desencriptar (1)?" << endl;
	cin >> ask;
	cout << "Quina paraula voleu que fagi de codi?" << endl;
    	if (ask){
        	cin >> buf;
        	c.resize(buf.size());
        	for (unsigned int i = 0; i < c.size(); i++){
            	c[i] = valorNum(buf[i])*(-1);
        	}


    	} else {
        	cin >> buf;
        	c.resize(buf.size());
        	for (unsigned int i = 0; i < c.size(); i++){
        		c[i] = valorNum(buf[i]);
			}
    	}    

	cout << "Pot escriure el text ara, per a sortir premi Control + Z:" << endl;

	ctemp = 0;
	while ( getline (cin, s) ) {
    	for (unsigned int i = 0; i < s.size(); i++){
        	cout << cycle(s[i], c[ctemp]);

			if (isCharacter(s[i])) { ctemp++;}
			ctemp = ctemp % c.size();
    	}
    	cout << endl;
		ctemp = 0;
        
	}
}