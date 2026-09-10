FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive
ARG STORM_ENABLE_PLOTTING=OFF

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    ninja-build \
    git \
    ca-certificates \
    gdb \
    valgrind \
    && if [ "${STORM_ENABLE_PLOTTING}" = "ON" ]; then \
        apt-get install -y --no-install-recommends \
            gnuplot-qt \
            libx11-6 \
            libgl1 \
            tk; \
    fi \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["/bin/bash"]