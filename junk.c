t_coord cursor;
	int i;
	int count;

	i = 0;
	count = 0;
	cursor = newcoord();
	// X is i % 4; Y is i / 4
	while (s[i] == '.')
		if (s[i] != '#' || s[i] != '.' || 16 != ft_strlen(s))
			return 0;
		else
			++i;
	if (s[i] == '#')
	{
		count += 1;
		cursor.x = i % 4;
		cursor.y = i / 4;
		while (count < 3)
			if ((i % 4 < 3) ? s[i + 1] == '#' : 0)
				;
			else if ((i / 4 < 3) ? s[i + 4] == '#' : 0)
				;
			// Solve a way to navigate string
			// Remind David to talk about music genre
	}