# STORM Tracking Algorithms  

This repo follows the tracking of storms from satellites using lightning flash detections. 

It is constructed using Docker, which imports necessary C++ libraries for compiling, and the C++ codes use CMAKE. 

## Docker

### Build

To build the docker image, enter in a terminal:

```docker build --build-arg CPP_ENABLE_PLOTTING=ON -t storm-dev .\.devcontainer\```

### Run

Then, to run the image while mounting the display, run:

```
docker run --rm -it \
    -v "${PWD}:/workspace" \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY="${DISPLAY}" \
    storm-dev
```

### Test Plotting:
Gnuplot can be started from the command line:

```gnuplot```

And then a simple sine wave can be plotted to ensure the docker is connected to the display:

```plot sin(x)```

### Troubleshooting:
If a plot did not appear and you're running WSL, 
- make sure you're using the WSL terminal
- make sure your WSL can access docker (go Docker > Settings > Resources > WSL integration)

## CMAKE Build

### Build

For building, ensure you are in the correct directory after running the docker image:

```cd cpp ```

Then, build the project using Ninja:

```cmake -S . -B build -G Ninja```

### Compile

Compile the project:

```cmake --build build```

### Run Test Script

Run the test script:

```./build/test/storm_test_ggiw```