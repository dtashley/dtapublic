// rap.cpp : Defines the entry point for the console application.
//

extern "C" int main_c (int argc, char *argv[]);
   /* Must use second source file.  The .C extension on the file
   ** containing main_c() causes the compiler to treat it as a
   ** C rather than a C++ deck.  A person wanting to recompile
   ** on any SDK except MSVC++ must toss out this software module
   ** (which is just a wrapper), and rename main_c() in RAP_C.C
   ** to be main().
   */
   
int main(int argc, char* argv[])
{
	int return_value;
	   /* Return value from the "real" main.  This is just a wrapper
	   ** to make coexistence with Microsoft Visual C++ more 
	   ** pleasant.
	   */

	return_value = main_c(argc, argv);
	   /* Call the real main function, and save the
	   ** return value.
	   */

    return(return_value);
	   /* Return the return value to the external
	   ** environment.
	   */
}

