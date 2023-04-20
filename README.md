1.0.1 versija yra versijos 1.0 patobulinimas duodant vartotojui galimybę pasirinkti, kokia strategija jis nori kad būtų rūšiuojami studentai ir išmatuotas bei palygintas kiekvienos strategijos veikimo laikas.

-----------------VEKTORIAI-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| 1 strategija               |      0.00s       |      0.00s       |     0.02s        |      0.29s        |       2.75s        |
| 2 strategija               |      0.00s       |      0.00s       |     0.01s        |      0.18s        |       2.26s        |

-----------------DEQUE-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| 1 strategija               |      0.00s       |      0.00s       |     0.03s        |     0.35s         |       3.96s        |
| 2 strategija               |      0.00s       |      0.00s       |     0.02s        |     0.21s         |       3.22s        |

-----------------LIST-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| 1 strategija               |      0.00s       |      0.00s       |     0.02s        |     0.31s         |      1.89s         |
| 2 strategija               |      0.00s       |      0.00s       |     0.01s        |     0.20s         |      1.25s         |

Išvada: kaip matome, mažuose ir vidutiniuose dydžiuose vektoriaus konteineris lenkia listą ir deqą, tačiau dekas lenkia vektorių ties 10M riba. o listas iš visų lėčiausias.
