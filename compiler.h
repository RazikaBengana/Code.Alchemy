#ifndef COMPILER_H
#define COMPILER_H


#include <stdio.h>
#include <stdlib.h>


/**
 * enum compiler_result - enumeration for the possible outcomes of the compile process
 *
 * @COMPILER_FILE_COMPILED_OK: indicates successful compilation without errors
 * @COMPILER_FAILED_WITH_ERRORS: indicates that the compilation process failed due to errors
 */

enum compiler_result
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};



/**
 * struct compile_process - structure representing the compilation process
 *
 * @flags: an integer holding flags for controlling the compilation process (how the file should be compiled)
 * @ofile: the file pointer to the output file where the compiled code will be written
 *
 *
 * struct compile_process_input_file - a nested structure representing the input file for compilation
 *
 * @fp: a file pointer to the input file
 * @abs_path: the absolute path of the input file
 * @cfile: an instance of 'compile_process_input_file' representing the input file details
 */

struct compile_process
{
	int flags;

	struct compile_process_input_file
	{
	    FILE* fp;
	    const char* abs_path;
	} cfile;

	FILE* ofile;
};


int compile_file(const char* filename, const char* out_filename, int flags);
struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags);


#endif /* COMPILER_H */
