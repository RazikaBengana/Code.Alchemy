#include "compiler.h"

/**
 * compile_process_create - program that creates and initializes a compile_process structure
 *
 * this function allocates memory for a compile_process structure and initializes it
 * with the provided parameters;
 * it opens the specified input file for reading and, if provided, opens the output file for writing;
 * if any file cannot be opened, it returns NULL;
 * this function is crucial for setting up the environment needed for the compilation process
 *
 * @filename: the name (path) of the file to be compiled
 * @filename_out: the name (path) of the output file where the compiled code will be written;
 *                if NULL, no output file is created;
 * @flags: integer flags used to control specific aspects of the compilation process
 *
 * Return: a pointer to the newly created compile_process structure, or NULL if an error occurred
 */

struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		return (NULL);
	}

	FILE* out_file = NULL;

	if(filename_out)
	{
		out_file = fopen(filename_out, "w");

		if (!out_file)
		{
			return (NULL);
		}
	}

	struct compile_process* process = calloc(1, sizeof(struct compile_process));

	process->flags = flags;
	process->cfile.fp = file;
	process->ofile = out_file;

	return (process);
}