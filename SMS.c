/*	Name: Student Management System (SMS)
	Copyright: root@kunu247
	Author: Mr. Kunal Mendarkar
	Date: 05-03-22 15.39
	Description: Student Management System (SMS) is a system to
				 record, update, manage students basic details in C programming */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
// function declaration
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
// creating structure for student variable
struct student {
    char name[20];
    char mobile[10];
    int roll;
    char course[20];
    char branch[20];
};
// -------------------------------------------------
// main function
int main() {
    gotoxy(15,3);
    printf("<--:Student Record Management System:-->");
    gotoxy(15, 5);
    system("type logo.txt");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
// -------------------------------------------------
// menu function
void menu() {
    int choice;
    system("cls && color CF");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("[ 1 ] : Add Record");
    gotoxy(10,8);
    printf("[ 2 ] : View Record");
    gotoxy(10,9);
    printf("[ 3 ] : Search Record");
    gotoxy(10,10);
    printf("[ 4 ] : Modify Record");
    gotoxy(10,11);
    printf("[ 5 ] : Delete");
    gotoxy(10,12);
    printf("[ 6 ] : Exit");
    gotoxy(10,13);
    printf("[ 7 ] : About");
    gotoxy(10,16);
    printf(" | Enter your choice = ");
    scanf("%d", &choice);
// -------------------------------------------------
    switch(choice) {
    // when 1 pressed
    case 1:
        add();
        break;
    // when 2 pressed
    case 2:
        view();
        break;
    // when 3 pressed
    case 3:
        search();
        break;
    // when 4 pressed
    case 4:
        modify();
        break;
    // when 5 pressed
    case 5:
        deleterec();
        break;
    // when 6 pressed
    case 6:
        exit(1);
        break;
    // when 7 pressed
    case 7:
        system("cls && color 0E && type about.txt");
        break;
    // when invalid value entered
    default:
        gotoxy(10,17);
        printf("Error !!!   Invalid Choice.");
    }
// -------------------------------------------------
}

// add function
void add() {
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls && color 09");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("[+] Enter Name : ");
//        gets(std.name);///???
        gets(std.name);
        gotoxy(10,8);
        printf("[+] Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("[+] Enter Roll No : ");
        scanf("%d",&std.roll);
        fflush(stdin);
        gotoxy(10,10);
        printf("[+] Enter Course : ");
//        gets(std.course);///???
        gets(std.course);
        gotoxy(10,11);
        printf("[+] Enter Branch : ");
        gets(std.branch);
//        gotoxy(10,12);
//        printf("Enter Father's Name : ");
//        gets(std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("[ # ]  Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls ");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
// ----------------------------------------------------------------------------------------------------------
// View Function
void view() {
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls && color 1E");
    gotoxy(10,2);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,4);
    printf("| ----- | ---------------------- | ------------ | --------- | ------------ | ------------ |");
    gotoxy(10,5);
    printf("| Sr.No |    Name of Student     |   Mobile No  |  Roll No  |    Course    |   Branch     |");
    gotoxy(10,6);
    printf("| ----- | ---------------------- | ------------ | --------- | ------------ | ------------ |");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=7;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("| %-5d | %-22s | %-12s | %-9d | %-12s | %-12s |",i,std.name,std.mobile,std.roll,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}

// -------------------------------------------------
// search function
void search() {
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls && color 0E");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("| Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,8);
            printf("| Name : %s",std.name);
            gotoxy(10,9);
            printf("| Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("| Roll No : %d",std.roll);
            gotoxy(10,11);
            printf("| Course : %s",std.course);
            gotoxy(10,12);
            printf("| Branch : %s",std.branch);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify() {
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls && color 0A");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,7);
            printf("[~] Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("[~] Enter mobile number : ");
            gets(std.mobile);
            gotoxy(10,9);
            printf("[~] Enter roll no : ");
            scanf("%d",&std.roll);
            gotoxy(10,10);
            printf("[~] Enter Course : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10,11);
            printf("[~] Enter Branch : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp , sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}

// delete record function
void deleterec() {
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls && color 0c");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf(" | Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
