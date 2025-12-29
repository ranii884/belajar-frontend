<?php
$data = [];

while (true) {
    echo "\n=== WEEK-2 ARRAY ===\n";
    echo "1. Tambah Item\n";
    echo "2. Lihat Semua Item\n";
    echo "3. Hapus Item\n";
    echo "4. Keluar\n";
    echo "Pilih menu: ";
    $menu = trim(fgets(STDIN));

    switch ($menu) {

        case 1:
            echo "Masukkan item baru: ";
            $item = trim(fgets(STDIN));
            $data[] = $item;                     // Item itu dimasukkan ke array ($data)
            echo "Item berhasil ditambahkan!\n";
            break;
            
        case 2:
            echo "\n=== Data Saat Ini ===\n";
            if (empty($data)) {
                echo "Belum ada data.\n";
            } else {
                foreach ($data as $i => $val) {
                    echo ($i+1) . ". $val\n";
                }
            }
            break;
// $i adalah indeks array
// $val adalah isi item
        case 3:
            echo "Masukkan nomor item yang ingin dihapus: ";
            $hapus = trim(fgets(STDIN)) - 1;

            if (isset($data[$hapus])) {
                unset($data[$hapus]);
                $data = array_values($data); // reset index
                echo "Item berhasil dihapus!\n";
            } else {
                echo "Nomor tidak valid!\n";
            }
            break;
// isset() → cek apakah indeks tersebut ada
// unset() → menghapus item array
// array_values() → merapikan ulang indeks array dari 0,1,2...
        case 4:
            echo "Program selesai.\n";
            exit;

        default:
            echo "Menu tidak valid!\n";
    }
}
?>
