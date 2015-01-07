#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

//Encriptació dels caràcters
//Lletres: 01-26
// '.': 27
// ',': 28
// ' ': 29
//Xifres: 30-39
// '!': 40
// '?': 41
// '-': 42

bool primRelatiu (int a, int b) { 
	for ( ; ; ) {
		if (!(a %= b)) return b == 1;
		if (!(b %= a)) return a == 1;
	}
}

int valorNum (char c) {
	int i = int(c);
	if((64<i) && (i<91)){
        	//Si és majúscula
        	return (i-64);

    	} else if ((96<i) && (i<123)) {
        	//Si és minúscula
        	return (i-96);
	} 
	else if (i == 46) { return 27; }
	else if (i == 44) { return 28; }
	else if (i == int(' ')) { return 29; }
	else if ((47 < i) && (i < 58)) { return i-18; } //Numeros
	else if (i == 33) { return 40; }
	else if (i == 63) { return 41; }
	else if (i == 45) { return 42; }
	return 0;
}

char valorChar (unsigned long long int i){
	if (i<27) {
        	//Retorna minuscules
        	return (i+96);
	} 
	else if (i == 27) { return 46; }
	else if (i == 28) { return 44; }
	else if (i == 29) { return ' '; }
	else if ((29 < i) && (i < 40)) { return i+18; } //Numeros
	else if (i == 40) { return 33; }
	else if (i == 41) { return 63; }
	else if (i == 42) { return 45; }
	return 0;
}

 unsigned long long int textToInt (string s) {
	 char c;
	 unsigned long long int M = 0;
	 for (unsigned int i = 0; i < s.size(); i++){
		 M = M*100;
		 c = s[i];
		 M = M + valorNum(c);

	 }
	 return M;
 }

int main() {
	//Text desencriptat numeric, text encriptat numèric, primer 1, primer 2,
	// modul, exponent, funcio d'Euler, clau privada, buffer per a passat a text
	unsigned long long int M, M2, p, q, n, e, fE, d, b;
	double dBuf; //Calcular la llargada del string
	string m;
	bool preg;

	cout << "Vols encriptar (0) o desencriptar (1)?" << endl;
	cin >> preg;
	if (preg) {
		cout << "Introdueixi la clau publica (n i e) i els dos nombres primers, tots separats per un espai:" << endl;
		cin >> n >> e >> p >> q;
		cin.ignore();
		cout << "Escrigui el nombre a desencriptar:" << endl;
		cin >> M2;

		//Trobar d
		fE = (p-1)*(q-1);
		for (int i = 2; ; i++){
			if (((i * e)%fE)==1){
				d = i;
				break;
			}
		}

		//Desencriptar 

		M = M2 % n;
		for (int i = 1; i < d; i++) {
			M = (M * M2) % n;
		}

		//Outputejar text
		dBuf = log10(M)+1;
		dBuf = floor(dBuf);
		dBuf = ceil(dBuf/2);

		b = int(dBuf);
		m.resize(b);
		for (int i = m.size()-1; i >= 0; i--){
			b = M%100;
			M = M / 100;
			m[i] = valorChar(b);
		}

		cout << "d: " << d << endl << "Text desencriptat: " << m << endl;
		cin >> preg;

	} else {

		cout << "Introdueixi els dos nombres primers:" << endl;
		cin >> p >> q;
		cin.ignore();
		cout << "Escrigui el text a encriptar:" << endl;
		getline(cin, m);

		//Trobar n
		n = p * q;

		//Passar el text a numero
		M = textToInt(m) ;
				
		//Trobar e
		fE = (p-1)*(q-1);
		for (int i = 2; ; i++){
			if (primRelatiu(fE, i)){
				e = i;
				break;
			}
		}


		//Trobar M2, el text a enviar
		M2 = M % n;
		for (int i = 1; i < e; i++) {
			M2 = (M2 * M) % n;
		}
		
		//Outputejar l'informació

		cout << "M no encriptat: " << M << endl << "M encriptat: " << M2 << endl << "Clau publica: (" << n << ", " << e << ")" << endl;
		cin >> preg;

	}
}