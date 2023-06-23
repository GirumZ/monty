#include "monty.h"
/**
 * init_global - initializes a global variable
 */

void init_global(void)
{
	glob.s_q_switch = 1;
	glob.cline = 1;
	glob.arg = NULL;
	glob.fp = NULL;
	glob.head = NULL;

}
/**
 * termi_global - terminates a global variable
 */

void termi_global(void)
{
	free_dlistint(glob.head);
	free(glob.buff);
	fclose(glob.fp);
}

