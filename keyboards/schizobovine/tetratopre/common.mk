CUSTOM_MATRIX = lite
ANALOG_DRIVER_REQUIRED = yes
SRC += matrix.c ec_board.c ec_switch_matrix.c via_ec.c

#ifeq ($(strip $(VIA_ENABLE)), yes)
#    SRC += via_ec.c
#endif
