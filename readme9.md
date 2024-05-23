# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
### Graph

![Cuplikan layar 2024-05-23 202858](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/b1d23545-b682-414e-b696-1b586763c752)


Graf adalah kumpulan titik (simpul) dalam bidang dua dimensi yang dihubungkan oleh garis-garis (sisi). Graf dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan di antaranya. Representasi visual dari graf melibatkan penggunaan titik untuk objek (Vertex), dan garis untuk hubungan antar objek (Edge). Graf secara matematis dinyatakan sebagai G = (V, E), di mana G adalah graf, V adalah kumpulan simpul atau node, dan E adalah kumpulan busur atau sisi.

Graf adalah cabang ilmu yang memiliki banyak penerapan. Banyak struktur dapat direpresentasikan dengan graf, dan banyak masalah dapat diselesaikan menggunakan graf. Graf sering digunakan untuk memodelkan jaringan, seperti jaringan jalan raya, dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan kota sebagai sisi (edge), di mana bobotnya adalah panjang jalan tersebut.

Ada beberapa metode untuk menyimpan graf dalam sistem komputer, bergantung pada struktur graf dan algoritma yang digunakan untuk memanipulasi graf tersebut. Struktur data yang umum digunakan termasuk daftar dan matriks, atau kombinasi keduanya.

Beberapa jenis graf meliputi:

a. Graf tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak dipentingkan. Misalnya, busur e1 dapat disebut busur AB atau BA.

b. Graf berarah (directed graph): Urutan simpul memiliki arti. Misalnya, busur AB adalah e1, sedangkan busur BA adalah e8.

c. Graf berbobot (weighted graph): Setiap busur memiliki nilai yang menyatakan hubungan antara dua simpul. Bobot ini dapat menyatakan panjang jalan antara dua titik, jumlah rata-rata kendaraan per hari yang melalui jalan tersebut, dan lain-lain.

Operasi yang diterapkan pada struktur data non-linear meliputi:

-Menambahkan elemen

-Menghapus elemen

-Menampilkan elemen

-Mengurutkan elemen

Operasi-operasi ini dapat dilakukan dengan menerapkan satu atau lebih fungsi dan metode untuk menggabungkan elemen data secara acak, sehingga membentuk berbagai jenis struktur data.

### Tree

Dalam ilmu komputer, pohon biner adalah struktur data pohon di mana setiap simpul memiliki paling banyak dua anak, yang disebut sebagai anak kiri dan anak kanan. Definisi rekursif menggunakan teori himpunan menyatakan bahwa pohon biner (non-kosong) adalah tupel (L, S, R), di mana L dan R adalah pohon biner atau himpunan kosong, dan S adalah himpunan tunggal. Beberapa penulis juga mengizinkan pohon biner menjadi himpunan kosong.
![Cuplikan layar 2024-05-23 205142](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/1ac1e2c8-2447-4064-a90d-cef38d8023f1)

Dari perspektif teori graf, pohon biner (dan K-ary) seperti yang didefinisikan di sini sebenarnya adalah arborescences. Oleh karena itu, pohon biner juga bisa disebut sebagai bifurcating arborescence, sebuah istilah yang muncul dalam beberapa buku pemrograman yang sangat lama sebelum terminologi ilmu komputer modern berkembang.

Pohon biner dapat pula diinterpretasikan sebagai graf tak berarah, dalam hal ini pohon biner adalah pohon berakar yang tertata. Beberapa penulis menggunakan istilah pohon biner berakar untuk menekankan bahwa pohon tersebut berakar, tetapi berdasarkan definisi di atas, pohon biner selalu berakar. Pohon biner adalah kasus khusus dari pohon K-ary yang tertata, di mana k adalah 2.

Dalam matematika, definisi pohon biner bisa bervariasi antara penulis. Beberapa menggunakan definisi yang umum dalam ilmu komputer, sementara yang lain mendefinisikannya sebagai pohon di mana setiap simpul non-daun memiliki tepat dua anak tanpa memerlukan urutan (seperti kiri/kanan) untuk anak-anaknya.

Dalam komputasi, pohon biner digunakan dalam dua cara utama:

1. Sebagai cara untuk mengakses simpul berdasarkan nilai atau label yang terkait dengan setiap simpul. Pohon biner berlabel seperti ini digunakan untuk mengimplementasikan pohon pencarian biner dan heap biner, serta digunakan untuk pencarian dan penyortiran yang efisien. Penempatan simpul non-akar sebagai anak kiri atau kanan, bahkan jika hanya ada satu anak, penting dalam beberapa aplikasi ini, khususnya dalam pohon pencarian biner. Namun, pengaturan simpul tertentu dalam pohon bukanlah bagian dari informasi konseptual. Misalnya, dalam pohon pencarian biner biasa, penempatan simpul sangat bergantung pada urutan penambahannya, dan dapat diatur ulang (misalnya dengan menyeimbangkan) tanpa mengubah artinya.

2. Sebagai representasi data dengan struktur bifurkasi yang relevan. Dalam kasus ini, susunan simpul tertentu di bawah dan/atau ke kiri atau kanan simpul lain adalah bagian dari informasi (artinya, mengubah susunan ini akan mengubah artinya). Contoh umum termasuk pengkodean Huffman dan cladogram. Pembagian dokumen sehari-hari menjadi bab, bagian, paragraf, dan sebagainya adalah contoh yang lebih sesuai dengan pohon n-ary daripada pohon biner.

## Guided





