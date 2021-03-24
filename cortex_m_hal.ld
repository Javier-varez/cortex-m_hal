MEMORY
{
  DWT : ORIGIN = 0xE0001000, LENGTH = 4K
  SYSTICK (rw) : ORIGIN = 0xE000E010, LENGTH = 16
  SCB : ORIGIN = 0xE000ED00, LENGTH = 240
  SCB_DEBUG : ORIGIN = 0xE000EDF0, LENGTH = 16
}

SECTIONS
{
	.systick_regs (NOLOAD) : {
		*(.systick_regs)
	} > SYSTICK

	.dwt_regs (NOLOAD) : {
		*(.dwt_regs)
	} > DWT

	.scb_regs (NOLOAD) : {
		*(.scb_regs)
	} > SCB

	.scb_debug_regs (NOLOAD) : {
		*(.scb_debug_regs)
	} > SCB_DEBUG
}

