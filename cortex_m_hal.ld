MEMORY
{
  SYSTICK (rw) : ORIGIN = 0xE000E010, LENGTH = 16
}

SECTIONS
{
	.systick_regs (NOLOAD) : {
		*(.systick_regs)
	} > SYSTICK
}

