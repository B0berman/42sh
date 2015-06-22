/*
** io_nextline.c for io in /home/zack/neptune/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:52:20 2015 Antoine Favarel
** Last update dim. mai 24 13:45:23 2015 Antoine Favarel
*/

#include	<unistd.h>

#include	"neptune/io.h"
#include	"neptune/strmut.h"

char		*st_save(t_io *this, char sep, char *line)
{
  line = sm_splithead(this->buffer, sep);
  sm_fillbuff(this->buffer,
      sm_splittail(this->buffer, sep), this->buffsize);
  return (line);
}

char		*st_nsave(t_io *this, char sep, char *line)
{
  line = sm_cat(line, sm_splithead(this->buffer, sep));
  sm_fillbuff(this->buffer, sm_splittail(this->buffer, sep)
      , this->buffsize);
  return (line);
}

char		*io_nextline(t_io *this, char separator)
{
  char		*line;

  line = NULL;
  if (sm_is_strcontainc(this->buffer, separator))
    return (st_save(this, separator, line));
  line = sm_cat(line, this->buffer);
  if (read(this->fd, this->buffer, this->buffsize) <= 0)
    return (NULL);
  if (sm_is_strcontainc(this->buffer, separator))
    return (st_nsave(this, separator, line));
  line = sm_cat(line, this->buffer);
  while (read(this->fd, this->buffer, this->buffsize) > 0
      && !sm_is_strcontainc(this->buffer, separator))
    line = sm_cat(line, this->buffer);
  return (st_nsave(this, separator, line));
}
