#include <stdio.h>
#include <stdlib.h>
#include "bode.h"
#include "callshell.h"
#include "gtk2.h"
#include "Nyquistgtk.h"
//#include "nyquist.h"

void main(int argc, char *argv[])
{

	bode(0,0);
	bodeplot("lib/disp/bode.sh");
	gtk2(argc, argv);
}
