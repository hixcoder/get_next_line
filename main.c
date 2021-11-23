/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:24:12 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/21 10:02:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	//int	fd;
	int	i;
	char *line;

	//fd = open("test", O_RDONLY);
	
	//fd = open("files/empty", O_RDONLY);
	//fd = open("files/nl", O_RDONLY);
	//fd = open("files/41_no_nl", O_RDONLY);
	//fd = open("files/41_with_nl", O_RDONLY);
	//fd = open("files/42_no_nl", O_RDONLY);
	//fd = open("files/42_with_nl", O_RDONLY);
	//fd = open("files/43_no_nl", O_RDONLY);
	//fd = open("files/43_with_nl", O_RDONLY);
	//fd = open("files/multiple_nlx5", O_RDONLY);
	//fd = open("files/multiple_line_no_nl", O_RDONLY);
	//fd = open("files/multiple_line_with_nl", O_RDONLY);
	//fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	//fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
	//fd = open("files/big_line_no_nl", O_RDONLY);
	//fd = open("files/big_line_with_nl", O_RDONLY);

	//stdin
	//fd = 0;
	
	
	i = 0;
	while ((line =  get_next_line(fd)))
	{
		printf("line %d ==> %s", i, line);
		i++;
	}
	close(fd);
	





	  //---------------------------------------------------------\\
	 //                           BONUS                           \\
	//-------------------------------------------------------------\\

	int	fd[5];
	

	fd[1] = open("files/t1", O_RDONLY);
	fd[2] = open("files/t2", O_RDONLY);
	fd[3] = open("files/t3", O_RDONLY);
	i = -1;
	while (++i < 13)
	{
		if (i == 1 || i == 4 || i == 7)
			printf("fd[1] ==> %s",get_next_line(fd[1]));
		if (i == 2 || i == 5 || i == 8)
			printf("fd[2] ==> %s",get_next_line(fd[2]));
		if (i == 3 || i == 6 || i == 9)
			printf("fd[3] ==> %s",get_next_line(fd[3]));
	}

}
