#include "algorithms.h"

int	is_sorted(const t_stack *stack_a)
{
	int	i;

	if (stack_a->top < 1)
		return (1);
	i = stack_a->top;
	while (i > 0)
	{
		// DÜZELTME: artan sıra kontrolü için < kullan
		if (stack_a->id[i] < stack_a->id[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_three(t_stack *stack_a)
{
	int	first, second, third;
	
	if (stack_a->top < 2)
		return;
	
	// Use id[] as you originally intended
	first = stack_a->id[stack_a->top];     // top
	second = stack_a->id[stack_a->top - 1]; // middle  
	third = stack_a->id[stack_a->top - 2];  // bottom
	
	// For the case: IDs 2 0 1 -> should result in sa
	if (first == 0 && second == 1 && third == 2)
		return; // Already sorted: 0 1 2
	else if (first == 0 && second == 2 && third == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first == 1 && second == 0 && third == 2)
		sa(stack_a);
	else if (first == 1 && second == 2 && third == 0)
		rra(stack_a);
	else if (first == 2 && second == 0 && third == 1)
		ra(stack_a); // 2 0 1 -> ra -> 0 1 2 
	else if (first == 2 && second == 1 && third == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
}
void	find_best_position_and_push(t_stack *stack_a, t_stack *stack_b)
{
    int	b_value;
    int	rotations_needed;

    // Use id[] instead of data[]
    b_value = stack_b->id[stack_b->top];
    rotations_needed = find_insertion_point(stack_a, b_value);
    
    // Rotate A to optimal position
    if (rotations_needed <= stack_a->top / 2)
    {
        while (rotations_needed-- > 0)
            ra(stack_a);
    }
    else
    {
        rotations_needed = stack_a->top + 1 - rotations_needed;
        while (rotations_needed-- > 0)
            rra(stack_a);
    }
    
    // Push from B to A
    pa(stack_a, stack_b);
}


void	sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	// Handle small stacks directly
	if (stack_a->top <= 2)
	{
		sort_three(stack_a);
		return ;
	}
	
	// Step 1: Push elements to B until only 3 remain in A
	while (stack_a->top > 2)
	{
		pb(stack_a, stack_b);
	}
	
	// Step 2: Sort the remaining 3 elements in A
	sort_three(stack_a);
	
	// Step 3: Move all elements back from B to A
	while (stack_b->top >= 0)
	{
		pa(stack_a, stack_b);
	}
	
	// Step 4: Simple final sort by rotating
	while (!is_sorted(stack_a))
	{
		ra(stack_a);
	}
}

// Helper function to find best position for B's top element in A
