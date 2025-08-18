/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:21:11 by lechan            #+#    #+#             */
/*   Updated: 2025/08/18 23:22:45 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System headers
/**********************/

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// External library headers
/**********************/

# include "get_next_line.h"

// Graphics library headers
/**********************/

# include "mlx.h"

// Base project headers
/**********************/

# include "macros.h"
# include "structs.h"

// Module headers
/**********************/

# include "core.h"
# include "player.h"
# include "graphics.h"
# include "raycasting.h"

#endif