# Example5: Simple C Web Server in Docker

A simple C program that greets the user, dockerized for easy execution in any environment.

## Description

This is a basic C program that implements a simple HTTP server. When accessed on port 8080, it responds with an HTML page that displays a welcome message with purple-colored text, centered in the page. The C app is dockerized to be easily executable in any environment.

## Technologies Used

- C
- GCC (GNU Compiler Collection)
- Docker

## Prerequisites

To run this project, you need to have Docker installed on your machine. If you don't have it, you can download it from [here](https://www.docker.com/products/docker-desktop).

## Instructions to Run the Project

1. **Clone this repository:**

   If you haven't cloned the repository yet, you can do so with the following command:

   ```bash
   git clone https://github.com/klever1995/Example_5.git

2. **Pull the Docker image:** 
   Before running the container, pull the Docker image with the following command:

   ```bash
   docker pull ksrobalino/example_cc:v1

3. **Run the Docker container:** 
   After pulling the image, run the container using this command:

   ```bash
   docker run -d -p 8080:8080 --name mi_contenedor ksrobalino/example_cc:v1

4. **Access the application:** 
   Once the container is running, you can access the application by navigating to the following URL in your web browser:
   http://localhost:8080
