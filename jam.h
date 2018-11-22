#ifndef jam_H
#define jam_H

#include "boolean.h"

/* Untuk ADT JAM -> Waktu game  */
typedef struct {
    int SS; /* buat simpan waktu permainan kalau jadi di save */
} JAM;
/*Definisi pemanggilan Time */
#define Time(J) (J).SS

#endif