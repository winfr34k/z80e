#include "cpu.h"
#include <string.h>
#include <stdlib.h>

z80cpu_t* z80cpu_init() {
    z80cpu_t* cpu = malloc(sizeof(z80cpu_t));
    
    cpu->state->primary_registers = calloc(1, sizeof(z80registers_t));
    cpu->state->shadow_registers = calloc(1, sizeof(z80registers_t));
    cpu->state->I = cpu->state->R = 0;

    return cpu;
}

void z80cpu_free(z80cpu_t* cpu) {
    free(cpu->state->primary_registers);
    free(cpu->state->shadow_registers);
    free(cpu->state);
    free(cpu);
}