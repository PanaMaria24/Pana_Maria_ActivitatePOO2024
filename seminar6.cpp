#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;//
	float* salarii;
	float suprafata;//
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin():anDeschidere(2024),nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m):anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}


	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float * salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}
	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	operator float() {
		float s = 0;
		for (int = 0; i < m.nrAngajati; i++) { 
			s += this->salarii[i];
		}
	}

	Magazin operator+(Magazin m2)const {
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Magazin& operator+=(Magazin m) {
		*this = *this + m;
		return *this;
	}

	Magazin operator+(float salariu)const {
		Magazin temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati]=salariu;
		temp.nrAngajati++;
		return temp;
	}

	//friend Magazin operator+(float salariu, Magazin m) {
	//	Magazin temp = m;
	//	if (temp.salarii != NULL) {
	//		delete[]temp.salarii;
	//	}
	//	temp.salarii = new float[temp.nrAngajati + 1];
	//	for (int i = 0; i < m.nrAngajati; i++) {
	//		temp.salarii[i] = m.salarii[i];
	//	}
	//	temp.salarii[temp.nrAngajati] = salariu;
	//	temp.nrAngajati++;
	//	return temp;
	//}

	friend Magazin operator+(float salariu, Magazin m);



	void afisare() {
		cout << "Oras:" << this->oras <<endl;
		cout << "Numar angajati:" << this->nrAngajati <<endl;
		cout << "Suprafata:" << this->suprafata <<endl;
		cout << "An deschidere:" << this->anDeschidere <<endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 <<endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}

	bool operator>( Magazin m) { // bool este tipul returnat
		return this->suprafata > m.suprafata && this->nrAngajati > m.nrAngajati;
	}
	bool operator==(Magazin m)
	{
		return this->suprafata == m.suprafata && this->nrAngajati == m.nrAngajati;
	}

	explicit operator int() {
		return this->nrAngajati;
	}
	float operator[](int index) {
		if (index <= 0 && index < this->nrAngajati) {//nu ths de salarii pt ca este vector si de fapt e dat de nrang
			return this->salarii[index];
		}
		else {
			throw "indexul este in afara limitelor"//pt ca nu e de tip float
			//TERMENI DE EXCEPTIE
			//throw
			//try
			//catch

		}
	}

	friend ostream& operator<<(ostream& out, const Magazin& m) {//FUNCTIE INLINE facem friend pt ca trb sa fie functie nu are cum sa fie metoda pt ca primul este cout si este de tipul ostream si nu de tipul clasei
		out << "Oras:" << m.oras << endl;
		out << "Numar angajati:" << m.nrAngajati << endl;
		if (m.nrAngajati >0 ) {//e de tip int deci pun >0 in loc de !=null
			for (i = 0; i < m.nrAngajati; i++) {
				out << m.salarii[i]<<" ";
			}
		}
		out << "Suprafata:" << m.suprafata << endl;
		out << "An deschidere:" << m.anDeschidere << endl;
		out << "Impozit pe m2:" << Magazin::impozitM2 << endl;
		return out;
	}
	friend istream& operator>>(istream& input, Magazin& m) //NU e fct inline
};
istream& operator>>(istream& input, Magazin& m)// nu e const pt ca vr sa l modif; nu citim var const si statice decat obiecte
{
	cout << "Oras:";
	input >> m.oras;
	cout << "nrAngajati:"
	input >> m.nrAngajati;
	if (m.salarii != NULL) {
		delete[]m.salarii;
	}
	if (m.nrAngajati > 0) {
		m.salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			cout << "Salariul" << i + 1 << ":"
				input >> m.salarii[i];
		}
	}
	else {
		m.salarii = NULL;
	}
	cout<<"Suprafata:"


}
int Magazin::impozitM2 = 2;

// stabilim daca il facem in afara sau inauntru daca poate sau nu sa fie metoda

Magazin operator+(float salariu, Magazin m) {
	float valoare = m.nrAngajati;
	return m + salariu;
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

int main() {
	//Magazin m1;
	//cout << m1.getNrAngajati() << endl;
	//m1.setNrAngajati(6, new float[6]{2,5,4,8,6,3});
	//cout << m1.getNrAngajati() << endl;

	//Magazin m2("Bucuresti", 3, 80, 2019);
	//cout << m2.getSalarii()[1]<<endl;
	//cout << m2.getSalariu(1)<<endl;
	//m2.setNrAngajati(5, new float[5] {5,8,3,9,4});

	//cout << m2.getSalariu(3) << endl;

	//Magazin* vector = new Magazin[100];
	////
	//delete[]vector;

	//Magazin m3(m2);
	//Magazin m4 = m2;
	//Magazin m5;
	//m5 = m2;
	//m2 = m2;

	//f(m4);

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2019);

	cout << m2 << endl;
	cin >> m2;
	cout <<endl<< m2;

	if (m1 > m2) {//m1.operator>(m2) este metoda pt ca o apelam prin punct si daca era fct nu era nev
		cout << "m1 este mai mare";
	}
	if (m1 == m2) {
		cout << "m1 este egal cu m2";
	}
	else{
		cout << "Sunt diferite";
	}
	//int nrAngajati = m2; apelare implicita
	int nrAngajati =(int) m2;//explicita
	float salariiTotale = m2;
	cout << endl << "Salarii totale";
	try { //pt ca avem exceptie
		cout<< m2[1];// operatorul de index suprainc DOAR prin met adc in int clasei
		m2[1] = 200;
		float s = m2[ - 9];
	}
	catch (int exceptie) {

	}
	catch (float exceptie) {

	}
	catch (const char* exceptie) {
		cout << endl << exceptie << endl;
	}
	catch (string ex) {

	}
	catch (...) {// captate toate exceptiile

	}
	return 765756;
}