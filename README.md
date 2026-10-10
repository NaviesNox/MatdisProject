# Kalkulator Himpunan

Aplikasi konsol C++17 untuk operasi himpunan pada tugas Matematika Diskrit.

## Kompilasi dan menjalankan

```text
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o kalkulator-himpunan
./kalkulator-himpunan
```

## Contoh penggunaan

Input melalui menu:

```text
1
1 2 3
3 4 5
2
1 2 3 4 5 6
3
4
5
7
0
```

Hasil utama:

```text
A ∪ B = {1, 2, 3, 4, 5}
A ∩ B = {3}
A - B = {1, 2}
B - A = {4, 5}
A' = {4, 5, 6}
B' = {1, 2, 6}
```