#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0

typedef struct // declaring a structure to store the value of final output
{
	int x, y;
	float percentage_plagiarism;
} result;

void modify_file_1(char *file_name)
{
	FILE *ifp, *ifr;
	int i, j;
	int count = 0;
	char line[1000], temp[] = "temp.c"; // creating a temporary file

	if ((ifp = fopen(file_name, "r")) == NULL)
	{
		printf("Error in opening file!\n");
		exit(1);
	}

	if ((ifr = fopen(temp, "w")) == NULL)
	{
		printf("Cannot open file to write!\n");
		exit(0);
	}

	while (fgets(line, 1000, ifp) != NULL) // considering max length of the line as 1000
	{
		for (i = 0; i < strlen(line); i++)
		{
			if (line[i] == '#') // removing Header Files and #define directive
				break;

			if ((i <= (strlen(line) - 2)) && (line[i] == '/') && (line[i + 1] == '*')) // checking if /* type comment has started
			{
				count = 1;
				i += 2;
			}

			if ((count == 1) && (line[i] == '\n')) // checking and printing if there is '\n' is in between /* */ type comment
				fputs("\n", ifr);

			if ((i <= (strlen(line) - 2)) && (i >= 1) && (line[i] == '*') && (line[i + 1] == '/') && (line[i - 1] != '/')) // checking if */ type comment has ended
			{
				count = 0;
				i += 2;
			}

			if (count == 0)
			{
				if ((i <= (strlen(line) - 2)) && (line[i] == '/') && (line[i + 1] == '/'))
					;

				else if ((line[i] != ' ') && (line[i] != '\t')) // removing spaces, '\t', and printing other characters outside comments
					fputc(line[i], ifr);
			}

			if ((count == 0) && (i <= (strlen(line) - 2)) && (line[i] == '/') && (line[i + 1] == '/')) // checking if // type comment has started
			{
				j = i + 2;

				while (j < strlen(line))
				{
					if (line[j] == '\n') // checking and printing if there is '\n' is in between // type comment
						fputs("\n", ifr);

					j++;
				}

				break;
			}
		}
	}

	fclose(ifr);

	fclose(ifp);

	remove(file_name); // removing original file

	rename(temp, file_name); // renaming modified file with the name of original file
}

void modify_file_2(char *file_name)
{
	FILE *ifp, *ifr;
	int i, j;
	int count = 0;
	char line[1000], temp[] = "temp.c"; // creating a temporary file

	if ((ifp = fopen(file_name, "r")) == NULL)
	{
		printf("Error in opening file!\n");
		exit(1);
	}

	if ((ifr = fopen(temp, "w")) == NULL)
	{
		printf("Cannot open file to write!\n");
		exit(0);
	}

	while (fgets(line, 1000, ifp) != NULL) // considering max length of the line as 1000
	{
		for (i = 0; i < strlen(line); i++)
		{
			if (line[i] == '\n')
				continue;

			fputc(line[i], ifr);

			if (line[i] == ';')
				fputs("\n", ifr);
		}
	}

	fclose(ifr);

	fclose(ifp);

	remove(file_name); // removing original file

	rename(temp, file_name); // renaming modified file with the name of original file
}

float calc_plagiarism(char *file_1, char *file_2)
{
	FILE *ifp_1, *ifp_2;
	int i;
	int flag=0;
	float plag_percent;
	char line_1[1000], line_2[1000];

	int plag_char = 0; // intitalizing number of plagiarised characters
	int total_char = 0; // intitalizing number of total characters

	if ((ifp_1 = fopen(file_1, "r")) == NULL)
	{
		printf("Error in opening file!\n");
		exit(1);
	}

	if ((ifp_2 = fopen(file_2, "r")) == NULL)
	{
		printf("Error in opening file!\n");
		exit(1);
	}

	while (fgets(line_1, 1000, ifp_1) != NULL) // considering max length of the line as 1000
	{
		while (fgets(line_2, 1000, ifp_2) != NULL) // considering max length of the line as 1000
		{
			i = 0;

			flag=1;

			while ((line_1[i] != ';') && (line_2[i] != ';')) // checking if any line has ended
			{
				if (line_1[i] == line_2[i])
					plag_char++;

				i++;
			}

			if (line_2[i] != ';') // checking if line_2 hasn't ended and adding the number of characters left in that line
			{
				while (line_2[i] != ';')
					i++;
			}

			else if (line_1[i] != ';') // checking if line_1 hasn't ended and adding the number of characters left in that line
			{
				while (line_1[i] != ';')
					i++;
			}
			
			total_char += i;

			break;
		}

		if(flag==0) // checking if File 1 has more number of lines than File 2 and adding the number of characters of those left lines
			total_char += strlen(line_1) - 2;

		flag=0;
	}

	while (fgets(line_2, 1000, ifp_2) != NULL) // checking if File 2 has more number of lines than File 1 and adding the number of characters of those left line
		total_char += strlen(line_2) - 2;
	
	plag_percent = ((float)plag_char / total_char) * 100;

	fclose(ifp_1);
	fclose(ifp_2);

	return (plag_percent);
}

