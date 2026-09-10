### STORM Tracking Algorithms  

# Build

For plotting, ensure the argument is ON:

```docker build --build-arg STORM_ENABLE_PLOTTING=ON -t storm-dev .\.devcontainer\```

# Run
```
docker run --rm -it \
    -v "${PWD}:/workspace" \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY="${DISPLAY}" \
    storm-dev
```

# Test Plotting:
```
gnuplot
plot sin(x)
```

# Troubleshooting:
If a plot did not appear and you're running WSL, 
- make sure you're using the WSL terminal
- make sure your WSL can access docker (go Docker > Settings > Resources > WSL integration)