/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:25:24 by aghergho          #+#    #+#             */
/*   Updated: 2025/03/17 12:40:28 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_WIDTH 1280.f
# define SCREEN_HEIGHT 720.f

# define EPSILON 1e-4f
# define PI 3.14159265359
# define ESC_KEY 65307

typedef struct s_vector
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_vector;

typedef struct s_color
{
	float				r;
	float				g;
	float				b;
}						t_color;

typedef enum e_shape_type
{
	SHAPE_SPHERE,
	SHAPE_PLANE,
	SHAPE_CYLINDER,
	SHAPE_CONE
}						t_shape_type;

typedef struct s_ray
{
	t_vector			origin;
	t_vector			direction;
}						t_ray;

typedef struct minor
{
	int					col;
	int					i;
	int					mi;
	int					n;
}						t_minor;

typedef struct light_utils
{
	t_vector			light_dir_normal;
	t_color				eff_color;
	t_color				ambient;
	t_color				diffuse;
	t_color				specular;
	float				light_dot_normal;
	float				reflect_dot_camera;
	t_color				res;
}						t_lihgt_color;

typedef struct s_intersection
{
	int					n_sol;
	float				t1;
	void				*object;
	int					type;
}						t_intersection;

typedef t_vector		t_point;

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef struct s_material
{
	t_color				color;
	float				ambient;
	float				diffuse;
	float				specular;
	float				shininess;
}						t_material;

typedef struct s_rmatrix
{
	float				cos_theta;
	float				sin_theta;
	float				one_minus_cos;
}						t_matrix;

typedef struct light_s
{
	t_color				color;
	t_point				position;
}						t_plight;

typedef struct var
{
	void				*mlx;
	void				*win;
	t_img				img;
	int					color;
}						t_var;

typedef struct t_scamera
{
	float				h_size;
	float				w_size;
	float				half_h_size;
	float				half_w_size;
	float				fov;
	float				**transform;
	float				pixel_size;
	t_point				origin;
	t_vector			direction;
}						t_scamera;

typedef struct lines
{
	char				**line_component;
	struct lines		*next;
}						t_map_line;

typedef struct map
{
	t_map_line			*lines;
	int					scen_elements[3];
}						t_map;

typedef struct s_texture
{
	t_color				*colors;
	char				*img_data;
	void				*img_ptr;
	int					width;
	int					height;
	int					size_line;
	int					bpp;
	int					endian;
}						t_texture;

typedef struct sphere
{
	float				sphere_diameter;
	t_vector			sphere_coordinates;
	t_color				sphere_color;
	t_color				checkered_color;
	float				**transform;
	t_material			*material;
	t_texture			*texture;
	int					has_texture;
	int					has_checkered;
	struct sphere		*next;
}						t_sphere;

typedef struct plane
{
	t_vector			plane_cordinates;
	t_vector			plane_normal;
	t_color				plane_color;
	t_material			*material;
	float				**transform;
	struct plane		*next;
}						t_plane;

typedef struct cylinder
{
	t_point				coordinates;
	t_vector			orientation;
	t_color				cylinder_color;
	double				raduis;
	double				height;
	float				**transform;
	t_material			*material;
	struct cylinder		*next;
}						t_cylinder;

typedef struct cone
{
	t_vector			apex;
	t_vector			axis;
	float				height;
	float				radius;
	t_color				color;
	t_material			*material;
	float				**transform;
	struct cone			*next;
}						t_cone;

typedef struct camera
{
	int					camera_fov;
	float				focal_lenght;
	int					hor_size;
	t_vector			camera_position;
	t_vector			camera_dir;
	t_vector			cam_u;
	t_vector			cam_v;
	t_vector			projection_center;
	t_vector			alignement_vector;
}						t_camera;

typedef struct ambient
{
	double				ambient_ration;
	t_color				ambient_color;
}						t_ambient;

typedef struct light
{
	t_point				coordinate;
	double				ration;
	t_color				color;
	struct light		*next;
}						t_light;

typedef struct u_objects
{
	int					object_id;
	void				*object;
	struct u_objects	*next;
}						t_object;

typedef struct s_compose
{
	t_intersection		intersection;
	void				*obj;
	int					obj_type;
	float				t;
	t_vector			camv;
	t_vector			normv;
	t_point				point;
	int					inside;
	int					shadow;
	t_point				over_point;
}						t_compose;

typedef struct s_shape
{
	t_shape_type		type;
	union
	{
		t_sphere		*sphere;
		t_plane			*plane;
		t_cylinder		*cylinder;
		t_cone			*cone;
	} u_objects;
	struct s_shape		*next;
}						t_shape;

typedef struct s_world
{
	int					n_objects;
	t_shape				*shape;
	t_light				*light;
}						t_world;

typedef struct s_scene
{
	t_scamera			*camera;
	t_ambient			*ambient;
	t_light				*light;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
	t_cone				*cone;
	t_var				*data;
	t_map				*map;
	t_world				*world;
}						t_scene;

typedef struct s_transform_vars
{
	float				dot;
	float				angle;
	t_vector			axis;
	t_vector			up;
	t_vector			cross;
}						t_transform_vars;

typedef struct s_quadratic
{
	float				a;
	float				b;
	float				c;
	float				t1;
	float				t2;
}						t_quadratic;

typedef struct set_view_matrix
{
	t_vector			up_n;
	t_vector			left_v;
	t_vector			forward_v;
}						t_view_matrix;

typedef struct s_world_system
{
	float				world_x;
	float				world_y;
}						t_world_sys;

typedef struct s_intdata
{
	float				t1;
	float				t2;
}						t_intdata;

typedef struct s_lighting
{
	t_color				texture_color;
	t_material			*material;
	t_light				*light;
	t_compose			*comp;
	int					shadow;
}						t_lighting;

typedef struct s_cylinder_equation
{
	float				a;
	float				b;
	float				c;
	float				discriminant;
	t_ray				tr_ray;
	float				sol[4];
	float				half_height;
	int					counter;
	int					is_inside;
	float				min_t;
}						t_cylinder_eq;
/*parsing utils*/
int						ft_check_empty_element(char *comp);
int						ft_gen_elements(t_vector *coordinates,
							char *components);
