<?php
echo "==============================\n";
echo " PROGRAM LATIHAN PHP DASAR\n";
echo "==============================\n\n";


//day 2
echo "Masukkan nama kamu: ";
$nama = trim(fgets(STDIN));
echo "Halo, $nama!\n\n";


//day 3
echo "=== Operasi Aritmatika ===\n";

echo "Masukkan angka pertama: ";
$a = trim(fgets(STDIN));

echo "Masukkan angka kedua: ";
$b = trim(fgets(STDIN));

echo "\nHasil Perhitungan:\n";
echo "Penjumlahan (A + B) = " . ($a + $b) . "\n";
echo "Pengurangan (A - B) = " . ($a - $b) . "\n";
echo "Perkalian  (A * B)  = " . ($a * $b) . "\n";

if ($b == 0) {
    echo "Pembagian  (A / B)  = Error: Tidak bisa membagi dengan nol.\n\n";
} else {
    echo "Pembagian  (A / B)  = " . ($a / $b) . "\n\n";
}


//day 4
echo "Masukkan nilai ujian: ";
$nilai = trim(fgets(STDIN));

if ($nilai >= 75) {
    echo "Status: Lulus\n\n";
} else {
    echo "Status: Tidak Lulus\n\n";
}


//day 5
echo "=== Deret Angka 1 - 20 ===\n";
for ($i = 1; $i <= 20; $i++) {
    echo $i . " ";
}
echo "\n\n";


//day 6
echo "Masukkan angka untuk dicek: ";
$angka = trim(fgets(STDIN));

if ($angka % 2 == 0) {
    echo "$angka adalah Bilangan Genap\n";
} else {
    echo "$angka adalah Bilangan Ganjil\n";
}

echo "\n=== Program Selesai ===\n";
?>
