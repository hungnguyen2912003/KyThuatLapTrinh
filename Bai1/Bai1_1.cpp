/*
Viết chương trình quản lý danh sách sinh viên đơn giản. Mỗi sinh viên cần quản lý các thông tin: Mã số sinh viên, họ và tên, điểm trung bình.

a) Khai báo kiểu struct mô tả thông tin của mỗi sinh viên.

b) Viết các hàm: 

- Nhập thông tin sinh viên;

- Xuất thông tin sinh viên;

- Tìm sinh viên dựa vào mã số sinh viên;

- Sắp xếp danh sách sinh viên theo thứ tự (giảm dần/tăng dần) của điểm trung bình. (Cần có một tham số cho phép lựa chọn sắp xếp tăng hay giảm).

c) Chương trình chính sử dụng các khai báo và hàm ở trên để thực hiện:

- Nhập danh sách n sinh viên (0<n<100);

- In ra danh sách vừa nhập;

- Nhập vào mã số sinh viên, tìm kiếm sinh viên có mã trên trong danh sách;

- Sắp xếp danh sách sinh viên theo thứ tự giảm dần của điểm trung bình. In danh sách sau sắp xếp lên màn hình.
*/

#include <stdio.h>

struct SinhVien{
    int MSSV;
    char HoTen[50];
    float diemtb;
};

void NhapSV(SinhVien &sv){
    printf("\n\tNhap MSSV: ");
    scanf("%d", &sv.MSSV);
    fflush(stdin);
    printf("\tNhap ho ten sinh vien: ");
    fgets(sv.HoTen,49,stdin);
    fflush(stdin);
    printf("\tDiem trung binh mon: ");
    scanf("%f", &sv.diemtb);
}

void InSV(SinhVien sv){
    printf("\tMSSV cua sinh vien: %d\n", sv.MSSV);
    printf("\tHo ten sinh vien: %s", sv.HoTen);
    printf("\tDiem trung binh cua sinh vien: %.1f", sv.diemtb);
}


void NhapDSSV(SinhVien sv[], int &n){
    for(int i = 0;i < n; i++){
        printf("\nNhap thong tin sinh vien thu %d\n", i+1);
        printf("-----------------------------------");
        NhapSV(sv[i]);
        printf("-----------------------------------");
        printf("\n");
    }
}

void InDSSV(SinhVien sv[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Thong tin cua sinh vien thu %d\n", i+1);
        InSV(sv[i]);
        printf("\n");
    }
}

void TimKiemSV(SinhVien sv[], int n, int maso){
    if(sv->MSSV!=maso)
        printf("MSSV khong ton tai");
    else
        for(int i=0;i<n;i++){
            if(sv[i].MSSV==maso){
                printf("Ho ten SV: %s", sv[i].HoTen);
                printf("MSSV: %d\n", sv[i].MSSV);
                printf("Diem trung binh cua sinh vien: %0.1f", sv[i].diemtb);     
            }
        }
}

void Hoanvi(SinhVien &x, SinhVien &y){
    SinhVien temp = x; x = y; y = temp;
}

void SapXepSVGiam(SinhVien sv[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n;j++){
            if(sv[i].diemtb<sv[j].diemtb)
                Hoanvi(sv[i], sv[j]);
        } 
}

int main(){
    SinhVien dssv[50];
    int n, maso;
    do
    {
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
    } while (!(n>0 && n<100));
    NhapDSSV(dssv,n);
    printf("\nDanh sach sinh vien vua nhap\n");
    printf("--------------------------------\n");
    InDSSV(dssv,n);
    fflush(stdin);
    printf("--------------------------------\n");
    printf("Nhap MSSV can tim kiem: ");
    scanf("%d", &maso);
    TimKiemSV(dssv,n,maso);
    printf("\n--------------------------------\n");
    SapXepSVGiam(dssv,n);
    printf("Danh sach sinh vien theo thu tu giam dan theo diem trung binh\n");
    InDSSV(dssv,n);
    return 1;
}