#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// them sinh vien, can thong tin gi?
// ten, tuoi, ma sv, diem tb-- su dung cau truc struct
// them sv xong chuong trinh se bao gi?-- them sv thanh cong
// so luong sinh vien toi da co the them? - 100sv
#define MAX_STUDENTS 100
struct sinhvien
{
    char name[50];
    char ma_sv[10];
    int age;
    double gpa;
};
// ham nay de them sinh vien moi vao danh sach
void addStudent(struct sinhvien sv[], int *count)
{

    if(*count > MAX_STUDENTS)
    {
        printf("danh sach sinh vien da day\n");
    }
    struct sinhvien newStudent;
    printf("nhap ma sinh vien: ");
    fgets(newStudent.ma_sv,sizeof(newStudent.ma_sv), stdin);
    newStudent.ma_sv[strcspn(newStudent.ma_sv, "\n")] = '\0';
    printf("nhap ten: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name,"\n")] = '\0';
    printf("nhap tuoi: ");
    scanf("%d", &newStudent.age);getchar();
    printf("nhap diem trung binh: ");
    scanf("%lf", &newStudent.gpa);getchar();
    printf("them sinh vien moi thanh cong\n");
    sv[*count] = newStudent;
    (*count)++;

}
// hien thi danh sach sinh vien
// can biet so luong sv co trong danh sach
// neu khong co sv trong danh sach, hien thi danh sach rong

void displayStudent(struct sinhvien sv[], int count)
{
    if(count == 0)
    {
        printf("danh sach sinh vien rong\n");
        return;
    }
    printf("so luong sinh vien trong danh sach: %d\n", count);
    printf("\t\tDANH SACH SINH VIEN\n");
    printf("---------------------------------------------------------------\n");
    printf("MA SV\tTen\t\tTuoi\tdiem trung binh\n");
    printf("---------------------------------------------------------------\n");
    // dung vong for 
    for(int i = 0; i < count; i++)
    {
        printf("%s\t%s\t%d\t%.2lf\n", sv[i].ma_sv, sv[i].name, sv[i].age, sv[i].gpa);
        printf("---------------------------------------------------------------\n");
    }
}
// tim sinh vien trong danh sach bang ma sv
// nhap ma sv sau do hien thi ra thong tin sv do
// so sánh 2 mã có giống nhau, nếu giống thì?
void findStudentbyId(struct sinhvien sv[], int count)
{
    char searchID[10];
    printf("nhap ma sv can tim: ");
    scanf("%s", &searchID);getchar();
    int found = 0;
    for(int i = 0; i < count; i++)
    {
        if(strcmp(searchID, sv[i].ma_sv) == 0)
        {
            printf("---------------------------------------------------------------\n");
            printf("MA SV\tTen\t\tTuoi\tdiem trung binh\n");
            printf("---------------------------------------------------------------\n");
            printf("%s\t%s\t%d\t%.2lf\n", sv[i].ma_sv, sv[i].name, sv[i].age, sv[i].gpa);
            printf("---------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    if(!found)
    {
        printf("khong tim thay sinh co ma sv %s\n", searchID);
    }
}
//xoa sinh vien
//nhap ma sv, hien thi thong tin sv do, hoi co dung sv do khong, neu dung thi xoa, khong thi tro lai buoc nhap ma sv
void removeStudent(struct sinhvien sv[], int *count)
{
    char removeID[10];
    printf("nhap ma sv can xoa: ");
    scanf("%s", &removeID);
    int found = 0;
    int removeIndex;
    for(int i = 0; i < *count; i++)
    {
        if(strcmp(removeID,sv[i].ma_sv) == 0)
        {
            found = 1;
            removeIndex = i;
            break;
        }
    }
    if(found)
    {
        for(int i = removeIndex; i < (*count) - 1; i++)
        {
            sv[i] = sv[i+1];
        }
        (*count)--;
        printf("xoa sinh vien thanh cong\n");
    }
    else
    {
        printf("khong tim thay sinh vien co ma %s\n", removeID);
    }
}
int main()
{
    struct sinhvien sv[MAX_STUDENTS];
    int choice;
    int count = 0;
    do
    {
        printf("==================================\n");
        printf("DANH SACH SINH VIEN\n");
        printf("==================================\n");
        printf("1. them sinh vien moi\n");
        printf("2. hien thi danh sach sinh vien\n");
        printf("3. tim sinh vien trong danh sach\n");
        printf("4. xoa sinh vien trong danh sach\n");
        printf("5. thoat chuong trinh\n");
        printf("chon cac lua chon(1-5): ");
        scanf("%d", &choice);getchar();
        switch (choice)
        {
        case 1:
            addStudent(sv, &count);
            break;
        case 2:
            displayStudent(sv, count);
            break;
        case 3:
            findStudentbyId(sv, count);
            break;
        case 4:
            removeStudent(sv, &count);
            break;
        case 5:
            printf("chuong trinh ket thuc\n");
            break;
        default:
            printf("lua chon khong hop le, vui long chon lai\n");
            break;
        }
    }
    while(choice != 5);
    return 0;
}
