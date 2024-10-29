![](https://github.com/ayogun/42-project-badges/blob/main/badges/minirtm.png?raw=true)

![42 Badge](https://img.shields.io/badge/42-Project-blue) 
![](https://img.shields.io/github/languages/code-size/IlYAN-FISHERMAN/miniRT-42?color=5BCFFF)

![](https://img.shields.io/badge/Linux-0a97f5?style=for-the-badge&logo=linux&logoColor=white)
![](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white)
![](https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white)

# ✨ MiniRT 42 ✨
Ahoy, coding voyagers! Welcome to the GitHub harbor for **Minirt-42**. Here, we dive into the thrilling realm of ray tracing—a mystical technique that brings 3D graphics to life! 🌄✨

![ezgif-5-abfccaac83](https://github.com/user-attachments/assets/9a7309b7-f5ec-45b1-adb6-3a36f2415afa)

## What's Minirt, Anyway?
Minirt invites you to create a mini-ray tracer from scratch. It’s a wild ride where you play with light, shadows, and reflections—bringing a world to life through code! 🌌💡

## Cloning the Repository
Ready to set sail? Cast this spell to board the Minirt ship:
```bash
git clone https://github.com/IlYAN-FISHERMAN/miniRT-42.git
```
## Executing Minirt! 💻
Using Make commands, you can navigate the Minirt universe with ease. Here are some commands to get you started:
- `make` - Compiles the Minirt project.
- `make bonus` - Compiles the Minirt project with bonus features and multi-threading.
- `make clean` - Removes object files. 🧹
- `make fclean` - Removes object files and the Minirt executable. 🧹
- `make re` - Re-compiles the Minirt project. 🔄

Execute the Minirt project with the following command:
```bash
./minirt "path/to/scene.rt"
```
### Camera Controls

You can navigate the camera using the following controls:

- **Movement**:
  - `W`, `A`, `S`, `D` - Move the camera around.
  
- **Direction**:
  - Arrow keys (`↑`, `←`, `↓`, `→`) - Change the camera's direction.

- **Altitude Adjustment**:
  - `Space` - Raise the camera higher.
  - `X` - Lower the camera.

**Note**: These controls are based on SWISS and US keyboard layouts.

### Map generator
You can generate a random map by using :
```bash
./minirt -r
```

For more informations, you can get the miniRT guidelines:
```bash
./minirt -h
```

## Scene File examples
```rt
# (optional)  resolution
#   width   height  
R   1000    1000
# ambient light
#   intensity   color
A   0.4         255,255,255
# camera
#   pos     look_at     fov
C   0,1.8,0 0,-0.01,1   80
# light
#   pos         intensity   color
L   0.0,2.2,2.1 1.0         255,255,255

# define a new material
define   moon   0.6 0.1 20 0.0 0.0 0.4 textures/moon.pgm

# you can then refer to this material by name, or use the defaults materials :
# metal, plastic, glass, mirror, wood, checkerboard, bricks, mat

#plane
#   pos     normal                  color       material
pl  0,0,0   0,1,0                   255,255,255 checkerboard
#sphere
#   pos     radius                  color       material
sp  -2,2,4  2.0                     255,255,255 moon
#cylinder
#   pos     normal  radius  height  color       material
cy  0,2,4   0,1,0   1.0     2.0     230,180,150 bricks
#cone
#   pos     normal  radius  height  color       material
co  0,5,4   0,-1,0  1.0     2.0     120,120,250 wood
```
You can define your own materials or use the built-in ones:
- `wood` - A wooden material.
- `metal` - A metallic material.
- `glass` - A glass material.
- `mirror` - A mirror material.
- `plastic` - A plastic material.
- `checkerboard` - A checkerboard material.
- `bricks` - A bricks material.
- `mat` - A mat material.

If defining your own material, you can also define (optional) a bump texture for the material.
The bump texture should be a PGM file (P2 format). No comments are allowed in the PGM file.
You can easily convert an image to a PGM file using the given script:
```bash
bash scripts/img2pgm.sh path/to/image.jpg path/to/save.pgm
```
note: the script requires `imagemagick` to be installed on your system.

# Minirt: Crafting Our Own Raytracer
Minirt is one of our grandest projects at 42 so far. Building our own ray tracer isn't exactly "mini," despite the name! It took over a month to bring this project to life with bonuses and a fully functional rendering system. 👀💥
## What We Learned 🧠
1. **Ray Tracing Basics**: Learned the science behind light rays and how to trace them for realistic reflections and refractions. 🕶️
2. **Math Meets Code**: Vectors, intersections, and light models became our best friends. Understanding the math behind graphics is key! 📐
3. **Modular Design**: Writing clean, modular code was a must for scaling this project. A tidy structure makes debugging so much easier! 📂

## Our Minirt Features 🎨
1. **Camera Control**: We implemented camera movement and perspective controls, so you can explore scenes from every angle. 📸
2. **Lighting & Shadows**: Light sources cast realistic shadows and add dimension. Multiple light models bring variety and depth to each scene! 🌞
3. **Reflections & Refractions**: Materials interact with light—whether shiny, matte, or transparent—to add realism. 🌊
4. **Material definitions**: Materials can be defined in the `.rt` file, allowing for a wide range of textures and effects. 🎨
