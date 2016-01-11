FROM thewtex/cross-compiler-linux-armv7

ENV ARCH arm
ENV CROSS_COMPILE arm-linux-gnueabihf-

WORKDIR /build/u-boot
ADD / /build/u-boot

RUN make novena_config
RUN make DEVICE_TREE=$PWD/dts/imx6q-novena.dtb SPL u-boot-dtb.img
