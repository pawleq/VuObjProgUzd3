# VuObjProgUzd3
Trecia objektinio programavimo uzduotis

Paulius Mykolaitis ISI I kursas

# Kaip paleisti programą?

Jeigu naudojate CodeBlocks, sekite šiuos žingsnius :

1. Atidarome ***main.cpp*** failą.

2. Sukompiliuojame kodą ir paleidžiame programą.

Jeigu naudojate C++ compiler, pavyzdziui, GCC, tai :

Norint paleisti šią programa g++ compiler pagalba, nuėję į failo vietą, rašykite : 

Makefile commands:

**make**

Sukuria .o failus ir juos sulinkina i "main" faila;

**clean**

Ištrina main ir .o failus.

Galite naudoti programą.

# Kiek užtrunka programa?

intel i5 8250u @ 1.6gHz, 8.0GB ram

Studentų duomenų failo generavimas (10 pažymių)

| Įrašų kiekis | Laikas |
|--|--|
| 1000 | 0,03452s |
| 10000 | 0,98574s | 
| 100000 | 1,5652s |
| 1000000 | 12.45678s |
| 10000000 | 120,54512s |

Studentų duomenų skaitymas

| Įrašų kiekis | std::vector(class) | std::vector(struct) |
|--|--|--|
| 1000 | 0.009s | 0.009s |
| 10000 |  0.096s | 0.094s |
| 100000 |  0.948s | 0.942s |
| 1000000 | 9.597s | 9.421s |
| 10000000 | 96.254s | 94.625s |

Studentų duomenų dalijimas ir išvedimas

| Įrašų kiekis | std::vector(class) | std::vector(struct) |
|--|--|--|
| 1000 | 0.026s | 0.03s |
| 10000 |  0.214s | 0.216s |
| 100000 |  2.308s | 2.126s |
| 1000000 | 24.551s | 21.272s |
| 10000000 | 245.129s | 212.625s |

Programos realizuotos su *class* veikimas užtraunka ilgiau negu veikimas su *struct*, galimai *class* veikia ilgiau, nes yra naudojama **private** kintamieji, o struct visi yra **vieši**.

# Kaip naudoti programą?

# v1.1

1. Paleidžiame **SarasoGen.cpp** failą, kurio pagalba yra sugeneruojama studentu duomenu failas :
  
   *Įvedame studentu kieki bei pazymiu kieki, su kuriais bus generuojamas studentu failas*
   
2. Sugeneravus studentu faila, paleidziame **main.cpp**.

3. Paleidus programa bus prasoma : 

    *Pasirinkti, pagal ka rusiuoti studentus (1- vidurkis, 0-mediana).*
    
    *Pasirinkti, pagal ka rusiuoti studentus (1- vardai, 0-pavardes).*
    
4. Tada reikes ivesti musu sugeneruoto studentu failo pavadinimas, siuo atveju **kursiokai.txt**.

5. Palaukiame tam tikra laiko tarpa, kol programa baigs veikima ir gausime programos veikimo trukme.
