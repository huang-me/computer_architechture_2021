BINS = emu-rv32i test1 countBits

CROSS_COMPILE = riscv-none-embed-
RV32I_CFLAGS = -march=rv32i -mabi=ilp32 -O3 -nostdlib

CFLAGS = -O3 -Wall -std=gnu99
LDFLAGS = -lelf

all: $(BINS)
	
emu-rv32i: emu-rv32i.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

test1: test1.c
	$(CROSS_COMPILE)gcc $(RV32I_CFLAGS) -o $@ $<

countBits: countBits.c
	$(CROSS_COMPILE)gcc $(RV32I_CFLAGS) -o $@ $<

run: $(BINS)
	./emu-rv32i countBits

check: $(BINS)
	./emu-rv32i test1

clean:
	$(RM) $(BINS)
