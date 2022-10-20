#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    
    // Code for employee number not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr-EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Code for employee name found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr!=NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr-EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Code for mployee for phone found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr!=NULL)
        printf("Employee phone number is in record %ld.\n", matchPtr-EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record.\n");
    
    // Code for employee phone not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-356-9001");
    if(matchPtr!=NULL)
        printf("Employee phone number is in record %ld.\n", matchPtr-EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record.\n");
    
    // Code for employee salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr!=NULL)
        printf("Employee salary is in record %ld.\n", matchPtr-EmployeeTable);
    else    
        printf("Employee salary is NOT found in the record.\n");
    
    // Code for employee salary not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 16.50);
    if(matchPtr!=NULL)
        printf("Employee salary is in record %ld.\n", matchPtr-EmployeeTable);
    else
        printf("Employee salary is NOT found in the record.\n");

    return EXIT_SUCCESS;
}