double					ft_atod(char *str);
int						ft_gen_colors(t_color *color, char *components);
int						ft_add_cone(t_scene **scene, char **components);
int						ft_add_sphere(t_scene **scene, char **components);
int						ft_count_components(char **components);
int						get_texture(t_sphere *sphere, char *texture_name,
							t_scene **scene);
int						handle_sphere_texture(t_sphere *sphere,
							char **components, int comp_count, t_scene **scene);
t_color					handle_textured_sphere(t_world *world, t_compose *comp,
							t_light *light, t_material *material);
t_color					sample_texture(t_texture *texture, float u, float v);
t_color					int_to_color(int color);
/*end of parsing utils*/

int						ft_close_window(t_scene *scen);
void					my_pixel_put(t_img *img, int x, int y, int color);
t_map_line				*ft_gen_scen_map(char *file_name);
int						render_image(t_scene *scene, t_scamera *cam);
void					display_progress(t_scene *scene, t_scamera *cam,
							int current_pixel, int total_pixels);
int						ft_generate_scene(t_map_line *compoenent,
							t_scene **scene);
void					var_dump_lines(t_map_line *map);
int						ft_check_map_components(t_map **map);
float					ft_vec_lenght(t_vector *v);
double					vec_lenght(t_vector v);
float					vector_dot(t_vector v1, t_vector v2);
t_vector				ft_new_vector(float x, float y, float z);
t_vector				vector_normilze(t_vector vec);
t_vector				vector_multiply_scalar(t_vector v, float scalar);
t_vector				vector_cross(t_vector v1, t_vector v2);
t_vector				vector_sub(t_vector v1, t_vector v2);
t_vector				vector_add(t_vector v1, t_vector v2);
void					var_dump_vector(t_vector vec);
void					init_scene(t_scene *scene);
t_ray					create_ray(t_vector origin, t_vector direction);
int						gen_ray(t_scene *scene, float x, float y, t_ray cam_r);
void					ft_set_camera(t_scamera **camera);
t_vector				vector_copy(t_vector src);
t_sphere				*ft_new_sphere(char **components, t_scene **scene);
t_vector				vector_mult_scalar(t_vector v, float scalar);

