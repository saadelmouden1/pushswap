#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


typedef struct s_stack_lst_node
{
    int value;
    int pos;
    int moves;
    bool before_middle;
    struct s_stack_lst_node *prev;
    struct s_stack_lst_node *next;
    struct s_stack_lst_node *place_node;
    bool small_n_moves;

} t_stack_lst_node;

void push_stack(t_stack_lst_node **dest, t_stack_lst_node **src);

t_stack_lst_node *get_larg_num(t_stack_lst_node *stack);
int get_list_size(t_stack_lst_node *stack);
t_stack_lst_node *find_last_node(t_stack_lst_node *first_element);

void add_element(t_stack_lst_node **stack, int value);
void sort_three(t_stack_lst_node **stack);
void push_swap(t_stack_lst_node **stack_a, t_stack_lst_node **stack_b);

void retate(t_stack_lst_node **stack);

void reverse_retate(t_stack_lst_node **stack);

void swap(t_stack_lst_node **stack);
void	stack_init(t_stack_lst_node **a, char **argv, int ac);
char	**ft_split(const char *s, char c);
bool is_sorted(t_stack_lst_node *list);
void stack_freeing(t_stack_lst_node **list);
int is_repet(t_stack_lst_node *a, int n);
int check_syntax(char *str);
void free_array(char **str);
void clean_mmr(t_stack_lst_node **a, char **av, int ac);
