/*
** adventure.h for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:51:22 2016 edouard puillandre
** Last update Wed Apr  6 20:04:01 2016 edouard puillandre
*/

#ifndef ADVENTURE_H_
# define ADVENTURE_H_

# define WIN_X (1280)
# define WIN_Y (1024)
# define INIT_COLOR (0x00000000)
# define BACK_COLOR (0x00CC33FF)
# define WIN_NAME "Window"
# define PIX_X (0)
# define PIX_Y (0)

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <lapin.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data * data;

/*definition d'un calque: ceux-ci seront stocké dans un tableau*/
typedef struct		s_calque
{
  t_bunny_pixelarray	*pix;
  float			x;
  float			x_speed; /* vitesse suivant x (peut être nulle)*/
  int			y;
}			t_calque;

/* rassemblement des infos d'une des animations*/
typedef struct		s_move
{
  t_bunny_pixelarray	*pix;
  int			div; /* nb image dans le sprite*/
  int			cur_pos; /* position courante */
}			t_move;

/*text avec position*/
typedef struct		s_text
{
  t_bunny_position	*pos;
  char			*str;
}			t_text;

/* défini l'échelle, la position et devant quel calque se trouve le move concerné (pnj / objet)*/
typedef struct		s_pixplus
{
  t_move		*move;
  t_bunny_position	*pos;
  int			id_cal;
  int			scale;
}			t_pixplus;

/* noeud de position*/
typedef struct		s_node
{
  t_bunny_position	*pos; /* position du noeud*/
  int			*scale; /* echelle du perso à ce noeud*/
  int			*way; /* chemin sur lequel se trouve le noeud*/
  int			pos_way; /* position du noeud dans le chemin */
  int			type; /*indication (0) noeud de poid ou (1) de placement*/
  int			id_cal; /*devant quel calque se trouve le node*/
}			t_node;

/* personnage principal*/
typedef struct	s_char
{
  t_move	**mov; /* tableau des mouvements*/
  t_node	*cur; /* node sur lequel est le perso */
  int		cur_mov; /*mouvement courant*/
}		t_char;

/*Objet avec indication + nom*/
typedef struct	s_obj
{
  t_pixplus	*pix;
  t_text	*name;
  t_text	*desc; /* description de l'objet */
  bool		pick; /* objet pickable ou non*/
  int		(*fct)(data); /* action de l'objet en fonction de t_data */
}		t_obj;

/*coffre avec les objets présents (4 max) */
typedef struct	s_chest
{
  t_pixplus	*pix;
  t_obj		obj[4];
  t_text	*desc; /* description du coffre*/
}		t_chest;

/* Pnj avec 2 lignes de dialogues : une avant sans l'objet (obj) donné au pnj, l'autre, après. Parfois, l'objet give est donné aux joueurs*/
typedef struct	s_pnj
{
  t_pixplus	*pix;
  t_text	*dial1;
  t_text	*dial2;
  t_text	*obj;
  t_obj		*give;
}		t_pnj;

/*Structure d'un plan avec les calques, objets et node présent*/
typedef struct	s_plan;
{
  t_calque	**calque;
  t_obj		**obj;
  t_chest	**chest;
  t_pnj		**pnj;
  t_node	**node;
  int		start_node; /*node de départ: peut changer par les déplacements du personnages*/
}		t_plan;

typedef struct	s_game
{
  int		id_plan; /*plan courant*/
  time_t       	timer; /*timer avant la mort du perso*/
  t_obj		*sel_obj; /* objet sélectionné */
  int		action; /*action sélectionnée*/
}		t_game;

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_position	*pos;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mouse;
  t_plan		**plan;
  t_char		*player;
  t_game		*game;
}			t_data;

typedef struct s_header
{
  unsigned short int	magic_number;
  unsigned int		size_file;
  unsigned int		reserved;
  unsigned int		offset;
} __attribute__((packed)) t_header;

typedef struct s_infoheader
{
  unsigned int		size_header;
  unsigned int		width;
  unsigned int	       	height;
  unsigned short int	planes;
  unsigned short int	bits;
  unsigned int		compression;
  unsigned int		imagesize;
  unsigned int	       	xresolution;
  unsigned int	       	yresolution;
  unsigned int		ncolours;
  unsigned int		importantcolours;
} __attribute__((packed)) t_infoheader;

t_bunny_response	my_fct_free(t_data *data, int error_true);
t_data			*my_init_data();
t_bunny_pixelarray	*load_bitmap(char *filepath);

#endif /* !ADVENTURE_H_ */