/* colors operations*/
t_color					ft_new_color(float r, float g, float b);
t_color					ft_add_color(t_color c1, t_color c2);
t_color					ft_sub_color(t_color c1, t_color c2);
t_color					ft_scale_color(t_color c, float scalar);
t_color					ft_multiply_color(t_color c1, t_color c2);
t_vector				negate_vector(t_vector vector);
int						compare_vector(float a, float b);
t_vector				reflect_vector(t_vector, t_vector);
t_color					ft_multiply_color_scalar(t_color color, float scalar);
/* end of color manipulation*/

/* matrix operations*/
float					**ft_create_matrix(int n_rows, int n_cols);
float					**ft_multiply_matrix(float **m1, float **m2, int n_cols,
							int n_row);
int						ft_compare_matrix(float **m1, float **m2, int n_col,
							int n_row);
t_vector				ft_multiply_matrix_vec(float **m, t_vector v);
float					**identity_matrix(int n);
void					ft_transpose_matrix(float ***m, int n_rows, int n_col);
float					**get_minor(float **m, int row, int col, int n);
float					determinant(float **m, int n);
float					**inverse_matrix(float **m, int n);
void					ft_scale_matrix(float ***m, float scale, int n);
t_intersection			ft_init_intersection(int type);
// float				**ft_scaling_matrix(float x, float y, float z,
// int inverse);
float					**ft_translate_matrix(t_point point, int inverse);
t_point					ft_transform(t_point p1, t_point p2, int inverse);
float					**shearing_matrix(int *coord);
t_point					ft_new_point(float x, float y, float z);
void					print_matrix(float **matrix, int rows, int cols);
t_point					ft_scale(t_point scale, t_point point, int inverse);

float					**rotate_x(float rad);
float					**rotate_y(float rad);
float					**rotate_z(float rad);
void					print_matrix(float **matrix, int rows, int cols);
float					**shearing_matrix(int *coord);
// inline float 		radian( float degree);
void					ft_free_matrix(float **m, int n);
t_material				*default_material(void);
t_plight				*ft_new_plight(t_color color, t_point point);
/* end of  matrix operation*/

/*generate components*/
int						ft_add_ambient(t_scene **scene, char **components);

int						ft_add_camera(t_scene **scene, char **components);
void					ft_set_camera(t_scamera **camera);
void					set_view_matrix(float **m, t_vector left_v,
							t_vector up_n, t_vector forward_v);
float					**get_view_transform(t_point from_v, t_vector to_v,
							t_vector up_v);

t_cone					*ft_new_cone(char **components);
int						ft_add_cone(t_scene **scene, char **components);

int						ft_add_light(t_scene **scene, char **components);

t_plane					*ft_new_plane(char **components);
int						ft_add_plane(t_scene **scene, char **components);

t_sphere				*ft_new_sphere(char **components, t_scene **scene);
int						ft_add_sphere(t_scene **scene, char **components);

int						ft_is_whitespace(char c);
char					**ftt_split(char const *s, char *delimiter);
double					ft_atod(char *str);
double					get_fractional(char *str, int i);
int						is_empty_line(char *line);
int						ft_check_file_name(char *filename);
char					**split(char const *s, char *delimiter);
int						check_delimiter(char c, char *delimiter);
int						ft_is_degit(char *str);

int						ft_count_components(char **components);
int						ft_gen_colors(t_color *color, char *components);
t_map_line				*ft_get_last_line(t_map_line **map);
int						file_cheker(char *file_name, int *fd);
int						ft_add_line(t_map_line **map, char *line);
t_map_line				*ft_gen_scen_map(char *file_name);
int						ft_gen_elements(t_vector *coordinates,
							char *components);
int						get_texture(t_sphere *sphere, char *texture_name,
							t_scene **scene);
int						ft_add_component(t_scene **scene, int identifier,
							char **components);
int						ft_generate_scene(t_map_line *compoenent,
							t_scene **scene);

