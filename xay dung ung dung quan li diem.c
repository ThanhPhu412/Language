#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "sinhvien.txt"

typedef struct {
    char id[6];
    char name[31];
    char class_name[11];
    float math_score;
    float physics_score;
    float chemistry_score;
} Student;

float calculate_average_score(Student student) {
    return (student.math_score + student.physics_score + student.chemistry_score) / 3;
}

void write_student_to_file(Student student) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi du lieu.\n");
        exit(1);
    }

    fprintf(file, "%s,%s,%s,%.2f,%.2f,%.2f\n", student.id, student.name, student.class_name,
            student.math_score, student.physics_score, student.chemistry_score);

    fclose(file);
}

void read_students_from_file(Student students[], int *num_students) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        *num_students = 0;
        return;
    }

    *num_students = 0;
    while (fscanf(file, "%5s,%30[^,],%10[^,],%f,%f,%f\n",
                  students[*num_students].id, students[*num_students].name, students[*num_students].class_name,
                  &students[*num_students].math_score, &students[*num_students].physics_score, &students[*num_students].chemistry_score) == 6) {
        (*num_students)++;
    }

    fclose(file);
}

void display_student(const Student *student) {
    printf("MaSV: %-2s | Ho va ten: %-5s | Lop: %-2s | Diem Toan: %-5.2f | Diem Ly: %-5.2f | Diem Hoa: %-5.2f | DiemTB: %-5.2f\n",
           student->id, student->name, student->class_name,
           student->math_score, student->physics_score, student->chemistry_score,
           calculate_average_score(*student));
}

void display_all_students(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        display_student(&students[i]);
    }
}

void add_student(Student students[], int *num_students) {
    if (*num_students == 100) {
        printf("Danh sach sinh vien da day. Khong the them moi.\n");
        return;
    }

    printf("Nhap ma sinh vien: ");
    scanf("%6s", students[*num_students].id);
    while (getchar() != '\n');  // Clear input buffer

// Kiểm tra mã sinh viên
    if (strlen(students[*num_students].id) != 5) {
        printf("Ma sinh vien khong hop le. Chon muc vua chon va vui long nhap lai, gioi han ma gom 5 ky tu.\n");
        return;
    }


    // Nhập các thông tin khác của sinh viên
    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", students[*num_students].name);
    while (getchar() != '\n');  // Clear input buffer

    // Chuẩn hóa tên
    for (int i = 0; i < strlen(students[*num_students].name); i++) {
        if (i == 0 || (i > 0 && students[*num_students].name[i - 1] == ' ')) {
            students[*num_students].name[i] = toupper(students[*num_students].name[i]);
        } else {
            students[*num_students].name[i] = tolower(students[*num_students].name[i]);
        }
    }

    printf("Nhap lop cua sinh vien: ");
    scanf("%10s", students[*num_students].class_name);
    while (getchar() != '\n');  // Clear input buffer

    printf("\nNhap diem toan: ");
    scanf("%f", &students[*num_students].math_score);
    while (getchar() != '\n');  // Clear input buffer
    if (students[*num_students].math_score < 0 || students[*num_students].math_score > 10) {
        printf("Diem toan khong hop le.Chon muc vua chon va vui long nhap lai, nhap diem tu 0 den 10.\n");
        return;
    }

    printf("\nNhap diem ly: ");
    scanf("%f", &students[*num_students].physics_score);
    while (getchar() != '\n');  // Clear input buffer
    if (students[*num_students].physics_score < 0 || students[*num_students].physics_score > 10) {
        printf("Diem ly khong hop le,Chon muc vua chon va vui long nhap lai diem tu 0 den 10.\n");
        return;
    }

    printf("\nNhap diem hoa: ");
    scanf("%f", &students[*num_students].chemistry_score);
    while (getchar() != '\n');  // Clear input buffer
    if (students[*num_students].chemistry_score < 0 || students[*num_students].chemistry_score > 10) {
        printf("Diem hoa khong hop le. Chon muc vua chon va vui long nhap lai diem tu 0 den 10.\n");
        return;
    }

    // Ghi dữ liệu mới vào tệp tin
    write_student_to_file(students[*num_students]);

    (*num_students)++;
    printf("Them sinh vien thanh cong.\n");
}


void write_students_to_file(Student students[], int num_students) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi du lieu.\n");
        exit(1);
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%s,%s,%.2f,%.2f,%.2f\n", students[i].id, students[i].name, students[i].class_name,
                students[i].math_score, students[i].physics_score, students[i].chemistry_score);
    }

    fclose(file);
}