void swap_int(int *xp, int *yp) // swapping value of x and y in structure
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swap_float(float *xp, float *yp) // swapping value of percentage plagiarism in structure
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(result *array_str, int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++) // one by one move boundary of unsorted subarray
	{
		min_idx = i; // find the minimum element in unsorted array

		for (j = i + 1; j < n; j++)

			if ((array_str[j].percentage_plagiarism) < (array_str[min_idx].percentage_plagiarism))
				min_idx = j;

		swap_float(&(array_str[min_idx].percentage_plagiarism), &(array_str[i].percentage_plagiarism)); // swap the found minimum element with the first element

		swap_int(&(array_str[min_idx].x), &(array_str[i].x)); // swap the x value of found minimum element with the x value of first element
		swap_int(&(array_str[min_idx].y), &(array_str[i].y)); // swap the y value of found minimum element with the y value of first element
	}
}

int main(int argc, char *argv[])
{
	int i, j;
	char **file_name;
	result *array_str;

	int total_files = atoi(argv[1]);
	int number_comparisons = (total_files * (total_files - 1)) / 2;
	int count = 0;
	float sum = 0;

	if (argc < 4)
	{
		printf("Inappropriate number of commandline arguments.\n\n");
		printf("Usage: ./a.out <.c file> <.c file> <.c file> ......all files to be compared. \n");

		exit(0);
	}

	if(total_files != (argc-2))
	{
		printf("\nInappropriate input. Number of files and number of file names are not matching.\n");

		exit(0);
	}

	if ((file_name = (char **)malloc(total_files * sizeof(char *))) == NULL) // creating array of strings
	{
		printf("Memory cannot be allocated.");
		exit(1);
	}

	for (i = 0; i < total_files; i++)
	{
		if ((file_name[i] = (char *)malloc(100)) == NULL) // considering max length of the file name as 100
		{
			printf("Memory cannot be allocated.");
			exit(1);
		}

		strcpy(file_name[i], argv[i + 2]);

		modify_file_1(file_name[i]); // modifying each and every file for the first time
		modify_file_2(file_name[i]); // modifying each and every file for the second time
	}

	if ((array_str = (result *)malloc(number_comparisons * sizeof(result))) == NULL) // creating array of structures 
	{
		printf("Memory cannot be allocated.");
		exit(1);
	}

	for (i = 0; i < total_files; i++) // initializing the structure
	{
		for (j = i + 1; j < total_files; j++)
		{
			array_str[count].x = i + 1;
			array_str[count].y = j + 1;
			array_str[count].percentage_plagiarism = calc_plagiarism(file_name[i], file_name[j]);

			count++;
		}
	}

	selectionSort(array_str, number_comparisons); // sorting the percentage plagairism between different files

	printf("\n\tPercentage Plagiarism between two files\n\t---------------------------------------\n\nFile_Name\tFile_Name\tPercentage Plagiarism\n-----------------------------------------------------\n");
	
	for (i = number_comparisons - 1; i >= 0; i--) // displaying the table of results
	{
		sum += array_str[i].percentage_plagiarism;

		printf("%s        %s\t     %f %%\n", file_name[ (array_str[i].x) - 1], file_name[ (array_str[i].y) - 1], array_str[i].percentage_plagiarism);
	}

	printf("\n\t    Average plagiarism: %f %%\n", sum / number_comparisons);

	free(array_str);
	free(file_name);
	
	return 0;
}