/*
linphone
Copyright (C) 2000  Simon MORLAT (simon.morlat@linphone.org)
Copyright (C) 2010  Belledonne Communications SARL

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "ringplayer.h"

#import "private.h"

LinphoneRingPlayer* linphone_ringplayer_new() {
	LinphoneRingPlayer* rp = ms_new(LinphoneRingPlayer, 1);
	return rp;
}

void linphone_ringplayer_destroy(LinphoneRingPlayer* rp) {
	if (rp->ringstream) {
		linphone_ringplayer_stop(rp);
	}
	ms_free(rp);
}

int linphone_ringplayer_start(LinphoneRingPlayer* rp, MSSndCard* card, const char* ring, int loop_pause_ms) {
	return linphone_ringplayer_start_with_cb(rp, card, ring, loop_pause_ms, NULL, NULL);
}

int linphone_ringplayer_start_with_cb(LinphoneRingPlayer* rp, MSSndCard* card, const char* ring, int loop_pause_ms, MSFilterNotifyFunc func, void * user_data) {
	if (linphone_ringplayer_is_started(rp)) {
		ms_message("the local ring is already started");
		return 2;
	}
	if (card!=NULL && ring){
		ms_message("Starting local ring...");
		rp->ringstream=ring_start_with_cb(ring,loop_pause_ms,card,func,user_data);
		return 0;
	}
	return 1;
}

bool_t linphone_ringplayer_is_started(LinphoneRingPlayer* rp) {
	return (rp->ringstream!=NULL);
}

int linphone_ringplayer_stop(LinphoneRingPlayer* rp) {
	ring_stop(rp->ringstream);
	return 0;
}
