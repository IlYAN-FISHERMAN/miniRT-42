# miniRT-42

![42 Badge](https://img.shields.io/badge/42-Project-blue)

## Description

miniRT is a project from school 42 aiming to create a simple raytracer capable of generating images based on minimal scene description. This project allows exploring the basics of image generation by ray tracing, a computer graphics rendering algorithm.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Project Structure](#project-structure)
- [Contributors](#contributors)
- [Resources](#resources)

## Installation

To install the project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/IlYAN-FISHERMAN/miniRT-42
   cd miniRT-42
   ```
2. Compile the project:
   ```bash
   make
   ```

## Usage

To execute the raytracer, use the following command:
   ```bash
   ./miniRT [path/to/scene_file.rt]
   ```

## Features

- Loading scenes from .rt files
- Support for multiple primitives (spheres, planes, etc.)
- Management of light sources
- Basic shadows and reflections
- Configurable camera
