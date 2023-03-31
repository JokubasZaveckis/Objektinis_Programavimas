#include "Header.h"
#include "Funkcijos_v0.5_vektoriai.h"

int main()
{
	int pasirinkimas;
	vector<Studentas> grupe;
	int talpa = 50;
	grupe.reserve(talpa);
	Studentas laikinas;
	string choice;
	cout << "Iveskite 0 kad studentai butu nuskaitomi is failo" << endl;
	cout << "Iveskite 1 kad studentus ivestumete ranka" << endl;
	cout << "Iveskite 2 kad sugeneruotumete studentu faila" << endl;
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
		else if (choice == "2")
		{
			cout << "Iveskite kokio dydzio faila norite sugeneruoti:" << endl;
			cout << "Galimi failo dydziai: 1 000, 10 000, 100 000, 1 000 000, 10 000 000" << endl;
			string failoDydis;
			while (true)
			{
				cin >> failoDydis;
				if (failoDydis == "1000" || failoDydis == "10000" || failoDydis == "100000" || failoDydis == "1000000" || failoDydis == "10000000")
				{
					int dydis = stoi(failoDydis);
					int pazymiai;
					while (true)
					{
						cout << "Iveskite kiek pazymiu turi kiekvienas studentas (nuo 1 iki 10)" << endl;
						cin >> pazymiai;
						if (pazymiai > 0 && pazymiai <= 10)
						{
							FailoSukurimas(grupe, dydis, pazymiai);
							break;
						}
						else
						{
							cout << "Netinkama ivestis, bandykite dar karta" << endl;
						}
					}
					break;
				}
				else
				{
					cout << "Tokio pasirinkimo nera, bandykite dar karta: " << endl;
				}
			}
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

// 10 000 000 - 2 min
// 1 000 000 - 11s