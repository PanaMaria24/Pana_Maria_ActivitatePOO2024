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
	Magazin operator=(const Magazin& m) {
		if(&m!=this){
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		if (this->salarii) {
			delete[]this->salarii;
		}
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		
	}
		return *this;
}
	Magazin operator+=(const Magazin& m) {
		this->getSuprafata=this->pret
	}

	Magazin operator+(float salariu)const //const ca sa nu se modif this ul si m2 este this atunci scriem doar float pt 5000.0f
	{
		Magazin temp = *this;
		temp.pret = this->pret + valoare;
		return temp;

	}
	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
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
	friend Magazin operator+(float valoare, const Masina& m);
};
int Magazin::impozitM2 = 2;

Magazin operator+(float valoare, const Masina& m) {
	Masina masina = m;
	masina.pret = valoare + m.pret;
	return masina;
}

Magazin operator+(const Magazin& m)const {
	Magazin temp = *this;
	temp.getNrAngajati=this->nrAngajati + m.nrAngajati;
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

int main() {
	Magazin m1;
	cout << m1.getNrAngajati() << endl;
	m1.setNrAngajati(6, new float[6]{2,5,4,8,6,3});
	cout << m1.getNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1]<<endl;
	cout << m2.getSalariu(1)<<endl;
	m2.setNrAngajati(5, new float[5] {5,8,3,9,4});

	cout << m2.getSalariu(3) << endl;

	Magazin* vector = new Magazin[100];
	//
	delete[]vector;

	Magazin m3(m2);
	Magazin m4 = m2;
    
	m4 = m2 = m3;
	m4.operator=(m2);//m4 se duce in this
	// tip returnat nume(lista parametri)
	m4 = m2 + m3;
	//m4.operator=(m2.operator+(m3));

	//m2 + m3;
	//m2.operator+(m3);

	m4 += m2;
	//m4=m4+m2 si atunci m4 se modifica si nu mai punem const

	m4 = m2 + 5000.0f;
	//m2.operator+(5000.0f)

	m4 = 5000.0f + m2;
	//daca facem un operator in cadrul cls devine metoda si primul param este this(5000.0f) si nu merge
	//operator+(5000.0f, m2); il vede asa pt ca este fct si nu metoda
}