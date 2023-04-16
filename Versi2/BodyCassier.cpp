#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cassier.h"


// Fungsi untuk memeriksa apakah username dan password sesuai dengan akun yang terdaftar
int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password) {
    int i;
	for (i = 0; i < jml_akun; i++) {
        if (strcmp(akun[i].username, username) == 0 && strcmp(akun[i].password, password) == 0) {
            return i; // username dan password sesuai
        }
    }
    return -1; // username dan password tidak sesuai
}
