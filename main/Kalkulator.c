#include<stdio.h>
#include<string.h>

float tambah(float angka1, float angka2);       //Deklarasi fungsi tambah
float kurang(float angka1, float angka2);       //Deklarasi fungsi kurang
float kali(float angka1, float angka2);         //Deklarasi fungsi kali
float bagi(float angka1, float angka2);         //Deklarasi fungsi bagi
float hasil_pangkat(float angka1, float pangkat);   //Deklarasi fungsi pangkat
float integral(float batas1, float batas2, int interval);      //Deklarasi fungsi integral dengan f(x) = x^2 + x
float fungsi(float x);      //Deklarasi fungsi "fungsi"

int main(){

    char perintah[100];
    printf("Masukkan perintah (tambah, kurang, kali, bagi, pangkat, integral):\n");
    scanf("%s", &perintah);      //Menerima command yang akan menjadi kondisi perhitungan

    if (strcmp(perintah, "tambah") == 0) {      //Jika user memasukkan input "tambah"
        
        float angka1, angka2;
        printf("Masukkan angka 1:\n");          //input angka yang pertama
        scanf("%f", &angka1);                   
        printf("Masukkan angka 2:\n");          //input angka kedua
        scanf("%f", &angka2);
        tambah(angka1, angka2);                 //Menghasilkan nilai tambah angka 1 dengan angka 2
    }
    else if ((strcmp(perintah, "kurang") == 0)) {       //Jika user memasukkan input "kurang"
        
        float angka1, angka2;
        printf("Masukkan angka 1:\n");          //input angka yang pertama
        scanf("%f", &angka1);
        printf("Masukkan angka 2:\n");          //input angka kedua
        scanf("%f", &angka2);
        kurang(angka1, angka2);                 //Menghasilkan nilai kurang angka 1 dengan angka 2

    }
    else if ((strcmp(perintah, "kali") == 0)) {         //Jika user memasukkan input "kali"
        
        float angka1, angka2;
        printf("Masukkan angka 1:\n");                  //input angka yang pertama
        scanf("%f", &angka1);
        printf("Masukkan angka 2:\n");                  //input angka kedua
        scanf("%f", &angka2);
        kali(angka1, angka2);                           //Menghasilkan nilai kali angka 1 dengan angka 2

    }
    else if ((strcmp(perintah, "bagi") == 0)) {         //Jika user memasukkan input "bagi"
        
        float angka1, angka2;
        printf("Masukkan angka 1:\n");                  //input angka pertama
        scanf("%f", &angka1);
        printf("Masukkan angka 2:\n");                  //input angka kedua
        scanf("%f", &angka2);
        bagi(angka1, angka2);                           //Menghasilkan hasil bagi angka 1 dengan angka 2

    }
    else if ((strcmp(perintah, "pangkat") == 0)) {      //Jika user memasukkan input "pangkat"
        
        float angka1, pangkat;
        printf("Masukkan angka basis:\n");              //Input basis pangkat
        scanf("%f", &angka1);
        printf("Masukkan pangkat:\n");                  //Input pangkat, dengan pangkat bilangan integer lebih dari 1
        scanf("%f", &pangkat);
        hasil_pangkat(angka1, pangkat);

    }
    else if ((strcmp(perintah, "integral") == 0)) {     //Jika user memasukkan input "integral"
        
        float batas1, batas2, interval;
        printf("Masukkan interval dari integral f(x):\n");      //Input interval dari riemann/integral
        scanf("%f", &interval);
        printf("Masukkan batas bawah dari integral f(x):\n");   //Input batas bawah integral
        scanf("%f", &batas1);
        printf("Masukkan batas atas dari integral f(x):\n");    //Input batas atas integral
        scanf("%f", &batas2);
        integral(batas1, batas2, interval);              //Menghasilkan hasil integral f(x) dari batas bawah hingga batas atas
        
    }
    else {                                              //Jika input tidak masuk syarat
        printf("Masukkan tidak valid");
    }

    return 0;
}

float tambah(float angka1, float angka2) {      //Fungsi tambah. Aplikasi : tambah(1, 2)
    printf("Hasilnya adalah %.2f", angka1 + angka2);
    return angka1 + angka2;
}

float kurang(float angka1, float angka2) {      //Fungsi kurang. Aplikasi : kurang(3, 1)
    printf("Hasilnya adalah %.2f", angka1 - angka2);
    return angka1 - angka2;
}

float kali(float angka1, float angka2) {      //Fungsi kali. Aplikasi : kali(2.6, 3)
    printf("Hasilnya adalah %.2f", angka1 * angka2);
    return angka1 * angka2;
}

float bagi(float angka1, float angka2) {      //Fungsi bagi. Aplikasi : bagi(7.5, 3)
    printf("Hasilnya adalah %.2f", angka1 / angka2);
    return angka1 / angka2;
}

float hasil_pangkat(float angka1, float pangkat) {      //Fungsi pangkat dengan syarat pangkat > 1 dan pangkat merupakan integer. Aplikasi : pangkat(2, 3)
    
    int i;
    float hasil;
    hasil = angka1;
    for (i = 1; i < (pangkat); i ++) {      
            hasil *= angka1;
    }
    printf("Hasilnya adalah %.1f", hasil);
    return hasil;
}

float fungsi(float x) {              //fungsi yang mengembalikan nilai dari f(x) = x^2 + x

    float f_x;
    f_x = (x*x) + x;
    return f_x;
}


float integral(float batas1, float batas2, int interval) {          //Fungsi integral dengan persamaan x^2 + x
                                                                    //Aplikasi: integral(2, 6, 4)
    float hasil, i, x, delta_x, x_atas, x_bawah, y_atas, y_bawah;
    hasil = 0;
    delta_x = (batas2-batas1)/interval;
    x_atas = batas1;
    x_bawah = batas1 + delta_x;
    y_atas = fungsi(x_atas);
    y_bawah = fungsi(x_bawah);

    for (i = 0; i < interval; i++) {

        hasil = hasil + (y_atas + y_bawah) * delta_x/2;
        x_atas = x_atas + delta_x;
        x_bawah = x_bawah + delta_x;
        y_atas = fungsi(x_atas);
        y_bawah = fungsi(x_bawah);

    }
    
    printf("Hasilnya adalah %.2f", hasil);
    return hasil;

}