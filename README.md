# get_next_line 
 Read get_next_line.en.pdf for project description

# Building The Project
 * clone get_next_line project
 * **cd** into the get_next_line directory
 * *clone libft project - get next line depends on it* [libft](https://github.com/wkhosa-wizro/libft.git)
 * run **make fclean && make all**
 * after running make get_next_line.o will be created
 * to clean run  **make clean**
 * to clean the build as well run **make fclean** this will clean the *get_next_line.o* file as well
   * The following steps are optional           
     * copy the get_next_line.o and get_next_line.c to libft directory
     * edit make file in the libft directory to include both source and object file of get_next_line
     * edit the libft.h header file to include get_next_line.h header
     * make the libft by running ** make fclean && make all**
     * then the libft.a created will have get_next_line function.

