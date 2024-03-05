# littleWizard-Game

Description
Project of the 42 school common core curriculum. The goal is to create a proof of concept of a 2D game using the MinilibX graphic library and the ANSI C language. No engines used.

This project is a simple game where the player must:
* collect all the items on the map and reach the exit
* the player can only move horizontally and vertically
* the map is composed of walls, empty spaces, collectible items and the exit.

# MLX
The MinilibX is a simple X-Window programming API in C. a mini version of Xlib --- C Language X Interface. 

# Map
### You can construct your own map.
make a .ber file and follow these rules : 
* The map has to be constructed with 3 components: walls, collectibles, and free space.
* The map can be composed of only these 5 characters:
  - 0 for an empty space,
  - 1 for a wall,
  - C for a collectible,
  - E for a map exit,
  - P for the player’s starting position.
  - Here is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
* The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
  - If the map contains a duplicates characters (exit/start), you should display an error message.
  - The map must be rectangular.
  - The map must be closed/surrounded by walls.
  - You have to check if there’s a valid path in the map. exit and all collectibles must be reached.
  - You must be able to parse any kind of map, as long as it respects the above rules.
  - Another example of  .ber map:
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
• If any misconfiguration of any kind is encountered in the file, the program must
will in a clean way, and return "Error\n" followed by an explicit error message of the error

# Installation
Before compiling the project it is necessary to have MLX library. (linux provided in the repo, if mac, please install the mac version)

This project also uses a library "Libft" also developed in the 42 school curriculum. (also provided, so no worries)

# play

#### To compile the game use:

```
make main
```
#### to run the game :
After compiling the project, the executable file with the name so_long will be created, to run the game call the executable passing the map as an argument:

Example:
```
./a.out map2.ber
```
some maps are provided in map folder

## example 

![image](https://github.com/alaato/littleWizard-Game/assets/68467723/dda0aab8-cca6-4c1c-9eb9-9e52a57c7849)
![image](https://github.com/alaato/littleWizard-Game/assets/68467723/a81af1ed-c71f-4967-8f86-d10fecd4a9ea)


