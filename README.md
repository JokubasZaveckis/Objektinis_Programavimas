1.0 versija yra galutinė projekto versija, kurioje buvo optimizuotas duomenų rūšiavimas į gerus ir blogus mokinius.
Pirmoji projekto versija buvo sukurta dviejomis realizacijomis: su C masyvais ir su vektoriaus konteineriu, abi programos iš esmės darė tą patį: leido vartotojui pasirinkti ar nori studentų sąrašą įvesti rankinių būdu, ar nori kad pažymiai būtų sugeneruoti atsitiktinai ir įvesti norimą kiekį pažymių kiekvienam studentui. Porgrama apskaičiuoja studento vidurkį ir medianą ir surūšiuoja pagal vardą.
Antroji programos versija buvo papildyta funkcija kuri leido skaityti duomenis iš failo ir juos taip pat spausdinti į tekstinį duomenų failą.
Trečioji programos versija buvo papildyta saugumo funkcijomis, programa apsaugota nuo netinkamų vartotojo įvesčių.
Ketvirtoji programos versija buvo papildyta funkcija, kuri lesdavo vartotojui pasirinkti failo dydį ir pagal įvestą skaičių sugeneruodavo atsitiktinius studentų vardus, pavardes bei pažymius, taip pat studentai buvo išrūšiuoti i du atskirs konteinerius, neproting - kurių vidurkis mažiau už 5 ir protingi - kuri vidurkis 5 ir daugiau.
Penktoji programos versija buvo naudojama ištriti kaip pasikeis programos laikas naudojant skirtingo tipo konteinerius: vector, list ir deque. Šie laikai priklauso nuo vartotojo programinės įrangos tačiau labai ryšių ksirtumų būti neturėtų.

Naudojimosi instrukcija: paleidus programą ši duos 3 pasirinkimus: ar norima nuskaityti duomenis iš jau esančio failo, ar norima sugeneruoti naują failą ir ar norima duomenis įvedinėti ranka. Pasirinkus pirmąjį variantą vartotojas turi įvesti jau programos direktorijoje esančio tekstinio failo pavadinimą ir programa išves kiek kiekviena programos dalis užtruko laiko. Pasirinkus antrąjį variantą vartotojas turės įvesti kokio dydžio failo nori sukurti, įvesti kiek pažymių turės kiekvienas studentas ir tada įvesti iš kokio failo nori duomenis nuskaityti, trečiasis variantas leis vartotojui tiek vardą tiek pavardę, pažymius bei egzaminą įvesti ranka.

Galutiniai programos testavimo rezultatai:

-----------------VEKTORIAI-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo nuskaitymas          |      0.00s       |      0.03s       |     0.29s        |      3.22s        |      28.34s        |
| Failo rikiavimas           |      0.00s       |      0.01s       |     0.17s        |      1.96s        |      19.87s        |
| Failo rusiavimas           |      0.00s       |      0.00s       |     0.01s        |      0.16s        |       1.53s        |
| Failo išvedimas            |      0.01s       |      0.04s       |     0.40s        |      4.20s        |      37.24s        |
| Programos veikimo laikas   |      0.01s       |      0.09s       |     0.88s        |      9.54s        |      86.98s        |

-----------------DEQUE-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo nuskaitymas          |      0.00s       |      0.04s       |     0.38s        |     3.61s         |      34.67s        |
| Failo rikiavimas           |      0.01s       |      0.06s       |     0.70s        |     7.52s         |      75.29s        |
| Failo rusiavimas           |      0.00s       |      0.00s       |     0.03s        |     0.36s         |       5.53s        |
| Failo išvedimas            |      0.01s       |      0.04s       |     0.42s        |     3.81s         |      37.51s        |
| Programos veikimo laikas   |      0.02s       |      0.09s       |     1.11s        |     14.49s        |      153.00s       |

-----------------LIST-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo nuskaitymas          |      0.00s       |      0.04s       |     0.29s        |     2.97s         |      27.98s        |
| Failo rikiavimas           |      0.00s       |      0.03s       |     0.22s        |     3.86s         |      44.84s        |
| Failo rusiavimas           |      0.00s       |      0.00s       |     0.02s        |     0.37s         |       3.46s        |
| Failo išvedimas            |      0.01s       |      0.06s       |     0.41s        |     4.10s         |      38.53s        |
| Programos veikimo laikas   |      0.01s       |      0.13s       |     1.34s        |     9.20s         |      114.81s       |
