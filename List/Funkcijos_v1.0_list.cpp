#include "Header_list.h"
#include "Funkcijos_v1.0_list.h"

void FailoSukurimas(list <Studentas>& grupe, int failoDydis, int pazymiuSkaicius)
{
	auto start = std::chrono::high_resolution_clock::now();

	ofstream sugeneruotas("sugeneruotas" + std::to_string(failoDydis) + ".txt");

	auto startGeneravimas = std::chrono::high_resolution_clock::now();

	std::random_device rd;
	std::mt19937 mt(static_cast<long unsigned int> (rd()));
	std::uniform_int_distribution<int> Dist(0, 99);
	std::uniform_int_distribution<int> paz_dist(0, 10);

	sugeneruotas << left << setw(15) << "Vardas" << setw(20) << "Pavarde";
	for (int j = 0; j < pazymiuSkaicius; j++)
	{
		sugeneruotas << left << setw(6) << ("ND" + std::to_string(j + 1));
	}
	sugeneruotas << left << setw(7) << "Egz." << endl;
	for (int i = 0; i < failoDydis; i++)
	{
		sugeneruotas << left << setw(15) << VARDAI[Dist(mt)] << setw(20) << PAVARDES[Dist(mt)];
		for (int j = 0; j <= pazymiuSkaicius; j++)
		{
			sugeneruotas << left << setw(5) << paz_dist(mt) << " ";
		}
		sugeneruotas << endl;
	}
	sugeneruotas.close();

	auto endGeneravimas = std::chrono::high_resolution_clock::now();
	auto generacija = std::chrono::duration_cast<std::chrono::milliseconds>(endGeneravimas - startGeneravimas).count();
	cout << "Failo sugeneruotas" + std::to_string(failoDydis) + ".txt" " generavimas truko: " << fixed << setprecision(2) << static_cast<double>(generacija) / 1000 << "s" << endl;

	KitiSkaiciavimai(grupe);
}

void Skaitymas(list <Studentas>& grupe, float& nuskaitymas)
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
			system("dir /b | findstr \\.txt$ | findstr /v protingi.txt | findstr /v neprotingi.txt");
		}
	}
	auto startNuskaitymas = std::chrono::high_resolution_clock::now();
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
	auto endSkaitymas = std::chrono::high_resolution_clock::now();
	auto skaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endSkaitymas - startNuskaitymas).count();
	nuskaitymas = skaitymas;
	cout << "Failo nuskaitymas truko: " << fixed << setprecision(2) << static_cast<double>(skaitymas) / 1000 << "s" << endl;

}

void KitiSkaiciavimai(list <Studentas>& grupe)
{
	float nuskaitymas;
	Skaitymas(grupe, nuskaitymas);
	auto start = std::chrono::high_resolution_clock::now();

	auto startRikiavimas = std::chrono::high_resolution_clock::now();
	grupe.sort(Palyginimas1);
	auto endRikiavimas = std::chrono::high_resolution_clock::now();
	auto Rikiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRikiavimas - startRikiavimas).count();
	cout << "Failo rikiavimas truko " << fixed << setprecision(2) << static_cast<double>(Rikiavimas) / 1000 << "s" << endl;

	auto startRusiavimas = std::chrono::high_resolution_clock::now();

	list <Studentas> neprotingi;

	auto it = std::remove_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.vidurkis < 5.0; });
	std::copy(it, grupe.end(), std::back_inserter(neprotingi));
	grupe.erase(it, grupe.end());

	auto endRusiavimas = std::chrono::high_resolution_clock::now();
	auto rusiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas).count();
	cout << "Failo rusiavimas truko: " << fixed << setprecision(2) << static_cast<double>(rusiavimas) / 1000 << "s" << endl;



	auto startIsvedimas = std::chrono::high_resolution_clock::now();

	ofstream smart("protingi.txt");

	smart << left << setw(13) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	smart << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : grupe)
	{
		smart << left << setw(13) << i.vardas << setw(20) << i.pavarde << setw(20) << fixed << setprecision(2) << i.vidurkis << setw(20) << i.mediana << endl;
	}

	ofstream stupid("neprotingi.txt");

	stupid << left << setw(13) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	stupid << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : neprotingi)
	{
		stupid << left << setw(13) << i.vardas << setw(20) << i.pavarde << setw(20) << fixed << setprecision(2) << i.vidurkis << setw(20) << i.mediana << endl;
	}

	auto endIsvedimas = std::chrono::high_resolution_clock::now();
	auto isvedimas = std::chrono::duration_cast<std::chrono::milliseconds>(endIsvedimas - startIsvedimas).count();
	cout << "Failo isvedimas truko: " << fixed << setprecision(2) << static_cast<double>(isvedimas) / 1000 << "s" << endl;

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << "Programos trukme: " << fixed << setprecision(2) << static_cast<double>(Rikiavimas + rusiavimas + nuskaitymas) / 1000 << "s" << endl;
}

bool Palyginimas(const Studentas a, Studentas b)
{
	return a.vardas < b.vardas;
}

bool Palyginimas1(const Studentas a, Studentas b)
{
	return a.vidurkis < b.vidurkis;
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

void Isvedimas(list<Studentas> grupe)
{
	cout << endl << left << setw(13) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : grupe)
	{
		cout << left << setw(13) << i.vardas << setw(15) << i.pavarde << setw(20) << fixed << setprecision(2) << i.vidurkis << setw(20) << i.mediana << endl;
	}
}

void IsvedimasIFaila(list<Studentas> grupe)
{
	ofstream rezultatai("rezultatai.txt");
	rezultatai << endl << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	rezultatai << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : grupe)
	{
		rezultatai << left << setw(13) << i.vardas << setw(15) << i.pavarde << setw(20) << fixed << setprecision(2) << i.vidurkis << setw(20) << i.mediana << endl;
	}
	rezultatai.close();
	cout << "Programa baigta, rezultatai surasyti i rezultatai.txt faila" << endl;
}