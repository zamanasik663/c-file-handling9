// searching records in a file
#include <stdio.h>
#include<stdlib.h>
// structure to hold the record
struct record
{
    char name[20];
    int rollno;
    float marks;
};

// driver code
int main()
{

    struct record r;
    FILE *fp;
    int roll, found = 0;
    // open the file in read mode
    fp = fopen("G:\\file-handling\\file-handling7\\student.txt", "rb");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    // take the roll number to be searched as input
    printf("Enter the roll number to be searched: ");
    scanf("%d", &roll);

    while (fread(&r, sizeof(r), 1, fp) > 0 && found == 0)
    {
        // check if the roll number matches
        if (r.rollno == roll)
        {
            printf("Record found:\n");
            printf("Roll No: %d\n", r.rollno);
            printf("Name: %s\n", r.name);
            printf("CGPA: %.2f\n", r.marks);
            found = 1;
        
        }
    }

    // if the record is not found
    if (found == 0)
    {
        printf("Record not found\n");
    }
    // close the file
    fclose(fp);
    // return success


    return 0;
}