#include <string.h>
#include "sys.h"
#include "settings.h"
#include "card.h"
#include "cpu.h"


// called after generic mmu setup
bool card_DFB1_Setup(struct TFCard* card, struct TFSettings* settings) {
	return true;
}

// called at beginning to find + configure card caps
bool card_DFB1_Find(struct TFCard* card) {
	int DFBx = 0;
	if (!testRead16((void*)0x00F1DFB0))
		return false;


	DFBx = safeRead8((void*)0x00F1DFB0);

	sprintf(card->name, "DFB%d", DFBx);
	card->Setup = card_DFB1_Setup;
	return true;
}
