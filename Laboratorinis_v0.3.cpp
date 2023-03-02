#include "Header.h"
#include "Funkcijos.h"

int main()
{
	int pasirinkimas;
	vector<Studentas> grupe;
	int talpa = 50;
	grupe.reserve(talpa);
	Studentas laikinas;
	string choice;
	cout << "Iveskite 1 kad studentus ivestumete ranka, 0 kad studentai butu nuskaitomi is failo: ";
	cin >> choice;
	while (true)
	{
		if (choice == "1")
		{
			do {
				cout << "Iveskite studento duomenis" << endl;
				Pildymas(laikinas);
				grupe.push_back(laikinas);
				laikinas.pazymiai.clear();
				cout << "Iveskite 1, kad pratestumete studentu irasyma, arba bet ka kito kad uzbaigtumete" << endl;
				cin >> pasirinkimas;
			} while (pasirinkimas == 1);

			Isvedimas(grupe);
			break;
		}
		else if (choice == "0")
		{
			Skaitymas(grupe);
			std::sort(grupe.begin(), grupe.end(), Palyginimas);
			IsvedimasIFaila(grupe);
			break;
		}
		else
		{
			cout << "Ivestis netinkama, bandykite is naujo" << endl;
			cin >> choice;
		}
	}


	for (int i = 0; i < grupe.size(); i++)
	{
		grupe[i].pazymiai.clear();
	}
	grupe.clear();
	return 0;
}