/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:53:15 by alaa              #+#    #+#             */
/*   Updated: 2024/03/01 20:53:39 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
int	add_shade(double shade, int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_trgb;

	t = shade * 255;
	r = get_r(trgb);
	g = get_g(trgb);
	b = get_b(trgb);
	new_trgb = create_trgb(t, r, g, b);
	return (new_trgb);
}

int	invert(int trgb)
{
	return (trgb ^ 0x00ffffff);
}
