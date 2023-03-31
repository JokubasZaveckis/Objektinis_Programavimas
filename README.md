Patikrintas programos veikimas pakeitus prieš tai buvusį vektorių su deku arba listu ir ištirti įvairūs programos veikimo laiko etapai.

Kompiuterio, ant kurio buto tiriama specifikacijos:
CPU - 11th Gen Intel(R) Core(TM) i5-11400H @ 2.70Ghz
RAM - 16GB SODIMM 3200MHz
SSD - OM3PDP3-AD NVMe KDI 512gb


**TYRIMO REZULTATAI**

-----------------VEKTORIAI-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo generavimas          |      0.009s      |      0.057s      |     0.397s       |     0.4129s       |      42.004s       |
| Failo nuskaitymas          |      0.5875s     |      0.404s      |     0.5435s      |     6.1636s       |      43.782s       |
| Failo rikiavimas           |      0.001s      |      0.013s      |     0.131s       |     0.1698s       |      19.537s       |
| Failo rusiavimas           |        0s        |      0.002s      |     0.019s       |      0.284s       |       3.104s       |
| Failo išvedimas            |      0.004s      |      0.06s       |     0.416s       |     0.3934s       |      37.127s       |
| Programos veikimo laikas   |     0.5891s      |      0.554s      |     0.6402s      |     7.1683s       |      145.558s      |

-----------------DEQUE-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo generavimas          |      0.0100s     |      0.047s      |     0.426s       |     4.5050s       |      48.0660s      |
| Failo nuskaitymas          |      0.0040s     |      0.034s      |     0.3430s      |     3.3770s       |      34.936s       |
| Failo rikiavimas           |      0.001s      |      0.060s      |     0.703s       |     7.7480s       |      77.651s       |
| Failo rusiavimas           |        0s        |      0.042s      |     0.059s       |     0.6310s       |       8.974s       |
| Failo išvedimas            |      0.006s      |      0.56s       |     0.387s       |     4.8510s       |      41.8510s      |
| Programos veikimo laikas   |     0.0260s      |      0.187s      |     1.9180s      |     20.049s       |      211.4780s     |

-----------------LIST-----------------------
|          Veiksmas          |   1000 studentų  |  10000 studentų  |  100000 studentų | 1000000 studentų  | 10000000 studentų  |
|----------------------------|------------------|------------------|------------------|-------------------|--------------------|
| Failo generavimas          |      0.013s      |      0.064s      |     0.426s       |     4.7210s       |      44.216s       |
| Failo nuskaitymas          |      0.0030s     |      0.028s      |     0.3430s      |     3.1870s       |      30.690s       |
| Failo rikiavimas           |      0.001s      |      0.015s      |     0.703s       |     3.7980s       |      51.561s       |
| Failo rusiavimas           |        0s        |      0.002s      |     0.3720s      |     0.3720s       |       4.309s       |
| Failo išvedimas            |      0.004s      |      0.053s      |     4.1270s      |     4.8510s       |      39.8340s      |
| Programos veikimo laikas   |     0.0170s      |      0.109s      |     5.9180s      |     12.078s       |      168.776s      |
