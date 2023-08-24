#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATE{
    int ngay;
    int thang;
    int nam;
};

void nhapDATE(DATE *x){
    scanf("%d%*c%d%*c%d",&x->ngay,&x->thang,&x->nam);
}

void xuatDATE(DATE *x){
    printf("  %02d/%02d/%04d  ",x->ngay,x->thang,x->nam);
}

struct SinhVien{
    char ht[30];
    char maSV[15];
    DATE ngaySinh;
    char gioiTinh[5]; // x - nu , y- nam
    char lop[20];
    char soDienThoai[30];
    char diaChi[30];
    float diemMon1;
    float diemMon2;
    float diemMon3; 
    float dtb;
    char hocLuc[20];
};

void xepLoai(SinhVien *x);

void nhap1SV(SinhVien *x){
    printf("Ma SV: ");
    scanf("%s",&x->maSV);
    fflush(stdin);
    printf("Ho Ten: ");
    fflush(stdin);
    gets(x->ht);
    printf("Ngay Sinh: ");
    fflush(stdin);
    nhapDATE(&x->ngaySinh);
    printf("Gioi Tinh: ");
    fflush(stdin); 
    scanf("%c",&x->gioiTinh);
    fflush(stdin);
    printf("Lop: ");
    scanf("%s",&x->lop);
    fflush(stdin);
    printf("So Dien Thoai: ");
    scanf("%s",&x->soDienThoai);
    fflush(stdin);
    printf("Dia Chi:");
    fflush(stdin);
    gets(x->diaChi);
    printf("Diem Mon 1: ");
    scanf("%f",&x->diemMon1);
    printf("Diem Mon 2: ");
    scanf("%f",&x->diemMon2);
    printf("Diem Mon 3: ");
    scanf("%f",&x->diemMon3);
    x->dtb = (x->diemMon1 + x->diemMon2 + x->diemMon3) / 3;
}


void xuat1SV(SinhVien *x){
    printf("\n%-7s%-21s%-3c",x->maSV,x->ht,x->gioiTinh);
    xuatDATE(&x->ngaySinh);
    printf("%-10s%-15s%-15s%.2f\t%.2f\t%.2f\t%.2f\t%s",x->lop,x->soDienThoai,x->diaChi,x->diemMon1,x->diemMon2,x->diemMon3,x->dtb,x->hocLuc);
    xepLoai(x);
}

int nhapN(){
    int n;
    do{
        printf("NHAP SO PHAN TU: ");
        scanf("%d",&n);
    }while(n<=0);
    return n;
}

void nhapDSSV(SinhVien *a, int n){
    for(int i=0; i<n; i++){
        printf("\tNHAP SINH VIEN THU %d:\n",i+1);
        nhap1SV(a+i);
    }
}

void xuatDSSV(SinhVien *a, int n){
    for(int i=0; i<n; i++){
        xuat1SV(a+i);
    }
}

void xepLoai(SinhVien *x){
    if(x->dtb>9)
        strcpy(x->hocLuc,"Xuat Sac");
    else if(x->dtb>8)
        strcpy(x->hocLuc,"Gioi");
    else if(x->dtb>7)
        strcpy(x->hocLuc,"Kha");
    else if(x->dtb>5)
        strcpy(x->hocLuc,"Trung Binh");
    else 
        strcpy(x->hocLuc,"Yeu");            
}

void xuatSVTheoMa(SinhVien *a, int n, const char *maMuonTim){
    printf("\n\tSINH VIEN CO MA LA %s", maMuonTim);
    for(int i=0; i<n; i++){
        if(stricmp(a[i].maSV, maMuonTim) == 0)
            xuat1SV(a+i);
    }
}

void timSVTheoTen(SinhVien *a, int n, const char *tenMuonTim){
    printf("\n\tCAC SINH VIEN CO TEN LA %s:", tenMuonTim);
    for(int i=0; i<n; i++){
        if(stricmp(a[i].ht, tenMuonTim) == 0)
            xuat1SV(a+i);
    }
}

void timSVTheoLop(SinhVien *a, int n, const char *lopMuonTim){
    printf("\n\tSINH VIEN THUOC LOP %s:", lopMuonTim);
    for(int i=0; i<n; i++){
        if(stricmp(a[i].lop, lopMuonTim) == 0)
            xuat1SV(a+i);
    }
}

void themSVMoi(SinhVien *a, int &n){
    printf("\nNHAP SINH VIEN CAN THEM: \n");
    nhap1SV(a+n);
    n++;
}

