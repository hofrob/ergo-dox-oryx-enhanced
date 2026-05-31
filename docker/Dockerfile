FROM python:3.14-slim-trixie
COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /bin/

RUN apt-get update && apt-get install -y \
    avr-libc \
    avrdude \
    build-essential \
    dfu-util \
    gcc-arm-none-eabi \
    gcc-avr \
    libnewlib-arm-none-eabi

RUN uv tool install qmk

ENV PATH="/root/.local/bin:$PATH"

WORKDIR /app
