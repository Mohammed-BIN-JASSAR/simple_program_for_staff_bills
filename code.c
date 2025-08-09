
                      /* This program will store and caculate the item,bill prices , and will add different staffs for different bills.
                      In adiition, it will concentrate on adding prices abd printing the results in the standard output(monitor) and of 
                                   files.This simple program contains simple functions and is runnung using C++ Conpiler*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 40
#define SIZE_1 80
#define SIZE_2 10

int  items_number, bills_number, staff_number = 0; //the actual sizes of items, bills and staffs

//function prototypes :
int search_by_id(int ids[], int size, int id);
int bill_total_price(int bill_ids[], int bill_items_numbers[][SIZE_2], int it_ids[], int cost_of_item[], int bill_id);

void main_menu(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void items_information(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void bills_system(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void bills_query(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void staff_information(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void backup_system(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);

void sort_staff_by_id(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);
void sort_staff_by_salary(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);

void printing_item(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int item_id);
void printing_bill(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int bill_id);
void printing_staff(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[], int staff_id);

void retrieve_items(int it_ids[], char it_names[][STR_LEN], int cost_of_item[]);
void retrieve_bills(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[]);
void retrieve_staffs(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);

void backup_items(int it_ids[], char it_names[][STR_LEN], int cost_of_item[]);
void backup_bills(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[]);
void backup_staff(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[]);


int main()
{
	int  choice, k;
	//declare the items arrays
	int  it_ids[SIZE_1];
	char it_names[SIZE_1][STR_LEN];
	int  cost_of_item[SIZE_1];
	//declare the bills arrays
	int bill_ids[SIZE_1];
	int bill_items_numbers[SIZE_1][SIZE_2];
	int bill_staff_number[SIZE_1];
	//declare the staff arrays
	int  staff_ids[SIZE_1];
	char staff_names[SIZE_1][STR_LEN];
	int  staff_salaries[SIZE_1];

	retrieve_items(it_ids, it_names, cost_of_item);
	//displaying the data that has been read
	if (items_number == 0)
	{
		printf("**************************************************************************\n");
		printf("  Error !! The file is empty ... \n");
                printf("**************************************************************************\n");
	}
	else
	{
		printf("**************************************************************************\n");
		printf("  Items Information :\n");
		for (k = 0; k < items_number; k++)
		{
			printing_item(it_ids, it_names, cost_of_item, it_ids[k]);
		}
		printf("**************************************************************************\n");
	}

	retrieve_bills(bill_ids, bill_items_numbers, bill_staff_number);
	//displaying the data that has been read
	if (bills_number == 0)
	{
		printf("  Error !! The file is empty ...\n");
                printf("**************************************************************************\n");
	}
	else
	{
		printf("  Bills Information :\n");
		for (k = 0; k < bills_number; k++)
		{
			printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[k]);
		}
		printf("**************************************************************************\n");
	}

	retrieve_staffs(staff_ids, staff_names, staff_salaries);
        sort_staff_by_id(staff_ids, staff_names, staff_salaries);
	//displaying the data that has been read
	if (staff_number == 0)
	{
		printf("  Error !! The File is empty ...\n");
	}
	else
	{
		printf("  Staff Information :\n");
		for (k = 0; k < staff_number; k++)
		{
			printing_staff(staff_ids, staff_names, staff_salaries, staff_ids[k]);
		}
	}
        
	main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
        system("pause");
        return 0;
}

void main_menu(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
        int choice, k;
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Choose from the main menu :\n\n");
		printf("  1-Item information \n  2-Bills system \n  3-Bills query \n  4-Staff information \n  5-Backup system \n  6-Exit\n\n");
		printf("**************************************************************************\n");	scanf("%d", &choice);
		switch (choice)
		{
		case 1:   items_information(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
			break;

		case 2:   bills_system(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
			break;

		case 3:   bills_query(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
			break;

		case 4:   staff_information(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
			break;

		case 5:   backup_system(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries);
			break;

		case 6:   printf("  Program was ended ... ");
			exit(1);

		default:   printf("  Error !! Choose from the menu ...\n");
		}

	} while (choice != 6);
}

//items information options
void items_information(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int choice, add1, k, x, index;
	char strtemp[STR_LEN];
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Item Information :\n\n");
		printf("  1-Add new item \n  2-Modify item \n  3-Delete item \n  4-Back \n  5-Exit\n\n");
		printf("**************************************************************************\n");    scanf("%d", &choice);
		switch (choice)
		{
		case 1:	//adding item
                        printf("  Enter the item's ID :  ");
			scanf("  %d", &add1);
                        //if item id does not already exist continue adding item
                        if (search_by_id(it_ids, items_number, add1) == -1)
                        {
                                it_ids[items_number] = add1;
                                printf("  Enter the item's name :  ");
                                scanf(" %s", &strtemp);
                                for (k = 0; k < strlen(strtemp); k++)
                                {
                                        strtemp[k] = toupper(strtemp[k]);
                                }
                                strcpy(it_names[items_number], strtemp);
                                printf("  Enter the item's cost :  ");
                                scanf("  %d", &add1);
                                cost_of_item[items_number] = add1;
                                items_number++;
                                printf("  Item was added :)");
                        }
                        //otherwise quit
                        else
                        {
                                printf("  Item ID already exists :(");
                        }
                        printf("\n\n  Enter any number to continue ... ");
                        scanf("  %d", &x);
			break;

		case 2: //modifying item
			printf("  Enter item's ID to modify :  ");
			scanf("  %d", &add1);
                        index = search_by_id(it_ids, items_number, add1);
                        //if item id does not exist quit
			if (index == -1)
			{
				printf("  Error !! Item's ID is wrong ...\n");
			}
                        //otherwise continue modifying item
			else
			{
				printf("  %d %s %d\n", it_ids[index], it_names[index], cost_of_item[index]);
				printf("  Enter new item's name :  ");
				scanf("  %s", &strtemp);
				for (k = 0; k < strlen(strtemp); k++)
				{
					strtemp[k] = toupper(strtemp[k]);
				}
				strcpy(it_names[index], strtemp);
				printf("  Enter new item's cost:  ");
				scanf("  %d", &add1);
				cost_of_item[index] = add1;
				printf("  Item was modified :) \n");
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 3:   //deleting item
			printf("  Enter item's ID to delete:  ");
			scanf("  %d", &add1);
			index = search_by_id(it_ids, items_number, add1);
                        //if item id does not exist quit
			if (index == -1)
			{
				printf("  Error !! Item's ID is wrong ...\n");
			}
                        //otherwise continue deleting item
			else
			{
				printf("  %d %s %d\n", it_ids[index], it_names[index], cost_of_item[index]);
				printf("  Are you sure? ( 1 = No, 2 = Yes )  ");
				scanf("  %d", &add1);
				if (add1 == 2)//in case answer is YES
				{
                                        //deleting item by shifting up other items
					for (k = index; k < items_number; k++)
					{
                                                it_ids[k] = it_ids[k+1];
						strcpy(it_names[k], it_names[k + 1]);
						cost_of_item[k] = cost_of_item[k + 1];
					}
					items_number--;
					printf("  Item was deleted :)\n");;
				}
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 4:  main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries); //back by calling main menu function
			break;

		case 5:   printf("  Program was ended ...\n");
			exit(1);

		default:   printf("  Error !! Choose from the menu ...\n");
		}

	} while (choice != 5);
}


//bills system options
void bills_system(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int choice, add1, x, k, j, index;
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Bills System :\n\n");
		printf("  1-Add new bill\n  2-Modify bill\n  3-Delete bill\n  4-Back\n  5-Exit\n\n");
		printf("**************************************************************************\n");    scanf("%d", &choice);
		switch (choice)
		{
		case 1: //adding bill
                        printf("  Enter the bill's ID :  ");
                        scanf("  %d", &add1);
                        //if bill id does not already exist continue adding bill
                        if (search_by_id(bill_ids, bills_number, add1) == -1)
                        {
                            bill_ids[bills_number] = add1;
                            k = 0;
                            do
                            {
                                    printf("  Enter item's number (-1 when finished) :  ");
                                    scanf("  %d", &add1);
                                    if (add1 != -1)
                                    {
                                            if (search_by_id(it_ids, items_number, add1) == -1)
                                            {
                                                    printf("  Error !! Item's ID is wrong ... \n");
                                            }
                                            else
                                            {
                                                    bill_items_numbers[bills_number][k] = add1;
                                                    k++;
                                            }
                                    }
                            } while (add1 != -1);
                            if (k == 0)
                            {
                                    printf("  Error !! Bill can not be added (no items) ...\n");
                                    break;
                            }
                            for (j = k; j < SIZE_2; j++)
                            {
                                    bill_items_numbers[bills_number][j] = 0;
                            }
                            printf("  Enter staff's ID :  ");
                            scanf("  %d", &add1);
                            if (search_by_id(staff_ids, staff_number, add1) == -1)
                            {
                                    printf("  Error !! Staff's ID is wrong ...\n");
                            }
                            else
                            {
                                    bill_staff_number[bills_number] = add1;
                                    bills_number++;
                                    printf("  Bill was added :) \n");

                            }
                        }
                        //otherwise quit
                        else
                        {
                                printf("  Bill ID already exists :(");
                        }
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 2: //modifying bill
			printf("  Enter bill's ID to modify :  ");
			scanf("  %d", &add1);
                        index = search_by_id(bill_ids, bills_number, add1);
                        //if bill id does not exist quit
			if (index == -1)
			{
				printf(" Error !! Bill's ID is wrong ...\n");
			}
                        //otherwise continue modifying bill
			else
			{
				printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[index]);
				k = 0;
				do
				{
					printf("  Enter new item's number (-1 when finished) :  ");
					scanf("  %d", &add1);
					if (add1 != -1)
					{
						if (search_by_id(it_ids, items_number, add1) == -1)
						{
							printf("  Error !! Item's ID is wrong ...\n");
						}
						else
						{
							bill_items_numbers[index][k] = add1;
							k++;
						}
					}
				} while (add1 != -1);
				if (k == 0)
				{
					printf("  Error !! Bill can not be modified (no items) ... \n");
					break;
				}
				for (j = k; j < SIZE_2; j++)
				{
					bill_items_numbers[index][j] = 0;
				}
				printf("  Enter new staff's ID :  ");
				scanf("  %d", &add1);
				if (search_by_id(staff_ids, staff_number, add1) == -1)
				{
					printf("  Error !! Staff's ID is wrong ... \n");
				}
				else
				{
					bill_staff_number[index] = add1;
					printf("  Bill was modified :) \n");
				}
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 3: //deleting bill
			printf("  Enter bill's ID to delete :  ");
			scanf("  %d", &add1);
                        index = search_by_id(bill_ids, bills_number, add1);
                        //if bill id does not exist quit
			if (index == -1)
			{
				printf("  Error !! Bill's ID is wrong ... \n");
			}
                        //otherwise continue deleting bill
			else
			{
				printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[index]);
				printf("  Are you sure? (1 = No, 2 = Yes)  ");
				scanf("  %d", &add1);
				if (add1 == 2)//in case answer is YES
				{
                                        //deleting bill by shifting up other bills
					for (k = index; k < bills_number; k++)
					{
                                            bill_ids[k] = bill_ids[k + 1];
						for (j = 0; j < SIZE_2; j++)
						{
							bill_items_numbers[k][j] = bill_items_numbers[k + 1][j];
						}
						bill_staff_number[k] = bill_staff_number[k + 1];
					}
					bills_number--;
					printf("  Bill was deleted :) \n");
				}
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 4:   main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries); //back by calling main menu function
			break;

		case 5:   printf("  Program was ended ...\n");
			exit(1);

		default:   printf("  Error!! Choose from the menu ...\n");
		}

	} while (choice != 5);
}

//bills query options
void bills_query(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int choice, add1, x, k, index;
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Bills Query :\n\n");
		printf("  1-Print bill information depends on bill number\n  2-Print all bills information [bill number and total price]\n");
		printf("  3-Print all items information\n  4-Back\n  5-Exit\n\n");
		printf("**************************************************************************\n");    scanf("%d", &choice);
		switch (choice)
		{
		case 1:   //printing bill information by id
			printf("  Enter bill`s ID to print :  ");
			scanf("  %d", &add1);
                        index = search_by_id(bill_ids, bills_number, add1);
                        //if bill id does not exist quit
			if (index == -1)
			{
				printf("  Error !! Bill's ID is wrong ... \n");
			}
                        //otherwise print bill information for the given id
			else
			{
				printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[index]);
			}
			break;

		case 2: //print bill information by id and total price
			for (k = 0; k < bills_number; k++)
			{
				add1 = bill_total_price(bill_ids, bill_items_numbers, it_ids, cost_of_item, bill_ids[k]);
				printf("  Bill number is %d - Total price is %d\n", bill_ids[k], add1);
			}
			break;

		case 3: //print all items information
			printf("  Items Information :\n");
			for (k = 0; k < items_number; k++)
			{
				printing_item(it_ids, it_names, cost_of_item, it_ids[k]);
			}
			break;

		case 4:  main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries); //back by calling main menu function
			break;

		case 5:   printf("  Program was ended ...\n");
			exit(1);

		default:   printf("  Error !! Choose from the menu ...\n");
		}

	} while (choice != 5);
}

//staff information options
void staff_information(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int choice, add1, x, k, j, index;
	char n[STR_LEN], f[20], l[20]; //f[20] = first name  //l[20] = last name  //n[STR_LEN] = name 
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Staff Information :\n\n");
		printf("  1-Add staff information \n  2-Modify staff information \n  3-Delete staff information \n");
		printf("  4-Print all staffs information sorted by their salary \n  5-Print all bills issued by a specific staff \n  6-Back\n  7-Exit\n\n");
		printf("**************************************************************************\n");    scanf("%d", &choice);
		switch (choice)
		{
		case 1: //adding staff
                        printf("  Enter the staff's ID :  ");
			scanf("  %d", &add1);
                        //if staff id does not already exist continue adding staff
                        if (search_by_id(staff_ids, staff_number, add1) == -1)
                        {
                                staff_ids[staff_number] = add1;
                                printf("  Enter staff name (first last) :  ");
                                scanf("  %s %s", &f, &l);
                                strcpy(n, f);
                                strcat(n, " ");
                                strcat(n, l);
                                for (k = 0; k < strlen(n); k++)
                                {
                                        n[k] = toupper(n[k]);
                                }
                                strcpy(staff_names[staff_number], n);
                                printf("  Enter staff salary :  ");
                                scanf("  %d", &add1);
                                staff_salaries[staff_number] = add1;
                                staff_number++;
                                printf("  Staff information was added :) \n");
                        }
                        //otherwise quit
                        else
                        {
                                printf("  Staff ID already exists :(");
                        }
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 2:   //modifying staff
			printf("  Enter staff ID to modify:  ");
			scanf("  %d", &add1);
                        index = search_by_id(staff_ids, staff_number, add1);
                        //if item id does not exist quit
			if (index == -1)
			{
				printf("  Error !! Staff's ID is wrong ... \n");
			}
                        //otherwise continue modifying staff
			else
			{
				printf("%d %s %d\n", staff_ids[index], staff_names[index], staff_salaries[index]);
				printf("  Enter new staff name (first last) :  ");
				scanf("  %s %s", &f, &l);
				strcpy(n, f);
				strcat(n, " ");
				strcat(n, l);
				for (k = 0; k < strlen(n); k++)
				{
					n[k] = toupper(n[k]);
				}
				strcpy(staff_names[index], n);
				printf("  Enter new staff salary:  ");
				scanf("  %d", &add1);
				staff_salaries[index] = add1;
				printf("  Staff information was modified :) \n");
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 3:   //deleting staff
			printf("  Enter staff ID to delete :  ");
			scanf("  %d", &add1);
                        index = search_by_id(staff_ids, staff_number, add1);
                        //if staff id does not exist quit
			if (index == -1)
			{
				printf("  Error !! ID is wrong ... \n");
			}
                        //otherwise continue deleting staff
			else
			{
				printf("  %d %s %d\n", staff_ids[index], staff_names[index], staff_salaries[index]);
				printf("  Are you sure? (1 = No, 2 = Yes)  ");
				scanf("  %d", &add1);
				if (add1 == 2)
				{
					for (k = index; k < staff_number; k++)
					{
                                                staff_ids[k] = staff_ids[k+1];
						strcpy(staff_names[k], staff_names[k + 1]);
						staff_salaries[k] = staff_salaries[k + 1];
					}
					staff_number--;
					printf("  Staff information was deleted ... \n");
				}
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 4: //viewing staff information sorted according to their salaries
			sort_staff_by_salary(staff_ids, staff_names, staff_salaries);
                        //displaying the list after sorting
                        for (k = 0; k < staff_number; k++)
                        {
                                printf("%d %s %d\n", staff_ids[k], staff_names[k], staff_salaries[k]);
                        }
                        printf("\n\n  Enter any number to continue ... ");
                        scanf("  %d", &x);
			break;

		case 5:   //viewing bills information that added by given staff id
			printf("  Enter staff ID to print his bills :  ");
			scanf("  %d", &add1);
			index = search_by_id(staff_ids, staff_number, add1);
                        //if staff id does not exist quit
			if (index == -1)
			{
				printf("Error !! Staff's ID is wrong ... \n");
			}
			else
			{
				for (k = 0; k < bills_number; k++)
				{
					if (bill_staff_number[k] == add1)
					{
						printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[k]);
					}
				}
			}
			break;

		case 6:   main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries); //back by calling main menu function
			break;

		case 7:   printf("  Program was ended ...\n");
			exit(1);

		default:  printf("   Error !! Choose from the menu ...\n");
		}

	} while (choice != 7);
}

//backup system options
void backup_system(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int choice, x, k;
	//displaying the available operations can be done
	do
	{
		printf("**************************************************************************\n");
		printf(" Backup System :\n\n");
		printf("  1-Backup all items information to file \n  2-Backup all bills information to file \n");
		printf("  3-Backup all staffs information to file \n  4-Retrieve bill information from the backup file\n");
		printf("  5-Back \n  6-Exit\n\n");
		printf("**************************************************************************\n");	scanf("%d", &choice);
		switch (choice)
		{
		case 1:   backup_items(it_ids, it_names, cost_of_item);
			printf("  Items Back up was done ... \n");
			break;

		case 2:   backup_bills(bill_ids, bill_items_numbers, bill_staff_number);
			printf("  Bills Back up was done ...\n");
			break;

		case 3:   backup_staff(staff_ids, staff_names, staff_salaries);
			printf("  Staffs Back up was done ...\n");
			break;

		case 4:   retrieve_bills(bill_ids, bill_items_numbers, bill_staff_number);
			if (bills_number == 0)
			{
				printf("  The file is empty !! There is no data has been read ... \n");
			}
			else
			{
				printf("  Bills Information :\n");
				for (k = 0; k < bills_number; k++)
				{
					printing_bill(bill_ids, bill_items_numbers, bill_staff_number, bill_ids[k]);
				}
                                printf("  Bills Retrieve was done ...\n");
			}
			printf("\n\n  Enter any number to continue ... ");
			scanf("  %d", &x);
			break;

		case 5:   main_menu(it_ids, it_names, cost_of_item, bill_ids, bill_items_numbers, bill_staff_number, staff_ids, staff_names, staff_salaries); //back by calling main menu function
			break;

		case 6:   printf("  Program was ended ...\n");
			exit(1);

		default:  printf("  Error !! Choose from the menu ...\n");
		}

	} while (choice != 6);
}

//search the ids array for a given id
int search_by_id(int ids[], int size, int id)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(id == ids[i])
        {
            return i;
            }
    }
    return -1;
}

//compute the total price of given bill by its id
int bill_total_price(int bill_ids[], int bill_items_numbers[][SIZE_2], int it_ids[], int cost_of_item[], int bill_id){
	int total, i, j, k, temp;
	total = 0;
        //return index of the given bill id
        i = search_by_id(bill_ids, bills_number, bill_id);
	k = 1;
	temp = bill_items_numbers[i][0];
	while (temp != 0)//as long as the item number is not zero keep retrieving items
	{
                //return index of the given item id
                j = search_by_id(it_ids, items_number, temp);
		total = total + cost_of_item[j];
		temp = bill_items_numbers[i][k];
		k++;
	}
	return total;
}

//sorting the staff by ids from low to high
void sort_staff_by_id(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int temp1;
	char temp2[40];
	int k, j, minpos;

	for (k = 0; k < staff_number - 1; k++)
	{
		minpos = k; // initialize location of minimum value
		// go over the elements to find location of minimum value
		for (j = k + 1; j < staff_number; j++)
		{
			if (staff_ids[j] < staff_ids[minpos])
			{
				minpos = j;
			}
		}
		// bring minimum value which is at minpos at index k  
                temp1 = staff_ids[minpos];
		staff_ids[minpos] = staff_ids[k];
		staff_ids[k] = temp1;
                
		strcpy(temp2, staff_names[minpos]);
                strcpy(staff_names[minpos], staff_names[k]);
                strcpy(staff_names[k], temp2);
                
                temp1 = staff_salaries[minpos];
		staff_salaries[minpos] = staff_salaries[k];
		staff_salaries[k] = temp1;

	}
}

//sorting the staff by salaries (from high to low)
void sort_staff_by_salary(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	int temp1;
	char temp2[40];
	int k, j, maxpos;
	
	for (k = 0; k < staff_number - 1; k++)
	{
		maxpos = k; // initialize location of maximum value
		// go over the elements to find location of maximum value
		for (j = k + 1; j < staff_number; j++)
		{
			if (staff_salaries[j] > staff_salaries[maxpos])
			{
				maxpos = j;
			}
		}
		// bring maximum value which is at maxpos at index k
                temp1 = staff_ids[maxpos];
		staff_ids[maxpos] = staff_ids[k];
		staff_ids[k] = temp1;
                
		strcpy(temp2, staff_names[maxpos]);
                strcpy(staff_names[maxpos], staff_names[k]);
                strcpy(staff_names[k], temp2);
                
                temp1 = staff_salaries[maxpos];
		staff_salaries[maxpos] = staff_salaries[k];
		staff_salaries[k] = temp1;

	}
}

//print item information by item id
void printing_item(int it_ids[], char it_names[][STR_LEN], int cost_of_item[], int item_id)
{
        //return index of the given item id
        int i = search_by_id(it_ids, items_number, item_id);
        
	printf("  %d %s %d\n", it_ids[i], it_names[i], cost_of_item[i]);
}

//print bill information by bill id
void printing_bill(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[], int bill_id)
{
	int temp, i, k;
        //return index of the given bill id
        i = search_by_id(bill_ids, bills_number, bill_id);
        printf("  Bill ID: %d\n  Items:", bill_ids[i]);
        k = 1;
        //getting the first item in the bill
	temp = bill_items_numbers[i][0];
	while (temp != 0)//as long as the item number is not zero keep printing items
	{
		printf(" %d ", temp);
		temp = bill_items_numbers[i][k];
		k++;
	}
	printf("\n  Staff ID: %d\n", bill_staff_number[i]);
        printf("-----------------------------------------------------------\n");
}

//print staff information by staff id
void printing_staff(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[], int staff_id)
{
        //return index of the given staff id
        int i = search_by_id(staff_ids, staff_number, staff_id);
        
	printf("  %d %s %d\n", staff_ids[i], staff_names[i], staff_salaries[i]);
}

//save the items arrays to the file
void backup_items(int it_ids[], char it_names[][STR_LEN], int cost_of_item[]){
	FILE *outfile;
	int  k;
	outfile = fopen("items.txt", "w");
	if (outfile == NULL)
	{
		printf("  File does not exist ... \n");
	}
	else
	{
		for (k = 0; k < items_number; k++)
		{
			fprintf(outfile, "%d %s %d\r\n", it_ids[k], it_names[k], cost_of_item[k]);
		}
	}
	fclose(outfile);
}

//save the bills arrays to the file
void backup_bills(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[])
{
	FILE *outfile;
	int  k, j, it[10];
	outfile = fopen("bills.txt", "w");
	if (outfile == NULL)
	{
		printf("  File does not exist ... \n");
	}
	else
	{
		for (k = 0; k < bills_number; k++)
		{
                        for (j = 0; j < SIZE_2; j++)
                        {
                                it[j] = bill_items_numbers[k][j];
                        }
			fprintf(outfile, "%d %d %d %d %d %d %d %d %d %d %d %d\r\n", bill_ids[k], it[0], it[1], it[2], it[3], it[4], it[5], it[6], it[7], it[8], it[9], bill_staff_number[k]);
		}
	}
	fclose(outfile);
}
//save the staff arrays to the file
void backup_staff(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	FILE *outfile;
	int  k;
	outfile = fopen("staff.txt", "w");
	if (outfile == NULL)
	{
		printf("  File does not exist ...\n");
	}
	else
	{
		for (k = 0; k < staff_number; k++)
		{
			fprintf(outfile, "%d %s %d\r\n", staff_ids[k], staff_names[k], staff_salaries[k]);
		}
	}
	fclose(outfile);
}

//retrieve the items information from items.txt file
void retrieve_items(int it_ids[], char it_names[][STR_LEN], int cost_of_item[])
{
	FILE *infile;
	int  i;
	i = 0;
	//reading the items info from the file "items.txt"
	infile = fopen("items.txt", "r");
	if (infile == NULL)
	{
		printf("  File does not exist ...\n");
	}
	else
	{
		//reading line by line till the end of the file and storing the data to the arrays
		while (fscanf(infile, "%d %s %d", &it_ids[i], &it_names[i], &cost_of_item[i]) != EOF)
		{
			i++;
		}
	}
	fclose(infile);
	items_number = i;
}

//retrieve the bills information from bills.txt file
void retrieve_bills(int bill_ids[], int bill_items_numbers[][SIZE_2], int bill_staff_number[])
{
	FILE *infile;
	int  i, k, it[10];
	i = 0;
	//reading the bills info from the file "bills.txt"
	infile = fopen("bills.txt", "r");
	if (infile == NULL)
	{
		printf("  File does not exist ...\n");
	}
	else
	{
		//reading line by line till the end of the file and storing the data to the arrays
		while (fscanf(infile, "%d %d %d %d %d %d %d %d %d %d %d %d", &bill_ids[i], &it[0], &it[1], &it[2], &it[3], &it[4], &it[5], &it[6], &it[7], &it[8], &it[9], &bill_staff_number[i]) != EOF)
		{
                        for (k = 0; k < SIZE_2; k++)
                        {
                                bill_items_numbers[i][k] = it[k];
                        }
			i++;
		}
	}
	fclose(infile);
	bills_number = i;
}

//retrieve the staff information from staff.txt file
void retrieve_staffs(int staff_ids[], char staff_names[][STR_LEN], int staff_salaries[])
{
	FILE *infile;
	int  k, i;
	char n[STR_LEN], f[20], l[20];
	i = 0;
	//reading the staff info from the file "staff.txt"
	infile = fopen("staff.txt", "r");
	if (infile == NULL)
	{
		printf("  File does not exist ...\n");
	}
	else
	{
		//reading line by line till the end of the file and storing the data to the arrays
		while (fscanf(infile, "%d %s %s %d", &staff_ids[i], &f, &l, &staff_salaries[i]) != EOF)
		{
			strcpy(n, f);
			strcat(n, " ");
			strcat(n, l);
			for (k = 0; k < strlen(n); k++)
			{
				n[k] = toupper(n[k]);
			}
			strcpy(staff_names[i], n);
			i++;
		}
	}
	fclose(infile);
	staff_number = i;
}
