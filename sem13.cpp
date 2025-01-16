#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<numeric>
#include<algorithm>

using namespace std;

class Librarie {
protected:
	string nume;
public:
	Librarie() {
		this->nume = "Mihai Eminescu";

	}
	Librarie(string nume) {
		this->nume = nume;
	}
	virtual string getDenumire() {
		return nume;
	}
};

class LibrarieOnline :public Librarie {
	string site;
public:
	LibrarieOnline() :Librarie("Librarie online") {
		this->site = "www.site.ro";
	}
	LibrarieOnline(string nume, string site) :Librarie(nume)//apelam coonstr din cls de baza cu alea :
	{
		this->site = site;
	}
	string getDenumire() {
		return nume + "-" + site;
	}
};

int main() {
	LibrarieOnline lo("Libris", "Libris.ro");

	cout << lo.getDenumire() << endl;

	Librarie* lib = new LibrarieOnline("Humanitas", "humanitas.ro"); //late binding
	cout << lib->getDenumire() << endl;

	vector<float>v;
	v.push_back(1.2);
	v.push_back(4.5);
	v.push_back(3.7);
	v.push_back(5.9);
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		s = s + v[i]; //s+=v[i]
	}

	float suma = accumulate(v.begin(), v.end(), 0);//fct tamplate face acelasi lucru ca suma de mai sus

	if (v.size() > 0) {
		cout << "Medie:" << s / v.size();
	}
	else
		cout << "Media nu se poate calc." << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}


	//list<Librarie>*lista;   asta e un pointer la o lista de librarii
	list<Librarie*> lista; //o lista cu pointer la librarie
	lista.push_front(new Librarie());
	lista.push_front(new Librarie("Carturesti"));
	lista.push_front(new LibrarieOnline("Bookzone", "Bookzone.ro"));
	lista.push_back(new LibrarieOnline());
	list<Librarie*>::iterator it = lista.begin(); //begin returneaza adresa primului op din lista // iterator este un pointer care ne ajuta sa parc el din lista
	while (it != lista.end()) {
		cout << (*it)->getDenumire() << endl;//it este un pointer si trb sa l dereferentiem de doua ori pt ca retine adresa unei adrese dar asta doar daca nu faceam cu getDenumire
		it++;
	}

	map<int, Librarie>librarii;
	librarii.insert(pair<int, Librarie>(1, Librarie()));//pair este cls tamplate
	librarii.insert(pair<int, Librarie>(27, Librarie("Carturesti")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Libris")));
	librarii.insert(pair<int, Librarie>(23, Librarie("Humanitas")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Mihail Sadoveanu")));

	cout << librarii[23].getDenumire() << endl;
	map<int, Librarie>::iterator iterator = librarii.begin();
	cout << "Afisare map" << endl;
	while (iterator != librarii.end()) {
		cout << iterator->first << " - ";
		cout << iterator->second.getDenumire() << endl;
		iterator++;
	}


	return 72;

}