void sapXepTangTheoDtb(SinhVien *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].dtb > a[j].dtb){
                SinhVien tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}


void xoaSV(SinhVien *a, int &n,int vitri){
    if(vitri < 0 || vitri >= n){
        printf("\nKHONG HOP LE !");
        return; 
    } 
    for(int i = vitri; i < n-1; i++){
        a[i] = a[i+1]; 
    }
    n--;
}




int main(){
    // int n = nhapN();
    // SinhVien *a = (SinhVien*)malloc(n*sizeof(SinhVien));
    // nhapDSSV(a,n);
    // printf("\n\tDANH SACH SINH VIEN SAU KHI NHAP:");
    // xuatDSSV(a,n);

    // char masv[15];
    // printf("\nNHAP MA SINH VIEN MUON XUAT: ");
    // scanf("%s", masv);
    // xuatSVTheoMa(a, n, masv);

    // char ten[30];
    // printf("\nNHAP HO VA TEN SINH VIEN MUON TIM: ");
    // fflush(stdin);
    // timSVTheoTen(a, n, ten);

    // char lop[20];
    // printf("\nNHAP LOP SINH VIEN MUON TIM: ");
    // scanf("%s", lop);
    // timSVTheoLop(a, n, lop);

    // themSVMoi(a, n);
    // printf("\n\tDANH SACH SINH VIEN SAU KHI THEM:");
    // xuatDSSV(a, n);

    // sapXepTangTheoDtb(a, n);
    // printf("\n\tDANH SACH SINH VIEN SAU KHI SAP XEP:");
    // xuatDSSV(a, n);
    // xepLoai(a);

    // int vitri;
    // printf("\nNHAP VI TRI SINH VIEN MUON XOA: ");
    // scanf("%d", &vitri);
    // xoaSV(a, n, vitri);
    // printf("\n\tDANH SACH SINH VIEN SAU KHI XOA:");
    // xuatDSSV(a, n);



    // free(a); // Gi?i ph�ng v�ng nh? d� c?p ph�t
    // return 0;
    
    int n = nhapN();
    SinhVien *a = (SinhVien*)malloc(n*sizeof(SinhVien));
    nhapDSSV(a, n);
    
    int choice = 0;
    while (choice != 9) {
        printf("\n==========================MENU==========================\n");
        printf("1. Xuat danh sach sinh vien\n");
        printf("2. Xuat sinh vien theo ma\n");
        printf("3. Tim sinh vien theo ten\n");
        printf("4. Tim sinh vien theo lop\n");
        printf("5. Them sinh vien moi\n");
        printf("6. Xoa sinh vien\n");
        printf("7. Sap xep danh sach sinh vien theo DTB\n");
        printf("8. Xuat danh sach sinh vien sau khi sap xep\n");
        printf("9. Exit\n");
        printf("\n==========================MENU==========================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n\tDANH SACH SINH VIEN:\n");
                xuatDSSV(a, n);
                break;
            case 2:
                char masv[15];
                printf("\nNHAP MA SINH VIEN MUON XUAT: ");
                scanf("%s", masv);
                xuatSVTheoMa(a, n, masv);
                break;
            case 3:
                char ten[30];
                printf("\nNHAP HO VA TEN SINH VIEN MUON TIM: ");
                scanf("%s", ten);
                timSVTheoTen(a, n, ten);
                break;
            case 4:
                char lop[20];
                printf("\nNHAP LOP SINH VIEN MUON TIM: ");
                scanf("%s", lop);
                timSVTheoLop(a, n, lop);
                break;
            case 5:
                themSVMoi(a, n);
                printf("\n\tDANH SACH SINH VIEN SAU KHI THEM:");
                xuatDSSV(a, n);
                break;
            case 6:
                int vitri;
                printf("\nNHAP VI TRI SINH VIEN MUON XOA: ");
                scanf("%d", &vitri);
                xoaSV(a, n, vitri);
                printf("\n\tDANH SACH SINH VIEN SAU KHI XOA:");
                xuatDSSV(a, n);
                break;
            case 7:
                sapXepTangTheoDtb(a, n);
                printf("\n\tDANH SACH SINH VIEN SAU KHI SAP XEP:");
                xuatDSSV(a, n);
                break;
            case 8:
                printf("\n\tDANH SACH SINH VIEN SAU KHI SAP XEP:");
                xuatDSSV(a, n);
                break;
            case 9:
                printf("Ket thuc chuong trinh.");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.");
                break;
        }
    }
    
    free(a);
    return 0;
}


