/* header untuk Tubes Engi's Kitchen Expansion */

#ifndef FP_H
#define FP_H

#include "boolean.h"
// ADT JAM
    void TulisJAM (JAM J);
    /* I.S. : J sembarang */
    /* F.S. :   Nilai J ditulis dg format HH:MM:SS */
    /* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

// ADT POINT

    /* *** DEFINISI PROTOTIPE PRIMITIF *** */
    /* *** Konstruktor membentuk POINT *** */
    POINT MakePOINT (float X, float Y);
    /* Membentuk sebuah POINT dari komponen-komponennya */

    /* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

    void TulisPOINT (POINT P);
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
       tanpa spasi, enter, atau karakter lain di depan, belakang,
       atau di antaranya
       Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */
    boolean EQ (POINT P1, POINT P2);
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

    POINT NextX (POINT P);
    /* Mengirim salinan P dengan absis ditambah satu */
    POINT NextY (POINT P);
    /* Mengirim salinan P dengan ordinat ditambah satu */
    float Panjang (POINT P1, POINT P2);
    /* Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
    /* Tuliskan spec fungsi yang lebih tepat. */
    void Geser (POINT *P, float deltaX, float deltaY);
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

// ADT ARRAY
    void MakeEmptyArray (TabInt * T);
    /* I.S. T sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    int NbElmtArr (TabInt T);
      /* Mengirimkan banyaknya elemen efektif tabel */
      /* Mengirimkan nol jika tabel kosong */
    int MaxNbElArr (TabInt T)
      /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    IdxType GetFirstIdxArr (TabInt T);
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    IdxType GetLastIdxArr (TabInt T);
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */

    boolean IsIdxValid (TabInt T, IdxType i);
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    boolean IsIdxEff (TabInt T, IdxType i);
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */

    boolean IsArrEmpty (TabInt T);
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    /* *** Test tabel penuh *** */
    boolean IsArrFull (TabInt T);
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */


    boolean SearchArr (TabInt T, ElType X);
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Memakai Skema search DENGAN boolean */

    void SortKesabaran (TabInt * T);
    /* I.S. T boleh kosong */
    /* F.S. T elemennya terurut menaik dengan Insertion Sort */
    /* Proses : mengurutkan T sehingga elemennya menaik/membesar */
    /*          tanpa menggunakan tabel kerja */


// MATRIKS

    /* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
    /* *** Konstruktor membentuk MATRIKS *** */
    void MakeMATRIKS (int NB, int NK, MATRIKS * M);
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

    /* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
    indeks GetFirstIdxBrs (MATRIKS M);
    /* Mengirimkan indeks baris terkecil M */
    indeks GetFirstIdxKol (MATRIKS M);
    /* Mengirimkan indeks kolom terkecil M */
    indeks GetLastIdxBrs (MATRIKS M);
    /* Mengirimkan indeks baris terbesar M */
    indeks GetLastIdxKol (MATRIKS M);
    /* Mengirimkan indeks kolom terbesar M */
    boolean IsIdxEff (MATRIKS M, indeks i, indeks j);
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */

    void TulisMATRIKS (MATRIKS M);
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
// Mesin Kar
    void START(char* filename);
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : CC adalah karakter pertama pada pita
              Jika CC != MARK maka EOP akan padam (false)
              Jika CC = MARK maka EOP akan menyala (true) */

    void ADV();
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela = CC, CC != MARK
       F.S. : CC adalah karakter berikutnya dari CC yang lama,
              CC mungkin = MARK
              Jika  CC = MARK maka EOP akan menyala (true) */

// Mesin Kata
    void IgnoreBlank();
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : CC sembarang
       F.S. : CC ≠ BLANK atau CC = MARK */

    void STARTKATA(char* filename);
    /* I.S. : CC sembarang
       F.S. : EndKata = true, dan CC = MARK;
              atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
              CC karakter pertama sesudah karakter terakhir kata */

    void ADVKATA();
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
       F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
              CC adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika CC = MARK, EndKata = true.
       Proses : Akuisisi kata menggunakan procedure SalinKata */

    void SalinKata();
    /* Mengakuisisi kata, menyimpan dalam CKata
       I.S. : CC adalah karakter pertama dari kata
       F.S. : CKata berisi kata yang sudah diakuisisi;
              CC = BLANK atau CC = MARK;
              CC adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
// QUEUE
    /* ********* Prototype ********* */
    boolean IsEmptyQ (Queue Q);
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    boolean IsFullQ (Queue Q);
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    int NBElmtQ (Queue Q);
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

    /* *** Kreator *** */
    void CreateEmptyQ (Queue * Q, int Max);
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */

    /* *** Primitif Add/Delete *** */
    void AddQ (Queue * Q, infotype X);
    /* Proses: Menambahkan X pada Q dengan aturan FIFO */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    void DelQ (Queue * Q, infotype * X);
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */

//STACK

    /* ************ Prototype ************ */
    /* *** Konstruktor/Kreator *** */
    void CreateEmptySt (Stack *S);
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
    /* Ciri stack kosong : TOP bernilai Nil */

    /* ************ Predikat Untuk test keadaan KOLEKSI ************ */
    boolean IsEmptySt (Stack S);
    /* Mengirim true jika Stack kosong: lihat definisi di atas */
    boolean IsFullSt (Stack S);
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */

    /* ************ Menambahkan sebuah elemen ke Stack ************ */
    void Push (Stack * S, infotype X);
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

    /* ************ Menghapus sebuah elemen Stack ************ */
    void Pop (Stack * S, infotype* X);
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

    void Put (Stack *SH, Stack *ST);
    /*SH adalah stack hand, ST adalah Stack tray*/
    /*I.S. : Ada tumpukan makanan di tangan, terbentuk karena urutan*/
    /*F.S. : Makanan yang terbentuk dipindah ke tray*/

    void Take (int ID, Stack *SH);
    /*I.S. : Ada bahan di sebelah pemain, kondisi tangan tidak penuh*/
    /*F.S. : Bahan berpindah ke tangan*/

    void Give (Stack *ST, int *ID);
    /*I.S : Ada tumpukkan di tray*/
    /*F.S : Makanan pada top of tray akan diberikan kepada pelanggan*/

#endif
