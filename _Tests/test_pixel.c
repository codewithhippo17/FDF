#include <math.h>
#include <stdio.h>

typedef struct p
{
	int a;
	struct p *next;
} t_p;



#include <stdlib.h>

int main()
{
	t_p *p;
	p = malloc(sizeof(t_p));

	p->a = 10;

	t_p	*p1 = malloc(sizeof(t_p));
	p1->a = 8;
	p->next = p1;

	t_p	*p2 = malloc(sizeof(t_p));
	p2->a = 6;
	p1->next = p2;
	p2->next = NULL;
	
	t_p *current;
	current = p;
	while (current)
	{
		printf("%d\n", current->a);
		current = current->next;
	}
	printf("%p\n", p->next);
	printf("%p\n", p1->next);
	printf("%p\n", p2->next);
	*p->next = *p->next->next;
	// current = p;
	// while (current)
	// {
	// 	printf("%d\n", current->a);
	// 	current = current->next;
	// }
	// p->next = p->next->next;
	current = p;
	while (current)
	{
		printf("%d\n", current->a);
		current = current->next;
	}
	printf("%p\n", p->next);
	printf("%p\n", p1->next);
	printf("%p\n", p2->next);
}