#include <unistd.h>

void	ft_fill(char *board)
{
	int i;

	i = 0;
	while (i < 10)
	{
		*(board + i) = 'q';
		i++;
	}
}

void	ft_print(char *board)
{
	int i;

	i = 0;
	while (i < 10)
	{
		write(1, board + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_is_place(char *board, int col, int row)
{
	int i;
	int up;
	int down;

	i = 0;
	while (i < col)
	{
		up = row - (col - i);
		down = row + (col - i);
		if (*(board + i) == row + '0')
			return (0);
		if ((up >= 0) && (*(board + i) == up + '0'))
			return (0);
		if ((down <= 9) && (*(board + i) == down + '0'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_queens_place(char *board, int col, int *nbr)
{
	int i;

	i = 0;
	if (col == 10)
	{
		*nbr = *nbr + 1;
		ft_print(board);
		return (1);
	}
	while (i < 10)
	{
		if (ft_is_place(board, col, i))
		{
			*(board + col) = i + '0';
			ft_queens_place(board, col + 1, nbr);
			*(board + col) = 'q';
		}
		i++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		nbr;

	nbr = 0;
	ft_fill(board);
	while (ft_queens_place(board, 0, &nbr))
		;
	return (nbr);
}
