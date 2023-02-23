#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

struct Studentas
{
    std::string vardas, pavarde;
    int n, egzaminas;
    float vidurkis, mediana;
    int* pazymiai;

};

void Vidurkis(Studentas*& studentai, int count);
void Mediana(Studentas*& studentai, int count);
void Isvedimas(Studentas*& studentai, int count);

int main()
{

    int count = 1, studentuSkaicius=0;
    Studentas* studentai = new Studentas[count];

    while(true)
    {
        std::cout << "Iveskite studento varda: ";
        std::cin >> studentai[studentuSkaicius].vardas;
        std::cout << "Iveskite studento pavarde: ";
        std::cin >> studentai[studentuSkaicius].pavarde;

        int pasirinkimas = 0;
        while(pasirinkimas!=1 && pasirinkimas!=2 && pasirinkimas!=3)
        {
            std::cout << "Iveskite 1 jei norite pazymius ivesti rankiniu budu, 2 jei norite kad pazymiai butu sugeneruoti atsitiktine tvarka, 3 jei nezinote kiek pazymiu ivesite: ";
            std::cin >> pasirinkimas;
        }

        if(pasirinkimas==1)
        {
            std::cout << "Iveskite kiek studentas turi pazymiu: ";
            std::cin >> studentai[studentuSkaicius].n;
            studentai[studentuSkaicius].pazymiai = new int[studentai[studentuSkaicius].n];
            std::cout << "Iveskite studento pazymius: ";
            for(int j=0; j<studentai[studentuSkaicius].n; j++)
            {
                std::cin >> studentai[studentuSkaicius].pazymiai[j];
            }
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> studentai[studentuSkaicius].egzaminas;
        }
        else if(pasirinkimas==2)
        {
            std::srand(std::time(NULL));
            studentai[studentuSkaicius].n = std::rand()%11+1;
            studentai[studentuSkaicius].pazymiai = new int[studentai[studentuSkaicius].n];
            for(int j=0; j<studentai[studentuSkaicius].n; j++)
            {
                studentai[studentuSkaicius].pazymiai[j]=std::rand()%11+1;
            }
            studentai[studentuSkaicius].egzaminas = std::rand()%100+1;
        }
        else if(pasirinkimas==3)
        {
            int* temp = new int[INT_MAX];
            int pazymiuSkaicius=0;
            while(true)
            {
                std::cout << "Iveskite po viena sveiko tipo pazymi (iveskite bet ka kito noredami sustoti vesti pazymius)" << std::endl;
                int pazymys;
                if(std::cin>>pazymys)
                {
                    if(pazymiuSkaicius<INT_MAX)
                    {
                        temp[pazymiuSkaicius++]=pazymys;
                    }
                    else
                    {
                        std::cout << "Ivestas maksimalus pazymiu skaicius";
                        break;
                    }
                }
                else
                {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
            studentai[studentuSkaicius].pazymiai = new int[pazymiuSkaicius];
            for (int j = 0; j < pazymiuSkaicius; j++)
            {
                studentai[studentuSkaicius].pazymiai[j] = temp[j];
            }       
            studentai[studentuSkaicius].n = pazymiuSkaicius;
            delete[] temp;
            std::cout << "Iveskite mokinio egzamino rezultata: ";
            std::cin >> studentai[studentuSkaicius].egzaminas;
        }
        studentuSkaicius++;
        if(studentuSkaicius==count)
        {
            count++;
            Studentas* temp2 = new Studentas[count];
            for(int i=0; i<studentuSkaicius; i++)
            {
                temp2[i]=studentai[i];
            }
            delete[] studentai;
            studentai = temp2;
        }
    bool papildymas;
    std::cout << "Iveskite 1, jei norite prideti studenta, 0 jeigu studento prideti nebenorite: ";
    std::cin >> papildymas;
    if(!papildymas) break;
    }
    Vidurkis(studentai, studentuSkaicius);
    Mediana(studentai, studentuSkaicius);
    Isvedimas(studentai, studentuSkaicius);

    for(int i=0; i<studentuSkaicius; i++)
    {
        delete[] studentai[i].pazymiai;
    }
    delete[] studentai;

    return 0;
}

void Vidurkis(Studentas*& studentai, int count)
{

    for(int i=0; i<count; i++)
    {
        float pazymiuVidurkis=0;
        float suma=0;
        for(int j=0; j<studentai[i].n; j++)
        {
            suma+=studentai[i].pazymiai[j];
        }
        pazymiuVidurkis = suma*1.0/studentai[i].n;
        studentai[i].vidurkis = 0.4*pazymiuVidurkis + 0.6*studentai[i].egzaminas;
    }
}

void Mediana(Studentas*& studentai, int count)
{
    for(int i=0; i<count; i++)
    {
        int* temp = new int[studentai[i].n];
        for (int j = 0; j < studentai[i].n; j++)
        {
            temp[j] = studentai[i].pazymiai[j];
        }    
        for(int j=0; j<studentai[i].n-1; j++)
        {
            int max=j;
            for(int k=j+1; k<studentai[i].n; k++)
            {
                if(temp[max]>temp[k])
                {
                    max=k;
                }
            }
            if(max!=j)
            {
                std::swap(temp[max], temp[j]);
            }
        }
        for (int j = 0; j < studentai[i].n; j++)
        {
            studentai[i].pazymiai[j] = temp[j];
        }

        delete[] temp;
        if(studentai[i].n%2==0)
        {
            studentai[i].mediana = ((studentai[i].pazymiai[studentai[i].n/2-1]+studentai[i].pazymiai[studentai[i].n/2])*1.0/2)*0.4+0.6*studentai[i].egzaminas;

        }
        else
        {
            studentai[i].mediana = 0.4*(studentai[i].pazymiai[studentai[i].n/2])+0.6*studentai[i].egzaminas;
        }
    }
}

void Isvedimas(Studentas*& studentai, int count)
{
    std::cout << std::endl << std::left << std::setw(13) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.) /" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    for(int i=0; i<count; i++)
    {
        std::cout << std::left << std::setw(13) << studentai[i].vardas << std::setw(15) << studentai[i].pavarde << std::setw(20) << std::fixed << std::setprecision(2) << studentai[i].vidurkis << std::setw(20) << studentai[i].mediana << std::endl;
    }
}