void update_student(Student students[], int num_students) {
    char student_id[6];
    printf("Nhap ma sinh vien can cap nhat: ");
    scanf("%5s", student_id);

    int index = -1;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, student_id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sinh vien co ma %s.\n", student_id);
        return;
    }

    printf("Nhap ten moi: ");
    scanf(" %[^\n]", students[index].name);
    // Chuẩn hóa tên
    for (int i = 0; i < strlen(students[index].name); i++) {
        if (i == 0 || (i > 0 && students[index].name[i - 1] == ' ')) {
            students[index].name[i] = toupper(students[index].name[i]);
        } else {
            students[index].name[i] = tolower(students[index].name[i]);
        }
    }

    printf("Nhap lop moi: ");
    scanf("%10s", students[index].class_name);

    printf("Nhap diem toan moi: ");
    scanf("%f", &students[index].math_score);
    if (students[index].math_score < 0 || students[index].math_score > 10) {
        printf("Diem toan khong hop le. Chon muc vua chon va vui long nhap lai diem tu 0 den 10.\n");
        return;
    }

    printf("Nhap diem ly moi: ");
    scanf("%f", &students[index].physics_score);
    if (students[index].physics_score < 0 || students[index].physics_score > 10) {
        printf("Diem ly khong hop le. Chon muc vua chon va vui long nhap lai diem tu 0 den 10.\n");
        return;
    }

    printf("Nhap diem hoa moi: ");
    scanf("%f", &students[index].chemistry_score);
    if (students[index].chemistry_score < 0 || students[index].chemistry_score > 10) {
        printf("Diem hoa khong hop le. Chon muc vua chon va vui long nhap lai diem tu 0 den 10.\n");
        return;
    }

    // Ghi lại toàn bộ danh sách sinh viên vào tệp tin
    write_students_to_file(students, num_students);

    printf("Cap nhat sinh vien thanh cong.\n");
}

void delete_student(Student students[], int *num_students) {
    char student_id[6];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%5s", student_id);

    int index = -1;
    for (int i = 0; i < *num_students; i++) {
        if (strcmp(students[i].id, student_id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sinh vien co ma %s.\n", student_id);
        return;
    }

    // Xóa sinh viên bằng cách dịch chuyển phần còn lại của danh sách
    for (int i = index; i < *num_students - 1; i++) {
        students[i] = students[i + 1];
    }

    (*num_students)--;
    printf("Xoa sinh vien thanh cong.\n");

    // Ghi lại danh sách sinh viên vào tệp tin
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi du lieu.\n");
        exit(1);
    }

    for (int i = 0; i < *num_students; i++) {
        fprintf(file, "%s,%s,%s,%.2f,%.2f,%.2f\n", students[i].id, students[i].name, students[i].class_name,
                students[i].math_score, students[i].physics_score, students[i].chemistry_score);
    }

    fclose(file);
}


void sort_students_by_average_score(Student students[], int num_students, int descending) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            float avg1 = calculate_average_score(students[j]);
            float avg2 = calculate_average_score(students[j + 1]);

            if ((descending && avg1 < avg2) || (!descending && avg1 > avg2)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void search_students_by_class(Student students[], int num_students) {
    char search_class[11];
    printf("Nhap lop can tim: ");
    scanf("%10s", search_class);

    int found = 0;
    printf("Sinh vien trong lop %s:\n", search_class);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].class_name, search_class) == 0) {
            display_student(&students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien trong lop.\n");
    }
}

void search_students_by_score_range(Student students[], int num_students) {
    float min_score, max_score;
    printf("Nhap diem toi thieu: ");
    scanf("%f", &min_score);
    printf("Nhap diem toi da: ");
    scanf("%f", &max_score);

    int found = 0;
    printf("Sinh vien trong khoang diem %.2f - %.2f:\n", min_score, max_score);
    for (int i = 0; i < num_students; i++) {
        float avg_score = calculate_average_score(students[i]);
        if (avg_score >= min_score && avg_score <= max_score) {
            display_student(&students[i]);
            found = 1;// đánh dấu tìm thấy 1 giá trị sinh viên
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien trong khoang diem.\n");
    }
}

int main() {
    Student students[100];
    int num_students = 0;

    read_students_from_file(students, &num_students);

    while (1) {
        printf("\n*************---MENU---*************:\n");
        printf("1. Them sinh vien\n");
        printf("2. Cap nhat sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Hien thi tat ca sinh vien\n");
        printf("5. Sap xep sinh vien theo diem trung binh\n");
        printf("6. Tim kiem sinh vien theo lop\n");
        printf("7. Tim kiem sinh vien theo khoang diem(min-max)\n");
        printf("8. Thoat\n");

        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                update_student(students, num_students);
                break;
            case 3:
                delete_student(students, &num_students);
                break;
            case 4:
                display_all_students(students, num_students);
                break;
            case 5: {
                int descending;
                printf("Chon kieu sap xep? (1: giam dan, 0: tang dan): ");
                scanf("%d", &descending);
                sort_students_by_average_score(students, num_students, descending);
                display_all_students(students, num_students);
                break;
            }
            case 6:
                search_students_by_class(students, num_students);
                break;
            case 7:
                search_students_by_score_range(students, num_students);
                break;
            case 8:
                printf("Ket thuc chuong trinh. Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long nhap so tu 1 den 8.\n");
                break;
        }
    }

    return 0;
}
