#include "shell.h"

Info get_info(int *status, int interactive, FILE *stream)
{
	Info shell;

	shell.status = *status;
	shell.interactive = interactive;
	shell.stream = stream;

	return (shell);
}
