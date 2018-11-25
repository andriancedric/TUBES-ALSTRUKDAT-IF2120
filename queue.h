#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "point.h"
#include "map.c"
/*Untuk ADT Queue*/

typedef struct
{
    int wktantri;    /* waktu antrean si pelanggan */
    int jumlahorang; /*antrian per grup, kan antriannya ga harus sendiri (per kelomppok)*/
} infotypeQ;

/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    infotypeQ *T; /*panjang antrian maksimal*/
    int HEAD; /* alamat penghapusan */
    int TAIL; /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
#define WktAntriHead(Q) (Q).T[(Q).HEAD].wktantri
#define JumlahOrangHead(Q) (Q).T[(Q).HEAD].jumlahorang
#define WktAntriTail(Q) (Q).T[(Q).TAIL].wktantri
#define JumlahOrangTail(Q) (Q).T[(Q).TAIL].jumlahorang
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define WktAntri(Q, i) (Q).T[i].wktantri
#define JumlahOrang(Q, i) (Q).T[i].jumlahorang
#define MaxEl(Q) (Q).MaxEl



/* ********* Prototype ********* */
boolean IsEmptyQ(Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQ(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
/* *** Kreator *** */
void CreateEmptyQ(Queue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
void DeAlokasiQ(Queue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddQ(Queue *Q, int jumlahorang, int wktantri);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQ(Queue *Q, int *jumlahorang, int *wktantri);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
boolean SearchQ(Queue Q, int X);
/* Proses : Search apakah ada X di Queue, mengembalikan true jika ada, dan false jika tidak */
/* I.S. Q tidak mungkin kosong */
/* F.S. X ketemu atau tidak */

void SortQ(Queue *Q);
/* Proses : Memindahkan antrian yang berjumlah 2 orang ke paling depan untuk di place di meja berkapasitas 2 orang */

void AddDepanQ(Queue *Q, int jumlahorang, int wktantri);
/* Proses : Memasukkan Orang ke paling depan Queue */

void DelQIdx(Queue *Q, int idx, int *jumlahorang, int *wktantri);
/* Proses : mengeluarkan orang yang berada pada index ke idx dari queue */

void KesabaranMinusQ(Queue *Q, int c, PLAYER * play);
/* Proses : mengurangi Kesabaran Customer setiap kali Command di lakukan, jika kesabaran sudah 0 maka Customer */
/*          di delete dari antrian dan nyawa player berkurang 1 */

void PrintQ(Queue Q);

void Place(Room R, Queue *Q, POINT P);

#endif
