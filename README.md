# get_next_line 
 Read get_next_line.en.pdf for project description

# Building The Project
* clone get_next_line project
* change into the get_next_line directory **cd get_next_line**
* *clone libft project - get next line depends on it* [libft](https://github.com/wkhosa-wizro/libft.git)
* run **make fclean && make all**
* after running make get_next_line.o will be created
* to clean run  **make clean**
* to clean the build as well run **make fclean** this will clean the *get_next_line.o* file as well
# How to use get_next_line function
* compile main.c function **gcc -Wall -Werror -Wextra -c main.c -o main.o**
* link with get_next_line function **gcc -Wall -Werror -Wextra -o main main.o get_next_line.o -L libft/ -lft**
* run main **./main "file1" "file2" "file..."
* this shoud read all files, one file at a time and one line at a time printing it on terminal
#### The following steps are optional
**To be added later**