int						ft_check_non_negative(char *component);
int						ft_check_fov(char *component);
int						ft_check_elements(char *component);
int						ft_check_colors(char *component);
int						ft_check_range(char *component);
int						ft_check_norm(char *component);
int						ft_check_norm_range(char *comp);
int						is_identifier(char *identifier);
int						check_xpm_file(char *file);

int						ft_check_cone_component(char **components);
int						ft_check_light_component(char **components,
							int *counter);
int						ft_check_camera_component(char **components,
							int *counter);
int						ft_check_ambient_component(char **components,
							int *counter);
int						ft_check_cylinder_component(char **components);
int						ft_check_plane_component(char **components);
int						ft_check_sphere_component(char **components);
int						ft_check_components(int identifier_id,
							char **components, int *counter);
int						ft_check_map_components(t_map **map);

/*add components*/
int						ft_add_ambient(t_scene **scene, char **components);

int						ft_add_camera(t_scene **scene, char **components);
void					ft_set_camera(t_scamera **camera);
void					set_view_matrix(float **m, t_vector left_v,
							t_vector up_n, t_vector forward_v);
float					**get_view_transform(t_point from_v, t_vector to_v,
							t_vector up_v);

int						ft_add_cone(t_scene **scene, char **components);

t_cylinder				*ft_new_cylinder(char **components);
int						ft_add_cylinder(t_scene **scene, char **components);

int						ft_add_light(t_scene **scene, char **components);

t_plane					*ft_new_plane(char **components);
int						ft_add_plane(t_scene **scene, char **components);

int						ft_add_sphere(t_scene **scene, char **components);
t_sphere				*ft_new_sphere(char **components, t_scene **scene);

/*errors handler*/
void					error_handler(int i, int line, char *identifier);

/* ray manipulation*/
float					**create_matrix(int rows, int cols);
float					**create_identity_matrix(int size);
void					free_matrix(float **m);
float					**matrix_multiply(float **a, float **b);
t_vector				matrix_multiply_vector(float **m, t_vector v);
void					create_rotation_matrix(t_vector axis, float angle,
							float rotation_matrix[4][4]);
t_point					position(t_ray ray, float distance);
t_ray					create_ray(t_point origin, t_vector dir);
t_intersection			ft_intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersection			ft_new_intersection(float t, void *object, int type);
t_intersection			ray_hit(t_intersection *inters, int count);
t_ray					transform(t_ray ray, float **m);
t_color					get_lighting_color(t_material *material, t_light *light,
							t_compose *comp, t_color base_color);
t_vector				normilize_at_sphere_pos(t_sphere *sphere, t_point w_p);
t_color					process_light(t_world *world, t_compose *comp,
							t_light *light, t_material *material);
t_material				*get_object_material(void *obj, int obj_type);
void					get_spherical_coordinates(t_vector hit_point,
							t_sphere *sphere, float *u, float *v);
t_color					shading_hit(t_world *world, t_compose *comp);

t_color					handle_checkered_sphere(t_world *world, t_compose *comp,
							t_light *light, t_material *material);
float					**get_combined_inv(t_cylinder *cy);
t_color					handle_textured_sphere(t_world *world, t_compose *comp,
							t_light *light, t_material *material);
t_color					get_color_at(t_world *world, t_ray ray);
t_vector				vector_mult_scalar(t_vector v, float scalar);
float					**copy_matrix(float **m);
t_vector				matrix_multiply_vector(float **m, t_vector v);
float					**rotation_matrix(t_vector axis, float angle);
float					**translation_matrix(float x, float y, float z);

/* end of ray manipulation functions*/

/* scene manipulation functions*/
t_world					*default_world(t_scene *scene);
t_intersection			intersect_world(t_world *world, t_ray ray);
t_sphere				*default_sphere(void);
t_compose				*prepare_computations(t_intersection inter, t_ray ray);
t_color					shading_hit(t_world *world, t_compose *comp);
t_color					get_color_at(t_world *world, t_ray ray);
float					**get_view_transform(t_point from_v, t_point to_v,
							t_vector up_v);
t_ray					get_ray_pixel(t_scamera *cam, float x, float y,
							float edge);
