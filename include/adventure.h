/*
** adventure.h for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:51:22 2016 edouard puillandre
** Last update Sun Apr 17 20:32:04 2016 edouard puillandre
*/

#ifndef ADVENTURE_H_
# define ADVENTURE_H_

# define WIN_X (1024)
# define WIN_Y (920)
# define COL_FONT (16)
# define ROW_FONT (16)
# define INIT_COLOR (0x00000000)
# define BACK_COLOR (0xFFCC33FF)
# define WIN_NAME "Window"
# define PIX_X (0)
# define PIX_Y (0)
# define WIDTH pix->clipable.clip_width
# define HEIGHT pix->clipable.clip_height
# define NB_BUTTON (6)
# define NB_OBJ (8)
# define ID_USE (0)
# define ID_GO (1)
# define ID_PICK (2)
# define ID_GIVE (3)
# define ID_TALK (4)
# define ID_LOOK (5)
# define X_USE (40)
# define Y_USE (732)
# define X_GO (220)
# define Y_GO (735)
# define X_PICK (400)
# define Y_PICK (733)
# define X_GIVE (40)
# define Y_GIVE (828)
# define X_TALK (214)
# define Y_TALK (830)
# define X_LOOK (400)
# define Y_LOOK (832)
# define W_BUTTON (165)
# define H_BUTTON (70)
# define OBJ_WIDTH (85)
# define OBJ_HEIGHT (70)
# define OBJ_STEP (20)
# define X_OBJ (595)
# define Y_OBJ (740)
# define BOARD_BMP "ressource/interface/interface_2.0.bmp"
# define FONT_BMP "ressource/interface/fonte.bmp"
# define ABS(x) (((x) < 0) ? - (x) : (x))
# define CUR data->player->cur_mov
# define MOV data->player->mov[CUR]->cur_pos
# define SCALE data->player->mov[CUR]->calque[MOV]->scale
# define PLAN data->plan[0]
# define CAL data->plan[0]->calque

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
  char			*file;
  t_bunny_pixelarray	*pix;
  float			x_init;
  float			y_init;
  float			x;
  float			x_speed; /* vitesse suivant x (peut être nulle)*/
  float			y;
  float			y_speed;
  int			scale;
}			t_calque;

/* rassemblement des infos d'une des animations*/
typedef struct		s_move
{
  t_calque		**calque; /* t_bunny_pixelarray	*pix; */
  int			div; /* nb image dans le sprite*/
  int			cur_pos; /* position courante */
}			t_move;

/* noeud de position*/
typedef struct		s_node
{
  t_bunny_position	pos; /* position du noeud*/
  int			scale; /* echelle du perso à ce noeud*/
  int			*way; /* chemin sur lequel se trouve le noeud*/
  int			pos_way; /* position du noeud dans le chemin */
  int			type; /*indication (-1) noeud de poid ou (-2) de placement ou de sortie (numéro du plan) */
  int			id_cal; /*devant quel calque se trouve le node*/
}			t_node;

/* personnage principal*/
typedef struct	s_char
{
  int		*chemin;
  t_move	**mov; /* tableau des mouvements*/
  float		coef[2];
  float		vec[2];
  int		cur_mov; /*mouvement courant*/
  int		mov_or_not;
  int		cur_node; /*Node sur lequel le perso se trouve */
  int		next_node; /*Node sur lequel le perso se trouve */
  int		dest_node; /*Node sur lequel le perso se trouve */
  float		x;
  float		y;
}		t_char;

/*Objet avec indication + nom*/
typedef struct	s_obj
{
  t_calque	*calque;
  char		*name;
  char		*desc; /* description de l'objet */
  char		*use;
  int		erase;
  int		id_calc;
  int		close;
}		t_obj;

/* Pnj avec 2 lignes de dialogues : une avant sans l'objet (obj) donné au pnj, l'autre, après. Parfois, l'objet give est donné aux joueurs*/
typedef struct	s_pnj
{
  t_calque	*calque;
  char		**dial;
  char		*name;
  char		*desc;
  int		cur_dial;
  char		*obj;
  t_obj		*give;
  int		id_calc;
  int		close;
}		t_pnj;

/*Structure d'un plan avec les calques, objets et node présent*/
typedef struct	s_plan
{
  t_calque	**calque;
  t_obj		**obj;
  t_pnj		**pnj;
  t_node	**node;
  int		start_node; /*node de départ: peut changer par les déplacement du personnage*/
}		t_plan;

typedef struct		s_button
{
  t_bunny_position	pos;
  int			(*fct)(data);
}			t_button;

typedef struct		s_board
{
  t_calque		*calque;
  t_button		**button;
  t_obj			**obj;
  int			sel;
}			t_board;

typedef struct		s_text
{
  t_bunny_pixelarray	*font;
  t_bunny_position	pos;
  char			*str;
}			t_text;

typedef	struct		s_data
{
  int			loop;
  t_bunny_window       	*win;
  t_bunny_position	*pos;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mouse;
  t_plan		**plan;
  t_char		*player;
  t_board		*board;
  t_text		*text;
  time_t		timer;
  int			id_plan;
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
void			envoi_to_copy(t_data *data);
void			copy_in_pix(t_calque *calque, t_data *data, int dec);
void			change_pos(t_data *);
void			change_pos_nuages(t_data *);
void			on_the_bord(t_data *, const t_bunny_position *);
void			have_pos(t_data *);
t_data			*load_decor_1(t_data *);
void			make_position_decor_1(t_data *);
t_data			*load_decor_2(t_data *);
void			make_position_decor_2(t_data *);
t_data			*malloc_and_load_perso(t_data *);
void			change_clipable(t_bunny_pixelarray *, int);
void			change_pos_perso(t_bunny_pixelarray *, int);
void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 unsigned int		color);
unsigned int		getpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos);
void			to_pix_scale(t_data *data, t_calque *calque, int dec);
void	free_calque(t_data *);
int	my_malloc_plan(t_data *, int);
t_board	*my_init_board();
int	check_click(t_data *);
int	my_use(t_data *);
int	my_go(t_data *);
int	my_pick(t_data *);
int	my_give(t_data *);
int	my_talk(t_data *);
int	my_look(t_data *);
int	compare_to_col(t_color, t_color);
void	draw_board(t_data *data);

void	calc_coef(float, float, t_bunny_position *, t_data *);
void	move_perso(t_data *);

void	load_node_1(t_data *);
int	check_click_pnj(t_data *data);
int	check_click_obj(t_data *data);
int	check_click_node(t_data *data);
int	check_click_button(t_data *data);
int	check_click_bis(t_data *data);

int	*search_way(int, int, t_node **, int *);
int	find_way(t_node *, t_node *);
int	find_same_way(int, int, int, t_node **);
int	find_diff_way(int, int, t_node **);
t_bunny_position	calc_coord(t_bunny_position	*tmp,
				   t_calque		*calque,
				   int			dec);
void	load_node_2(t_data *);
void	to_next_node(t_data *);
void	tektext(t_bunny_pixelarray *out, t_text *text);
t_text	*init_text();
char	*my_strcpy(char *str);
void	move_poteau(t_data *);

#endif /* !ADVENTURE_H_ */
