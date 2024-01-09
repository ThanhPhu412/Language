#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TEN_TEP_TIN "sinhvien.txt"

typedef struct {
    char id[6];
    char ten[31];
    char lop[11];
    float diem_toan;
    float diem_ly;
    float diem_hoa;
} SinhVien;

void doc_du_lieu_tu_tep(SinhVien sinhviens[], int *so_luong) {
    FILE *tep = fopen(TEN_TEP_TIN, "r");
    if (tep == NULL) {
        *so_luong = 0;
        return;
    }

    *so_luong = 0;
    while (fscanf(tep, "%5s,%30[^,],%10[^,],%f,%f,%f\n",
                  sinhviens[*so_luong].id, sinhviens[*so_luong].ten, sinhviens[*so_luong].lop,
                  &sinhviens[*so_luong].diem_toan, &sinhviens[*so_luong].diem_ly, &sinhviens[*so_luong].diem_hoa) == 6) {
        (*so_luong)++;
    }

    fclose(tep);
}

void ghi_du_lieu_vao_tep(SinhVien sinhviens[], int so_luong) {
    FILE *tep = fopen(TEN_TEP_TIN, "w");
    if (tep == NULL) {
        printf("Khong the mo tep tin de ghi du lieu.\n");
        exit(1);
    }

    for (int i = 0; i < so_luong; i++) {
        fprintf(tep, "%s,%s,%s,%.2f,%.2f,%.2f\n",
                sinhviens[i].id, sinhviens[i].ten, sinhviens[i].lop,
                sinhviens[i].diem_toan, sinhviens[i].diem_ly, sinhviens[i].diem_hoa);
    }

    fclose(tep);
}

int kiem_tra_diem(float diem) {
    return diem >= 0 && diem <= 10;
}

int kiem_tra_ma_sinhvien(const char *ma_sinhvien) {
    return strlen(ma_sinhvien) == 5;
}

void chuan_hoa_ten(char *ten) {
    for (int i = 0; i < strlen(ten); i++) {
        if (i == 0 || (i > 0 && ten[i - 1] == ' ')) {
            ten[i] = toupper(ten[i]);
        } else {
            ten[i] = tolower(ten[i]);
        }
    }
}

void them_sinhvien(SinhVien sinhviens[], int *so_luong) {
    if (*so_luong == 100) {
        printf("Danh sach sinh vien da day. Khong the them moi.\n");
        return;
    }

    printf("Nhap ma sinh vien: ");
    scanf("%5s", sinhviens[*so_luong].id);
    if (!kiem_tra_ma_sinhvien(sinhviens[*so_luong].id)) {
        printf("Ma sinh vien khong hop le. Vui long nhap ma gom 5 ky tu.\n");
        return;
    }

    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", sinhviens[*so_luong].ten);
    chuan_hoa_ten(sinhviens[*so_luong].ten);

    printf("Nhap lop cua sinh vien: ");
    scanf("%10s", sinhviens[*so_luong].lop);

    printf("Nhap diem toan: ");
    scanf("%f", &sinhviens[*so_luong].diem_toan);
    if (!kiem_tra_diem(sinhviens[*so_luong].diem_toan)) {
        printf("Diem toan khong hop le. Vui long nhap diem tu 0 den 10.\n");
        return;
    }

    printf("Nhap diem ly: ");
    scanf("%f", &sinhviens[*so_luong].diem_ly);
    if (!kiem_tra_diem(sinhviens[*so_luong].diem_ly)) {
        printf("Diem ly khong hop le. Vui long nhap diem tu 0 den 10.\n");
        return;
    }

    printf("Nhap diem hoa: ");
    scanf("%f", &sinhviens[*so_luong].diem_hoa);
    if (!kiem_tra_diem(sinhviens[*so_luong].diem_hoa)) {
        printf("Diem hoa khong hop le. Vui long nhap diem tu 0 den 10.\n");
        return;
    }

    (*so_luong)++;

    ghi_du_lieu_vao_tep(sinhviens, *so_luong);
    printf("Them sinh vien thanh cong.\n");
}

void hien_thi_sinhvien(const SinhVien *sinhvien) {
    printf("%-5s\t%-30s\t%-10s\tToan: %.2f\tLy: %.2f\tHoa: %.2f\tTrung binh: %.2f\n",
           sinhvien->id, sinhvien->ten, sinhvien->lop,
           sinhvien->diem_toan, sinhvien->diem_ly, sinhvien->diem_hoa,
           (sinhvien->diem_toan + sinhvien->diem_ly + sinhvien->diem_hoa) / 3);
}

