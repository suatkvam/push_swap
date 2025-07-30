#ifndef UTILS_H
#define UTILS_H

typedef struct s_stack
{
    int *data;
    int top;
    int capacity;
    void (*f)(unsigned int, char*);
}   t_stack; 

void init_stack(t_stack *s_data,int capacity);
void push(t_stack *s_data, int value);
void free_stack(t_stack *s_data);
void sa(t_stack *s_data_a);
void sb(t_stack *s_data_b);
void ss(t_stack *s_data_a, t_stack *s_data_b);
void pa(t_stack *s_data_b, t_stack *s_data_a);
void pb(t_stack *s_data_a, t_stack *s_data_b);
void ra(t_stack *s_data_a);
void rb(t_stack *s_data_b);
void rr(t_stack *s_data_a, t_stack *s_data_b);
void rra(t_stack *s_data_a);
void rrb(t_stack *s_data_b);
void rrr(t_stack *s_data_a, t_stack *s_data_b);
#endif