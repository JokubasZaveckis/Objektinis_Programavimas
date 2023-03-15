#pragma once
#include "Header_v0.4.h"

const string VARDAI[100] = {
    "Adomas", "Aivaras", "Albertas", "Aleksandras", "Algis", "Alvydas", "Andrius", "Antanas", "Arminas", "Arnoldas", //10
    "Arturas", "Aurimas", "Benas", "Dainius", "Dalius", "Danas", "Darius", "Deividas", "Domantas", "Donatas", //10
    "Dovydas", "Edgaras", "Edvinas", "Egidijus", "Evaldas", "Gediminas", "Gintaras", "Gytis", "Ignas", "Ilja", //10
    "Ilona", "Inga", "Ingrida", "Jonas", "Juras", "Juozapas", "Justinas", "Kajus", "Karolis", "Kasparas", //10
    "Kestutis", "Kipras", "Klaudijus", "Konstantinas", "Kristijonas", "Laimonas", "Linas", "Mantas", "Marius", "Martynas", //10
    "Mindaugas", "Meta", "Nerijus", "Nijole", "Olegas", "Osvaldas", "Ovidijus", "Patrikas", "Paulius", "Petras", //10
    "Raimondas", "Ricardas", "Rimantas", "Rolandas", "Rokas", "Romualdas", "Saulius", "Simone", "Simonas", "Stanislovas", //10
    "Svetlana", "Sarunas", "Tadas", "Tauras", "Tautvydas", "Teodoras", "Tomas", "Valdas", "Valentinas", "Vidmantas", //10
    "Vidmante", "Viktoras", "Vilius", "Vytautas", "Zilvinas", "Zygimantas", "Karolis", "Aretas", "Nojus", "Giedrius",//10
    "Dominykas", "Dziugas", "Arnas", "Augustas", "Algimantas", "Maksas", "Orestas", "Tautrimas", "Vladas", "Rytis" //10
};
const std::string PAVARDES[100] = {
    "Adomaitis", "Alekna", "Aleknavicius", "Andriuskevicius", "Antanaitis", "Arlauskas", "Baksys", "Balciunas", "Baltuska", "Baranauskas", //10
    "Bartkus", "Bendikas", "Bikulcius", "Birzietis", "Bubnys", "Budrys", "Buivydas", "Cepulis", "Cerniauskas", "Cesnulevicius",
    "Dambrauskas", "Dapkus", "Didziokas", "Dilys", "Dobilas", "Dobrovolskis", "Dovydaitis", "Drevinskas", "Dubickas", "Dumbrys",
    "Duda", "Dumbliauskas", "Eidimtas", "Gedvilas", "Gintalas", "Girdauskas", "Girgždys", "Grybauskas", "Grigaitis", "Gudaitis",
    "Gudynas", "Gulbinas", "Gvildys", "Janilionis", "Jankauskas", "Jankunas", "Jonauskas", "Juska", "Juskevicius", "Jusys",
    "Kairys", "Kazlauskas", "Klimasauskas", "Kraujalis", "Kudirka", "Kulvietis", "Lapenas", "Lapinas", "Laukaitis", "Laurinaitis",
    "Laurusaitis", "Liubinas", "Maciulis", "Makaveckas", "Malinauskas", "Markauskas", "Markevicius", "Marozas", "Masalskis", "Maskoliunas",
    "Mazeika", "Mikalauskas", "Miknevicius", "Milaknis", "Miliauskas", "Mockus", "Monstvilas", "Montvilas", "Narkevicius", "Navickas",
    "Norkus", "Pakalniskis", "Pakalniskis", "Palionis", "Petrulis", "Pocius", "Povilaitis", "Rakauskas", "Razmas", "Rimkus", //10
    "Rimsa", "Rupsys", "Rusinas", "Rutkauskas", "Ruzgys", "Sabaliauskas", "Sabonis", "Sakalauskas", "Samsonas", "Savickas" //10
};

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
void FailoSukurimas(vector <Studentas>&, int failoDydis, int pazymiuSkaicius);

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
