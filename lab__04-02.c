#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_PATH_LEN 100

int main()
{
	time_t t = time(NULL);
	FILE * pArgsFile, * pOutputFile, * pLogFile;
	char argsFilePath[MAX_PATH_LEN], outputFilePath[MAX_PATH_LEN];
	float x = 0, y = 0;
	const int a = 2;

	pLogFile = fopen("logfile.log", "a");
	fprintf(pLogFile, "Program has been started. %s", ctime(&t));

	puts("Enter arguments x and y:");
	scanf("%f %f", &x, &y);
	puts("Enter a path to the binary file:");
	scanf("%s", argsFilePath);

	pArgsFile = fopen(argsFilePath, "wb");

	t = time(NULL);

	fprintf(
		pLogFile, 
		"Parameters file '%s' has been opened. "
		"X = %f, Y = %f. %s",
		argsFilePath, x, y, ctime(&t)
	);

	puts("Enter a path to the output file:");
	scanf("%s", outputFilePath);

	pOutputFile = fopen(outputFilePath, "w");

	if (
		pArgsFile == NULL 
		|| pOutputFile == NULL 
		|| pLogFile == NULL
	) 
	{
		printf("Error opening the file. \n");

		exit(1);
	}

	pArgsFile = freopen("args.bin", "rb", stdin);

	fwrite(&x, sizeof(x), 1, pArgsFile);
	fwrite(&y, sizeof(y), 1, pArgsFile);
	fread(&x, sizeof(x), 1, pArgsFile);
	fread(&y, sizeof(y), 1, pArgsFile);
	fclose(pArgsFile);

	float z = pow(a, pow(y, x)) + pow(pow(3, x), y);

	t = time(NULL);

	fprintf(
		pLogFile,
		"Expression has been calculated. "
		"Result = %f. %s",
		z, ctime(&t)
	);

	fprintf(pOutputFile, "Result = %.2f", z);

	t = time(NULL);

	fprintf(
		pLogFile,
		"Output file '%s' has been saved. %s",
		outputFilePath, ctime(&t)
	);

	fprintf(pLogFile, "Program has been ended. %s", ctime(&t));

	fclose(pOutputFile);
	fclose(pLogFile);

	return 0;
}