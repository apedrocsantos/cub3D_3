#include "../includes/cub3D.h"

int init_raycaster(t_data *data)
{
    if (data->player.direction == 'N')
        data->player.pa = (180);
    else if (data->player.direction == 'S')
        data->player.pa = (0);
    else if (data->player.direction == 'E')
        data->player.pa = (90);
    else if (data->player.direction == 'W')
        data->player.pa = (270);
    else
        leave_on_error(data, "Invalid player direction");
    data->player.pdx = cos(degToRad(data->player.pa));
    data->player.planeX = cos(degToRad(data->player.pa - (90)));
    data->player.planeY = sin(degToRad(data->player.pa - (90)));
    data->player.pdy = sin(degToRad(data->player.pa));
    return (SUCCESS);
}