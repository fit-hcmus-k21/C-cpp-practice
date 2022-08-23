#include<stdio.h>
#include<stdlib.h>

int** Taomang(int& m, int& n)
{
    printf("Nhap kich thuoc mang: ");
    scanf("%d%d", &m, &n);

    int** p = new int*[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
    }
    return p;
}

void Nhapmang(int** p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("p[%d][%d]: ", i, j);
            scanf("%d", &p[i][j]);
        }
    }
}

void Xuatmang(int** p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void Giaiphong(int** &p, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete[] p[i];
        p[i] = NULL;
    }
    delete[] p;
    p = NULL;
}

void ThemDong_Truoc(int** &p, int &m, int n, int* r)
{
    m++;
    // Dùng thủ công.
    // int** q = new int*[m];
    // for (int i = 1; i < m; i++)
    // {
    //     q[i] = p[i-1];
    // }
    // q[0] = r;
    // delete[] p;
    // p = q;

    // Dùng hàm.
    p = (int**)realloc(p, m*sizeof(int*));
    for (int i = m-1; i > 0; i--)
    {
        p[i] = p[i-1];
    }
    p[0] = r;
}

void ThemDong_Sau(int** &p, int &m, int n, int* r)
{
    m++;
    // Dùng thủ công.
    int** q = new int*[m];
    for (int i = 0; i < m-1; i++)
    {
        q[i] = p[i];
    }
    q[m-1] = r;
    delete[] p;
    p = q;

    // Dùng hàm.
    // p = (int**)realloc(p, m*sizeof(int*));
    // p[m-1] = r;
}

void ThemTruoc1D(int* &p, int &n)
{
    int value;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    n++; 
    int *q = new int[n];
    for (int i = 1; i < n; i++)
    {
        q[i] = p[i-1];
    }
    q[0] = value;
    // delete[] p;
    p = q;
}

void ThemCot_Truoc(int** p, int m, int &n)
{
    // Dùng thủ công.
    for (int i = 0; i < m; i++)
    {
        int value;
        printf("Nhap gia tri muon them: ");
        scanf("%d", &value);
        int arr_size = n+1;
        int* arr = new int[arr_size];
        for (int j = 1; j < arr_size; j++)
        {
            arr[j] = p[i][j-1];
        }
        arr[0] = value;
        delete[] p[i];
        p[i] = arr;
    }
    n++;

    // Dùng hàm ThemTruoc1D.
    // for (int i = 0; i < m; i++)
    // {
    //     int arr_size = n;
    //     ThemTruoc1D(p[i], arr_size);
    // }
    // n++;
}

void ThemSau1D(int* &p, int &n)
{
    n++;
    int value;
    printf("Nhap gia tri muon them: " );
    scanf("%d", &value);
    int* q = new int[n];
    for (int i = 0; i < n-1; i++)
    {
        q[i] = p[i];
    }
    q[n-1] = value;
    // delete[] p;
    p = q;
}

void ThemCot_Sau(int** p, int m, int &n)
{
    for (int i = 0; i < m; i++)
    {
        int temp= n+1;
        int value;
        printf("Nhap gia tri muon them: ");
        scanf("%d", &value);
        int* q = new int[temp];
        for (int j = 0; j < temp-1; j++)
        {
            q[j] = p[i][j];
        }
        q[temp-1] = value;
        // delete[] p[i];
        p[i] = q;
    }
    n++;

    // Dùng hàm ThemSau1D
    // for (int i = 0; i < m; i++)
    // {
    //     int arr_size = n;
    //     ThemSau1D(p[i], arr_size);
    // }
    // n++;
}

void XoaDong(int** &p, int& m, int n)
{
    int index;
    printf("Nhap dong muon xoa: ");
    scanf("%d", &index);

    m--;
    int** q = new int*[m];
    for (int i = 0; i < index; i++)
    {
        q[i] = p[i];
    }
    for (int i = index; i < m; i++)
    {
        q[i] = p[i+1];
    }
    delete[] p;
    p = q;
}

void XoaCot(int** p, int m, int &n)
{
    int index;
    printf("Nhap cot muon xoa: ");
    scanf("%d", &index);
    for (int i = 0; i < m; i++)
    {
        int arr_size = n-1;
        int* arr = new int[arr_size];
        for (int j = 0; j < index; j++)
        {
            arr[j] = p[i][j];
        }
        for (int j = index; j < arr_size; j++)
        {
            arr[j] = p[i][j+1];
        }
        delete[] p[i];
        p[i] = arr;
    }
    n--;
}

int main()
{
    int** p = NULL;
    int m = 0, n = 0;
    p = Taomang(m, n);
    Nhapmang(p, m, n);
    Xuatmang(p, m, n);printf("\n");
    int a[] = {0, 0, 0};
    ThemDong_Truoc(p, m, n, a);
    Xuatmang(p, m, n);printf("\n");
    ThemDong_Sau(p, m, n, a);
    Xuatmang(p, m, n);printf("\n"); 

    /* Lưu ý, 2 phần này nếu chạy riêng từng phần thì đúng, nhưng khi tách biệt thì phần trên chỉ chạy được mỗi 2 hàm, phần dưới chạy được các hàm còn lại */

    ThemCot_Truoc(p, m, n);
    Xuatmang(p, m, n);printf("\n");
    ThemCot_Sau(p, m, n);
    Xuatmang(p, m, n);printf("\n");
    XoaCot(p, m, n);
    Xuatmang(p, m, n);printf("\n");
    XoaDong(p, m, n);
    Xuatmang(p, m, n);printf("\n"); 
    Giaiphong(p, m);
    return 1;
}
