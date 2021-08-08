
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*temp;
	t_list	*node;
	t_list	*nlst;

	temp = lst;
	nlst = NULL;
	while (temp)
	{
		node = ft_lstnew(f(temp->content));
		if (!node)
		{
			ft_lstclear(&nlst, del);
			break ;
		}
		ft_lstadd_back(&nlst, node);
		temp = temp->next;
	}
	return (nlst);
}
