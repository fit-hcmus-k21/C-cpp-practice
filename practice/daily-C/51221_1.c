#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[ ]) 
{
            int soluongBanbe = 0, i = 0;
            int* tuoiBanbe = NULL; // con tro nay se duoc su dung nhu mot mang sau khi dung malloc
            // Chung ta se yeu cau nguoi dung cho biet so luong ban be cua ho
            printf ("Ban co bao nhieu nguoi ban ? ");
            scanf ("%d", &soluongBanbe);
            if (soluongBanbe > 0) // Phai co it nhat mot nguoi ban (xin chia buon neu ko co ai ^^!)
            {
            tuoiBanbe = malloc(soluongBanbe * sizeof(int)); // Phan phoi bo nho cho mang
            if (tuoiBanbe == NULL) // Kiem tra xem viec cap phat bo nho co thanh cong ko?
            {
            exit(0); // Chuong trinh ngung lai ngay lap tuc
            }
            // Yeu cau nhap tuoi tung nguoi ban
            for (i = 0 ; i < soluongBanbe ; i++)
            {
            printf ("Nguoi ban thu %d bao nhieu tuoi ? ", i + 1);
            scanf ("%d", &tuoiBanbe[i]);
            }
            // Lan luot hien thi tuoi cua ban be
            printf ("\n\nTuoi cua ban be ban la :\n");
            for (i = 0 ; i < soluongBanbe ; i++)
            {
            printf ("%d tuoi\n", tuoiBanbe[i]);
            }
            // Giai phong bo nho da duoc cap phat cho mang boi malloc, no ko con can thiet nua.
            free(tuoiBanbe);
            }
 return 0;
}