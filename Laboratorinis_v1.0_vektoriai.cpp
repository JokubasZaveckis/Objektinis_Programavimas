#include "Header.h"

struct Studentas
{
	string vardas, pavarde;
	int n=0, egzaminas=0;
	float vidurkis=0, mediana=0;
	vector<int> pazymiai;

};

void Pildymas(Studentas& temp);
float Vidurkis(Studentas temp);
float Mediana(Studentas temp);
void Isvedimas(vector<Studentas> grupe);

int main()
{
	int pasirinkimas;
	vector<Studentas> grupe;
	int talpa = 50;
	grupe.reserve(talpa);
	Studentas laikinas;
	do {
		cout << "Iveskite studento duomenis" << endl;
		if (grupe.capacity() == grupe.size())
		{
			grupe.reserve(talpa * 2);
		}
		Pildymas(laikinas);
		grupe.push_back(laikinas);
		laikinas.pazymiai.clear();
		cout << "Iveskite 1, kad pratestumete studentu irasyma, arba bet ka kito kad uzbaigtumete" << endl;
		cin >> pasirinkimas;
	} while (pasirinkimas == 1);

	grupe.shrink_to_fit();

	Isvedimas(grupe);

	for (int i = 0; i < grupe.size(); i++)
	{
		grupe[i].pazymiai.clear();
	}
	grupe.clear();
}

void Pildymas(Studentas& temp)
{
	int talpa = 50;
	temp.pazymiai.reserve(talpa);
	cout << "Iveskite studento varda ir pavarde:" << endl;
	cin >> temp.vardas >> temp.pavarde;

	int pasirinkimas = 0;
	while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3)
	{
		cout << "Iveskite 1 jei norite pazymius ivesti rankiniu budu, 2 jei norite kad pazymiai butu sugeneruoti atsitiktine tvarka, 3 jei nezinote kiek pazymiu ivesite: ";
		cin >> pasirinkimas;
	}

	if (pasirinkimas == 1)
	{
		cout << "Iveskite kiek studentas turi pazymiu: ";
		cin >> temp.n;;
		cout << "Iveskite studento pazymius: ";
		int pazymys;
		for (int j = 0; j < temp.n; j++)
		{
			cin >> pazymys;
			if (temp.pazymiai.capacity() == temp.pazymiai.size())
			{
				temp.pazymiai.reserve(talpa * 2);
			}
			if (pazymys > 0 && pazymys < INT_MAX)
			{
				temp.pazymiai.push_back(pazymys);
			}
			else
			{
				cout << "Neteisingas pazymio formatas" << endl;
				j--;
			}
		}
		cout << "Iveskite egzamino rezultata: ";
		cin >> temp.egzaminas;
	}
	else if (pasirinkimas == 2)
	{
		std::random_device rd;
		std::mt19937 mt(static_cast<long unsigned int> (rd()));
		std::uniform_int_distribution<int> dist(1, 10);
		temp.n = dist(mt);
		//srand(time(NULL));
		//temp.n = rand() % 11 + 1;
		for (int j = 0; j < temp.n; j++)
		{
			if (temp.pazymiai.capacity() == temp.pazymiai.size())
			{
				temp.pazymiai.reserve(talpa * 2);
			}
			//temp.pazymiai.push_back(rand() % 11 + 1);
			temp.pazymiai.push_back(dist(mt));
		}
		//temp.egzaminas = rand() % 11 + 1;
		temp.egzaminas = dist(mt);
	}
	else if (pasirinkimas == 3)
	{
		while (true)
		{
			cout << "Iveskite po viena sveiko tipo pazymi (iveskite bet ka kito noredami sustoti vesti pazymius)" << endl;
			int mark;
			if (cin >> mark)
			{
				if (temp.pazymiai.capacity() == temp.pazymiai.size())
				{
					temp.pazymiai.reserve(talpa * 2);
				}
				temp.pazymiai.push_back(mark);
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				break;
			}
		}
		cout << "Iveskite mokinio egzamino rezultata: ";
		cin >> temp.egzaminas;
	}
	temp.pazymiai.shrink_to_fit();
	temp.vidurkis = Vidurkis(temp);
	temp.mediana = Mediana(temp);
}

float Vidurkis(Studentas temp)
{
	float suma = 0;
	for (int i = 0; i < temp.pazymiai.size(); i++)
	{
		suma += temp.pazymiai[i];
	}
	float vidurkis = suma / temp.pazymiai.size();

	float pazymys = 0.4 * vidurkis + 0.6 * temp.egzaminas;
	return pazymys;
}

float Mediana(Studentas temp)
{
	sort(temp.pazymiai.begin(), temp.pazymiai.end());
	float mediana;
	int dydis = temp.pazymiai.size();
	if (dydis % 2 == 0)
	{
		mediana = (temp.pazymiai[dydis / 2 - 1] + temp.pazymiai[dydis / 2]) / 2.0;
	}
	else
	{
		mediana = temp.pazymiai[dydis / 2];
	}
	
	float pazymys = 0.4 * mediana + 0.6 * temp.egzaminas;
	return pazymys;
}

void Isvedimas(vector<Studentas> grupe)
{
	cout << endl << left << setw(13) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < grupe.size(); i++)
	{
		cout << left << setw(13) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(20) << fixed << setprecision(2) << grupe[i].vidurkis << setw(20) << grupe[i].mediana << endl;
	}
}