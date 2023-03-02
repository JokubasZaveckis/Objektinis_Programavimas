#pragma once
#include "Header.h"

struct Studentas
{
	string vardas, pavarde;
	int n = 0, egzaminas = 0;
	double vidurkis = 0, mediana = 0;
	vector<int> pazymiai;

};

void Skaitymas(vector <Studentas>& grupe);
void Pildymas(Studentas& temp);
double Vidurkis(Studentas temp);
float Mediana(Studentas temp);
void Isvedimas(vector<Studentas> grupe);
bool Palyginimas(const Studentas a, Studentas b);
void IsvedimasIFaila(vector<Studentas> grupe);