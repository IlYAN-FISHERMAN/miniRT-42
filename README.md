![](https://github.com/ayogun/42-project-badges/blob/main/badges/minirtm.png?raw=true)

![42 Badge](https://img.shields.io/badge/42-Project-blue) 
![](https://img.shields.io/github/languages/code-size/IlYAN-FISHERMAN/miniRT-42?color=5BCFFF)

![](https://img.shields.io/badge/Linux-0a97f5?style=for-the-badge&logo=linux&logoColor=white)
![](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white)
![](https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white)

# ✨ MiniRT 42 ✨
Ahoy, coding voyagers! Welcome to the GitHub harbor for **Minirt-42**. Here, we dive into the thrilling realm of ray tracing—a mystical technique that brings 3D graphics to life! 🌄✨

![Screencast from 2024-10-26 01-50-22 (1)](https://github.com/user-attachments/assets/dec7f312-2abd-424e-8cb8-6bb82488c483)


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

## Scene File examples
```rt
R 1280 720
A 0.2                      255,255,255
C 1,0.80,-10   0,-0.06,1   70
l 0,0,0        0.6         255,255,255

# defining a new material
define moon	0.6	0.2	300	0.1	0.0	1.0	textures/moon.pgm

sp 0,0,0		   4		      255,255,255 moon
sp -25,0,50	   30		      0,0,255	   wood
```
You can define your own materials or use the built-in ones:
- `wood` - A wooden material.
- `metal` - A metallic material.
- `glass` - A glass material.
- `mirror` - A mirror material.
- `plastic` - A plastic material.

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
