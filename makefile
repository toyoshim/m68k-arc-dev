PREFIX=$(HOME)/opt/m68k-arc-dev
MAKEFLAG=-j4

.PHONY: all clean m68k-elf-binutils m68k-elf-gcc runtime romutils

all:
	make m68k-elf-binutils
	PATH=$(PATH):$(PREFIX)/bin make m68k-elf-gcc
	PATH=$(PATH):$(PREFIX)/bin make runtime
	make romutils

clean:
	rm -f runtime/*.o a.out

m68k-elf-binutils:
	mkdir -p build/m68k-elf-binutils && \
	cd build/m68k-elf-binutils && \
	../../third_party/binutils-gdb/configure \
		--prefix=$(PREFIX) \
		--target=m68k-elf && \
	make $(MAKEFLAG) && \
	make install

m68k-elf-gcc:
	mkdir -p build/m68k-elf-gcc && \
	cd build/m68k-elf-gcc && \
	../../third_party/gcc/configure \
		--prefix=$(PREFIX) \
		--target=m68k-elf \
		--enable-languages=c \
		--disable-nls \
		--disable-shared \
		--disable-multilib \
		--disable-decimal-float \
		--disable-threads \
		--disable-libatomic \
		--disable-libgomp \
		--disable-libmpx \
		--disable-libquadmath \
		--disable-libssp \
		--disable-libvtv \
		--disable-libmudflap \
		--disable-libstdcxx \
		--disable-libstdcxx-pch \
		--nfp \
		--with-gnu-as \
		--with-gnu-ld \
		--with-newlib \
		--with-sysroot=$(PREFIX) \
		--with-local-prefix=$(PREFIX) \
		--with-native-system-header-dir=$(PREFIX)/include \
		--without-headers && \
	make $(MAKEFLAG) && \
	make install

runtime:
	m68k-elf-gcc -nostdlib -c -o runtime/vectors.o runtime/vectors.S && \
	m68k-elf-gcc -O2 -nostdlib -c -o runtime/start.o runtime/start.c && \
	mkdir -p $(PREFIX)/lib/runtime && \
	cp runtime/*.o $(PREFIX)/lib/runtime && \
	mkdir -p $(PREFIX)/m68k-elf/include && \
	cp -r include/* $(PREFIX)/m68k-elf/include

romutils:
	make tools/romutils && cp tools/romutils $(PREFIX)/bin
