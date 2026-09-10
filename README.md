### STORM Tracking Algorithms  

First, build the image with the plotting argument enabled:

```docker build --build-arg STORM_ENABLE_PLOTTING=ON -t storm-dev .\.devcontainer\```

Next, run the docker file with the .x11 mounted so it can be found:
```
docker run --rm -it \
    -v "${PWD}:/workspace" \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY="${DISPLAY}" \
    storm-dev
```

To test:
```
gnuplot
plot sin(x)
```