t_color					clamp_color(t_color color);
int						is_shadowed(t_world *world, t_light *light,
							t_point point);
float					clamp(float value, float min, float max);
t_vector				ft_scale_vector(t_vector vector, float scale);
t_point					ft_multiply_matrix_point(float **m, t_point v);
t_point					ft_scale_point(t_point vector, float scale);

t_intersection			ft_intersect_cone(t_ray ray, t_cone *cone);
float					**create_cone_transform(t_cone *cone);
t_ray					get_local_ray(t_ray ray, t_cone *cone);
void					copy_matrix_cone(float **dst, float temp_matrix[4][4]);
float					**create_translation_matrix(t_cone *cone);
t_vector				normalize_at_cone_pos(t_cone *cone, t_vector point);

/* end of scene manipulation functions*/

/*shapes intersection*/
int						check_cylinder_caps(t_ray *ray, float t, float radius);
t_intersection			check_intersection_caps(t_ray ray, t_cylinder *cylinder,
							float cap);
float					get_min_sol(float *arr, int len);
int						is_point_inside_cylinder(t_point point,
							t_cylinder *cylinder);
void					calculate_cylinder_discriment(t_cylinder_eq *tmp,
							t_cylinder *cylinder, t_ray ray, float **inverse);
void					descriminant_intersction(t_cylinder_eq *tmp);
void					set_result_equation(t_intersection *result,
							t_cylinder_eq *tmp, t_ray ray,
							t_cylinder *cylinder);
t_intersection			ft_init_intersection(int type);
t_intersection			ft_intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_vector				normalize_at_cylinder_pos(t_cylinder *cylinder,
							t_point world_p);
float					**create_rotation_matrix_from_vector(
							t_vector orientation);
float					**get_combined_inv(t_cylinder *cy);
void					ft_add_cylinder_shape(t_world *world,
							t_cylinder *cylinder);

t_intersection			ft_intersect_plane(t_ray ray, t_plane *plane);
t_vector				normalize_at_plane_pos(t_plane *plane);
void					ft_add_plane_shape(t_world *world, t_plane *plane);

float					calculate_discriment(t_quadratic *tmp, t_ray ray,
							t_sphere *sphere);
void					ft_set_equation_sol(t_intersection *result,
							t_sphere *sphere, float closest_t);
t_intersection			intersect_world(t_world *world, t_ray ray);
t_compose				*init_composition(t_intersection inter, t_ray ray);
t_point					position(t_ray ray, float distance);
t_ray					transform(t_ray ray, float **m);
t_point					point_add(t_point point, t_vector p2);
int						calculate_pixel_color(t_world *world, t_ray ray);
t_ray					create_ray(t_point origin, t_vector dir);
void					rotation_matrix_helper(t_matrix tr, t_vector axis,
							float rotation_matrix[4][4]);
void					create_rotation_matrix(t_vector axis, float angle,
							float rotation_matrix[4][4]);
t_ray					get_ray_pixel(t_scamera *cam, float x, float y,
							float edge);
void					render_pixel(t_scene *scene, t_scamera *cam, int x,
							int y);

/*shapes functions*/
t_shape					*ft_new_shape(void *shape_obj, int shape_type);
void					ft_add_shape(t_world **root, void *new, int shape);
void					ft_add_sphere_shape(t_world *world, t_sphere *sphere);
void					ft_add_cone_shape(t_world *world, t_cone *cone);
void					ft_add_plight(t_world *world, t_light *light);

/*hooks event*/
void					setup_window_hooks(t_scene *scene);
int						key_hook(int keycode, t_scene *data);

/* destroy scen functions */

int						ft_close(t_var *vars);
void					ft_destroy_scene(t_scene *scen);
void					ft_free_map(t_map_line **map_lines);
void					ft_free_map_line(t_map *map);
void					ft_free_line_components(char **components);
void					ft_free(char ***words, int size);
void					free_matrix(float **m);
void					ft_free_camera(t_scamera **cam);
void					ft_free_sphere(t_sphere *sphere, t_var *data);
void					ft_free_cylinder(t_cylinder *cy);

#endif /* MINIRT_H */
