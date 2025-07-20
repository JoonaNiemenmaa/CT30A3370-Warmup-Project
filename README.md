# Projekti I: Warmup to C and Unix-programming

Tämä on kolmas valitsemani projekti. Ohjelma siis lukee tiedostosta rivejä yksi kerrallaan ja kirjoittaa rivit käänteisessä järjestyksessä toiseen tiedostoon.

Tässä demo siitä, kun ohjelma ajetaan ilman parametreja:

<img width="854" height="212" alt="image" src="https://github.com/user-attachments/assets/86115784-77e1-4760-950f-ee3318b78d64" />


Seuraavaksi ohjelman ajo syötetiedostolla:

<img width="961" height="341" alt="image" src="https://github.com/user-attachments/assets/d271dc50-004a-4248-83f0-46db956be1b6" />


Sitten vielä kokeilut kolmella parametrilla, eli määritetään myös tulostetiedosto:

<img width="1063" height="293" alt="image" src="https://github.com/user-attachments/assets/98cad8ab-f06d-41df-a0e4-62bd02fee9b5" />


## Käyttö

Ohjelma käännetään gcc:llä. Käännä ohjelma seuraavalla komennolla:

```console
foo@bar:~$ gcc reverse.c -o reverse -Wall -pedantic -std=c99
```

Ohjelman ajo:

```console
foo@bar:~$ ./reverse <syötetiedosto> <tulostetiedosto>
```
