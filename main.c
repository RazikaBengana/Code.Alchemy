#include "compiler.h"

/**
 * main - the entry point
 *
 * program that serves as the entry point for the compiler program
 *
 * this function initiates the compilation process by calling the compile_file function
 * with the source file ("./test.c") and the target output ("./test");
 * it then checks the result of the compilation process;
 * if the compilation is successful, it prints a success message;
 * in case of a failure, it prints an error message;
 * if the result is neither, it prints a message indicating an unknown response;
 *
 * Return: 0 if the program executes successfully, regardless of the compilation result
 */
 
int main(void)
{
	int res = compile_file("./test.c", "./test", 0);

	if (res == COMPILER_FILE_COMPILED_OK)
	{
		printf("Everything compiled successfully\n");
	}

	else if (res == COMPILER_FAILED_WITH_ERRORS)
	{
		printf("Compile failed\n");
	}

	else
	{
		printf("Unknown response for compile file\n");
	}

	return (0);
}