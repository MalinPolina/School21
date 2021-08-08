#include "libasm.h"
#include "libasm_bonus.h"
#include <stdio.h>
#include <string.h>

int main()
{
	t_list	*list = NULL;
	t_list	*temp;

	printf("PUSH_FRONT\n");
	ft_list_push_front(&list, strdup("One"));
	printf("%s\n", list->data);
	ft_list_push_front(&list, strdup("Two"));
	printf("%s\n", list->data);
	ft_list_push_front(&list, strdup("Three"));
	printf("%s\n", list->data);
	printf("Size: %d\n", ft_list_size(list));
	printf("List:");
	while (list)
	{
		temp = list->next;
		printf(" %s", list->data);
		free(list->data);
		free(list);
		list = temp;
	}
	printf("\n");
	return (0);
}
