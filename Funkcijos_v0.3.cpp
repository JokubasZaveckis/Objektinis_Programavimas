#include "Header.h"
#include "Funkcijos.h"

void Skaitymas(vector <Studentas>& grupe)
{

	string failas;
	ifstream duomenys;

	while (true)
	{
		cout << "Iveskite is kurio failo noretumete nuskaityti duomenis:" << endl;
		cin >> failas;

		try {
			duomenys.open(failas);

			if (!duomenys)
			{
				throw std::runtime_error("Failo atverti nepavyko, bandykite dar karta: ");
			}
			else
			{
				cout << "Failas atidarytas sekmingai, nuskaitoma..." << endl;
				break;
			}

		}
		catch (std::exception& e)
		{
			cout << "Error: " << e.what() << endl;
			cout << "Galimi tekstinio failo pavadinimai:" << endl;
			system("dir /b | findstr \\.txt$");
		}
	}

	string pirmaEilute;
	getline(duomenys, pirmaEilute);

	string line;
	while (getline(duomenys, line)) {
		Studentas temp;
		std::istringstream ss(line);
		ss >> temp.vardas >> temp.pavarde;
		int pazymys;
		while (ss >> pazymys) {
			temp.pazymiai.push_back(pazymys);
		}
		temp.egzaminas = temp.pazymiai.back();
		temp.pazymiai.pop_back();

		temp.vidurkis = Vidurkis(temp);
		temp.mediana = Mediana(temp);
		grupe.push_back(temp);
	}
	duomenys.close();

}

bool Palyginimas(const Studentas a, Studentas b)
{
	return a.vardas < b.vardas;
}


void Pildymas(Studentas& temp)
{
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
			if (pazymys > 0 && pazymys < 11)
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
		for (int j = 0; j < temp.n; j++)
		{
			temp.pazymiai.push_back(dist(mt));
		}
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

double Vidurkis(Studentas temp)
{
	double suma = 0;
	for (int i = 0; i < temp.pazymiai.size(); i++)
	{
		suma += temp.pazymiai[i];
	}
	double vidurkis = suma / temp.pazymiai.size();

	double pazymys = 0.4 * vidurkis + 0.6 * temp.egzaminas;
	return pazymys;
}

float Mediana(Studentas temp)
{
	sort(temp.pazymiai.begin(), temp.pazymiai.end());
	size_t mediana;
	size_t dydis = temp.pazymiai.size();
	double dydis1 = dydis / 2.0 - 1;
	double dydis2 = dydis / 2.0;

	size_t vidurinis = temp.pazymiai[dydis / 2];
	size_t vidurinis_mazesnis = temp.pazymiai[dydis / 2];

	if (dydis % 2 == 0)
	{
		mediana = (vidurinis + vidurinis_mazesnis) / 2.0;
	}
	else
	{
		mediana = temp.pazymiai[dydis2];
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

void IsvedimasIFaila(vector<Studentas> grupe)
{
	ofstream rezultatai("rezultatai.txt");
	rezultatai << endl << left << setw(13) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	rezultatai << "-----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < grupe.size(); i++)
	{
		rezultatai << left << setw(13) << grupe[i].vardas << setw(15) << grupe[i].pavarde << setw(20) << fixed << setprecision(2) << grupe[i].vidurkis << setw(20) << grupe[i].mediana << endl;
	}
	rezultatai.close();
	cout << "Programa baigta, rezultatai surasyti i rezultatai.txt faila" << endl;
}