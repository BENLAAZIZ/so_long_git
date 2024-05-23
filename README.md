 # so_long_git

<img width="1296" alt="Screen Shot 2024-02-28 at 9 42 48 PM" src="https://github.com/BENLAAZIZ/so_long_git/assets/99501397/cf749244-61eb-49b3-aeb7-c6dad2252718">

# Game
* The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.

* The W, A, S, and D keys must be used to move the main character.

* The player should be able to move in these 4 directions: up, down, left, right.
  
* The player should not be able to move into walls.

* At every move, the current number of movements must be displayed in the shell.

* You have to use a 2D view (top-down or profile).

* The game doesn’t have to be real time.
 
* Although the given examples show a dolphin theme, you can create the world you
want.

## 
# Graphic management
* Your program has to display the image in a window.
 
* The management of your window must remain smooth (changing to another window, minimizing, and so forth).

* Pressing ESC must close the window and quit the program in a clean way.

* Clicking on the cross on the window’s frame must close the window and quit the
 
program in a clean way.
* The use of the images of the MiniLibX is mandatory.
##
 # Map
* The map has to be constructed with 3 components: walls, collectibles, and free
space.
* The map can be composed of only these 5 characters:
  
### `0` -> for an empty space,
### `1` -> for a wall,
### `C` -> for a collectible,
### `E` -> for a map exit,
### `P` -> for the player’s starting position.

* The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.

* The map must be rectangular.
 
* The map must be closed/surrounded by walls. If it’s not, the program must return
an error.

* You have to check if there’s a valid path in the map.

* You must be able to parse any kind of map, as long as it respects the above rules.

<img width="898" alt="Screen Shot 2024-03-06 at 4 41 50 PM" src="https://github.com/BENLAAZIZ/so_long_git/assets/99501397/9bc24c42-58a2-4d34-a733-8f85f4f5357c">


## 
# What is the MLX?
The MiniLibX, or MLX, is a framework built by Olivier Crouzet on top of X11, a window system developed back in 1984! The MLX is a beginner-friendly C API to interact with the X11 system behind it. Let's look at some of the functions you might be using.

* `mlx_init`: Initialises the MLX library. Must be called before using any other functions.
* `mlx_new_window`: Creates a new window instance.
* `mlx_hook`: Registers events.
* `mlx_loop`: Loops over the MLX pointer, triggering each hook in order of registration.
* `mlx_xpm_file_to_image`: Converts an XPM file to an MLX image pointer.
* `mlx_put_image_to_window`: Puts your image to the screen at the given coordinates.
* `mlx_destroy_image`: Frees the image.
* `mlx_destroy_window`: Frees the window instance.
* `mlx_destroy_display`: Frees MLX.
We will be looking into each function in more detail later, but if you want more information about these functions, I recommend visiting 42Docs, as they have done a great job documenting the MLX (linked in additional resources).
https://harm-smits.github.io/42docs/libs/minilibx
