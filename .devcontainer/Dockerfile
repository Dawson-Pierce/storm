FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive
ARG CPP_ENABLE_PLOTTING=OFF

### C++ Development
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    ninja-build \
    libeigen3-dev \
    git \
    ca-certificates \
    gdb \
    valgrind \
    && if [ "${CPP_ENABLE_PLOTTING}" = "ON" ]; then \
        apt-get install -y --no-install-recommends \
            gnuplot-qt \
            libx11-6 \
            libgl1; \
    fi \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y --no-install-recommends \
    python3 \
    python3-pip \
    python3-dev \
    python3-venv\
    python3-tk \
    python-is-python3 \
    && rm -rf /var/lib/apt/lists/*

# Set up virtual environment for python
RUN python -m venv /opt/venv

ENV PATH="/opt/venv/bin:${PATH}"

# Install python dependencies
RUN pip install numpy matplotlib bsk



ENV HOME="/home/ubuntu"
USER ubuntu

WORKDIR /workspace

CMD ["/bin/bash"]