void hien_thi_tat_ca_sinhvien(SinhVien sinhviens[], int so_luong) {
    printf("%-5s%-30s%-10s%-5s%-5s%-5s%-10s\n",
           "Ma", "Ten", "Lop", "Toan", "Ly", "Hoa", "Trung binh");
    for (int i = 0; i < so_luong; i++) {
        float diemTB = (sinhviens[i].diem_toan + sinhviens[i].diem_ly + sinhviens[i].diem_hoa) / 3;
        printf("%-5s\t%-30s\t%-10s\t%-5.2f\t%-5.2f\t%-5.2f\t%-10.2f\n",
               sinhviens[i].id, sinhviens[i].ten, sinhviens[i].lop,
               sinhviens[i].diem_toan, sinhviens[i].diem_ly, sinhviens[i].diem_hoa,
               diemTB);
    }
}




void sap_xep_sinhvien_theo_trung_binh(SinhVien sinhviens[], int so_luong, int giam) {
    for (int i = 0; i < so_luong - 1; i++) {
        for (int j = 0; j < so_luong - i - 1; j++) {
            float tb1 = (sinhviens[j].diem_toan + sinhviens[j].diem_ly + sinhviens[j].diem_hoa) / 3;
            float tb2 = (sinhviens[j + 1].diem_toan + sinhviens[j + 1].diem_ly + sinhviens[j + 1].diem_hoa) / 3;
            if ((giam && tb1 < tb2) || (!giam && tb1 > tb2)) {
                SinhVien temp = sinhviens[j];
                sinhviens[j] = sinhviens[j + 1];
                sinhviens[j + 1] = temp;
            }
        }
    }
}

void tim_kiem_sinhvien_theo_lop(SinhVien sinhviens[], int so_luong) {
    char lop_sinhvien[11];
    printf("Nhap lop can tim: ");
    scanf("%10s", lop_sinhvien);

    int tim_thay = 0;
    printf("Sinh vien trong lop %s:\n", lop_sinhvien);
    for (int i = 0; i < so_luong; i++) {
        if (strcmp(sinhviens[i].lop, lop_sinhvien) == 0) {
            hien_thi_sinhvien(&sinhviens[i]);
            tim_thay = 1;
        }
    }

    if (!tim_thay) {
        printf("Khong tim thay sinh vien trong lop.\n");
    }
}

void tim_kiem_sinhvien_theo_khoang_diem(SinhVien sinhviens[], int so_luong) {
    float diem_toi_thieu, diem_toi_da;
    printf("Nhap diem toi thieu: ");
    scanf("%f", &diem_toi_thieu);
    printf("Nhap diem toi da: ");
    scanf("%f", &diem_toi_da);

    int tim_thay = 0;
    printf("Sinh vien trong khoang diem %.2f - %.2f:\n", diem_toi_thieu, diem_toi_da);
    for (int i = 0; i < so_luong; i++) {
        float trung_binh = (sinhviens[i].diem_toan + sinhviens[i].diem_ly + sinhviens[i].diem_hoa) / 3;
        if (trung_binh >= diem_toi_thieu && trung_binh <= diem_toi_da) {
            hien_thi_sinhvien(&sinhviens[i]);
            tim_thay = 1;
        }
    }

    if (!tim_thay) {
        printf("Khong tim thay sinh vien trong khoang diem.\n");
    }
}

int main() {
    SinhVien sinhviens[100];
    int so_luong_sinhvien = 0;

    doc_du_lieu_tu_tep(sinhviens, &so_luong_sinhvien);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi tat ca sinh vien\n");
        printf("3. Sap xep sinh vien theo trung binh\n");
        printf("4. Tim kiem sinh vien theo lop\n");
        printf("5. Tim kiem sinh vien theo khoang diem\n");
        printf("6. Thoat\n");

        int lua_chon;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                them_sinhvien(sinhviens, &so_luong_sinhvien);
                break;
            case 2:
                hien_thi_tat_ca_sinhvien(sinhviens, so_luong_sinhvien);
                break;
            case 3: {
                int giam;
                printf("Sap xep giam dan? (1: Co, 0: Khong): ");
                scanf("%d", &giam);
                sap_xep_sinhvien_theo_trung_binh(sinhviens, so_luong_sinhvien, giam);
                hien_thi_tat_ca_sinhvien(sinhviens, so_luong_sinhvien);
                break;
            }
            case 4:
                tim_kiem_sinhvien_theo_lop(sinhviens, so_luong_sinhvien);
                break;
            case 5:
                tim_kiem_sinhvien_theo_khoang_diem(sinhviens, so_luong_sinhvien);
                break;
            case 6:
                printf("Ket thuc chuong trinh. Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long nhap so tu 1 den 6.\n");
                break;
        }
    }

    return 0;
}
