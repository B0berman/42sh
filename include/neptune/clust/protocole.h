/*
** protocole.h for clust in /home/zack/Projects/neptune_architecte/include/neptune/clust
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 10:33:57 2015 Antoine Favarel
** Last update mer. avril 29 13:49:04 2015 Antoine Favarel
*/

#ifndef		NEP_C_PROTOCOLE_H_
# define	NEP_C_PROTOCOLE_H_

typedef	enum	e_role
{
  MR_DATA,
  MR_ORDER,
  MR_RESPONS,
  MR_AKN
}		t_role;

typedef	enum	e_desc
{
  MD_DATA,
  MD_LIST
}		t_desc;

typedef	struct	s_metadata
{
  t_role	role;
  t_desc	desc;
}		t_metadata;

t_metadata	*new_metadata(t_role role, t_desc desc);

#endif		/* !NEP_C_PROTOCOLE_H_ */
